# SOF設定記録 — 2026-11-26

- 操作者承認: `OPERATOR_AUTHORIZATION_RECORD.json` に記録した明示承認。
- 操作: Quartus Prime Programmer 25.1std.0 Build 1129、USB-Blaster、JTAG mode、指定 `.sof` のみをSRAMへ設定。
- 対象: DE0-CV / Cyclone V `5CEBA4F23C7`、JTAG IDCODE `02B050DD`。
- SOF: `build/quartus_external_attempt2/rtnn_c3_measurement_v2.sof`
- SOF SHA-256: `5e333e9377b7188a394d04b93b98833d91afb2cd53eca8d976e6aa715dfa00c4`
- Programmer記録上のchecksum: `0x0579C373`。
- 結果: `Configuration succeeded — 1 device(s) configured`; Quartus Programmer 0 errors / 0 warnings。
- 生ログ: `build/physical_preflight_20261126_attempt1/sof_sram_programming.log`。
- 操作範囲: SRAM configuration only. Flash/CFM、EPM240/CPLDは書き換えていない。
- read-only identity: Build ID `45585631`。これはSOF全bitのreadback証明ではなく、内部Build IDの一致確認。

同じSOFをRUN2–RUN4の間に再設定していない。電源断、KEY0 reset、配線・電圧・クロック変更も行っていない。
