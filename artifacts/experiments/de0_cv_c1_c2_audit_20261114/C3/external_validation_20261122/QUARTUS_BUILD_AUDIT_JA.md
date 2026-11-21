# Quartus build・timing・警告監査

## 対象

- Quartus Prime Lite `25.1std.0 Build 1129`、revision `rtnn_c3_measurement_v2`
- DE0-CV / Cyclone V `5CEBA4F23C7`
- SOF SHA-256: `5e333e9377b7188a394d04b93b98833d91afb2cd53eca8d976e6aa715dfa00c4`
- SDC SHA-256: `ceaaa6708f0ed8f6d2c1443b60d9511c51d21f96ddaf914117ee6a65410c82eb`
- 成果物: [`build/quartus_external_attempt2/`](build/quartus_external_attempt2/)

## ビルド・資源

Analysis & Synthesis、Fitter、AssemblerはいずれもSuccessful。SRAM設定ファイル（SOF）が生成された。これはファイル生成の結果であり、基板への書込みや物理動作を示さない。Flash/CFMへの書込みはしていない。

| 項目 | 結果 |
|---|---:|
| ALM | 4,726 / 18,480 (26%) |
| レジスタ | 9,146 |
| RAM block | 256 / 308 (83%) |
| block memory bits | 2,097,152 / 3,153,920 (66%) |
| DSP | 3 / 66 (5%) |

## 内部STA

保存済みpost-fit reportと`run_external_sta.tcl`の追加4コーナーreportを確認した。`CLOCK_50`は20 ns。埋込みSLD hubが作る`altera_reserved_tck`はreport上33.333 ns。制約された内部パスで最悪setupはslow 85°Cの`+1.803 ns`、最悪holdはfast 0°Cの`+0.124 ns`。4コーナーでsetup/hold違反は報告されていない。

これはレポートされた制約済みパスに限る。STAのfully-constrained警告を解消した結果ではない。

## CDC・未制約I/O

Design Assistant reportにはmedium D102が16件残る。対象は800-bit request bundled-data busの1構造とresponse bus側15のreport node。Quartusの構造警告は保持失敗を断定しないが、単独でCDC証明にもならない。従来のC3 v2レビューではrequest/responseの保持、capture-pending、同期ACK/consume順序を固定firmware経路と有限simulationでレビューし、経験的pilotに限定した扱いとしている。今回のnative・sv2v・Quartus-flat simulationも20要求とreset replayを検査した。これは形式CDC証明、analog metastability評価、MTBF保証ではない。response source selector 484個と論理480 bitの差は旧レビューと同じ4 duplicate fitter aliasを含む。route reportは4 cornerで480論理bitを示す。

I/O unconstrained reportは入力2 port / 41 path（TDI/TMSを含む）、出力4 port / 8 path（TDOおよびLEDRを含む）。board-level USB-Blaster/JTAGのlaunch/capture timingが不明なのでport delayやfalse pathを推測追加していない。16 ns net-delay screenは診断上の経験値であり、vendor保証ではない。

## 警告

- DRC: Critical/High 0、medium D102 16、information 342（T101 292、T102 50）。DRC summary warning 308071も保持。
- Fitter: warning 12473（processor数の通知）、15714（pin assignment incomplete）、292013（LogicLock license）。
- 未制約I/OとD102を抑制・隠蔽する変更は加えていない。

## ゲート判定

- `NEW_SOF_READY`: PASS（SOF生成済み。物理ロード済みという意味ではない）
- 経験的pilotの内部設計適格性: `PASS_LIMITED`。既存C3 v2の限定CDCレビューに、今回の不変mailbox構造、4-corner内部STA、動的入力SoC回帰を加えた範囲のみ。
- `B-SIGNOFF`: `BLOCKED_EXTERNAL_BOARD_TIMING`。外部JTAG timingと未制約I/Oは未解決。
- hard deadline / WCET / formal timing signoff: 未成立。
- 実機pilot: `NOT_RUN`。明示的な物理実行はこの作業範囲に含めず、基板・Flash・電源・配線には触れていない。

再実行コマンド（出力は元作業環境で生成し、保存reportは上記directory）:

```powershell
C:\altera_lite\25.1std\quartus\bin64\quartus_sh.exe --flow compile rtnn_c3_measurement_v2 -c rtnn_c3_measurement_v2
C:\altera_lite\25.1std\quartus\bin64\quartus_sta.exe -t .\run_external_sta.tcl
C:\altera_lite\25.1std\quartus\bin64\quartus_drc.exe rtnn_c3_measurement_v2 -c rtnn_c3_measurement_v2
```

