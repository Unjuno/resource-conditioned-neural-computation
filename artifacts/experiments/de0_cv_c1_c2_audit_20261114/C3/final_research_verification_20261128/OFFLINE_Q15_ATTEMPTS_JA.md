# Q15オフライン解析の試行履歴

物理基板は使用していない。以下の失敗試行の一時生成CSVは削除せず保存したが、確定結果として使用せず、RUN6のみを最終集計に採用する。

| 出力 | 状態 | 発見した問題 |
|---|---|---|
| `q15_stopping_comparison_RUN1_20261128/` | INVALID_INPUT_TRUNCATION | Windows標準入力のテキストモードがバイト列中のCR-LFを改行変換し、validation 359件のうち最後の1画像が欠落。 |
| `q15_stopping_comparison_RUN2_20261128/` | INVALID_SCHEMA | Windows stdinをbinaryにした後、C helperが出力すべき確率合計列を初版parserが要求していたため途中停止。 |
| `q15_stopping_comparison_RUN3_20261128/` | INVALID_SCALE_ASSUMPTION | 確率をQ17/131072と誤認。凍結coreの確率量子化はQ15/32768だったため正規化検査で停止。 |
| `q15_stopping_comparison_RUN4_20261128/` | INVALID_ANALYZER_ACCESS | entropy preferred Exitの集計で入れ子の記録を誤参照し停止。 |
| `q15_stopping_comparison_RUN5_20261128/` | SUPERSEDED_REPORTING_BUG | Q15予測・block数は取得したが、固定方式にも適応判定check数があるように報告していた。固定Exitのdecision checkを0に修正し再実行。 |
| `q15_stopping_comparison_RUN6_20261128/` | PASS_SUPERSEDED_BY_LOGGED_RUN | binary stdin、Q15スケール、oracle照合、固定/適応のdecision-check定義を修正後、全件PASS。 |
| `q15_stopping_comparison_RUN7_20261128/` | PASS_SUPERSEDED_BY_LOGGED_RUN | RUN6と同じ入力・コード・seedで再実行し、全stdoutを保存。全件PASS。 |
| `q15_stopping_comparison_RUN8_20261128/` | FINAL_OFFLINE_ANALYSIS | Windows stdin/stdoutをbinary固定し、CSVとraw stdoutのSHA一致も確認。RUN6/7と分類・集計が一致し、全件PASS。 |
| `exit_counterexamples_RUN1_20261128/` | PASS_SUPERSEDED_BY_RUN8_SOURCE | 全Exitの値は正しい。確定RUN8の出力を参照する再実行結果は `exit_counterexamples_RUN2_20261128/`。 |

別の試験起動ミス：`python -m unittest <絶対ファイルパス>` はunittestのmodule指定として解釈できず失敗した。テストファイルを直接 `python <path> -v` で起動し、4/4 PASSを確認した。この起動エラーは成果物や入力に影響しない。
