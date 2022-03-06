# SPI-communication
The C-code of a master and slave that communicate over SPI.

# Master
- reads the state of a button
- Send the button state over SPI to the slave
- controls the SPI communication

# Slave
- controls an LED depending on the button state of the master
- Turns on the LED in case button is pressed
- Turns off the LED in case button is not pressed

The code was written in Atmel Studio and is supposed to demonstrate the functionality of the SPI. It can be integrated in bigger projects.

Schematic follows.
