# 失敗試行記録 — 2026-11-26 RUN2

状態: `ERROR_AFTER_REQUEST_1_BEFORE_RESPONSE_CAPTURE`。Tcl runnerはexit 2、PowerShell wrapperはexit 1。Quartus ProgrammerによるログからRUN2 bindingのSOF SHAとケースSHAは一致。

raw_jtag.logにはsequence 1 / input ID 3660 / adaptiveの要求フレーム1件が記録され、runnerはDONE statusを見て応答読み出しに進んだ。その読み出しで480-bit幅に対して96桁（384-bit）のゼロ値を渡し、Quartusが長さ不一致で停止した。従って、要求は送信され、DONEが観測されたが応答payloadを取得できていない。実測結果としては0/20完了。残り19要求は送っていない。

このrunは失敗記録として保全し、pilot gateの生成に使わない。応答取得や再実行でこのrunをPASSへ昇格させない。修正版runnerは480-bit読み出しに120桁を指定する。再実行する場合は、原因修正のオフライン確認後、新experiment ID・新binding・新出力先を使う。

Flash/CFM/CPLD書込みは行っていない。既存SOF/ELF/modelは変更していない。外部JTAG timing signoffはBLOCKEDのまま。
