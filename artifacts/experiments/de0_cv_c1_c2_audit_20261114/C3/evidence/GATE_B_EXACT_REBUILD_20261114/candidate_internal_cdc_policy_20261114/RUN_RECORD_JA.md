# Internal CDC candidate policy: isolated Quartus STA evidence

日時: 2026-11-14 JST  
対象: 正しいRTNNリポジトリ `Unjuno/resource-conditioned-neural-computation` のC2 exact-input fitted database。Quartus Prime Lite 25.1std.0 Build 1129。これは新しい候補SDCを当てたSTA診断であり、Gate B全体のPASSではない。

## 変更と識別

元のC2 SDCを複製し、SDC読込みの最後に以下を追加した候補 `rtnn_de0_cv_c3_candidate.sdc` を作成した。元のC2 SDCとソースRTL/QSFは変更していない。

- SLD hub内蔵の単一 `set_clock_groups -asynchronous -group {altera_reserved_tck}` を `remove_clock_groups -all` で解除。
- 7本の非同期制御トグル/状態のsource→first-stage synchronizerだけに個別false path。
- 800-bit要求bundleに40 nsのmax-delayとmax-skew、384-bit応答bundleに60 nsのmax-delayとmax-skew。
- 基板回路図で非同期LED負荷と確認したLEDR[0], [1], [3]に限り、非capture端点としてfalse path。

元のSTA報告にあるクロックは `CLOCK_50` と `altera_reserved_tck` の2つのみで、clock groupも上記1件だけ。候補制約後に全クロック間を網羅してsetup pathを列挙し、TCK→systemに要求バス800経路、system→TCKに応答バス384経路だけが各コーナーに残ることをassertした。他の内部CDC交差は見つからなかった。これは `remove_clock_groups -all` が実際にはこのデザイン唯一の2ドメイン関係に作用したことを、端点数と全4コーナーの経路数で検証したもの。

入力ソースの候補QSFは元SDCを二重登録せず、元SDC内容を含む候補SDCだけを登録する。初回統合では二つのSDCを同時登録してCLOCK_50重複警告 Warning 332043が出た。初回ログを `initial_duplicate_sdc_warning.log` に保存。QSFを候補SDC一つだけに修正して再実行し、この警告が消えたことを確認した。最終runの唯一のWarningはWarning 12473（QSFが1 processor指定、利用可能14）で、時間解析上の警告ではない。

候補QSF変更はSDC_FILE assignmentのみ。candidate QSF SHA-256 `cbdcff25b00785c08291dde8e18e3a9bc78f54d9f0055a92c41616cbde073e3a`。候補SDC SHA-256 `6160a1ccda09a9955cbb2fc5ef59b8d33eb91e9b3c707ffa983dd9c2e7d54d4e`。元SDC SHA-256 `8ba18e9829ebb9754278867948a1b0fffb360144738f1c3e45f1650592a87690`。最終flat RTL SHA-256 `fdfcdf037eb55225e3e6eef06b01fc92e608951c54ece946461408131f2e5ca7`。SOFは再生成・書込みしていない。

## 再検証結果

1. 候補SDCをQSF経由で読み込んだSTA、Quartus終了コード0。
2. 各4コーナーにTCK→system 800 setup paths、system→TCK 384 setup paths。他のclock-to-clock setup pathはゼロ。全経路0違反。
3. max-delay最悪slack（Slow 85C, Slow 0C, Fast 85C, Fast 0C）: request +32.704/+32.957/+36.018/+36.381 ns、response +57.936/+57.933/+58.625/+58.780 ns。
4. max-skewは全4コーナーで32 path records、違反0。実測max skewの最大値（同じコーナー順）: request 3.528/3.431/2.239/1.978 ns、response 3.330/3.249/2.103/1.874 ns。
5. 7組のscalar synchronizer stage1→stage2について、4コーナーごとにsetup/hold各1 path（計28 setup + 28 hold）。最小setup slack +18.856 ns、最小hold slack +0.255 ns。全件違反0。
6. LED指示灯を除いた後もUCPは2 input ports/41 input paths（TDI/TMS）と1 output port/5 output paths（TDO）。クロックは2つとも定義済み。Quartusは依然setup/hold fully constrainedでないと報告。

candidate SDCは既存配置/配線結果に対するSTA検査用としてQSF経由で適用した。**Fitterを候補SDCで再実行していない**ため、新制約を使った配置/配線の最終タイミング保証ではない。さらにTDI/TMS外部入力遅延、実TCK/duty/launch phase、TDO受信側要求が未確定で、I/O UCPが残る。この候補に対するSTAは内部CDC候補の部分PASSに限り、Gate BはBLOCKED、Gate Cは未実施のまま。

## 再実行情報

作業cwd: `D:\rtnn_c3_gateb_exact_rebuild_20261114_internal_cdc_sdc_candidate`  
最終コマンド: `C:\altera_lite\25.1std\quartus\bin64\quartus_sta.exe -t .\candidate_full_cdc_sta_final.tcl`（同じcwdからcandidate_sta_final.tclも実行、両方exit 0）。失敗・重複定義を含む初回ログは上書きせず保存。

生レポートと再実行Tclは `candidate_sta/` および `synchronizer_setup_hold/`。この作業領域はSTA用の隔離コピーであり、FPGAへの書込みなし、Flash/CFM無変更。


補足: LED例外はUCPにあった非同期インジケータ出力3経路を除外する目的で記述した。Quartus `report_exceptions`では該当行が `Paths will not be analyzed` / setup slack `Invalid` と表示され、clocked setup/hold経路が存在しないことが分かる。この表示をtiming PASSとは解釈しない。Terasic回路図上の抵抗付きLED負荷という端点分類の記録である。
