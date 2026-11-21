# RTNN external-input protocol v1

This is a new protocol/build family. It is not wire-compatible with the frozen
C3 v2 ROM-input campaign. Physical operation is not authorized by this file.

## Identity and scope

| Field | Value |
|---|---:|
| model ID | `0x52544e4e` |
| build ID | `0x45585631` |
| binding ID | `0x45585632` |
| request version / size | 2 / 100 bytes (800 bits) |
| response version / size | 3 / 60 bytes (480 bits) |
| pixel count/range | 64 unsigned bytes / 0–16 |
| allowed modes | fixed Exit 2; adaptive, budget 65535, deadline 0 |
| cycle source | Ibex 64-bit `mcycle`, sampled immediately before/after Q15 call |

## Request layout (little endian)

Bytes 0–31: `RTNQ`, version, mode, fixed exit, reserved zero, sequence (u32),
input ID (u16), budget (u16), deadline cycles (u32), model ID (u32), build ID
(u32), CRC32 over bytes 0–27 (u32). Bytes 32–95 are the actual 64 pixel values.
Bytes 96–99 are CRC32 over the pixel payload. The reference/teacher label is
never serialized. The input ID identifies the manifest row and does not select
a ROM image.

## Response layout

Bytes 0–23: `RTNR`, version, status, echoed mode, stop reason, sequence (u32),
input ID (u16), budget (u16), echoed payload CRC32 (u32), admitted Exit (i8),
executed Exit (i8), prediction (i8), label sentinel `-1` (i8). Bytes 24–39 are
64-bit cycle start and end. Bytes 40–55 are model/build/binding IDs and flags;
bytes 56–59 are CRC32 over bytes 0–55.

Success requires exact identity/sequence/input/mode/budget/payload CRC, label
sentinel -1, prediction 0–9, valid nonzero increasing counter, valid response
CRC, and the expected admitted/executed Exit. Any error is retained as a failed
row; the host stops immediately. Sequence numbers strictly increase within a
boot/session. Replays use a new experiment ID and sequence space.

## Mailbox and measurement boundary

The existing 800-bit request/480-bit response mailbox widths are unchanged.
Firmware snapshots all request words into local memory before request ACK,
then validates header and payload CRC/range and passes the snapshot pixel array
directly to the frozen Q15 core. Result words are written before response
commit. No JTAG transfer or host wait occurs between the two `mcycle` samples.
This does not establish external USB-Blaster/JTAG timing signoff or a WCET bound.

## Fixed limits

The firmware accepts IDs 1–3823, budget 65535, deadline 0 and exactly the two
registered modes. Inputs are separate from labels. Model source/weight hashes
are captured in the build manifest. This is not a claim that any SOF has been
built, timed, programmed, or exercised physically.
