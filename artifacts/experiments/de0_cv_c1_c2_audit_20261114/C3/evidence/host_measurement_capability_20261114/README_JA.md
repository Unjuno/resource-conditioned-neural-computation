# Gate B 外部JTAG測定手段のホスト確認

日時: 2026-11-14 JST
Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
Branch at audit: `codex/stage-c3-jtag-pilot-20261114`
監査前HEAD: `2c46ee16b6ebcf3700453e3853b1c3448a2336e5`

## 結果

- Quartus Prime Lite 25.1std.0 Build 1129と`quartus_sh`、`quartus_stp`、`jtagconfig`の実行ファイルを確認。
- Windowsのpresent PnP device名で`Altera USB-Blaster`、Status `OK`を確認。
- 接続済みデバイス名を絞った照会では、オシロスコープ/ロジックアナライザに該当するpresent deviceは検出されなかった。
- Uninstall registryの表示名・版だけを絞った照会ではQuartus以外の対応計測アプリは検出されなかった。

これは限定した名前検索の結果であり、別名の計測器・未接続機器・他PC上の設備が存在しないことを証明しない。JTAG TCK/TDI/TMS/TDOの電気波形はこの照会では取得していない。基板へのJTAG scan、SOF設定、Flash/CFM操作、設定変更も行っていない。

既存の読み取り専用`jtagconfig --getparam 1 JtagClock`は`No parameter named JtagClock`（exit 4）であり、オンボードUSB-BlasterのTCK設定を得られなかった。FPGA端点のCyclone Vデータシート仕様だけでは、オンボードEPM240/配線の相対遅延とTDO capture windowを補えないためGate Bは引き続き**BLOCKED**。

再実行スクリプト、コマンド出力、終了コードは同じディレクトリに保存する。スクリプトはホストの名前を絞った読み取りだけを行う。
