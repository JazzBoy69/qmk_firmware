Keyboard/Mouse QMK Converter Firmware
======================

These configuration files use a completely different 'matrix scan' system than other keyboards. This converter relies on an external controller to maintain a matrix of keystates. It also requests rotary encoder and mouse info from the external controller. This project allows QMK features to be used on the received matrix and mouse info.

This can be useful if:
    1) The attached keyboard does not implement QMK
    2) The attached mouse does not implement QMK 
    3) You want to use the mouse and keyboard as one QMK device

## First step

send keyboard and mouse data to microcontroller over SPI or I2C

## Next

setup microcontroller to send info to host