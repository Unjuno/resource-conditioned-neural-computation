# データ露出・独立性の再確認

## 確認できたこと

* 凍結監査記録ではUCI `optdigits.tra` 3,823行、各64画素、値0–16、10クラス。
* `sklearn.load_digits`全1,797画像との完全画素一致は0件。内部重複も0件。
* pilot 10画像は主要候補から分離され、primary候補は3,813画像。pixel overlapなしの根拠は既存 `data/dataset_audit.json` と原本SHA `e1b683cc211604fe8fd8c4417e6a69f31380e0c61d4af22e93cc21e9257ffedd`。
* リポジトリの追跡ソースでは `sklearn.load_digits` の利用が見つかる。今回の対象外も含めた全Git履歴で `optdigits.tra` 文字列の追跡利用は見つからなかった。

## 事前登録と初回oracle出力の時系列

* 事前登録文書の現在のWindowsファイル作成・更新時刻は2026-11-22 03:57:14 (Asia/Tokyo)。
* `build/cpu_oracle_attempt1/oracle_pilot.csv` と `oracle_primary.csv` のファイル時刻は2026-11-22 04:06:44。firmware API prediction CSVは04:24:30–04:24:51。
* Git履歴では事前登録文書と該当準備物がcommit `96825d9c913f4467daf27c3feed40ae08da67a9e` (05:53:48+09:00)で記録されており、commitはoracle出力より後。oracleより前の独立した署名済みcommit、trusted timestamp、外部監査記録は見つからない。
* 従って、OSファイル時刻は事前登録が先だったことを示唆するが、変更可能な同一PC上のmetadataだけで順序を証明できない。既存locked文書のSHAは一致し維持するが、確認的事前登録の時系列適格性は`PREREGISTRATION_TIMELINE_UNVERIFIED`とする。独立した先行記録が示されない限り、今後の評価結果は探索的として扱う。

## 判定

* `NO_PIXEL_OVERLAP_CONFIRMED`: 確認済み。
* `NO_TRACKED_PRIOR_USE_FOUND`: 今回のgit/source検索範囲に限って確認。
* `DATA_EXPOSURE_UNCERTAIN`: 維持。未記録の過去利用・手元コピー・モデル選択時の露出は否定できない。
* `WRITER_CLUSTER_UNKNOWN`: 維持。UCI各行にwriter IDがない。
* `AUTHOR_ATTESTED_NO_PRIOR_USE`: 未取得。著者本人の申告を記録する欄を下に用意するが、未記入。
* `PREREGISTRATION_TIMELINE_UNVERIFIED`: oracleとfirmware予測CSVが存在し、先行時刻の独立・改ざん耐性ある記録は確認できなかった。

## 申告欄（事実の記録用。独立証明ではない）

```text
申告者:
確認日:
optdigits.tra / 同一画素 / 派生版を学習・検証・モデル選択・調整に使ったか:
使った場合のファイル・期間・目的:
記憶が不確かな点:
根拠となる記録とSHA-256:
署名または確認方法:
```

この申告を受けても、未記録履歴が独立に証明されたとは扱わない。writer clusterが不明なため、画像単位のCIを筆記者母集団への確証と表現しない。既存事前登録SHAを変更しない。
