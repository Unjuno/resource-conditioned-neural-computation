#!/usr/bin/env bash
set -euo pipefail
cd /mnt/d/rtnn_c2_cdc_2ff_bus_20261113_capture_delay_sv2v
sv2v --version > sv2v.version
sv2v -D "RTNN_C2_BUILD_ID=32'h43324a32" rtnn_c2_vjtag_mailbox.sv > rtnn_c2_vjtag_mailbox.v 2> sv2v_mailbox.log
