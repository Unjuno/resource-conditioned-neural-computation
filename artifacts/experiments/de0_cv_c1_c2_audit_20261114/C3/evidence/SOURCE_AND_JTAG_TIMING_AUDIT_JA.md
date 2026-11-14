# C3 実験証跡とJTAGタイミング資料の照合

作成日: 2026-11-14 JST  
リポジトリ: `https://github.com/Unjuno/resource-conditioned-neural-computation`  
専用ブランチ: `codex/stage-c3-jtag-pilot-20261114`

## 実機SOF・ソース・firmwareの対応

C2J2の保存済み実機記録 `C2/evidence/physical_empirical_42/RUN_RECORD_JA.md`、run manifest、Quartus ProgrammerのJTAG書込みログ、Virtual-JTAGの生応答を突合した。プログラマログは `USB-Blaster [USB-0]` と `02B050DD` に対してSRAM JTAG configure成功を記録し、P.O.F./JIC/Flash操作はない。保存済みSOFのSHA-256は `5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6`。

そのSOFの保存済みQuartus project入力とのSHA対応:

| 入力 | SHA-256 | 照合 |
|---|---|---|
| SOF `C2/evidence/quartus_d101/rtnn_c2.sof` | `5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6` | 物理run manifestと一致 |
| QSF | `9d270c2f57ca7f6ee1f68f4d525a685625a7cc5311b0a55ee363e23f823f675e` | run recordと一致、Cyclone V 5CEBA4F23C7 / C2 top / 43324a32 |
| C2 flat RTL | `fdfcdf037eb55225e3e6eef06b01fc92e608951c54ece946461408131f2e5ca7` | recovered source/146-file regressionのbuild input SHAと一致 |
| board top | `639e58115cc2f249b7aceb9e89fd2670896c5810ea442c31836926ac3bed5d5a` | run recordと一致 |
| SDC | `8ba18e9829ebb9754278867948a1b0fffb360144738f1c3e45f1650592a87690` | run recordと一致 |
| firmware ELF | `625daf8cc194f1bc7d48eefff0f07939c5e0988bb07fc8a3e7efad7e613a15fd` | frozen firmware manifestと一致 |
| frozen Q15 header | `961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f` | firmware manifestと一致 |
| RAM lanes 0..3 | `7704b387d02830327de288cfcced5d1a485c75b6f0cb838db1da4e87661f5f5a`, `8c98d35b71595a0fc6fb40be2177dbac3883b4439a5ae894355bd3c3288af1c6`, `8e8d201adf2f8e383d42bb116d75fa3e0fb6675d8bf96c694a8fc969547d5873`, `affa1411c8c1ea6c443b2b6729502b58b63a6561fcf3177c65d7f34e635e1d11` | 各Quartus入力がfirmware manifestのlane SHAと一致 |

QSFが選ぶflat RTLは`$readmemh`で4つのlane imageを読む。lane imageとELFを記録するfirmware manifest、build/model IDを返す実機JTAG応答（build `43324a32`, model `52544e4e`）、既存42件の出力監査が同一IDに揃う。Gate Aの再構築SOF `878dd27e…` は別QSF/SOFで、物理42件のSOFと混同しない。物理runの対象は上記`5aa5…`のまま維持した。

物理記録に先行するD101 build recordの「この工程ではまだprogrammingしていない」と、後続の`physical_empirical_42` Programmer logの「configuration succeeded」は時系列が異なる。firmware manifestの`RV32_IMAGE_BUILT_NOT_SIMULATED`はbuild時点の状態であり、単独では実機書込みの証明に使わない。後続のJTAG応答と生ログを実機証跡として使う。

Gate Aのネイティブ/sv2v/flat回帰はRTL回帰証拠であり、基板実行証跡とは分離する。Gate Bの未制約外部JTAG経路とD101処置は正式signoff未完了のまま。

## JTAG FPGA端点タイミング資料

2026-11-14にAltera公式Cyclone V Device Datasheetの「FPGA JTAG Configuration Timing」Table 56を取得して数値を照合した。Cyclone V FPGA専用JTAG端点について:

| 記号 | 公式仕様 | 単位 |
|---|---:|---|
| tJCP | 最小30 | ns |
| tJCH / tJCL | 最小14 / 14 | ns |
| tJPSU(TDI) / tJPSU(TMS) | 最小1 / 3 | ns |
| tJPH | 最小5 | ns |
| tJPCO | 最大11 (注1) | ns |
| tJPZX / tJPXZ | 最大14 (注1) | ns |

