# Fendt_Canbus
A canbus sniffer for Fendt tractors , SCR, S4 , ONE  (and possibly others brands)

Usage : tested with Arduino UNO with a MCP2515 board connected, no 120 ohm resistor.

The KBus can most easely be found in the infotainment module in the roof, if there is an normal
radio present this connector (A181) has a blue subconnecter where the KBus yellow and green wires are 
freely present. There is no separate KBus connector like in the older SCR/S4 models.

Put the .INO code on the arduino and plug it in. fire up the software on windows, choose the serial
port and hit 'connect' . All the unique CAN ID's will be filling up the box on the left. Just wait
at least a minute before the counter stops increasing, don't touch anything. 

When the counter is stopped, start manipulating the buttons you want to find. If the ID has not been
used (most likely) it will be added on the bottom of the checklist box. 

Start from the bottom, select the last ID and it will show the incoming data on that ID. Press the buttons
you want to find to see if any data comes in, if not, go your way up in the ID list.

If you would like to see improvements (which will be plenty, i know) , just let me know.

Bart De Reu
bartdereu@telenet.be


