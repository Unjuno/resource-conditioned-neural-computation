# RTNN C3 v2 査読前最終監査・GO/NO-GO判定（2026-11-17）

## 結論

**保存済み実機データ解析はPASS。限定した経験的ケーススタディの草稿は作成済みだが、投稿・公開の最終GOには未達。**

独立した新しい評価で精度非劣性を実証したとの主張、全条件での速度優位、外部JTAGの正式タイミング保証・WCET・hard deadlineの主張はNO-GOである。今回は別のLinuxクラウド端末にclean checkoutして保存済み実験データだけを再解析した。基板、オシロ、JTAG、Quartusへの書込み・新規実機測定は行っていない。

## 確認したデータ

| 対象 | 判定 | 根拠 |
|---|---|---|
| 新C3 v2 full campaign | PASS_SAVED_EVIDENCE | 13/13 schedule、24,840/24,840要求、別buildのC2J2とは分離 |
| 最大予算のprimary比較 | PASS_DATA_INTEGRITY | 10 schedule×360入力×2方式=7,200要求 |
| fixed2対adaptive実測 | 条件付き記述 | 平均943,929.77対746,327.99 cycles、削減率20.93395% |
| 入力単位bootstrap | 限定区間 | 5000回seed63、95%CI 16.804–24.903%、未確認boot変動は対象外 |
| accuracy | INCONCLUSIVE_NONINFERIORITY | 両方式339/360、差の95%CI [-1.389,+1.389]pp、1pp非劣性未達 |
| 既知の旧C2J2との対応 | PASS_OBSERVATIONAL_MATCH | 7,200件すべて新build+5 cycles、予測とExit不変、原因は未証明 |
| 固定7クラス診断 | PASS_SAVED_EVIDENCE | 2,520件 |
| adaptive/capped予算21水準 | PASS_SAVED_EVIDENCE | 7,560+7,560件、凍結入力IDとcycle/Exit/cap一致 |
| 解析系の独立環境 | PASS_ANALYSIS_REPRO | 別clean Git checkout、15/15 unit tests、同じ解析を2回実行しSHA一致 |
| 物理時間保証 | BLOCKED | JTAG外部I/O遅延/16件D102 CDC未解消 |
| clean checkoutからのRTL再ビルド | BLOCKED_SOURCE_HASH_MISMATCH | 外部Ibex 141/141整合、リポジトリ内の4/5整合。ibex_top_gate_bypass.svの1ファイルが保存監査SHAと異なる。Verilator未実行 |

## 見落とすと重大な査読上の問題

**1. 最大予算と予算可変の混同を禁止。** 主7,200要求はすべてbudget_q16=65535、deadline_cycles=0。したがって20.934%は、最大予算下での適応早期停止と固定Exit2との比較であり、21予算全域の改善率ではない。予算に応じたサイクル変化は別枠17,640件のsecondary診断が支える。

**2. 後知恵による比較対象の選択を隠さない。** 凍結campaignにはprior_test_results_known=true、primary_comparator=previously_observed_comparator_not_test_blind_selectionと記されている。固定Exit2を独立した盲検比較対象と呼ばない。新規汎化能力の推定には別の未使用評価データが必要。

**3. 評価データセットを具体化。** sklearn.datasets.load_digitsの8×8手書き数字画像（各値0–16、10クラス）、固定されたstratified 60/20/20分割（random_state 123/456）から得られた360入力、seed63凍結Q15モデル、6 optional attention/MLP blocks、7 exitsを記述。MNIST（28×28）とは異なる。

**4. 10反復と独立電源セッションは別。** 同じ入力/modeのcyclesは全10 primary scheduleで一致する。これを10独立cold bootとしてbootstrapしてはいけない。入力標本のCIはboot・温度・個体・発振周波数の不確かさを代表しない。

**5. モデルの正答数が同じでも非劣性は未成立。** Accuracy差の下側95%CIは-1.389ppで、予め固定された-1pp幅より下。反復24,840を独立入力として扱わない。

**6. ソースや保証の再現性は別ゲート。** 保存C3 v2解析はclean checkoutで再実行でき、Ibex上流commit 7b5df75a041affe56e8c235260f98a09b3319008を外部取得して141/141 SHA一致を確認した。しかし、repo内のibex_top_gate_bypass.svは保存回帰時に要求された e1728fb6…633254b3f50 ではなく 1360b260…e93270 であり、146-source全体は145/146一致に留まる。詳細は[SOURCE_REPRO_GAP_JA.md](SOURCE_REPRO_GAP_JA.md)。Verilatorを今回実行していない。外部JTAGのTCK/データ相対遅延と計測不確かさも未確定であり、どちらも虚構のPASSにしない。

## 次の最短ルート

### 限定した経験的ケーススタディを外部公開する前の残作業

1. 改訂済みの論文草稿で、最大予算primary・21予算secondary・既知の固定2選択・入力のみbootstrapを著者と独立レビュー者がチェックする。
2. モデル・Q15変換・入力分割・コンパイラ/ISA/メモリ構成・サイクル境界、先行研究、元データの再配布条件・引用を最終確認する。
3. 著者名・投稿先体裁・図の可読性・公開リンク・データライセンスを整備し、提出版のcommitを固定する。外部査読の承認は今回実施していない。
4. ハードウェアソース完全再生成を主張するなら、141 Ibex依存の再取得手順、上流commitとファイルハッシュを添え、別環境で検査する。

### より強い統計・リアルタイム保証を主張するときだけ必要

- 精度1pp非劣性を証明したいなら、未使用データを事前登録した上で増やす。既存360件のJTAG反復では不可。
- 速度優位の独立起動感度を主張したいなら、確認可能な3以上の独立電源セッションを事前計画し、入力×sessionの階層分析を行う。
- 正式なハード期限保証は、対象DE0-CV revisionの外部JTAG仕様とCDC/timing signoffが整ってから別途評価する。オシロの安全な測定点が未確認の状態で接続しない。

## H / T / D / C / U

H: 特定の単一基板・build・保存セッションにおける、最大予算での入力対応cycle削減。  
T: 360入力IDを単位に5000回bootstrapし、10反復は各入力に属するものとして扱う。  
D: 保存データ整合性PASS、条件付きcycle削減は記述PASS、精度非劣性INCONCLUSIVE、独立電源変動UNCERTAIN、全体タイミングBLOCKED。  
C: 後知恵の比較対象、後段Exitに進む97入力、計測境界差、未確認boot差が代替説明となる。  
U: 入力標本の統計変動はCIで記述。基板全体の合成標準不確かさ・包含係数は根拠不足で未算定。

## ERROR CHECK

- 原本campaign.jsonの既知テスト結果・比較対象・最大予算とdeadline条件を直接照合。
- 13 scheduleの保存済みmanifest、7200 primary行、17640 secondary診断行を別々に検査。
- 15/15試験PASS、主解析・診断解析の各2回実行で出力SHA一致。
- 原典: [BranchyNet DOI](https://doi.org/10.1109/ICPR.2016.7900006)、[MSDNet arXiv](https://arxiv.org/abs/1703.09844)、[SkipNet arXiv](https://arxiv.org/abs/1711.09485)、[scikit-learn JMLR](https://www.jmlr.org/papers/v12/pedregosa11a.html)、[load_digits公式資料](https://scikit-learn.org/stable/modules/generated/sklearn.datasets.load_digits.html)。

**自分で考えるための問い:** この研究を単一FPGA上の経験的比較の論文として仕上げるのか、それとも独立データ・独立boot・正式期限保証まで含む強い論文を狙うのか。前者には今の24,840件を目的なく再測定する必要はない。
