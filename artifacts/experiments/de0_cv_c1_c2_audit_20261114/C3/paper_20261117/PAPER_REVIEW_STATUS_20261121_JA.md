# 論文準備の現状（2026-11-21）

## 結論

**判定：REVIEW_READY_LIMITED（技術査読用の限定版）**。現時点で提示可能なのは「特定のFPGA・softcore・凍結Q15 buildに限定した経験的ケーススタディ」である。これは投稿・出版準備完了を意味しない。早期終了、予算適応、エントロピー停止、FPGA上の動的推論を新規アルゴリズムとして主張する根拠はない。

## 今回の再確認

- 旧C2J2とC3 v2は、別buildとして分離されたまま。保存済みC3 v2本測定は24,840/24,840要求、13/13 schedule。独立再解析で記録されたデータ整合性を追跡する。
- 最大budgetでのC3 v2 fixed Exit 2比較は、360入力に対して平均 `mcycle` が固定2で943,929.77、adaptiveで746,327.99、観測差は20.934%。単一基板・独立cold boot未確認・比較器はtest結果を見た後に選ばれており、探索的な結果である。入力bootstrap区間は16.804–24.903%だが、基板・session・温度・クロックの変動を含まない。
- 両方式とも339/360正解。事前指定の1 percentage point非劣性は、差の95%区間が−1.389から+1.389 ppのため **INCONCLUSIVE**。
- 診断用17,640要求から、49条件を同一入力で再集計した補足Pareto frontierを作成した。これはpost-hocの探索解析であり、主解析、独立標本、全budgetでの速度優位の証明ではない。
- 入力別診断v2で17,640行、fixed2対応比較7,560行、単調性診断36行を出力し、最終run3/run4のハッシュを照合した。解析は保存済みデータのみ。
- 7,200件の旧新build照合ではC3 v2が全行ちょうど+5 cycles。開始counterを測定区間内に保存する追加命令が候補だが、RISC-V disassembly/traceで原因を特定できていない。5 cyclesを補正値として差し引いてはいけない。
- 146-source graphは145/146 SHA一致の監査記録があり、期待hashの1つのproject-owned RTLが公開checkoutで未回収。clean-checkoutでの完全なRTL再構築は未確立。

## 判定

| 項目 | 状態 | 解釈 |
|---|---|---|
| 保存済み実測データの独立再集計 | PASS（保存証拠の範囲） | 新たな基板測定ではない |
| 20.934% cycle差 | OBSERVED / EXPLORATORY | 特定build/session、test依存 comparator |
| 1 pp accuracy noninferiority | INCONCLUSIVE | 閾値を満たす証拠がない |
| 再現可能なPareto補足解析 | PASS（同一保存データ） | post-hoc、探索的 |
| +5 cycleの観測 | PASS（ペア比較） | 原因は未特定 |
| 146-source完全再構築 | BLOCKED | 1ファイルhash未解決 |
| B-EMPIRICAL | PASS_LIMITED | 測定build/boardの経験的適格性のみ |
| B-SIGNOFF | BLOCKED_EXTERNAL_BOARD_TIMING | 外部JTAG timingとCDC/D102 signoff未完了 |
| 独立cold-boot変動 | UNCERTAIN | full rail discharge/session独立性未確認 |
| WCET / hard deadline | NOT_ESTABLISHED | 静的上界・正式signoffなし |

## 論文に使える範囲

「凍結Q15モデルを載せた特定のDE0-CV/Cyclone V・Ibex RV32 buildで、要求ID、応答ID、CRCと `mcycle` を保存した24,840件のJTAG経験データを再集計した。保存された360入力上では、test結果を見た後に指定された固定Exit 2と比べ、最大budget adaptiveの平均cycleが20.934%低かった。これは独立cold bootを伴わない1 build/sessionの探索的実測で、1 pp精度非劣性は未確定である。」

実機発振器未校正の絶対時間、基板間一般化、speed superiorityの確認的主張、hard deadline/WCET、世界初・新規アルゴリズム、完全なclean build再現は記載しない。

## 次の価値ある作業

現時点で基板を使わず進められる作業は、英語原稿の全claim/citation/figure/table監査、対象venueに合わせた短報・ケーススタディへの再構成、凍結データのPareto図表を本文へ適切に配置すること。再現性を強める作業は、失われたRTL source hashの正本を見つけること。確認的な性能・非劣性主張には、事前登録した新キャンペーンと独立した評価入力/電源sessionが必要で、既存データの再解析では代替できない。

## 出力と保全

技術査読用の限定パッケージは`PREPUBLICATION_CHECKLIST_JA.md`に従って確認できる。投稿先書式、全書誌の最終照合、著者・共著者の承認、完全なRTLソース再現性は未完了であり、出版・投稿可の判定ではない。

- 先行研究・新規性: [`PRIOR_ART_COMPARISON.md`](PRIOR_ART_COMPARISON.md), [`NOVELTY_VERDICT_JA.md`](NOVELTY_VERDICT_JA.md)
- claim/evidence: [`CLAIM_EVIDENCE_MATRIX.csv`](CLAIM_EVIDENCE_MATRIX.csv), [`CRITICAL_REVIEW_JA.md`](CRITICAL_REVIEW_JA.md)
- Pareto解析: [`analyze_pareto_frontier.py`](analyze_pareto_frontier.py), [`PARETO_INTERPRETATION_JA.md`](PARETO_INTERPRETATION_JA.md), [`pareto_final_run3/`](pareto_final_run3/)
- +5 cycle/source recovery: [`CYCLE_OFFSET_AUDIT.md`](CYCLE_OFFSET_AUDIT.md), [`SOURCE_RECOVERY_RESULT.md`](SOURCE_RECOVERY_RESULT.md)
- 実行記録とSHA: [`PAPER_REVIEW_RUN_RECORD_20261121_JA.md`](PAPER_REVIEW_RUN_RECORD_20261121_JA.md), [`SHA256SUMS_PAPER_REVIEW_20261121.txt`](SHA256SUMS_PAPER_REVIEW_20261121.txt)

今回もオフラインの保存証拠レビューのみであり、基板、JTAG、Quartus、外部連絡を使っていない。
