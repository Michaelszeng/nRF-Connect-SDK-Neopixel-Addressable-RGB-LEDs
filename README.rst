nRF-Connect-SDK-Neopixel-Addressable-RGB-LEDs
###########

Overview
********

A simple sample and library that enables use of neopixels or any RGB Addressible LED that has similar nano-second timing specifications, with Nordic Semi SoCs.

This library is configured for just two LEDs. However, it should be simple to adapt this library to your own use.

Note: technically, the timing of NOP commands, which are used in neopixel.c, are non-deterministic on ARM processors; but this still seems to work. 
