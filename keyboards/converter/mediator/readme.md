Keyboard/Mouse QMK Converter Firmware
======================

This converter does not implement the ‘matrix scan’ in the same way that other keyboards do. It relies on an external controller to maintain a matrix of keystates and send the information. It also receives rotary encoder and mouse information from the external controller. The converter uses QMK to process the received information.

This can be useful if: 1) the attached keyboard does not implement QMK, 2) the attached mouse does not implement QMK, and/or 3) you want to use the mouse and keyboard as one QMK device.

## Setup connection between Raspberry Pi and Arduino

send keyboard and mouse data to microcontroller over SPI or I2C

## Setup connection between Arduino and host computer

setup microcontroller to send info to host

## Program to convert input to matrix info

pygame

5 x 24 matrix 120 keys
``Pseudocode
``

