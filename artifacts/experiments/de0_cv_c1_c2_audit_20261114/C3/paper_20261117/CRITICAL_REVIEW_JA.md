# 査読者視点の重大論点（2026-11-21）

## 判定案

限定した実装・測定ケーススタディとしてはデータ整合性が強化されている。アルゴリズム新規性を主題とする論文としては、現状の先行研究との重複から大幅な主張縮小が必要。2026-11-22に公開branchのfresh cloneからmapped native source graph 146/146とVerilator回帰を再現した。一方、Quartus/SOF同一再構築、正式JTAGタイミングとCDC signoffは未完了のため、物理buildの完全再現性・リアルタイム保証を主張する論文はNo-Go。

## Major concerns

1. **新規性の主張を早期終了方式から外す。** MSDNet/EENetが予算対応multi-exitを、Kong & Nunez-Yanezが低精度FPGA entropy早期終了を、Dimitriou et al.がFPGA dynamic early-exit実装を先行している。本文の位置付けは「特定のIbex/DE0-CV実装に関するケーススタディ」とする。
2. **主解析の比較選択バイアスを明記する。** 固定Exit 2は事前テスト結果を知らない比較対象ではない。20.934%を全budget、全基板、全入力へ一般化しない。
3. **1 pp非劣性は未達。** 339/360対339/360という同じ観測正答率は、95%差区間下限−1.389 ppを覆さない。非劣性PASSと書かない。
4. **Pareto図は探索的。** 49条件を同じ360例で走査してParetoを選んだ後の結果は、多重な設定探索を含む事後記述であり、一次検定ではない。
5. **旧新+5 cyclesの因果関係は未確定。** source diffは新しい開始カウンター保存を測定区間に置くが、5 cyclesを命令列で確認していない。offset補正をしない。
6. **source/build再現性とデータ再解析を区別する。** mapped native graphは公開branchのfresh cloneで146/146照合とVerilator回帰に成功したが、これはbit-identical SOF再現性を示さない。
7. **外部タイミングとWCETを分ける。** 正の制約内slackは、未制約JTAG外部パスやCDC課題を解決しない。オシロの計測箇所も未確認。hard deadline/WCETは記載しない。
8. **サンプルと反復単位を明確にする。** 実験要求24,840行ではなく、accuracyの独立単位は360入力ID。10 scheduleは10 independent bootsではない。
9. **データセットと引用条件を具体化する。** `load_digits`は8×8画像でありMNISTではない。元データの利用条件・引用、scikit-learn版、入力分割生成物SHAを投稿時のデータ公開条件と照合する。

## Minor / editorial checks

- 「resource budget」がdeadline guaranteeを意味しないことを各図表captionで確認する。
- mcycleはサイクル数であり、発振器校正なしに絶対秒数へ変換しない。
- model prediction/reference label/teacher truthの語を一貫して使い分ける。
- Fixed2 comparatorが過去観測に基づいて選択された事実をabstract・methods・limitationsに残す。
- DOI、著者、年、引用版を最終投稿フォーマットで照合する。
- 著者名、責任著者、データ/コード公開URL、ライセンスは著者が承認するまで補作しない。

## 投稿前のgo/no-go

**限定ケーススタディ:** 著者が上記制約のあるタイトル・abstractへ同意し、再現用archiveとデータ利用条件を整えれば、投稿用体裁の準備は続けられる。これは本レビューだけで投稿可能を承認するものではない。

**新規アルゴリズム／精度非劣性／広い速度優位／formal real-time保証:** 現状は `PUBLICATION_NO_GO`。必要なのは独立入力を事前登録した精度実験、比較対象の事前固定、独立board/boot測定、source graph recovery、外部timing/CDC signoff、および対象を固定したWCET手法である。
