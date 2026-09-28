---
title: "Multi-material Pliers"
excerpt: "A pair of multi-material 3D printed needle nose pliers." # TODO: one-sentence description (this is what shows on the Portfolio archive page)
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

### 2. Design and assembly check

The design has three parts: two handles and a TPU hinge. I designed each handle separately, then assembled them in CAD to check the motion. The jaws didn't close when the handles did, so before printing anything I moved the joint further up the handles until the jaw tips met when the handles closed.

### 3. Pivot iterations

The handles connect with a press-fit peg-in-hole joint. On my first print the peg fitted, but it was too thin and snapped easily, so I made both the peg and the hole larger to make the joint sturdier. I also designed the peg to be 2 mm longer than the other side of the joint.

### 4. Material and thickness changes

The first print was in PLA, which turned out to be too brittle for a part that flexes and takes load at the pivot. I reprinted in PETG, which is tougher and less likely to crack. I also reduced the thickness of the pliers from 1 cm to 0.6 cm.

### 5. Hinge iterations

My first hinge was a simple rectangle of TPU pressed between the handles. These print quickly, so I made several, but I wanted something more secure. I redesigned the hinge with circular ends that press-fit into matching slots in the handles, so there's something holding the hinge in place instead of relying on friction alone.

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
| Printer | Voron300 | Voron300 |
| Nozzle diameter | 0.6 mm | 0.6 mm |
| Nozzle temperature | 245 C | 240 C |
| Bed temperature | 80 C | 60 C |
| Layer height | 0.3 mm | 0.2 mm |
| Infill | 15% | 25% |
| Print speed | 80 mm/s| 35 mm/s |
| Supports | Everywhere | Everywhere |

## Pliers in action

<!-- TODO: add the GIF as assets/img/Pliers-Working.gif -->
![Pliers picking up resistor leads](/assets/img/Pliers-Working.gif)

## Gallery

{% include gallery caption="Iterations and final pliers" %}
