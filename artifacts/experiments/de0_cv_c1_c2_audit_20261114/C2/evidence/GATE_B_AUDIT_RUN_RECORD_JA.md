# Gate B evidence recheck — run record

日時: 2026-11-14 JST
正本repo: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
Branch: `codex/stage-c3-repro-timing-20261114`
監査開始HEAD: `0bf7421f1ee3358b31ddeb51195a770d8180ac5e`
実行cwd: `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114`

## 目的と結果

Quartusの保存済みC2J2結果、D101個別処置監査、全コーナーCDC path監査、JTAG外部タイミング調査を読み取り照合した。Quartus buildは再実行していない。新しいC3ビルドも実機へ書いていない。

| 項目 | 状態 |
|---|---|
| 正しいGit origin / branch確認 | PASS |
| 作業開始時にclean、HEAD記録 | PASS |
| exact C2J2 QSF/SDC/flat RTL/SOF SHA照合 | PASS |
| D101 801個別処置とglobal rules有効の保存audit照合 | PASS |
| 4コーナー request 800/800・response 384/384 path/net-delay audit照合 | PASS |
| JTAG未制約I/Oと外部仕様不足の確認 | PASS（不足を確認） |
| embedded asynchronous clock-group cutとQuartus raw MTBF未計算fractionの確認 | PASS（raw fieldを確認。383 payload auto-chainは後続詳細監査で再分類） |
| max-skew raw reportsの判定 | NOT_EVALUATED（4件とも `Nothing to report.`） |
| Gate B全体 | BLOCKED |
| 新C3の実機書込み・42件・360入力campaign | NOT_RUN |

## 新規に保全した調査資料

以前の作業ツリー `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\RTNN` を変更せず、以下だけを読み取り複製した。複製先は `jtag_timing_research_20261113/`。

* `JTAG_TIMING_RESEARCH_20261113.md`
* `JTAG_TIMING_RESEARCH_FOLLOWUP_20261113_JA.md`
* `TERASIC_JTAG_TIMING_SUPPORT_REQUEST_DRAFT_JA.md`
* `jtag_interface_requirement_20261113/` の63ファイルとSHA manifest

inner manifest SHA-256: `f0b558dea10db382fa4728f55eb44fac469201041c04a7fe202633a49d1f400b`。manifest内63項目は複製後に全件一致した。複製した総数67ファイル、7,765,409 bytes。大規模なQuartus一時DBは複製していない。

## 検証コマンド

コマンド（PowerShell）:

```powershell
& '.\artifacts\experiments\de0_cv_c1_c2_audit_20261114\C2\evidence\verify_gate_b_evidence.ps1' *> '.\artifacts\experiments\de0_cv_c1_c2_audit_20261114\C2\evidence\gate_b_evidence_recheck_20261114.log'
```

直後にPowerShellの`$?`を確認し、成功時にexit sentinel `0`を書き込んだ。結果: **exit 0**。出力は `gate_b_evidence_recheck_20261114.log` に保存。QSF/SDC/flat RTL/SOFのSHA、Quartus 59項目・移送JTAG資料63項目のmanifest、D101全フラグ、各corner/path array件数・bound、embedded async group、Quartus raw MTBF summary field、max-skew空出力、unconstrained portsを検査した。整合性再検査はPASSだが、JTAG I/O外部タイミングとCDCの物理signoffが未完了のため、スクリプトもGate B decisionをBLOCKEDのまま記録する。後続の392-chain詳細監査では、raw 0.977の未計算fractionのうち383件をresponse payload auto-chain、残る9件をMTBF算定済みのreset/control同期器と特定した。従ってraw summary fieldの検出をscalar synchronizerのMTBF欠落と解釈しない。

その他の再確認はPowerShell `Get-FileHash`, `Get-Content`, `Select-String` による読み取りだけである。

Gitの自動改行変換で複製証拠のSHAが変わらないよう、今回追加したC2 evidenceのファイルだけを `.gitattributes` で `-text` にした。staged blobとraw fileのSHA-1 object IDを確認した。全追加証拠に対する `git diff --cached --check` はQuartus生成のraw `.rpt` / `.log` 内の行末空白を多数報告したため、このraw出力は改変せず保存した。Codex作成の2文書、PowerShell checker、`.gitattributes` に限定した `git diff --cached --check` はexit 0。

## この実行で行っていないこと

Quartus compile/STA/Design Assistantを再実行していない。実機とのJTAG操作、FPGA SRAM書込み、Flash/CFM操作をしていない。RTL/QSF/SDCを変更していない。commit、push、PR、mergeをしていない。

内容と生成ログのSHAは隣接する `SHA256SUMS_GATE_B_AUDIT_20261114.txt` に記録する。
