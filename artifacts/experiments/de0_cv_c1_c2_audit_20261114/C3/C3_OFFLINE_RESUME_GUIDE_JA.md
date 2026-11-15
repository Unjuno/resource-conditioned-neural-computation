# C3 オフライン作業後の再開手順

## 現在の前提

この手順の基準はC3 v2 build `43334531`、SOF SHA-256 `85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d`、model ID `52544e4e`。過去にKEY0 replay RUN5 20/20とfrozen C3 v2 campaign 24,840/24,840が保存・audit済みである。再実行する場合もそれらに追記せず、新experiment ID・新出力ディレクトリを使う。

stage作成、read-only identity check、Quartus Tcl呼出し、PowerShell/Python audit、reset gate作成の具体的なコマンド例は[KEY reset後の再開runbook](C3_RESTART_AFTER_KEY_RESET_JA.md)にある。そこに書かれたRUN1等は履歴用の例なので、再実行時には未使用の新run IDと空のstageを使う。runbookの操作自体は今回実行していない。

## 新しいreset replayを明示的に再確認するとき

1. DE0-CVが接続されているときに限り、Quartusのread-only identity scriptを実行し、USB-Blaster/JTAG IDCODE、C3 v2 build ID、READY状態が一致することを確認する。SOFやFlash/CFMへ書き込まない。
2. オペレーターがKEY[0]を押して離した事実を実験記録に記入する。キー操作と完全電源断を同一視しない。
3. `primary_01`の凍結20 sequenceを使い、新しいrun IDで物理runnerを一度実行する。既存RUN5の結果をコピーして新runにしない。
4. raw JTAG log、JSON/CSV、case list、bindingを保存し、PowerShell監査と`audit_saved_c3_v2_runs.py`の独立監査を実行する。sequence、request/response ID、CRC、凍結予測、Exit/cap、uint64 start/end、statusがすべて一致しなければ停止し、失敗を残す。
5. reset gate JSONは実際の新しい20行と独立監査のSHAからだけ生成する。既存gateを新runへ流用しない。
6. 既存full campaignは既に保存PASSである。再取得が本当に必要か、過去campaignに対して何の新しい仮説を検証するのかを記録してから、別ID・別directoryの新campaign計画を作る。旧24,840行へ追加・上書きしない。

## 別操作として記録する項目

* KEY[0] press/release: CPU/SoCの論理リセット操作。
* SOF SRAM reload: volatile FPGA configurationの再設定。
* 完全電源断: 全電源railが落ちたことを別途確認する操作。USB接続による給電可能性を確認せず、LED消灯だけを証明と扱わない。
* Flash/CFM programming: 永続構成の変更。今回の作業では実行しない。

外部JTAG timing資料または適切な測定がない限り、B-SIGNOFFは`BLOCKED_EXTERNAL_BOARD_TIMING`を維持する。JTAG実測を行ってもformal timing signoff/WCETに格上げしない。
