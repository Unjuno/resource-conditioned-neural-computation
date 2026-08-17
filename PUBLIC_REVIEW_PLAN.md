# Public review plan

## Purpose

Use GitHub as a short falsification and reproduction window before any arXiv submission.

## Proposed dates

- Public repository release: 2026-08-17 (or the actual publication date if later)
- Initial review window: 14 days
- Earliest arXiv decision point if released on 2026-08-17: 2026-08-31

If repository publication occurs later, shift the decision date so that a full 14-day public window remains.

## Do not expand the claim during the review window

The repository should remain a mechanism/reproduction package. Do not add scaling experiments merely to strengthen presentation.

## Evidence that should block or delay arXiv submission

- A materially identical prior method establishing the same narrow mechanism claim.
- A clean reproduction failure that cannot be explained by environment/timing variation.
- A confound showing that interventions on the resource-price input do not actually control routing.
- A stronger matched baseline that removes the claimed within-safe-set resource advantage.
- A calibration or data leakage issue affecting the core result.

## Evidence that should not automatically block submission

- Requests to scale to larger models or LLMs.
- The observation that this is not hard real-time/WCET work; that limitation is already explicit.
- Different absolute latency measurements on other machines, provided the mechanism reproduces.
- Suggestions for future energy/Joule measurements.

## Decision after 14 days

If there is no unresolved core objection, freeze a Git commit/tag and use that exact revision as the reproducibility reference for the arXiv technical note.
