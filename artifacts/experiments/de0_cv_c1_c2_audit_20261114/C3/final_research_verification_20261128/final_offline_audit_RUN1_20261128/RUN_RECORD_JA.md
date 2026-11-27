# Offline final research verification run — 2026-11-28

Repository: `Unjuno/resource-conditioned-neural-computation`; branch `codex/external-validation-20261122`; HEAD `461c8b7393bec299736ebee28f82c1f1fdbaa7e2`.

Commands and results are captured verbatim in `validation.log`: manuscript Q15 table verification PASS (11/11 rows against RUN8); stopping comparison tests 5/5 PASS; exit-transition/counterexample tests 3/3 PASS; primary audit tests 14/14 PASS; primary analysis/readiness tests 2/2 PASS. Total unit tests: 24/24. All commands exited 0. These are offline artifact/validator checks and do not constitute new physical measurements.

No board, JTAG, SOF, power, KEY0, or wiring operation was performed. The external UCI primary remains `NOT_RUN`; population inference, independent cold boot, prior exposure, writer clustering, and formal timing statuses remain unchanged.

SHA-256 for `validation.log` and the authoritative scripts/results are listed in `SHA256SUMS_FINAL.txt`. A first manifest-helper attempt exited with an `AttributeError` before writing the manifest; it did not affect the checks, and the recovery is recorded in `manifest_helper_attempt.log`.
