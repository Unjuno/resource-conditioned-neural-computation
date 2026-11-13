# DE0-CV LED判定の根拠

- TerasicのDE0-CV User Manual 1.1.2（§3.2、図3-8、表3-4）は、LEDRのFPGA出力がHighなら点灯、Lowなら消灯と記載する。表3-4ではLEDR0=AA2、LEDR1=AA1、LEDR2=W2、LEDR3=Y3。
- ボード資源の公式ページ: https://www.terasic.com.tw/cgi-bin/page/archive.pl?CategoryNo=13&Language=English&No=921&PartNo=4 （同ページがDE0-CV User Manual 1.1.2を掲載）
- 読みやすい直接PDFコピー: https://mm.digikey.com/Volume0/opasdata/d220001/medias/docus/5740/DE0_CV_User_Manual_112.pdf
- 今回のRTLは `assign LEDR={pass_q,fail_q,case_q[1:0]};`。従ってPASS=LEDR[3:0] `1000`、FAIL bitはLEDR[2]。LEDR3がHIGHのとき物理LEDの「LEDR3」表示位置が点灯する。
- 7-segment HEX表示やJTAG/USB-Blasterの青い状態LEDとは別の表示。