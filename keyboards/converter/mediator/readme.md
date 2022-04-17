Keyboard/Mouse QMK Converter Firmware
======================

These configuration files does not implement the ‘matrix scan’ in the same way that other keyboards do. This converter relies on an external controller to maintain a matrix of keystates and receives the matrix state from the external controller. It also requests rotary encoder and mouse info from the external controller. This project allows QMK features to be used on the received matrix and mouse info.

This can be useful if: 1) the attached keyboard does not implement QMK, 2) the attached mouse does not implement QMK, and/or 3) you want to use the mouse and keyboard as one QMK device.

## Setup connection between Raspberry Pi and Arduino

send keyboard and mouse data to microcontroller over SPI or I2C

## Setup connection between Arduino and host computer

setup microcontroller to send info to host

## Program to convert input to matrix info

``Pseudocode
``

