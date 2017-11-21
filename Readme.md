# BLE Relay

Bluetooth low energy driven relays

# Hardware
* HM-10
* Arduino Nano
* 4 x Relay board

# Design options
- Delayed relay (with Ardunio)
- Straight relay (only HM-10)

# Main points
- BLE security
- Power study

# Related docs and projects
- https://drive.google.com/file/d/0B-M9mRnKKpvSbTBrOGlnNllMWFU/view
- ftp://imall.iteadstudio.com/Modules/IM130614001_Serial_Port_BLE_Module_Master_Slave_HM-10/DS_IM130614001_Serial_Port_BLE_Module_Master_Slave_HM-10.pdf
- https://medium.com/@enriqueramrezmanzaneda/controlling-a-digital-potentiometer-with-an-android-device-over-ble-using-arduino-1347547e375a
- https://github.com/nickswalker/ble-dev-kit/wiki/HM-10-Pinout


# Application serial protocol

## Request
Seconds;Relay stream output

For instance:
23;1001

First and last relay up for 23 seconds

## Answer
Senconds;Relay stream output
10;1001

Current relay status, and remain seconds to full stop.

