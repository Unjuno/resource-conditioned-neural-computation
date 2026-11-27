# 形式検証・RTL測定・DE0-CV経験値の証拠対応

## 結論

既存の形式解析とRTL測定は、固定したソフトウェア関数・バイナリ・Ibex Simple System構成に限った計算上限やタイミング関係を支える。これはDE0-CV上の新外部画像buildのSTA、外部USB-Blaster timing、silicon WCETを証明しない。新しいprimary測定は未実施。

| 層 | 既存証拠 | 支持する範囲 | 支持しない範囲 |
|---|---|---|---|
| ソース制御 | `notes/realtime_nn_cbmc_actual_control.md`; `results/realtime_nn_cbmc_actual_control_results.json` | 実際のbudget/adaptive/certification制御関数の抽出版で、uint16 budgetとdeadline classに対するoptional block上限、順序、実行数の性質をCBMCで確認。entropyは任意系列に抽象化。 | NN数値カーネルの正しさ、抽出・実体関数の全binary equivalence、FPGAタイミング。 |
| Finite runtime contract | `results/realtime_nn_cbmc_runtime_contract_results.json`; `notes/realtime_nn_software_formal_closure.md` | 指定した型域・式・仮定下の有限クラス/予算制御特性。 | 外部メモリ・周辺回路・ボードのWCET。 |
| binary control flow | `notes/realtime_nn_binsec_controlflow.md`; `results/realtime_nn_binsec_controlflow_results.json` | exact retained ELFの固定クラス経路を対象としたBINSEC制御フロー検査。関連する taint/漏洩解析の対象範囲を明記する。 | 任意の新ELF、すべてのデータ依存memory behavior、実機周期保証。 |
| pinned Ibex RTL | `notes/realtime_nn_ibex_rtl_validation.md`; `results/realtime_nn_ibex_rtl_validation_results.json` | pinned Ibex commit・Simple System・単一host・内部RAM・無競合等の条件でのRTL測定値とQ15参照一致。旧算術モデルが観測を外した履歴も保持。 | DE0-CV実装、別build/メモリ/割込み/競合、シリコンWCET。 |
| pinned memory response | `notes/realtime_nn_ibex_memory_timing.md` | exact ELFのLUT load address全域が特定のSimple System RAMへdecodeし、特定RTL構成におけるresponse-validがaddress非依存という監査。 | FPGA内部RAMとQsys/Quartus構成のタイミング。 |
| Q15 finite-exit accuracy | `notes/realtime_nn_fixed_time_target.md`; `results/realtime_nn_fixed_time_target_results.json` | 保存済みseed 63・既存分割・固定モデルでのexit別正答率等。 | UCI external dataset上の一般化、動的入力firmwareの未測定挙動。 |
| DE0-CV external pilot | `external_validation_20261122/build/physical_pilot_RUN4_complete_20261126/` | 10 frozen pilot images×2 modes＝20要求について、保存raw JTAGとCPU Q15 oracleの整合を報告。限定的な実機機能証拠。 | 3,813画像全体、速度・精度一般化、独立cold boots、formal/STA signoff。 |
| New external primary | `final_research_verification_20261128/primary_schedule_OFFLINE_TEMPLATE.csv` | 7,626行のオフライン候補scheduleのみ。 | 実測、binding、JTAG、cycle、精度、主張の根拠。 |

## 主張の境界

「Q15制御実装が有限のoptional-block上限を守る」は指定されたCBMC証明対象について述べられる。「特定のpinned Ibex RTL構成においてcycle数が観測/検証された」は構成を併記して述べられる。「DE0-CVの新buildが10 pilot画像でCPU oracleと一致した」は保存RUN4の範囲で述べられる。一方、外部USB-Blaster timing signoff、今回の新入力全体の精度非劣性、一般的なcycle優位、WCET、hard deadlineは未成立。
