# C3 v2 外部画像 1 セッション探索的評価 amendment（未実施）

## 状態と適用範囲

本書は、凍結済みの `PREREGISTRATION_LOCKED_JA.md` を変更せず、3 セッション計画からの逸脱を明記するための提案 amendment である。ここでは結果を閲覧していない。対象の primary 実機測定は未実施であり、この文書だけでは操作者承認、binding、実験開始を意味しない。承認日と適用開始コミットは測定前に記録してSHA-256で固定する。

この評価は `EXPLORATORY_EMPIRICAL_ONLY` とする。データ来歴・writer cluster・事前登録時系列の不確実性により、確認的な母集団推論は適格としない。

## 固定する対象と変更しない条件

- build `45585631`、binding identity `45585632`、model `52544e4e`。
- SOF SHA-256 `5e333e9377b7188a394d04b93b98833d91afb2cd53eca8d976e6aa715dfa00c4`、ELF SHA-256 `4673f6a8b90493c15c327ed3be1167e0fcf3ff2be60292dcb12a1391124a0c2e`。
- 凍結 primary 3,813 画像×2方式＝7,626要求。pilot 10画像は永久除外。
- `fixed2` 対 `adaptive`、budget Q0.16 = 65535、deadline = 0、batch = 1。
- 同じ画像バイト列・Q15重み・build・計測境界。64-bit Ibex `mcycle` の推論開始・終了差分を記録し、JTAG転送とhost待機は含めない。
- 既存の凍結画像順・hash定義mode順を保持する。欠損・失敗を含む全行を保全し、成功だけの置換や結果を見た早期終了をしない。
- RUN4保存raw logで観測したpilot sequenceは2–21。オフライン予定表は22から採番したが、実機での次sequenceを保証しない。開始前に現在buildの状態を読み取り確認し、sequence衝突なら新しい実験ID・scheduleを事前作成する。

## 変更される設計

元の3独立電源セッション計画を、このamendmentで1回の連続した基板電源セッションに限定する。cold boot間変動を推定しない。確認できない完全電源断をcold bootと呼ばない。結果は対象基板・対象sessionの経験的観測としてのみ記述する。

事前指定の数値解析は、凍結手順のペアClopper–Pearson/Bonferroni数値判定（片側alpha each 0.025、差のmargin −1 pp）と、入力単位の10,000反復percentile bootstrap（seed 20261122、cycle削減点閾値5%）に限定する。これらの数値結果は独立画像・writer相関の問題を解消せず、母集団確認的結論に使わない。測定後に閾値・標本・指標を変えない。

## 停止・保存規則

1件でもCRC、sequence/ID、pixel、build/model/binding、oracle prediction/Exit/stop reason、counter、timeout、trap、statusの異常があれば停止する。失敗・未取得・再試行は新しいattemptとして元記録と併存させ、欠損を隠さない。再試行の採否を結果閲覧後に決めない。

JTAG timing signoff、WCET、hard deadline、一般的速度優位、母集団非劣性はこの実験でPASSにしない。既存のpilot gateは独立validatorで再検証し、primary binding・raw run・auditを実行前後にSHAで結ぶ。実機実行は別途明示承認後に限る。

## 未解決の適格性

`DATA_EXPOSURE_UNCERTAIN`; `WRITER_CLUSTER_UNKNOWN`; `PREREGISTRATION_TIMELINE_UNVERIFIED`; `COLD_BOOT_UNVERIFIED`; `FORMAL_TIMING_SIGNOFF_BLOCKED` を維持する。操作者の「過去に使っていない」申告は証拠来歴と別に記録する。

## 適用記録（測定前に記入）

- 承認者・承認時刻：未記入
- amendment SHA-256：この草稿をレビュー・固定した後に生成
- 適用開始コミット：未記入
- physical experiment ID / session ID：未割当
- 実施状態：`NOT_RUN`
