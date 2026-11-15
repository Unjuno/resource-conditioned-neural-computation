# Gate B: Altera公式JTAG制約ガイド再確認

確認日: 2026-11-15  
対象repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`  
作業branch / HEAD: `codex/stage-c3-jtag-pilot-20261114` / `b332ba02ab992227140998a1d67513c690ae17cf`  
分類: 保存済みSDCに対する公式手順の追加照合。基板・JTAG操作なし。

## 確認した一次資料

1. Altera, [USB Blaster III FPGA Development Cable User Guide — JTAG Timing Constraints and Waveforms](https://docs.altera.com/r/docs/864466/current/usb-blaster-iii-fpga-development-cable-user-guide/jtag-timing-constraints-and-waveforms), 2026-10-14版。対象ケーブルの条件で、最大30 MHz時のTCK周期・high/low、target device側のsetup/hold、cable/header経路に関する値を掲載している。同ページは、target device固有仕様とtrace propagation delayも考慮するよう明記する。
2. Altera, [Creating JTAG Timing Constraints in Quartus Prime Software](https://docs.altera.com/r/docs/864466/current/usb-blaster-iii-fpga-development-cable-user-guide/creating-jtag-timing-constraints-in-quartus-prime-software), 2026-10-14版。JTAG TCKをvirtual clockとして定義し、TDI/TMS等のI/O delayを実際のJTAG setupとdevice characteristicsに基づいて与える手順を説明する。

## 適用できること・できないこと

このガイドは、外部JTAG制約を単にTCKの周期だけで閉じず、実際のcontroller/cable/traceと対象デバイスに対応するmin/max delayを根拠付きで用意すべきことを裏付ける。一方、ガイドの製品はUSB-Blaster III FPGA Development Cableであり、このDE0-CVのオンボードFT245BL/EPM240T100経路とは異なる。したがって、同ガイドの数値・波形・遅延をDE0-CV内蔵経路へ転用しない。

また、同ガイドのTDO節はtarget-device perspectiveのTDO出力を説明しながら、例示SDCコマンドが`set_input_delay`となっている。TDOの制約方向を決めるときは、対象ポートの実際のタイミング視点とQuartusのポート方向を確認する必要があるため、このコマンド例をそのまま採用しない。誤記か別の視点を意図したものかは本資料だけでは決着しない。

## Gate Bへの影響

既存C3 v2 SDCは`CLOCK_50`と内部bundled-data screenを制約しているが、保存TimeQuest UCP reportでは`altera_reserved_tdi`・`altera_reserved_tms`の41 input pathsと`altera_reserved_tdo`を含む4 output portsが未制約である。今回の公式資料は制約方法の一般要件を補強するが、board revision固有のTCK/duty、controller launch/capture edge、controllerとFPGA間の相対遅延、I/O電圧・温度範囲を与えない。

そのため、JTAGのI/O delay値やfalse pathは追加せず、B-SIGNOFFは**BLOCKEDを維持**する。既存の`TERASIC_SUPPORT_JTAG_TIMING_SPEC_REQUEST_C3_EN.md`は未送信のまま保管する。Terasic公式DE0-CV manualの該当箇所を含む既存レビューにも、revision-specific JTAG timing envelopeは見つかっていない。公式DE0-CV resource pageへの今回の直接openはtimeoutし、新しいboard-specific資料は取得できなかった。

## 再現メモ

- Web query: `site:terasic.com DE0-CV USB Blaster TCK timing specification EPM240`; `site:altera.com DE0-CV onboard USB-Blaster JTAG timing`; `site:docs.terasic.com DE0-CV JTAG timing TCK TDI TDO`。検索結果に混在したcommunity/forum投稿は一次資料として採用していない。
- 開いた公式Alteraページは上記2件。URL、文書版、対象ケーブル、制約上の適用限界を本記録に固定。
- Terasic公式DE0-CV User Manual resource URLへの直接openはtimeoutし、新しいboard-specific資料は得られなかった。既存の保存manualレビューはそのまま参照し、今回再取得したとは扱わない。
- 保存SDC SHA-256: `ceaaa6708f0ed8f6d2c1443b60d9511c51d21f96ddaf914117ee6a65410c82eb`。
- SDC/QSF、Quartus project、FPGA、JTAG状態を変更していない。
- 外部照会は送信していない。
