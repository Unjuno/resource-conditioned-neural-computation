# PHYSICAL PREFLIGHT — 2026-11-26

## 判定

RUN4 の事前確認は `PREFLIGHT_ONLY`、20件、`physical_jtag_started=false` でPASS。実行前のread-only確認もDE0-CV、Build ID `45585631`、mailbox `READY` と一致しました。

- Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation`
- Branch/HEAD at start: `codex/external-validation-20261122` / `b8c7e0a54b545bf75591497adcfc6ff4aabbbbf3`
- Board: Terasic DE0-CV / Cyclone V 5CEBA4F23C7 / JTAG IDCODE `02B050DD`
- SOF SHA-256: `5e333e9377b7188a394d04b93b98833d91afb2cd53eca8d976e6aa715dfa00c4`
- ELF SHA-256: `4673f6a8b90493c15c327ed3be1167e0fcf3ff2be60292dcb12a1391124a0c2e`
- Model ID: `52544e4e`; Build ID: `45585631`; Binding ID: `45585632`
- Preregistration SHA-256: `5005c80c6d2d8eefbf87dd4dfdb4c91e26adb7960a3e5b1f04a977fdaee3b33b`
- Experiment/session: `C3_EXTVAL_PILOT_20261126_RUN4` / `BOARD_POWER_EPOCH_20261126_CURRENT`
- Frozen pilot cases: 10 input IDs × `{fixed2, adaptive}` = 20; primary inputs are disjoint.
- Transport sequence values: 2–21, to continue the existing FPGA firmware's strictly increasing sequence counter after earlier recorded failed attempts. Pixels, modes, labels, references and input ordering were preserved.
- Cases SHA-256: `fb37097914916ad41a18e9c13e476216f66335e91973aff6b333e62546529093`
- Binding SHA-256: `68a381e78cdcee2dc49e18f00914528290ec01d9b33bac5e1903681df436070e`

The operator authorization is stored separately in `OPERATOR_AUTHORIZATION_RECORD.json`. It covers SRAM configuration and the 20-case pilot only. No primary campaign was started.
