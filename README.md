# ESP32-custom
Created an ESP32Cam module based custom board with FT232H JTAG and 0.91" OLED display module. JTAG debugging is achieved using the following tutorials: https://medium.com/@manuel.bl/low-cost-esp32-in-circuit-debugging-dbbee39e508b

Pin map is as follows:
#  ESP32Cam - FT232H
	GPIO12 — AD1 (TDI)
	GPIO15 — AD2 (TDO)
	GPIO13 — AD0 (TCK)
	GPIO14 — AD3 (TMS)
	GND — GND	
	Vin - 5V

#  ESP32  - OLED
  GPIO2  — SDA
	GPIO14 — SCL
 	GND    — GND	
	3.3V   - Vcc

 GPIO4 is routed through jumper to DTR and Push Button on the board.
 On Board led is connected to Pin 0 via jumper
