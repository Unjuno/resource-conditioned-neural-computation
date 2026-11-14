# C2J2 firmware source recovery

正本RTNN repository内の `origin/handoff/de0cv-stage2-2026-11-03` に格納されたStage 2 ZIPから、build ID `43324a32` のC2 firmware補助ソースを復元した。ZIP SHA-256は `7f5c666514729b0d5f776904ec5662187271beb90f30d4c33231b7b92b4c5507`、212 entries、ZIP integrity PASS。

`firmware/rtnn_c2_main.c` は保存済みC2 response-hold監査コピーから復元し、他11ファイルは同ZIPの展開物から復元した。既存C2 manifestの12 source SHA-256に対し復元元とこのsnapshotを照合し、12/12一致。frozen Q15 C/H・weight header・heldout360 headerもSHA一致。

これは旧buildのsource recoveryであり、32-bit wire cycle fieldを持つ旧protocolをそのまま新gateへ適格化するものではない。元ZIP・既存SOF・C2証拠は変更していない。
