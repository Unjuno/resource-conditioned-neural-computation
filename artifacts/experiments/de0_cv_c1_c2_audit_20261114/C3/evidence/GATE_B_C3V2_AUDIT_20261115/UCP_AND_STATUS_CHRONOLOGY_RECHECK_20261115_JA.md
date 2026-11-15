# Gate B 未制約I/O・status chronology 再照合

監査日: 2026-11-15 JST  
Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`  
Branch/HEAD: `codex/stage-c3-jtag-pilot-20261114` / `b332ba02ab992227140998a1d67513c690ae17cf`  
対象: C3 v2 build `43334531`、Cyclone V `5CEBA4F23C7N`  
分類: 保存RTL/QSF/SDC/TimeQuest/既存statusの静的照合。RTL・SDC変更、Quartus再実行、基板操作なし。

## 未制約端点の役割

| TimeQuest端点 | RTL/QSF上の役割 | timing disposition |
|---|---|---|
| `altera_reserved_tdi` / `altera_reserved_tms` | Cyclone V dedicated JTAG入力。保存STAではSLD/VJTAG hub等へ41 pathずつ入る。 | 外部USB-Blaster→FPGA timingを要する機能JTAG入力。board/controllerのTCK period/duty・launch edge・TDI/TMS min/max arrivalがなく未制約。B-SIGNOFF blockerとして維持。 |
| `altera_reserved_tdo` | Cyclone V dedicated JTAG出力。保存STAでは8出力path。ホスト側JTAG controllerが捕捉する信号。 | 外部TDO capture timingが必要。controller capture edge/setup/holdと基板経路が不明。B-SIGNOFF blockerとして維持。 |
| `LEDR[0]` (`PIN_AA2`) | top RTL `heartbeat_q[25]`。基板上LED表示。 | FPGA内部の同期機能データを外部同期受信器へ渡す経路ではない。外部setup/hold出力遅延はLED表示の目的からは定義しない。ただしTimeQuest UCP表示はそのまま残し、false pathを追加しない。Fitterの出力drive/slew警告も別途残す。 |
| `LEDR[1]` (`PIN_AA1`) | top RTL `response_commit`。基板上LED表示。 | 同上。LEDへの表示出力なので外部同期setup/hold関係なし。UCPとFitter電気属性警告は隠さない。 |
| `LEDR[3]` (`PIN_Y3`) | top RTL `bus_fault`。基板上LED表示。 | 同上。外部同期receiverなし。UCPとFitter電気属性警告は隠さない。 |

根拠はC3 v2 top RTLの`LEDR = {bus_fault, halted, response_commit, heartbeat_q[25]}`、QSFの上記pin assignment、保存TimeQuest UCPレポート、およびDE0-CV manual reviewにあるLEDをboard表示器として扱う記載。`LEDR[2]`は保存レポートでGND固定に関するwarningが別記され、UCP port一覧には含まれない。LEDの分類はJTAGポートの制約不足を解消せず、全I/O fully-constrainedとも主張しない。

## TCK modelと残る制約

SDC/TimeQuest上の`altera_reserved_tck` 33.333 nsはQuartus生成の30 MHz clock modelである。物理DE0-CV内蔵FT245BL/EPM240T100 USB-Blasterの実TCK、duty/high-low、startup/idle条件を測定または保証した値ではない。従ってTDI/TMSへの入力delayやTDOの出力delay値は推定で補わない。SDCのKEY[0] false-path例外と16 ns内部bundled-data screenを変更せず、TDI/TMS/TDOをfalse pathにも分類しない。

保存TimeQuest件数はsetup/holdそれぞれ、入力2 ports・41 paths、出力4 ports・8 paths。出力のうちLED 3本はタイミング上の受信先がなくJTAG TDOとは性質が異なる。一方、TDI/TMS/TDOの外部仕様不足は実質的なsignoff blockerであり、B-SIGNOFFはBLOCKEDのまま。

## 過去statusの読み分け

`TERASIC_USER_MANUAL_TIMING_REVIEW_20261114_JA.md`はHEAD `efe93a627c688a91b7c8ef9bd56e2d3e22d70124`時点の歴史記録で、当時のB-EMPIRICAL blockerに32-bit cycle responseとsource reproducibility課題を挙げる。その後のC3 v2 build `43334531`では64-bit start/end responseを実装し、wrap/zero-span等のhost rejection testと保存pilot監査を行ったため、**限定pilot適格性だけ**を`PASS_LIMITED`へ更新している。これはB-SIGNOFF、native 146-source graph再build可能性、正式なfirmware-source provenanceをPASSにした意味ではない。現在もnative 146-source graphは依存Ibex source/commit不足で`NOT_REPRODUCIBLE_YET`。旧manual-review文書は歴史証拠として変更せず、現行判定は`C3_CURRENT_STATUS_20261115_OFFLINE_REPRO_JA.md`を参照する。

## 入力ファイルSHA-256

| File | SHA-256 |
|---|---|
| `rtnn_de0_cv_c2_top.sv` | `c6d602e252f8e4f472cd79237f241becc9bdecb535d4ceba88d8bfbcecfe3265` |
| `rtnn_c3_measurement_v2.qsf` | `0d1f4e375c12526acab789112882defe903c2044009ea051ad4a2537eddbdebe` |
| `rtnn_c3_measurement_v2.sdc` | `ceaaa6708f0ed8f6d2c1443b60d9511c51d21f96ddaf914117ee6a65410c82eb` |
| `c3_v2_retry03_unconstrained_paths.rpt` | `d6b1ef57a80ae1bc6ec35d696775bde44e63445c05da0a325ea126fb303f6028` |
| `TERASIC_USER_MANUAL_TIMING_REVIEW_20261114_JA.md` | `ce371473b54ff6c280719e9a26bf04775ce3ddebc81b963fde01db6ecef23f66` |
| `C3_CURRENT_STATUS_20261115_JA.md` | `3b4f3d4709f98009b25365b5cea89e7861c1d2fc497799d9fb96eb9c434bae19` |

