# Nyancat
Nyancat PCB KiCad project: 

The footprints of this project had been modified.
- SW_SPDT_PCM12 removed mechanical pin
- LED_WS2812B_mini3535 larger pads than original footprint

BOM:
WS2812B-3535 x 7
ATTINY85 x 1
0.1uF 0805 cap x 1
slide switch smd x 4
jst-ph 2pin x 1

Arduino sketch:
Based on Adafruit's rainbow chaser.
Use J1 pads to program ATTINY with ICE programmer or Arduino ISP.
