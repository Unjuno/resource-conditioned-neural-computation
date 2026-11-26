# Status register bit decode correction

Earlier `read_only_identity_after_failure.log` used a display script that labelled status bit 6 (`0x40`) as `busy`. The RTL status vector is `{error, done, busy, pending, ready, 3'b000}`; therefore bit 7 is error, bit 6 is done, bit 5 is busy, bit 4 pending, bit 3 ready. Preserve the historical log unchanged, but do not interpret its `busy=1` label as the actual BUSY bit.

Corrected response-recovery logs report post-recovery `READY=1`, and the RUN4 pre-run and post-run read-only identity logs explicitly decode all fields. RUN4 began and ended with status `0x08`: READY=1, pending=0, busy=0, done=0, error=0.
