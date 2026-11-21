# 過去データ使用・漏洩監査

## 調査した履歴

- 追跡済みモデル学習コード `experiments/realtime_nn_real_sequence_generalization.py` は `sklearn.datasets.load_digits()`を読み、固定stratified 60/20/20分割（seed 123、456）で訓練・検証・testを作る。
- 追跡済みの別実験 `experiments/realtime_nn_digits_budget_gate.py` も `load_digits()` を用いる。
- seed-63凍結Q15ヘッダーのSHA-256は `961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f`。モデル生成コードは追跡済みだが、外部の個人作業や未保管データ履歴を包括的に証明する訓練データアクセスログは見つからなかった。
- 現在取得できるGit履歴・追跡ファイルを検索した範囲では `optdigits.tra` への過去参照は見つからなかった。これは追跡範囲内での不使用の証拠であり、ローカル外・未記録の利用を否定するものではない。

## 画素漏洩検査

scikit-learn 1.8.0の全1,797 `load_digits`画像とUCI `optdigits.tra` 全3,823画像を64バイト画素列で完全一致照合した。一致0件、tra内重複0件。公式`optdigits.tes`は`load_digits`全1,797画像・ラベルと一致した。したがって候補traは既知のload_digits配列と画素レベルでは重複しない。

UCIの`optdigits.names`は、30人のtraining sideとそれと異なる13人のtest sideを記す。既知RTNNコードのload_digitsはtest file側と一致するため、公式split記載に基づけばtra側と従来load_digits側は筆記者群が別である。ただしtraの各行には筆記者IDがなく、tra内の筆記者間・筆記者内クラスタを識別できない。

## 判定

`DATA_EXPOSURE_UNCERTAIN`。既知のソースではoptdigits.tra使用・画素再利用は認められないが、全ての過去利用履歴を証明する記録はなく、行単位筆記者IDもない。したがって実測を行う場合も、ユーザーまたはデータ管理者による未記録利用の確認が得られるまで「独立・未使用データで確認的に検証した」と主張しない。条件が確認できなければ探索的な外部評価候補として扱い、非劣性CIは画像独立性を仮定する入力単位の参考区間に留める。
