#!/usr/bin/env python3
import argparse
import hashlib
import json
import re
import zipfile
from pathlib import Path

EXPECTED_ZIP_SHA = "9150b0763e5d7b7c305441befdb4161ccf95612edd924b525f8388e06d9a86b0"
EXPECTED_ELF_SHA = "234a7f46cf227a11f5d97f3c778cbb0c4ed4f7067f8994bcca86c4b08ff4e742"
EXPECTED_BIN_SHA = "266ecb70c723b2164f6fe9039f27d4cb49c4d7271d4aca0cf69f2692cdfdf7a1"


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def parse_ints(s: str):
    return [int(x.strip()) for x in s.split(",") if x.strip()]


def derive(zip_path: Path):
    raw = zip_path.read_bytes()
    if sha256(raw) != EXPECTED_ZIP_SHA:
        raise SystemExit("frozen ZIP SHA mismatch")

    with zipfile.ZipFile(zip_path) as z:
        elf = z.read("rtnn_ibex_rtl.elf")
        binary = z.read("rtnn_ibex_rtl.bin")
        if sha256(elf) != EXPECTED_ELF_SHA:
            raise SystemExit("contained ELF SHA mismatch")
        if sha256(binary) != EXPECTED_BIN_SHA:
            raise SystemExit("contained BIN SHA mismatch")
        header = z.read("rtnn/realtime_nn_ibex_rtl_vectors_generated.h").decode()
        validation = json.loads(z.read("realtime_nn_ibex_rtl_validation_results.json"))

    indices = parse_ints(
        re.search(r"RTNN_RTL_TEST_INDEX\[[^]]+\]=\{([^}]*)\}", header).group(1)
    )
    labels = parse_ints(
        re.search(r"RTNN_RTL_LABEL\[[^]]+\]=\{([^}]*)\}", header).group(1)
    )
    body = re.search(r"RTNN_RTL_X\[[^]]+\]\[64\]=\{(.*)\};", header, re.S).group(1)
    inputs = [parse_ints(s) for s in re.findall(r"\{([^{}]+)\}", body)]

    if not (len(indices) == len(labels) == len(inputs) == 3):
        raise SystemExit("expected exactly three frozen RTL vectors")
    if any(len(x) != 64 for x in inputs):
        raise SystemExit("frozen RTL vector length changed")

    predictions = {i: [] for i in range(3)}
    for row in validation["certification_rows"]:
        predictions[int(row["slot"])].append(int(row["pred"]))
    if any(len(predictions[i]) != 7 for i in range(3)):
        raise SystemExit("expected seven fixed-class predictions per vector")

    out = {
        "schema": "rtnn-de0-cv-preflight-v1",
        "status": "BOARD_FREE_REFERENCE_ONLY",
        "source_artifact": {
            "frozen_zip_sha256": EXPECTED_ZIP_SHA,
            "elf_sha256": EXPECTED_ELF_SHA,
            "bin_sha256": EXPECTED_BIN_SHA,
        },
        "finite_classes": list(range(7)),
        "normalized_classes": [0.0, 1 / 6, 2 / 6, 3 / 6, 4 / 6, 5 / 6, 1.0],
        "vectors": [],
        "nonclaims": [
            "No DE0-CV measurement has been performed.",
            "Simple-System cycle counts are intentionally omitted; the FPGA must derive a new target-specific timing table.",
            "These vectors validate prediction/class behavior, not physical WCET by themselves.",
        ],
    }

    for slot in range(3):
        out["vectors"].append(
            {
                "slot": slot,
                "test_index": indices[slot],
                "label": labels[slot],
                "preferred_exit": int(validation["host_preferred_by_slot"][str(slot)]),
                "input_u8_64": inputs[slot],
                "expected_fixed_class_prediction": predictions[slot],
            }
        )
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--zip", required=True)
    ap.add_argument("--reference", required=True)
    args = ap.parse_args()

    derived = derive(Path(args.zip))
    reference = json.loads(Path(args.reference).read_text())
    if derived != reference:
        raise SystemExit("preflight reference does not match frozen certification artifact")

    print(
        json.dumps(
            {
                "decision": "PASS",
                "schema": derived["schema"],
                "vectors": len(derived["vectors"]),
                "fixed_class_cases": sum(
                    len(v["expected_fixed_class_prediction"]) for v in derived["vectors"]
                ),
                "frozen_zip_sha256": EXPECTED_ZIP_SHA,
                "simple_system_cycles_intentionally_absent": True,
                "de0_cv_measurement_claimed": False,
            },
            indent=2,
        )
    )


if __name__ == "__main__":
    main()
