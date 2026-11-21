# 新規画像評価 事前登録（ローカル固定版）

事前登録固定日: 2026-11-22  
プロトコル: `RTNN_EXTVAL_V1`  
Build ID: `0x45585631`  
Binding ID: `0x45585632`  
model ID: `0x52544e4e`  
request protocol: v2 / 100 bytes  
response protocol: v3 / 60 bytes

この文書と後掲manifestのSHA-256を、Q15推論出力を生成する前に保存する。もし既に新規入力の推論を実行した場合、この事前登録は確認的事前登録として無効であり、その場合は探索的評価として再分類する。

## 固定入力とモデル

- UCI公式`optdigits.tra` SHA-256: `e1b683cc211604fe8fd8c4417e6a69f31380e0c61d4af22e93cc21e9257ffedd`。
- fixed `sklearn.load_digits`完全一致・tra内重複を除いた後、pilot10画像を恒久除外する。
- primary候補: `data/primary_manifest.csv` に固定した3,813画像。最低3,000件条件は満たすが、検出力保証を意味しない。
- pilot 10画像は`data/pilot_manifest.csv`のIDsに固定。pilot結果をprimaryへ再利用しない。
- モデル: 凍結seed-63 Q15。重みヘッダーSHA-256 `961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f`。量子化core SHA-256 `a6b2807bd4a60534c250fca3005322cf14ba0a92f6b16e28241109385efc6809`。重み、演算、entropy thresholdは変更しない。
- UCI教師ラベルはhost-onlyで保持し、request payload、firmware入力バッファ、model inference APIに渡さない。

## 推論条件

各画像につきbatch=1で、同一の新build内に以下の2モードを対で実行する。

1. `fixed2`: fixed Exit=2。
2. `adaptive`: budget=`65535`、deadline=`0`、既存停止方針。

両者で同一pixel bytes・Q15モデル・周波数設定・boardを使う。各推論の開始・終了を64-bit Ibex `mcycle`で記録する。JTAG scan、host wait/retry、応答読み出しは推論区間に含めない。mainの実行前後にカウンタとbuild identityを検査する。

新firmwareは任意の64 pixel payloadを検証後、実際にQ15 coreへ渡す。input_idはhostのsample keyを応答に返す識別子であり、ROM lookupには使わない。teacher labelをfirmwareに送らない。

## H1: paired accuracy noninferiority

画像iの正解指示変数を`Y_Fi`（fixed2）、`Y_Ai`（adaptive）とし、差は`Delta = P(Y_A=1)-P(Y_F=1)`。非劣性マージンは−0.010（−1 percentage point）、片側有意水準0.05。

対応discordant率 `p10=P(Y_A=1,Y_F=0)` と `p01=P(Y_A=0,Y_F=1)` を別々に計算する。保守的な片側Clopper–Pearson下限`L(p10)`・上限`U(p01)`を各alpha=0.025で求め、Bonferroni下限`L(p10)-U(p01)`が−0.010を**超えた場合のみ**数値ゲートをPASSとする。

この区間は画像ペア間独立性を仮定する。UCI原本には行ごとのwriter IDがないため、筆記者内相関を評価できない。独立性の確認が得られない場合は、数値ゲートが通っても母集団の確認的非劣性を主張せず`INCONCLUSIVE_WRITER_CLUSTER_UNKNOWN`とする。

## H2: paired cycle reduction

各画像・各sessionの差`D_is = F_is - A_is`（cycle count）と削減率を計算する。主推定量は同一画像対応の平均cycle削減率`R = sum(F-A)/sum(F)`。入力単位のペアbootstrap 10,000反復、固定seed `20261122`で95% percentile区間を作る。これは入力標本の不確かさだけでありsession/board母集団の区間と混同しない。

目標値は5%。統計ゲートは点推定値が5%以上かつ入力bootstrap 95%下限が5%を上回る場合のみPASSとする。3つの独立電源sessionそれぞれの差・削減率を別々に保存し、session間の範囲も示す。3 sessionは起動間の分布推定には少なく、cold-boot母集団の強い推論はしない。

## 実行順・停止・欠損

- 先に10-image engineering pilot（fixed2/adaptive各1回）を実施し、独立監査PASS後だけmainへ進む。pilot画像はmainから除外済み。
- Mainは3つの独立電源sessionで、全3,813画像×2 modeを完遂する。各sessionで画像順をpixel SHAの昇順とし、mode順は`SHA256("RTNN-EXTVAL-MODE-ORDER-v1\\0" || traSHA || uint32le(input_id))`の先頭bitで固定する。結果を見て順序・回数を変更しない。
- CRC、要求/応答ID、pixel hash、build/model/binding、status、Exit、cap、64-bit counter異常、timeout、trapのいずれかで停止する。失敗・再試行も元行を残し、補完行に置き換えない。
- 早期成功による途中終了をしない。再試行は新しいattempt IDで記録し、主解析に採用するルールを結果閲覧前に別途固定しなければならない。
- 電源sessionはKEY0リセットと区別する。USB-Blaster等からの逆給電が否定できない場合`COLD_BOOT_UNVERIFIED`。ユーザーが安全に全電源を遮断した事実を確認できない限り独立sessionと数えない。

## 事前データ・ビルドbinding

この事前登録は`RTNN_EXTVAL_V1`の設計条件を固定する。実際のELF、RAM image、SOF SHA、toolchain、SV source graphが生成された後、それらを`binding.json`へ追加して別hashで承認する。旧C3 v2 SOF/ELF、過去結果を新buildの代用にしない。

`DATA_EXPOSURE_UNCERTAIN`と行単位writer不明が解消しない場合、実機結果は探索的外部評価としてのみ扱う。B-SIGNOFF、WCET、hard deadlineは本キャンペーンの結果で解除しない。
