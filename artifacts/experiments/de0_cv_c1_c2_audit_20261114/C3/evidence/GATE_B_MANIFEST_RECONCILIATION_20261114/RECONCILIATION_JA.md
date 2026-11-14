# Gate B証拠manifestの追補照合

日時: 2026-11-14 JST
Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
Branch: `codex/stage-c3-jtag-pilot-20261114`
監査HEAD: `ce453529f9f3bb4c4daf6c6a77e9b23bdbfbfd0f`

## 発見と処置

`C3/evidence/GATE_B_EXACT_REBUILD_20261114/SHA256SUMS.txt` の120項目を現在のworktreeに対して照合したところ、119項目は一致し、`RUN_RECORD_JA.md` だけが不一致だった。既存manifestは保持し、現行ファイル一式の追補manifest `SHA256SUMS_CURRENT_20261114.txt` をこのディレクトリに作成する。

不一致のmanifest期待値は `f8175f6bc29ac4c5c41f0eb2f5424c44eb3e9a6b7053244b44fd984493f79136`。これは `cfa736657e4a03f1b621c93c7b5b26e7cd71adc9` 時点の同じレポートblobのSHA-256と一致した。後続の `389a0610`（CDC capture phase修正）、`542edeae`（4-corner synchronizer監査）、`f6f437b`（LED端点分類）で同じレポートへ追記されたが、元manifestの同項目は更新されていなかった。現行コミット済みblobおよびworktreeファイルのSHA-256は `be30c8de5db8e2db03ee711e9e5bfdc66a30c99332902d58b6f82b50c0ad7df5`。

これはGate Bの測定・STA結果に対する不一致ではなく、後から追記された監査レポート1ファイルに対するmanifest更新漏れである。元manifestとGit履歴は書換えず、追補manifestで現在の120ファイルを再固定する。Gate Bの判定は変わらず **BLOCKED**。

## 現在のGate B技術判定

- 再現Quartus入力のQSF/SDC/flat RTL/RAM lane SHAは記録済み。保存済みexact-inputビルドはCyclone VでFitter成功、4 cornerのCLOCK_50内部STAはsetup/hold slack正。
- 原SDCのTimeQuest実行はsetup/hold fully constrainedではないと明示。入力 `altera_reserved_tdi`, `altera_reserved_tms` の41 path（要求payload bit 799を含む）と出力`altera_reserved_tdo`等が残る。
- `altera_reserved_tck`の30 MHzはHDL埋込SLD hubの解析用クロックで、実USB-Blaster TCK測定値ではない。`jtagconfig --getparam 1 JtagClock`はparameter unavailable。
- request 800 / response 384 bundled-data pathと7 scalar synchronizer対を対象にした候補CDC診断では4-corner setup確認がある。しかしclock groupを診断時に全解除したレポート、`set_max_delay` / `set_max_skew`診断をそのまま本番SDCとは扱えず、全CDC例外方針を含むproduction STAの成立証拠ではない。
- LED出力のfalse-path分類も診断Tcl内だけ。原SDCには追加されていない。JTAG TDI/TMS/TDOのboard/cable相対遅延とTDO capture条件が資料未取得のため、ここを推測で制約しない。
- D101の局所抑制は800 request hold nodeとresponse代表nodeの明示処置として保存される。全体抑制ではないが、Design Assistantの成功だけで未制約STA経路を閉じない。

結論: 内部クロックの実装STAとCDC診断には有用な肯定的証拠があるが、正式な全経路・board-level timing signoffは成立していない。経験的な24,840行の測定記録は独立したEMPIRICAL_ONLY証拠として維持し、WCET・hard-deadline保証へ読み替えない。

## 再実行

`verify_current_manifest.ps1` が追補manifest全件をSHA-256照合する。終了コード0かつmissing/mismatch/malformedが0の場合にのみ追補照合PASSとする。元manifestの過去状態を再現する場合は、元manifestと上記Git commitの記録を使用する。
