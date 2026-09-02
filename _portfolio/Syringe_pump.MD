---
title: "Syringe Pump"
excerpt: "" # TODO: 1-2 sentence purpose/feature summary, in your own words
header:
  image: /assets/img/Syringe-Pump-Banner.jpg
  teaser: /assets/img/Syringe-Pump-TH.jpg
gallery:
  - url: /assets/img/Syringe-Pump-1.jpg
    image_path: assets/img/Syringe-Pump-1.jpg
    alt: "Syringe pump — front view"
---

<!-- TODO: Purpose & features paragraph, in your own words -->


## Materials List

### Off-the-shelf parts

| Part | Qty | Source / Notes |
|------|-----|-----------------|
| 250 mm lead screw, 2 mm pitch, 8 mm lead | 1 | Course-supplied |
| 1/4" x 8mm flexible coupling | 1 | Course-supplied |
| 200 mm linear rod, 8 mm diameter | 2 | Course-supplied |
| LM8UU linear bearing (8 mm rod) | 2 | Course-supplied; press-fit into carriage |
| 2040 aluminum extrusion, 1 ft length | 1 | Course-supplied |
| NEMA 17 stepper motor | 1 | Course-supplied |
| MEAN WELL RQ-65D AC-DC power supply | 1 | Course-supplied |
| Arduino Uno | 1 | Course-supplied |
| A4988 stepper driver | 1 | Course-supplied |
| Small breadboard | 1 | Course-supplied |
| Panel mount latching push button | 1 | Start/pause control |
| Limit switch | 1 | Detects empty/end-of-travel |
| RGB common cathode LED | 1 | Group-supplied; status indicator |

### 3D printed parts

| Part | Qty | Material |
|------|-----|----------|
| Carriage | 1 | PLA |
| Syringe holder | 1 | PLA |
| End support | 2 | PLA |
| Front support (rail) | 1 | PLA |
| Side bracket (holds button) | 1 | PLA |
| Motor mounting plate | 1 | ABS (heat tolerance near stepper motor) |
| Electronics housing — base | 1 | PLA |
| Electronics housing — lid | 1 | PLA |
| Electronics housing — front panel | 1 | PLA |

## Code

[View the Arduino code](https://github.com/isabel-thorburn-chen/isabel-thorburn-chen.github.io/blob/main/_portfolio/syringe_pump.ino)

## CAD Model

<!-- Fusion 360 → Share → Embed → paste the iframe src below -->
<div style="position: relative; padding-bottom: 56.25%; height: 0; overflow: hidden;">
  <iframe src="" style="position: absolute; top: 0; left: 0; width: 100%; height: 100%; border: 0;" allowfullscreen></iframe>
</div>

## Operation

1. Make sure all components are unplugged and nothing is wet.
2. Check that all users are wearing proper PPE before operation.
3. Plug the laptop into the Arduino through the hole on the side of the syringe pump.
4. Flash the Arduino with the program updated to the desired flow rate and syringe size.
5. Once the Arduino is programmed, unplug the USB cable and plug in the power outlet cable.
6. Check that the limit switch is secured along the rail so the pump will stop at the desired length.
7. If the LED is not yellow, press the Start button so it is.
8. Use the Forward and Backward buttons to adjust the syringe holders to securely fit your filled syringe.
9. Once the syringe is fitted, press the Start button to begin the specified flow.

{% include gallery caption="Syringe pump — DF-2100 project, documented for ChBE 4200." %}
