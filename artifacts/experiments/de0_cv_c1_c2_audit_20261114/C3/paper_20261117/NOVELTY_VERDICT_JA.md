# 新規性判定（2026-11-21）

## 判定

**アルゴリズムの新規性：NOVELTY_UNPROVEN。** 入力ごとの早期終了、複数exit、同一モデルでの予算別実行、エントロピーによる停止判断、FPGA上の動的推論は、今回確認した一次資料ですでに実現されています。特に低精度FPGAのエントロピー早期終了（Kong & Nunez-Yanez, 2022）とFPGA上の動的早期終了実装（Dimitriou et al., 2025）は、本稿の強い新規性主張に対する直接の反証です。

**限定された実装・実証貢献：INCREMENTAL_CONTRIBUTION。** 1台のDE0-CV上でIbex RV32 softcoreが凍結Q15を実行し、JTAG要求と応答identityを付けたmcycle計測を24,840要求分保存・独立再集計した事例は、具体的な実装条件を持つ経験的ケーススタディとして報告できます。ただし「新方式」や「初の実機実装」とは呼べません。独立した電源セッションのばらつき、精度1 pp非劣性、Quartus/SOF再構築同一性、正式JTAGタイミングは確立していません。mapped 146-source native graphとclean-clone Verilator回帰は確認済みです。

## 貢献候補ごとの分類

| 候補 | 判定 | 理由 |
|---|---|---|
| 同一Q15重みで固定・適応の複数実行を行う | `ALREADY_KNOWN` | MSDNetや多段exit研究が同一multi-exitモデルの予算・入力依存実行を扱う。 |
| エントロピーで早期終了する | `ALREADY_KNOWN` | FPGA低精度ネットワーク上のentropy-based early-exitが2022年に報告済み。 |
| FPGAで早期終了型DNNを物理実装してcycle/latencyを測る | `ALREADY_KNOWN` | 2020年、2022年、2025年のFPGA研究が関連する実装・性能評価を報告。 |
| 連続Q0.16予算を7段階の許可上限へ写像し、許可exitと実行exitを別々に記録する | `NOVELTY_UNCERTAIN` | RTNN内の明確な実装要件だが、今回の比較だけでは類似の量子化・cap設計を網羅的に除外できない。 |
| Ibex/DE0-CVでのJTAG要求identity付きmcycleケーススタディと全件保存監査 | `INCREMENTAL_CONTRIBUTION` | プラットフォーム固有の測定記録として具体的。アルゴリズムやFPGA早期終了一般の新規性を意味しない。 |
| board-level hard deadline / WCET保証 | `ALREADY_KNOWN`（研究領域として方法あり）/ RTNN結果は`NOT_ESTABLISHED` | Patmos上の静的時間解析やFPGA DPU向けWCET解析は存在。RTNNは外部JTAG/CDC signoffを満たさず、WCET解析も未実施。 |
| mapped 146-source native graphを第三者が再構築・回帰できる | `PASS_NATIVE_ONLY` | 公開branchのclean cloneで146/146 SHA照合とnative Verilator回帰に成功。Quartus/SOF同一再構築は未確立。 |

## 論文に記載可能な貢献文

“本研究は、早期終了アルゴリズムを新たに提案するものではない。凍結Q15モデルをIbex RV32 softcoreとしてCyclone V DE0-CVに実装した特定buildについて、要求・応答identityを保持したJTAG実測サイクル記録を提示し、24,840要求の保存データを再集計する経験的ケーススタディである。結果は当該build・基板・保存sessionの範囲に限定され、精度非劣性、基板間一般化、正式タイミング保証またはWCETを示さない。”

## 参考文献監査の境界

比較表とリンクは [PRIOR_ART_COMPARISON.md](PRIOR_ART_COMPARISON.md)。これは査読前の重点調査であり、完全なsystematic reviewではない。従って「世界初」「文献に例がない」と結論しない。投稿前には著者が対象分野の検索式・期間・データベースを固定したsystematic searchを行うか、タイトルとabstractを正確に限定する。
