# Attempt 03 compiler outcome

The native mailbox phase matrix completed 19/19 conditions. The flat-mailbox compile stopped before simulation because `-Wall` treated `DECLFILENAME` as fatal: the extracted file was named `rtnn_c2_vjtag_mailbox_flat.v` while the module is `rtnn_c2_vjtag_mailbox`. No warning was suppressed. Attempt 04 writes the same verbatim extracted module to a matching filename in `flat/rtnn_c2_vjtag_mailbox.sv`, then compiles with the unchanged `-Wall` policy.
