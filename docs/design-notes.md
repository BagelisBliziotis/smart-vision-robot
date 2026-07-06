# Chassis Design Notes — Bottom Plate v2

## Overview
Differential-drive base plate, designed parametrically in Fusion 360, printed in PETG on a Bambu Lab P1S.

## Dimensions
- Plate: 150 × 120 × 3 mm, R6 rounded corners
- Coordinates below are measured from the exported STL, origin at the plate corner (0, 0)

## Features (verified from the STL)

| Feature | Qty | Ø | Positions (X, Y) |
|---|---|---|---|
| Motor mount holes (zip-tie / M3) | 8 | 3.2 mm | Left: (5,30) (5,47) (25,30) (25,47) · Right: (125,30) (125,47) (145,30) (145,47) |
| Second-deck standoff holes (M3) | 4 | 3.5 mm | (20,15) (130,15) (20,105) (130,105) → 110 × 90 mm pattern |
| Caster mount holes | 2 | 4.2 mm | (55,100) (95,100) → 40 mm spacing |

Drive axle line ≈ Y 38.5 (rear) · caster at Y ≈ 100 (front) → wheelbase ≈ 61.5 mm.

## v1 → v2 changes
- v1 (140 × 200 mm) had misaligned motor holes and excess length. v2 resized to 150 × 120 mm and re-dimensioned from actual motor measurements.
- R6 corner fillets added; 4-hole standoff pattern added for a future second deck (Raspberry Pi + electronics).

## Mounting decisions
- TT motors sit on top of the plate, held by zip ties through the Ø3.2 holes. Watch item: if the ties loosen under vibration, switch to printed L-brackets (planned fallback).
- Ball caster bolts under the front. With the motors on top, the plate bottom sits ≈ 18–19 mm above ground (66 mm wheels, axle ≈ 11 mm above the plate), which matches the caster height — no riser needed.
- The full-size breadboard (165 × 55 mm) is intentionally NOT carried on the robot — it stays on the bench for prototyping. On-robot wiring uses direct jumpers; a mini breadboard will carry the ECHO voltage divider + IMU from the STM32 phase onward.

## Print settings
PETG · 0.2 mm layers · 3 walls · 25–30 % infill · printed flat, largest face down (no supports needed)

## Superseded by v3 — see below.

## Chassis v3 (Jul 6) — final layout for this build

v2 review caught a CG problem: the power bank bay sat behind the wheel
contact line, outside the support triangle, so the robot would tip
backward under load. v2 was superseded before use. v3 keeps the same
150 × 191 × 3 mm plate but fixes it with layout instead of hardware:

- Motor zip-tie grid (Ø3.2 ×8) moved to the rear — 30 mm and 47 mm from
  the rear edge, the identical relationship it had on v1
- Caster mount unchanged at the front (Ø4.2 ×2, 40 mm apart, 20 mm from
  the front edge)
- Standoffs (Ø3.5 ×4) at x = ±55, 15 mm from front and rear edges —
  second-deck rectangle is now 110 × 161 mm
- The inserted 70 mm of mid-plate becomes the power-bank bay, now inside
  the wheel–caster support span: estimated CG ~45–50 mm ahead of the
  axle, ~60/40 wheel/caster load split
- Keeps three-point contact — no rocking, no extra parts, tipping solved
  by rearrangement rather than a second caster
