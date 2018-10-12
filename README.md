# Digithermo
Digital Thermometer
![PCB Front](/images/pcb_front.png)

# BOM

Qty | Parts              | Value    | Device          | Package      | Description      |Vendor       |
----|--------------------|----------|-----------------|--------------|------------------|-------------|
1   |B1                  |MB6S      |Rectifier        |SOIC-4        |Bridge Rectifier  |[AliExpress](https://www.aliexpress.com/item/-/32838702658.html?spm=a2g0s.8937460.0.0.4f812e0eONVXqt)
1   |C1                  |100µ/16V  |Elko             |SMD 6.3x5.4mm |e.g. EEEFT1C101AR |[AliExpress](https://www.aliexpress.com/item/-/32911815415.html?spm=a2g0s.8937460.0.0.4f812e0eONVXqt)
1   |C2                  |10µ/16V   |Elko             |SMD 5x4mm     |e.g. EEEFK1C100AR |[AliExpress](https://www.aliexpress.com/item/Free-shiping-20pcs-16V-10UF-SMD-4x5mm-chip-Aluminum-Electrolytic-Capacitor/1342839445.html?spm=a2g0s.8937460.0.0.4f812e0eONVXqt)
1   |C3                  |100n      |Capacitor        |0603          |
1   |IC1                 |MEGA8     |Microcontroller  |TQFP32        |Atmel ATmega8A-AU|[AliExpress](https://www.aliexpress.com/item/-/32883046023.html?spm=a2g0s.8937460.0.0.4f812e0eONVXqt)
1   |IC4                 |7805      |Voltage regulator|DPAK/TO252    |L78M05CDT        |[AliExpress](https://www.aliexpress.com/item/20pcs-lot-New-78M05-TO252-7805-750mA-L78M05CDT-Three-terminal-voltage-regulator-tube/32818562902.html?spm=a2g0s.8937460.0.0.4f812e0eONVXqt)
4   |Q1,Q2,Q3,Q4         |BC847     |Transistor       |SOT23         |NPN Transistor   |[AliExpress](https://www.aliexpress.com/item/100pcs-BC847C-BC847-SOT-23-NPN-smd-transistor/32364894157.html?spm=a2g0s.8937460.0.0.4f812e0eONVXqt)
7   |R1,R2,R3,R4,R5,R6,R7|220       |Resistor         |0603          |
1   |R8                  |390       |Resistor         |0603          |
5   |R9,R10,R11,R12,R13  |4,7k      |Resistor         |0603          |
1   |R14                 |10k       |Resistor         |0603          |
4   |U1,U2,U3,U4         |          |7-Segment Display|              |0,56", Common Cathode|[AliExpress](https://www.aliexpress.com/item/-/32876326696.html?spm=a2g0s.8937460.0.0.4f812e0eONVXqt)
1   |J1                  |          |3.5mm Audio Jack |SMD           |e.g. PJ-328          |[AliExpress](https://www.aliexpress.com/item/10PCS-3-5mm-Female-Audio-Connector-5-Pin-SMT-SMD-Headphone-Jack-Socket-PJ-328/32828776775.html?spm=a2g0s.8937460.0.0.4f812e0eONVXqt)
1   |                    |          |3.5mm Audio Plug |              |                     |[AliExpress](https://de.aliexpress.com/item/10Pcs-lot-Plastic-metal-3-5mm-Male-Plug-Jack-Adapter-dual-channel-Audio-Connector-Male-Jack/32890263251.html?spm=a2g0s.9042311.0.0.542c4c4dyi8zH7)
1   |J2                  |          |DC Jack 2.1mm    |              |                     |[AliExpress](https://www.aliexpress.com/item/-/32902679494.html?spm=a2g0s.8937460.0.0.4f812e0eONVXqt)
1   |                    |DS18b20   |Temperaturfühler |              |                     |[AliExpress](https://www.aliexpress.com/item/Stainless-steel-package-Waterproof-DS18b20-temperature-probe-temperature-sensor-18B20-For-Arduino/32236998050.html?spm=a2g0s.8937460.0.0.4f812e0eONVXqt)


# Schematic

![Schematic](/images/schematic.png)

# Anschlüsse Temperaturfühler

![Anschlüsse Temeperaturfühler](/images/DS18b20-cable.jpg)

Rot: VCC  
Schwarz: GND  
Gelb: DATA  


# Bilder

![Bild](/images/IMG_20181008_231634360.jpg)
