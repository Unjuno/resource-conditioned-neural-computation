# Gate B — 公開System CD・Internet Archive調査と代替経路

確認日: 2026-11-15 JST  
対象repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`  
対象board: Terasic DE0-CV、既存オンボードUSB-Blaster経路  
分類: 公開配布物の読み取り調査。基板、Quartus project、JTAG、Flashは操作していない。

## 公開物を確認した結果

Terasicの現行配布一覧には`DE0-CV_v.1.2.1_SystemCD.zip`（表示サイズ63.8M、2018-01-25）と`DE0CV_ControlPanel_V101.zip`が掲載されている。2025-01-17のInternet ArchiveディレクトリsnapshotにもSystem CD ZIPへのリンクが残っている。しかしWayback CDXのexact ZIP URL検索結果は空で、ZIP本体のarchive snapshotは確認できなかった。ZIP自体はTerasicの現行配布元から取得できた。

取得・検査記録:

* Official index: <https://download.terasic.com/downloads/cd-rom/de0-cv/>
* Official System CD ZIP: <https://download.terasic.com/downloads/cd-rom/de0-cv/DE0-CV_v.1.2.1_SystemCD.zip>
* Wayback directory snapshot: <https://web.archive.org/web/20250117214719/http://download.terasic.com/downloads/cd-rom/de0-cv/>
* Wayback exact-file CDX query: <https://web.archive.org/cdx/search/cdx?url=download.terasic.com%2Fdownloads%2Fcd-rom%2Fde0-cv%2FDE0-CV_v.1.2.1_SystemCD.zip&output=json> — response `[]`。
* Archive filename: `%TEMP%\RTNN_DE0CV_SystemCD_inspection_20261115.zip`（検査後の展開・repositoryへのコピーなし）。Size 66,908,883 bytes、SHA-256 `ed4ac9cf4ae3d6ce27e6f2e66d42745b0a55fc2cc883b07069363d9947db942e`。
* Read-only listing: `tar -tf`; exit 0、1,089 entries。

ZIPに`Manual/DE0_CV_User_Manual.pdf`、`Schematic/DE0-CV.pdf`、Cyclone V datasheet/handbook、FPGA demonstration project/source/bitstream、`Tools/ControlPanel/DE0CV_ControlPanel.exe`およびTerasic JTAG DLLがある。1,089 entry名を検索した範囲では、USB-Blaster EPM240用の独立したCPLD RTL/project/sourceまたはboard-specific JTAG timing specificationは見つからなかった。これはZIP内の公開ファイル名・構成の調査結果であり、Terasic社内資料や別revisionの資料が存在しない証明ではない。

DE0-CV資料からUSB-Blasterの構成・接続は分かるが、現在必要な内蔵コントローラ出力のTCK period/duty/startup、TDI/TMS launch edgeとCyclone V端子での相対min/max arrival、TDO capture edge/setup/holdを埋める値は確認できていない。USB-Blaster IIIの公開timing tableは外付けCableの仕様であり、内蔵FT245BL/EPM240経路へは転用できない。

## 進める方法

1. **Terasicにrevision-specific timingを問い合わせる。** PCB revision、EPM240型番/speed gradeを添えてTCK周期/duty/startup、TDI/TMS launchと相対min/max、TDO capture/setup/hold、電圧・温度範囲、推奨SDCまたは同等仕様を要求する。問い合わせ文案は既存の未送信文書を使用できる。送信はユーザー承認が必要。
2. **対象基板を測定器でcharacterizeする。** 校正済み高速oscilloscopeと低容量probe等で、Cyclone V側にできるだけ近いJTAG各信号の波形・相対遅延を取り、測定帯域、probe loading、校正、uncertaintyを記録する。仕様温度・電圧範囲全体をカバーできなければ、その範囲の保証はしない。JTAG test pointがなくBGA/CPLD端子への追加配線が必要なら、基板改造やはんだ付けをせず、適切なfixture/専門測定が可能か先に検討する。
3. **測定を用意できない間は経験値として進める。** 現在の`B-EMPIRICAL=PASS_LIMITED`範囲で、既存build・boardに限定した測定を行うことはできる。成功回数は外部setup/holdやPVT保証に換算しない。`B-SIGNOFF`はBLOCKEDのまま、結果は`EMPIRICAL_ONLY`と報告する。
4. **将来、タイミング資料を得やすいtransportへ変更する。** 別の明示仕様付きprogrammer/controllerへ置き換える案はあるが、DE0-CVの接続・adapter対応、追加hardware、別FPGA buildと再検証が必要。今回の無改造・追加hardwareなしの前提には含まれない。

## 現在の判定

* 公開済み資料を調べる方法は残っているが、System CDとInternet Archiveの確認ではrequired onboard JTAG timing valuesは得られなかった。
* 正式signoffを確立する手段は、メーカー提供の適用可能な仕様、または適切に校正・範囲設定された実機characterization。
* 適切な測定器、アクセス可能なsignal pickup、メーカー仕様のいずれもない状態では、正式timing保証を主張できない。RTL regressionや42/24,840件の機能成功はこの欠落を埋めない。
* B-SIGNOFFは`BLOCKED_EXTERNAL_BOARD_TIMING_AND_UNCONSTRAINED_IO`、B-EMPIRICALは既存対象範囲に限った`PASS_LIMITED`を維持する。

## 再現コマンド

PowerShell:

```powershell
$url = 'https://download.terasic.com/downloads/cd-rom/de0-cv/DE0-CV_v.1.2.1_SystemCD.zip'
Invoke-WebRequest -Uri $url -OutFile "$env:TEMP\RTNN_DE0CV_SystemCD_inspection_20261115.zip"
Get-FileHash "$env:TEMP\RTNN_DE0CV_SystemCD_inspection_20261115.zip" -Algorithm SHA256
tar -tf "$env:TEMP\RTNN_DE0CV_SystemCD_inspection_20261115.zip"
```
