# Terasic DE0-CV User Manual timing-source review

Review date: 2026-11-14 JST
Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
Branch at review: `codex/stage-c3-jtag-pilot-20261114`
HEAD at review: `efe93a627c688a91b7c8ef9bd56e2d3e22d70124`

## Source checked

Terasic's DE0-CV resource page lists **DE0-CV User Manual v1.1.2**, dated 2015-05-08. The manual's configuration and Control Panel material was checked for board-level JTAG timing, TCK rate/duty, TDI/TMS launch timing, TDO capture timing, and a recommended external JTAG SDC. Those reviewed sections describe board configuration and the host/control-panel path, but do not provide the missing board/cable timing envelope or a revision-specific JTAG timing constraint set.

The manual describes the on-board USB-Blaster path as part of the DE0-CV configuration flow and the Control Panel's FPGA-side design/host communication. This is useful architecture/procedure context; it does not reveal the onboard controller's external setup/hold budget or measured TCK/capture waveform.

Official source listing: [Terasic DE0-CV resources](https://www.terasic.com.tw/cgi-bin/page/archive.pl?CategoryNo=163&Language=English&No=921&PartNo=4). It identifies User Manual v1.1.2 and the separate System CD v1.2.1 / ControlPanel v1.0.1 packages. The current official download index lists the same System CD and ControlPanel packages: [Terasic DE0-CV download index](https://download.terasic.com/downloads/cd-rom/de0-cv/).

## Gate effect

- This newly checked board manual does not close the external JTAG timing gap.
- **B-SIGNOFF remains BLOCKED**. Do not use this manual as evidence of measured TCK, external path delays, TDO capture window, or full-board timing signoff.
- The manual review does not change **B-EMPIRICAL** eligibility. That gate remains blocked by the separately documented cycle-counter observability and reproducible firmware-source issues.
- No source archive was re-downloaded or re-inventoried; the existing System CD audit is preserved. No board/JTAG operation, SOF programming, Flash/CFM operation, or Terasic inquiry was performed.

## Scope and limits

This is a targeted review of the manual's configuration and Control Panel material, not a claim that every page or every board revision was exhaustively searched. The official resource page identifies the manual version/date, but does not expose a revision-specific external timing specification. If Terasic supplies a newer or board-revision-specific timing document, audit it as a new source and preserve this record unchanged.
