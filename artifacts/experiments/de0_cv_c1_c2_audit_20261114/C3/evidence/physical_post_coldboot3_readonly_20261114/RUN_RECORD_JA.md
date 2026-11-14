# ユーザー確認の3回目DC電源サイクル後のJTAG読み取り専用確認

* 日時: 2026-11-14 19:43 JST
* Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
* Branch/HEAD: `codex/stage-c3-jtag-pilot-20261114` / `cfa736657e4a03f1b621c93c7b5b26e7cd71adc9`
* CWD: `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114`
* Board DC power cycle 3/3: ユーザーがDC電源再投入と全LED消灯を確認。停止時間は独立計時していない。指示に従いUSB-Blaster USB-Bは接続されたまま。
* 操作範囲: JTAG chain/nodeの読み取りだけ。SOF設定・Flash/CFM書込み・実験要求は行っていない。

## 実行

Quartus Prime Shell 25.1std.0 Build 1129 10/21/2025 SC Lite Edition。

```powershell
& 'C:\altera_lite\25.1std\quartus\bin64\quartus_sh.exe' --version
& 'C:\altera_lite\25.1std\quartus\bin64\jtagconfig.exe' -n
```

終了コードはそれぞれ0。Quartus起動時に`TBBmalloc: skip allocation functions replacement in ucrtbase.dll: unknown prologue for function _msize`という警告が出た。バージョン表示とJTAG照会は完了。

JTAG出力:

```text
1) USB-Blaster [USB-0]
  02B050DD   5CE(BA4|FA4)
    Design hash    DF2731CF973C3275CFE6
    + Node 00406E00  Virtual JTAG #0
```

## 判定と制約

* USB-BlasterとCyclone V IDCODE `02B050DD`を検出: **PASS**。
* Virtual JTAG nodeとdesign hash `DF2731CF973C3275CFE6`を読出し: **PASS**。
* Terasic公式System CDアーカイブにはDE0-CV System CDが掲載されている。同System CDのSheet 16電源回路図のコピーでは`VCC5_USB`が基板5V電源入力回路へ接続されている。従ってUSB-Bを接続したままDCアダプターだけを切った操作は、FPGA railの完全な電源断を単独では証明しない。基板のSW11経路を含む実際の電圧は本検査で測定していない。
* 直前の保存済み`cold_boot_replays/BOOT03_20261114/jtag_pre_program.log`にはdevice IDCODEだけがありnode/hashはない。一方、本読み取りでは同じpower-cycle報告後にnode/hashを検出した。どちらの状態変化が原因かは確定できない。電源断後の不揮発構成、USB/DC power path、SW11状態などの原因を特定していない。
* よってこの回および過去の3 replayを「3独立cold boot」と認定しない。runごとの測定値は有効なpower-session結果として保全するが、cold-boot独立性に関する解析解釈は**UNCERTAIN**。
* C3 candidate SOFは本確認で使用していない。新SOFのGate BはBLOCKEDのまま。
* 42ケース再実行は行っていない。既存の`C3_PRIMARY01_COLD_BOOT_REPLAY03_20261114`成果物を重複計上しない。

参照:

* [Terasic公式DE0-CV System CD archive](https://download.terasic.com/downloads/cd-rom/de0-cv/)（System CD ZIP内にboard schematicを収録）
* [Sheet 16 DE0-CV Power schematic mirror](https://edu.mmcs.sfedu.ru/pluginfile.php/20116/mod_folder/content/0/DE0-CV_v.1.2.1_SystemCD/Schematic/DE0-CV.pdf)（Terasic著作権表示あり。`5V Power from USB Port`, `VCC5_USB`を確認）