注1: TDO bank VCCIOが3.0 Vより低い場合は1段ごとに1 ns加算（公式ページ例: 2.5 Vで+2 ns、1.8 Vで+3 ns）。本boardの当該条件をこの資料だけから確定していないため、加算後の値を本レポートに推測記入しない。

資料はCyclone Vデバイス端点の仕様であり、Terasic基板上のUSB-Blaster/CPLD/配線遅延、ケーブル出力遅延、Quartus Programmerの実TCK設定、基板ごとの外部setup/holdを与えない。したがって、これだけで現行SDCの未制約JTAG I/Oを閉じることはできない。

* [Altera: Cyclone V Device Datasheet — FPGA JTAG Configuration Timing](https://docs.altera.com/r/docs/683801/current/cyclone-v-device-datasheet/fpga-jtag-configuration-timing?contentId=tHclXha2uF6DJBsBSWaFRA) — Table 56。
* [Altera: Cyclone V Device Handbook — I/O Voltage for JTAG Operation](https://docs.altera.com/r/docs/683375/current/cyclone-v-device-handbook-volume-1-device-interfaces-and-integration/i/o-voltage-for-jtag-operation) — dedicated JTAG pinsとbank電源条件。
* [Terasic: DE0-CV Board documents](https://www.terasic.com.tw/cgi-bin/page/archive.pl?CategoryNo=13&Language=English&No=921&PartNo=4) — board/manualの公式配布ページ。掲載manualはv1.1.2 (2015-05-08)。同ページの記載はon-board USB-Blaster/JTAG機能の確認に使い、伝搬遅延値としては扱わない。

## USB-Blaster/TCK資料と実機query

Terasicの公式DE0-CV仕様ページは、対象基板を5CEBA4F23C7N、USB-B type-Bのon-board USB-Blaster、JTAG/AS対応と記載する。今回の実機ログでもQuartusは`USB-Blaster [USB-0]`を列挙した。これはUSB-Blaster IIIのケーブルとは異なる名称であり、USB-Blaster III guideのdefault 15 MHz / 最大30 MHzや同ケーブル固有の配線setup値を本基板へ流用しない。

読み取り専用でQuartus 25.1std.0 Build 1129を確認し、`jtagconfig --getparam 1 JtagClock`を実行したが、終了コード4、`No parameter named JtagClock`となった。設定変更は行っていない。したがって現在の物理USB-Blaster TCK実周波数は未確認。AlteraのDownload Cable II向けTCK設定手順も、実機IDが`USB-Blaster [USB-0]`であるため、この個体のCable II証拠としては使わない。

この読み取り専用queryのコマンド・cwd・終了コード・ログSHAは`evidence/JTAG_EXTERNAL_TIMING_READONLY_20261114/`に保存した。公式の現行USB-Blaster III guideは、JTAG制約にケーブル経路遅延を加味し、実際に使うケーブルとTCK設定に合わせた入力/出力遅延を設定する必要があることの参考にした。DE0-CVで確認されたケーブルと異なるため、その数値は設計制約に転用していない。

* [Altera: USB-Blaster III JTAG Timing Constraints and Waveforms](https://docs.altera.com/r/docs/864466/current/usb-blaster-iii-fpga-development-cable-user-guide/jtag-timing-constraints-and-waveforms) — そのCable IIIに限る制約要件と経路遅延の扱い。
* [Altera: USB-Blaster III — Creating JTAG Timing Constraints](https://docs.altera.com/r/docs/864466/current/usb-blaster-iii-fpga-development-cable-user-guide/creating-jtag-timing-constraints-in-quartus-prime-software) — JTAG TCKをvirtual clockとして扱い、TDI/TDO/TMS等のI/O delayを定義する手順。
* [Terasic: DE0-CV Board specifications](https://www.terasic.com.tw/cgi-bin/page/archive.pl?CategoryNo=163&Language=English&No=921&PartNo=2) —搭載FPGA、on-board USB-Blaster、JTAG対応の確認。

現時点の結論: 経験的mcycle測定は実施可能。JTAG外部タイミングと全経路制約はBLOCKEDのままであり、WCET、hard-deadline、board-level timing signoffは主張しない。

