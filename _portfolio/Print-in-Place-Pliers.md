---
title: "Print-in-Place Pliers"
excerpt: "" # TODO: one-sentence description (this is what shows on the Portfolio archive page)
header:
  image: /assets/img/Pliers-Banner.jpg
  teaser: /assets/img/Pliers-Banner.jpg
gallery:
  - url: /assets/img/Pliers-Iteration-1.jpg
    image_path: assets/img/Pliers-Iteration-1.jpg
    alt: "Pliers iteration 1"
  - url: /assets/img/Pliers-Iteration-2.jpg
    image_path: assets/img/Pliers-Iteration-2.jpg
    alt: "Pliers iteration 2"
  - url: /assets/img/Pliers-Iteration-3.jpg
    image_path: assets/img/Pliers-Iteration-3.jpg
    alt: "Pliers iteration 3"
  - url: /assets/img/Pliers-Final.jpg
    image_path: assets/img/Pliers-Final.jpg
    alt: "Final print-in-place pliers"
---

## What is print-in-place?

Print-in-place is a 3D printing technique that produces a design with multiple components, including moving or interlocking parts, in one continuous print job, with no assembly or post-processing afterwards. The connected parts are oriented and spaced with clearances that allow motion or rotation between them.

To avoid brittle joints, print-in-place works well when it combines a rigid and a flexible material, for example PETG and TPU.

## Print-in-place in the wild

### [Print-in-Place Spring-Loaded Box (Instructables)](https://www.instructables.com/Print-in-Place-Spring-Loaded-Box/)

<!-- TODO: add thumbnail as assets/img/PIP-Instructables-TH.jpg -->
<a href="https://www.instructables.com/Print-in-Place-Spring-Loaded-Box/"><img src="/assets/img/PIP-Instructables-TH.jpg" alt="Print-in-place spring-loaded box on Instructables" style="width:250px;"/></a>

A 12-step tutorial by SunShine on designing print-in-place parts for FDM printers in Fusion 360, using a spring-loaded box as the worked example. As well as walking through the box itself, it shares practical tricks for getting moving parts to come off the printer actually working. It was useful as a reference because it uses the same CAD software I used for my pliers.

### [Print-in-Place: The Additive Holy Grail (Make:)](https://makezine.com/article/digital-fabrication/3d-printing-workshop/print-in-place-the-additive-holy-grail/)

<!-- TODO: add thumbnail as assets/img/PIP-Make-TH.jpg -->
<a href="https://makezine.com/article/digital-fabrication/3d-printing-workshop/print-in-place-the-additive-holy-grail/"><img src="/assets/img/PIP-Make-TH.jpg" alt="Print-in-place article on Make:" style="width:250px;"/></a>

A 2014 article by Kacie Hultgren on why print-in-place designs are such a demanding test of a 3D printer. Using Samuel N. Bernier's articulated robot as an example, where the gaps between limb parts are only just over 0.3 mm, she explains that success depends less on layer height and more on the slicer and how well the printer handles bridges, overhangs and accurate dimensions. Because there's no design standard, designers usually find the right tolerances through trial and error on their own printer, which is the same process I went through with my pin diameters. The article finishes with troubleshooting tips, such as adjusting the Z-offset so the first layer doesn't fuse joints and making small test prints before a long print.

## CAD model

<div style="position: relative; padding-bottom: 56.25%; height: 0; overflow: hidden;">
  <iframe src="https://a360.co/47r14F6" style="position: absolute; top: 0; left: 0; width: 100%; height: 100%; border: 0;" allowfullscreen></iframe>
</div>

[View the model in Fusion 360](https://a360.co/47r14F6)

## Design and iterative process

### 1. Purpose

The pliers are designed to pick up as many resistor leads as possible in one minute. Needle-nose pliers have fine tips that give good control when picking up, holding and moving small parts, which makes them well suited to moving resistor leads quickly and accurately.

### 2. Pivot design

The design has three parts: two handles and a spring. I used a press-fit pin-in-hole joint to connect the handles and printed iterations with pin diameters from 1 mm to 3 mm. The best diameter was the one that let the pin go in while still leaving enough clearance for the jaws to move freely. I made the pin slightly longer than the handle thickness so it had enough length in the hole to stay seated without wobbling. The pivot was designed so the two arms sit directly on top of each other without colliding.

### 3. Spring and hinge iterations

My first idea for the spring was an angled slot, where the TPU piece would sit at an angle between the handles and bend as they closed. I moved to a compression-loaded notch instead, where the TPU insert sits in a notch on each handle and gets squeezed as the handles close. The compression approach worked better because the TPU stays held in place by the notches rather than relying on the slot to stop it slipping out, and it pushes the handles back open more consistently each time.

### 4. Tolerance testing

I tested the fit between the pivot and the hole by printing versions with an interference of 0 to 3 mm. At 3 mm the pin was too loose and the jaws fell apart, and with no space, it was too tight to move. I landed on 2 mm, which held the TPU insert securely without making the handles stiff to close.

### 5. What went wrong and got fixed

In the assembly motion test, the jaw tips didn't meet when the handles were fully closed. The problem was the position of the pivot, the ratio between the jaw offset and the jaw length meant the jaws needed more rotation to close than the handles could give before they hit each other. Moving the pivot changed that ratio so the tips met fully when the handles closed.

## Specifications

| Spec | Value |
|------|-------|
| Jaw length (pivot to tip) | 20 mm |
| Jaw capacity (max opening at tip) | 11 mm |
| Overall length | 105 mm |
| Handle spread at full open | 52 mm |
| Pivot interference (boss vs. hole) | TODO mm |
| Hinge insert dimensions | TODO (L × W × H) mm |
| Rigid material | PETG |
| Flexible material | TPU (90A) |

## Print settings

<!-- TODO: fill in every TODO cell, and add or remove rows to match your slicer -->

| Setting | PETG (rigid parts) | TPU 90A (flexible insert) |
|---------|--------------------|---------------------------|
| Printer | TODO | TODO |
| Nozzle diameter | TODO | TODO |
| Nozzle temperature | TODO | TODO |
| Bed temperature | TODO | TODO |
| Layer height | TODO | TODO |
| Infill | TODO | TODO |
| Print speed | TODO | TODO |
| Supports | TODO | TODO |

## Pliers in action

<!-- TODO: add the GIF as assets/img/Pliers-Working.gif -->
![Pliers picking up resistor leads](/assets/img/Pliers-Working.gif)

## Gallery

{% include gallery caption="Iterations and final pliers" %}
