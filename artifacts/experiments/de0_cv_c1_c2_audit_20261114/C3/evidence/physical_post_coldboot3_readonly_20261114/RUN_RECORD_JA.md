# Cold boot 3後のJTAG読み取り専用確認

* 日時: 2026-11-14 19:43 JST
* Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
* Branch/HEAD: `codex/stage-c3-jtag-pilot-20261114` / `cfa736657e4a03f1b621c93c7b5b26e7cd71adc9`
* CWD: `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114`
* Board power cycle 3/3: ユーザーが電源再投入と全LED消灯を確認。停止時間は独立計時していない。
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
* 電源投入後の構成ソースがSRAMか自動起動した不揮発構成かは、この照会だけでは判別できない。したがって「SRAMが電源断後に保持された」とも「Flash未変更」とも新たには判定しない。
* C3 candidate SOFは本確認で使用していない。新SOFのGate BはBLOCKEDのまま。
* 42ケース再実行は行っていない。既存の`C3_PRIMARY01_COLD_BOOT_REPLAY03_20261114`成果物を重複計上しない。
