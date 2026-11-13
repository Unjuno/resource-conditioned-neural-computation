# C2 42件から360入力へ移る条件

2026-11-13時点ではC2実機42件が未実施のため、論文キャンペーンはNOT_RUN。以下は既存計画の読み取り専用照合と、移行時に満たす条件である。

既存の統合先は`de0cv_setup/verified_inputs_2026-11-03/stage2_finalwork/fpga/de0_cv/paper/campaign/`。`paper_eval/changes/`は差分ZIPの展開領域で、全scheduleの保管場所ではない。

| 確認対象 | 結果 |
|---|---|
| 入力 | 360 |
| schedule | 13、予定合計24,840行 |
| campaign JSONのファイルSHA-256 | `3d97a1cd87395e294299cacb617474367c89a9295355cd25fb1b4fa67464c936` |
| campaign定義のcanonical SHA-256 | `d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc` |
| 13 scheduleのrows canonical SHA | 全件一致 |
| 元のexpected build ID | `44563032`（C2J2の`43324a32`とは異なる） |

`schedule_sha256`はファイルのバイト列ではなく、既存`paper_campaign.py`が定義するrowsのcanonical JSONのSHAである。campaign自身も`campaign_sha256`フィールドを除いたcanonical JSONで検査する。最初に差分だけの領域やファイルSHAで調べた不一致は、この格納場所／hash定義の違いによるもので、schedule内容を修正して合わせていない。照合スクリプトと全13件の結果は`evidence/host_runner_20261113/campaign_readonly_audit.json`に保存する。

移行時は次を順に行う。

1. C2J2の同一SOFで実機42件の完全性・予測・Exit・cycle・reset再現性・タイミングゲートを通す。ホストmockとRTL simulationのcycleは論文の実測列へ入れない。
2. 既存campaign、全schedule、heldout360とQ15参照をSHA照合し、変更せず保管する。再生成コマンドを既存campaignへ実行しない。
3. 旧build IDとC2J2の差を明示したJTAG用実行bindingを別の記録として作る。凍結campaignの順序・入力・mode・予算・期待値を保持し、既存のbuild ID検査を無効化して通さない。bindingと対象SOFの整合性はレビューしてから実測する。
4. 固定Exit 2と適応RTNNを同じモデル、入力、50 MHz設定、firmware測定境界で対にする。実行されたブロック数は、このcoreでは`executed_exit`と同じ値（0～6）。headや入力初期化とは区別する。
5. 実験ID、session/boot ID、入力ID、schedule行、mode、budget、予測/参照、admitted/実行Exit、cycle、status、build ID、SOF SHA、campaign/binding SHAを各行に結び付ける。失敗行を捨てず、再試行は新しい実験IDにする。
6. 元の統計計画に従い、入力ごとのsession内平均から固定・適応の対応差を求め、平均・中央値・分布・95% bootstrap区間を出す。campaignのseed、5,000回、入力を単位とする定義を維持し、bootを跨ぐ主張には既存のtwo-way bootstrap条件も適用する。今は測定データがないため数値を作らない。

実際の発振周波数、温度や電源条件、reset/boot状態を別々に記録する。未測定の実周波数・ppm・絶対時間を推定値で埋めない。測定モデルが成立してから不確かさを評価し、仮の合成標準不確かさや包含係数を置かない。
