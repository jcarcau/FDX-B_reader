<h1>FDX-B 134.2 kHz RFID reader</h1>

<p>
I used this cheap module from AliExpress for this project: https://web.archive.org/web/20200607232505/https://fr.aliexpress.com/item/33051835647.html
<br>
It works on a Raspberry Pi using the WiringPi library (http://wiringpi.com/).
<br>
Once you installed it and all the usual stuff to be able to compile C, type `make`.
<br>
You can now read 134.2 kHz tags using `./serial_rfid.sh <serial_port>`. Usually, the port is "/dev/ttyAMA0" if you plugged the reader directly on the Raspberry pins or "/dev/ttyUSB0" if you used a serial to USB converter like a CH340, a CP2102...</p>
