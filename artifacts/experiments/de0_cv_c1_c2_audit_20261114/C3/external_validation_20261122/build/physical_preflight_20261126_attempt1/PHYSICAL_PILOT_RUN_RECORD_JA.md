# 実機パイロット記録

状態: `NOT_RUN_USER_APPROVAL_PENDING`

実機要求数: 0/20。JTAG raw log、実測CSV、実機run statusは取得していない。実行結果や再試行を作成・補完していない。

停止条件はユーザーの明示承認待ち。承認後に別の空出力先 `build/physical_pilot_RUN1` を使用し、異常・timeout・trap・identity/counter/CRC不一致があればその場で停止して記録する。
