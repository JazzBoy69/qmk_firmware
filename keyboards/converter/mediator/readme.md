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


## QMK 

``process_wheel``

``process_mouse``

``process_key``

``matrix_scan``


Using the custom driver will require implementing the following functions:

```
void           pointing_device_driver_init(void) {}
report_mouse_t pointing_device_driver_get_report(report_mouse_t mouse_report) { return mouse_report; }
uint16_t       pointing_device_driver_get_cpi(void) { return 0; }
void           pointing_device_driver_set_cpi(uint16_t cpi) {}

i2c_status_t i2c_receive(uint8_t address, uint8_t* data, uint16_t length, uint16_t timeout)
```
Receive multiple bytes from the selected SPI device.

Arguments

```uint8_t address``` The 7-bit I2C address of the device.

```uint8_t *data``` A pointer to the buffer to read into.

```uint16_t length``` The number of bytes to read. Take care not to overrun the length of data.

```uint16_t timeout``` The time in milliseconds to wait for a response from the target device.

Return Value I2C_STATUS_TIMEOUT if the timeout period elapses, I2C_STATUS_ERROR if some other error occurs, otherwise I2C_STATUS_SUCCESS.


	Send row/column info
	Read info in ``uint8_t matrix_scan(void)``
	Set matrix array
	Call matrix_scan_quantum();
```
    report_mouse_t currentReport = {};
	currentReport = pointing_device_get_report();
            //mouseReport.x = 127 max -127 min
   currentReport.x = (int8_t) uart_data[6];
            //mouseReport.y = 127 max -127 min
    	currentReport.y = (int8_t) uart_data[7];
            //mouseReport.v = 127 max -127 min (scroll vertical)
    	currentReport.v = (int8_t) uart_data[8];
            //mouseReport.h = 127 max -127 min (scroll horizontal)
    	currentReport.h = (int8_t) uart_data[9];

    	currentReport.x = 0;
        currentReport.y = 0;
    	currentReport.v = 0;
        currentReport.h = 0;

        pointing_device_set_report(currentReport);
```

