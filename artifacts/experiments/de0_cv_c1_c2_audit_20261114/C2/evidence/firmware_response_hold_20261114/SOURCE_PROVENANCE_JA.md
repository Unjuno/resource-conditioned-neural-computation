# C2 response-hold source provenance

日時: 2026-11-14 JST
正本repo: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
branch: `codex/stage-c3-repro-timing-20261114`
build ID: `43324a32`

## 対象と取得元

このフォルダには、C2 firmware response-hold 条件の監査に必要な3ソースだけを保存した。

| 保存名 | SHA-256 | 取得元と照合根拠 |
|---|---|---|
| `rtnn_c2_main.c` | `a6964666d08695bdc447f2315b1683c90a08750a76db1188cb8d8669428cc917` | 保全中の旧ローカル作業ツリー `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\RTNN\de0cv_setup\stage3_experiments\ibex_csa_2026-11-03\c2_jtag_measurement_20261111\firmware\`。C2 firmware manifestの同一source SHAと一致。旧ツリーは読み取りだけで、編集・移動・削除していない。 |
| `rtnn_de0_cv_soc_c2.sv` | `9fbc58508e023f05c8dba59d085ef7cf673a04b7d9e9a6b0d6cc18dd0ca5acdc` | 同じ保全ツリーのC2 `rtl/`。回収済み146-source manifestの該当エントリと一致。 |
| `rtnn_c2_vjtag_mailbox.sv` | `b4107f64666f27f798be25ba013a15a7f993c9d5bde07b7f9fa241ca498871d0` | 正本repo内の `c3_gate_a_recheck_20261114/rtnn_c2_vjtag_mailbox_final_candidate.sv`。Gate A recovered-artifact manifestと一致。capture-pendingを含むC2J2 exact flat RTLに対応する回収版。 |

Firmware manifest: `../candidate_firmware_build/c2_firmware_manifest.json`。manifest SHA-256は `16acc8375c18868c2e70885b1ecdb88c98598a98e53d94f8fda309aee0230c16`、ELF SHA-256は `625daf8cc194f1bc7d48eefff0f07939c5e0988bb07fc8a3e7efad7e613a15fd`。同manifest記録の4 RAM lane SHAは `quartus_d101/rtnn_ram_lane[0-3].hex` の各SHAとすべて一致し、exact flat RTLの `$readmemh` 入力名とも一致した。

## ソース上で確認した順序と範囲

1. `rtnn_c2_main.c` は要求wordを読み切った後にrequest ACKを書き、推論を実行する。
2. firmwareは48-byte responseを12 wordに書いた後、最後にresponse commitを書く。
3. mailboxはJTAG要求を受け付ける際、previous response pending、busy、doneがいずれも解除されていることを要求する。
4. TCK側はpendingな384-bit responseの完全scan後だけconsume toggleを出し、sys側は同期後にDONEを解除する。
5. 従ってこのbuildでは、hostが前responseをconsumeするまで新要求・次response payload書換えへ進まないプロトコルがRTLとfirmwareにある。

実行可能な監査: `../audit_firmware_response_hold.py`。結果は `../firmware_response_hold_20261114_audit.json`。これはSHA固定したソース・RAM初期化と制御順序の静的監査であり、形式検証、アナログmetastability解析、基板JTAGの外部タイミングsignoffではない。
