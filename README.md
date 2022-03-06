# SPI-communication
The C-code of a master and slave that communicate over SPI.
The code was written in Atmel Studio and is supposed to demonstrate the functionality of the SPI communication.

# Master
- reads the state of a button
- Send the button state over SPI to the slave
- controls the SPI communication

# Slave
- controls an LED depending on the button state of the master
- Turns on the LED in case button is pressed
- Turns off the LED in case button is not pressed

Schematic:
![grafik](https://user-images.githubusercontent.com/75970114/156928800-558700fe-855b-4e23-88f7-b167ededae27.png)
