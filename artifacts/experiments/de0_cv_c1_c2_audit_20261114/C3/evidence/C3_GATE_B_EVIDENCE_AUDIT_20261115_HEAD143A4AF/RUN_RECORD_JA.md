# Gate B 現HEAD再照合 — execution record

実施日: 2026-11-15 JST  
対象Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`  
Branch / HEAD: `codex/stage-c3-jtag-pilot-20261114` / `143a4af545b49391b2413751918f7bb515277ae9`  
originの当該branch: `143a4af545b49391b2413751918f7bb515277ae9`  
対象build: `43334531`; Quartus Prime Lite 25.1std.0 Build 1129; Cyclone V `5CEBA4F23C7N`

## 目的・境界

前回のGate B evidence audit記録はHEAD `c17c44e...`時点だったため、現在のHEAD `143a4af...`から保存済みの入力59件を再照合した。これは保存済みレポートとidentityを読むread-only Python監査であり、Quartus、TimeQuest、JTAG、USB-Blaster、基板を起動・操作していない。QSF/SDC/RTL、SOF、Flash/CFMを変更していない。

Codex shellの既定cwdは旧`RTNN`作業フォルダだったが、originはkardaneh repositoryであるため、その場所には書き込んでいない。実行script、`--repo`、出力先はすべて正しいUnjuno repositoryを絶対パスで指定し、本記録とJSONはUnjuno側の証拠folderに作成した。

## 実行

Tool: Python 3.11.9  
Command:

```powershell
python "C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114\artifacts\experiments\de0_cv_c1_c2_audit_20261114\C3\source\audit_c3_gate_b_evidence.py" --repo "C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114" --output "C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114\artifacts\experiments\de0_cv_c1_c2_audit_20261114\C3\evidence\C3_GATE_B_EVIDENCE_AUDIT_20261115_HEAD143A4AF"
```

Process exit code: **0**. Stdout: `PASS: 59 inputs hashed; 13 campaign bindings identity-matched; 4 setup/hold corners parsed; 16 CDC structures retained`; `B-SIGNOFF=BLOCKED; B-EMPIRICAL=PASS_LIMITED`.

## 再照合結果

* 59 evidence input hashes, 13 schedule bindings / 24,840 frozen rows: PASS identity consistency.
* 4 timing corners × setup/hold reports: 20 reported paths each, 0 reported violations in those reports. This result covers only paths included by the saved reports and current constraints.
* Bundled-data CDC: request 800 bits and response 480 bits in all corners under the recorded 16 ns **internal screening constraint**; 16 Design Assistant D102 structures remain visible and unwaived.
* TimeQuest unconstrained endpoints remain: TDI/TMS 2 input ports and 41 paths; TDO plus LEDR status outputs 4 output ports and 8 paths. The LED timing disposition does not resolve JTAG port timing.
* Status remains `B-SIGNOFF=BLOCKED_EXTERNAL_JTAG_TIMING_AND_UNCONSTRAINED_IO`, `B-EMPIRICAL=PASS_LIMITED_NOT_A_TIMING_WCET_OR_DEADLINE_GUARANTEE`.

The audit JSON records source-evidence hashes and the exact scope limit. `SHA256SUMS.txt` covers the JSON and this run record. No new Quartus synthesis/Fitter/STA was run; saved Quartus logs were parsed and hashed by the script. No external timing constraint was inferred from the 30 MHz Quartus `altera_reserved_tck` model.

Remaining signoff input: a revision-applicable DE0-CV onboard controller/board timing specification or appropriate measured TCK/TDI/TMS/TDO waveforms and relative delay, plus evidence that the fitted board assembly matches those conditions. The FT245BL FIFO bus datasheet does not provide these JTAG endpoint values. Existing Terasic inquiry draft remains unsent.
