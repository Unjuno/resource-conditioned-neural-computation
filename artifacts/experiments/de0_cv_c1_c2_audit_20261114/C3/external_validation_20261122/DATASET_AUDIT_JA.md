# 新規画像データ監査

監査日: 2026-11-22  
状態: `CANDIDATE_DATASET_READY`; 未使用・独立の確認的標本としての資格は別ゲート。

## 取得元と原本

指定された準備ZIP `RTNN_external_validation_preparation_20261122.zip` は、リポジトリ作業領域とCodex添付領域で見つからなかった。既存の成功ログは今回の実行として流用していない。公式UCI配布元からアーカイブを取得し、`downloads/uci_optical_recognition_handwritten_digits.zip` に保存した。

UCI配布物の記載は`optdigits.tra` 3,823行、`optdigits.tes` 1,797行、64画素と末尾の0–9ラベル、画素値0–16である。`optdigits.names` は総43筆記者のうち30人をtraining side、別の13人をtest sideに割り当てたと記す。またtra側の用途には学習・検証・writer-dependent testが含まれる。行単位筆記者IDは配布されていない。

| 検査 | 結果 |
|---|---:|
| ZIP SHA-256 | `0d7b054fea010270e9b3f06411c654c5e59547732ad626381980baffe0a23fb0` |
| `optdigits.tra` SHA-256 | `e1b683cc211604fe8fd8c4417e6a69f31380e0c61d4af22e93cc21e9257ffedd` |
| tra行数 / 画素数 | 3,823 / 64 |
| tra画素範囲 / クラス | 0–16 / 0–9 |
| `sklearn.datasets.load_digits`完全画素一致 | 0 / 3,823 tra行 |
| tra内重複画素 | 0グループ、除外0行 |
| pilot | 10画像 |
| primary候補 | 3,813画像 |
| 3,000画像完全性ゲート | PASS（検出力保証ではない） |

直接照合にはscikit-learn 1.8.0の`load_digits()`全1,797行を用いた。UCIの公式`optdigits.tes`もその1,797画素配列・ラベル配列と全行一致した。画素とラベルの正規化バイト列SHAは[`data/ORIGINAL_1797_PIXEL_SHA256.txt`](data/ORIGINAL_1797_PIXEL_SHA256.txt)に保存した。モデルの既存訓練・評価で使用されたデータとの漏洩照合では、load_digitsのtest splitとの完全画素重複は0件だった。

## 除外と選定規則

全3,823行を画素bytesで照合した。load_digitsと完全一致する画像があれば除外し、tra内の同一画素重複は同一ラベルなら最小source rowだけ残し、ラベル矛盾があればその画素群全てを除外する規則で実装した。今回、この規則による除外は0件。

pilot 10件は推論結果を見る前に、候補SHA・1-based source row・64画素bytesだけから作る次のSHA-256昇順で選んだ。ラベルは選択式に使っていない。

```text
SHA256("RTNN-EXTVAL-PILOT-v1\\0" || raw-tra-SHA256-bytes || uint32le(source-row) || pixel-bytes)
```

pilot input ID（1-based UCI source row）は `525, 277, 321, 921, 519, 1673, 3689, 3660, 57, 667`。この10画像は工学pilot専用で、primary統計から永久に除外する。残る3,813行がprimary候補。

全行のpartition・pixel SHA・pilot selection SHAは`data/image_manifest_all_rows.csv`、pilotとprimaryの固定集合は`data/pilot_manifest.csv`と`data/primary_manifest.csv`、ラベルを含まないFPGA転送用連結画像bytesは`data/pilot_inputs.bin`と`data/primary_inputs.bin`にある。ラベルはホストのmanifestにだけ残し、モデル入力バッファには入れない。

データセットはUCIのCC BY 4.0条件に従い帰属表示する。配布原本と`optdigits.names`はSHA付きで保持する。
