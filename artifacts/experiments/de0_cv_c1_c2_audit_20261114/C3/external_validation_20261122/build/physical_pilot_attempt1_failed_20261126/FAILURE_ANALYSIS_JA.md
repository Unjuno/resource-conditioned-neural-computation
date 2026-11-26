# 失敗試行記録 — 2026-11-26

状態: `ERROR_BEFORE_FIRST_REQUEST`。PowerShell物理runnerはexit 1、Quartus STP Tclはexit 2。`run_status.json`は空で、raw_jtag.logには初期行と`RUN_ERROR=missing close-bracket completed=0 expected=20`のみ。要求行0件、結果行はヘッダー＋FAIL行のみ。pilot要求が完了した証拠はなく、PASSにもゲート生成にも使わない。

Quartusのstderrには、失敗状態を書き出す際にTcl式の不正な引用で`invalid character "\\" in expression "$opened ? \\"true\\" : \\"false\\""`も出た。この二次エラーでrun_status.jsonが空になり、一次エラーの詳細が失われている。新しい試行の前にTcl runnerを修正版でオフライン確認し、新experiment IDと新出力先を使う。

対象SOFは別途Quartus ProgrammerがFPGA SRAMへ設定し、設定操作は成功と報告された。Flash/CFM/CPLDは対象にしていない。runner失敗後のmailbox状態・JTAG open状態はこの空statusからは確定できない。pilotを再開する前にread-only Build ID/READYを再確認する。
