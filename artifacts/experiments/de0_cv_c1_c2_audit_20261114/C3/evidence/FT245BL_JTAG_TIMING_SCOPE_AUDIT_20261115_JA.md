# FT245BLデータシートとDE0-CV外部JTAG timingの適用範囲

監査日: 2026-11-15  
Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`  
対象: DE0-CV搭載USB-Blaster経路の外部timing証拠整理  
判定: **追加の部品仕様は確認したが、B-SIGNOFFを成立させるJTAG timing仕様ではない**

## 新たに確認した一次資料

FTDIの公式[FT245BL USB FIFO datasheet](https://ftdichip.com/wp-content/uploads/2020/08/DS_FT245BL.pdf)は、FT245BLの8-bit FIFO parallel bus timingを規定している。例として、read cycleではRD# activeからdata validまで20–50 ns（30 pF負荷条件）、RD# inactiveからvalid-data holdはminimum 0 ns、write cycleではdata setup before WR# inactive minimum 20 ns、data hold after WR# inactive minimum 0 nsと記載される（datasheet Table「FT245BL Timing Diagram – FIFO Read/Write Cycle」）。

この部品はDE0-CV配布回路図でUSB-Blaster経路上のUSB FIFOとして記録されている。しかし、これらの値は**FT245BL parallel FIFO busと同チップ信号のタイミング**であり、FPGA側JTAG端点のTCK周期/duty、TDI/TMS launch edgeとTCK相対skew、TDO capture/setup/holdを直接規定しない。

## 経路上の境界

```text
PC / USB transfers
      │  USB transaction / FT245 FIFO behavior
      ▼
FT245BL 8-bit FIFO bus  ── T3/T9等のIC timingはdatasheetに存在
      │
      ▼
MAX II EPM240 controller logic  ── board-specific RTL/fit or pin-level timing model未確認
      │  TCK/TDI/TMS output phase, duty, relative skew
      ▼
DE0-CV board traces / connectors
      │  revision-specific route/loads未確認
      ▼
Cyclone V TAP pins  ── FPGA endpoint constraints/data sheetとは別のboard-input timing boundary
```

FT245BLのFIFO clockingやparallel-bus pulse widthから、EPM240が生成するTCKの周波数・dutyやTDI/TMSとのrelative delayは一意に決まらない。EPM240のロジック実装・実際のspeed grade・routing情報もこの部品datasheet単独には含まれない。したがって、FIFO timing値をTCK `create_clock`、JTAG input/output delay、false path、uncertainty値に流用する根拠はない。

## Gateへの影響

* B-SIGNOFF: **BLOCKED_EXTERNAL_BOARD_TIMINGを維持**。この資料は既知のboard-level gapを埋めない。
* B-EMPIRICAL: 変更なし。保存済みbuild・boardに限定した既存`PASS_LIMITED`をformal signoffへ格上げしない。
* Quartus SDC/QSF/RTL: 変更なし。推測値、追加false path、制約緩和は入れていない。
* 次に必要な根拠: DE0-CV該当revisionのオンボードUSB-Blaster/TAP信号のTCK波形とTDI/TMS/TDO relative timing仕様、EPM240 fitted timing情報を含むメーカー回答、または適切な帯域・閾値での基板上測定と再現可能な解析。

Terasic向けの仕様照会案は既存の未送信文書に保持する。問い合わせは送信していない。FTDI datasheetは新規の部品レベル根拠として記録したが、board-specific controller behaviorの再調査や同一System CD ZIPの再走査は行っていない。
