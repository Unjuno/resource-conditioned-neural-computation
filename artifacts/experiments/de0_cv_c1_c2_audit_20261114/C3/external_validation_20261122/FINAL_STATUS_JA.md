# 最終status — independent-image validation preparation

## ゲート

| Gate | Status | 根拠・制限 |
|---|---|---|
| Dataset package | `DATA_EXPOSURE_UNCERTAIN` | 3,823行を監査。過去学習・画像選択履歴が完全に残っていないので未使用とは証明できない。UCI行にwriter IDなし。 |
| Candidate size | `PASS` | pilot 10画像を永久除外した主要候補は3,813画像（閾値3,000以上）。 |
| Preregistration | `PREREGISTRATION_READY` | 画像結果を見る前のlocked protocol; SHA `5005c80c6d2d8eefbf87dd4dfdb4c91e26adb7960a3e5b1f04a977fdaee3b33b`。 |
| Firmware | `NEW_FIRMWARE_PASS` | dynamic 64-pixel payloadを実推論APIへ渡すRV32 build、software oracle比較7,646件一致。教師ラベルを入力に含めない。 |
| RTL regression | `HOST_AND_RTL_REGRESSION_PASS` | native SV / sv2v / Quartus-flatの20 pilot cases、reset replay、8 negative checks、mailbox partial-response commit guard各PASS。これはsimulation。 |
| Quartus | `NEW_SOF_READY` | Prime Lite 25.1、Fitter/Assembler success、SOF生成。内STA 4 corners positive。D102 16、JTAG I/O unconstrainedの制限を維持。 |
| Empirical eligibility | `PASS_LIMITED` | 同一C3 v2 mailbox構造の限定CDC review、現buildの内部STA・simulationまで。JTAG運用の物理確認や保証ではない。 |
| Formal timing | `FORMAL_TIMING_SIGNOFF_BLOCKED` | external JTAG timing資料不足、TDI/TMS/TDO unconstrained、D102が残る。WCET/hard deadlineを主張しない。 |
| Physical pilot | `PHYSICAL_PILOT_NOT_RUN` | 今回は基板操作をしていない。JTAG, SOF SRAM設定, reset, powerを行っていない。 |
| Confirmatory campaign | `CONFIRMATORY_CAMPAIGN_NOT_RUN` | 新規実機結果なし。7,626条件のcase/oracleは準備済みだが計測値はない。 |
| Statistical conclusions | `NOT_RUN` | 合成またはsimulation cycleは実機解析へ流用していない。 |

## 次にユーザーが基板前で行う工程

1. 新SOF SHA、ELF SHA、Build ID、binding JSONをread-onlyで照合。
2. 明示的な物理実行承認後、新SOFをSRAMへ設定する。Flash/CFMは使わない。
3. read-only JTAG identity確認の後、pilot bindingに対して10画像×fixed2/adaptiveを1回実行。
4. raw log/CRC/予測/Exit/cycle/identityを独立監査。異常時は停止し、失敗データを残す。
5. pilot適格後にのみ、独立電源session計画と主要キャンペーンへ進む。3独立電源session未確認なら`COLD_BOOT_UNVERIFIED`を維持。

`KEY0` resetは電源再投入ではない。今回、どちらも実施・attestしていない。

## 論文上の表現

現時点で記載できるのは、UCI候補データ監査、事前登録、動的入力対応firmware、simulation、Quartus compileと制約済み内部path結果まで。新規画像でのFPGA実測精度、cycles、速度優位、1 pp非劣性は未取得であり、主張できない。データの過去使用履歴が確定しない場合は、実機評価が完了しても確認的な未使用テストという主張を保留する。

## 保存場所

このdirectoryの`build/`に全attemptログ・生成物を保全。`SHA256SUMS.txt`はpackage内ファイルmanifest。commit/push/PR/mergeは未実施。

