#!/usr/bin/env bash
# Rebuild the C1-proven Ibex graph with both required overlays and UART-free C2 SoC.
set -euo pipefail
: "${IBEX_ROOT:=/opt/rtnn-tools/ibex}"
: "${IBEX_SOURCE_LIST:?set IBEX_SOURCE_LIST to rtl/ibex_fusesoc_sources_c2.txt}"
: "${C2_BUILD_DIR:?set C2_BUILD_DIR to a new D: build directory}"
[[ ! -e "$C2_BUILD_DIR" ]] || { echo "Refusing existing C2 build directory: $C2_BUILD_DIR" >&2; exit 2; }
[[ "$(git -C "$IBEX_ROOT" rev-parse HEAD)" == 7b5df75a041affe56e8c235260f98a09b3319008 ]] || {
  echo 'Pinned Ibex revision mismatch' >&2; exit 2; }
command -v sv2v >/dev/null && command -v python3 >/dev/null || exit 2
build_id=${RTNN_C2_BUILD_ID:-43324a31}
[[ "$build_id" =~ ^[0-9a-fA-F]{8}$ ]] || { echo 'RTNN_C2_BUILD_ID must be exactly 8 hex digits' >&2; exit 2; }
build_id=$(printf '%s' "$build_id" | tr 'A-F' 'a-f')
export RTNN_C2_BUILD_ID="$build_id"
mkdir -p "$C2_BUILD_DIR"
mapfile -t files < <(sed '/^[[:space:]]*#/d;/^[[:space:]]*$/d' "$IBEX_SOURCE_LIST")
[[ ${#files[@]} -eq 146 ]] || { echo "expected 143 Ibex graph sources + 3 C2 sources, got ${#files[@]}" >&2; exit 2; }
for f in "${files[@]}"; do [[ -f "$f" ]] || { echo "missing source: $f" >&2; exit 2; }; done
sv2v --define=SYNTHESIS \
  --define="RTNN_C2_BUILD_ID=32'h${build_id}" \
  -I"$IBEX_ROOT/rtl" \
  -I"$IBEX_ROOT/vendor/lowrisc_ip/dv/sv/dv_utils" \
  -I"$IBEX_ROOT/vendor/lowrisc_ip/ip/prim/rtl" \
  -I"$IBEX_ROOT/vendor/lowrisc_ip/ip/prim_generic/rtl" \
  "${files[@]}" > "$C2_BUILD_DIR/rtnn_c2_soc_flat.v" 2> "$C2_BUILD_DIR/sv2v.log"
python3 "$(dirname "$IBEX_SOURCE_LIST")/../../quartus_pkg/tools/sv2v_quartus_compat.py" \
  "$C2_BUILD_DIR/rtnn_c2_soc_flat.v"
python3 - "$IBEX_SOURCE_LIST" "$C2_BUILD_DIR" <<'PY'
import hashlib,json,os,subprocess,sys
from pathlib import Path
source_list=Path(sys.argv[1]); out=Path(sys.argv[2])
sources=[line.strip() for line in source_list.read_text().splitlines() if line.strip() and not line.lstrip().startswith('#')]
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
manifest={
 'schema':'rtnn-c2-fusesoc-flat-v1','status':'SV2V_FLAT_NOT_SIMULATED',
 'build_id':os.environ.get('RTNN_C2_BUILD_ID','43324a31').lower(),'ibex_commit':subprocess.check_output(['git','-C','/opt/rtnn-tools/ibex','rev-parse','HEAD'],text=True).strip(),
 'source_count':len(sources),'source_list_sha256':sha(source_list),
 'source_sha256':{p:sha(p) for p in sources},
 'flat_sha256':sha(out/'rtnn_c2_soc_flat.v'),
 'nonclaims':['not functionally simulated','not synthesized','no timing signoff','no FPGA programming']}
(out/'source_manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
print('C2_SV2V_FLAT_READY_NOT_SIMULATED',manifest['flat_sha256'])
PY
