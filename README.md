The FatLight
======================================

What Is this?
-------------
Short: It's a controller board for RGB LED strips that has a bluetooth and some GPIO pins.

Long: I recently ordered everything needed for the creation of PCBs, i.e. a UV exposure unit,
an etching apparatus, chemicals, boards, the works. As a first project, I wanted to do something
that I could use, that I understood from the electronics perspective and that could easily be
done on a one-sided PCB without solder mask. A controller for RGB strips seemed to be a good idea, so here we go. :)

**WARNING IF YOU WANT TO BUILD THIS**
Make sure that the pinout of your Bluetooth module matches the pinout on the board. I have three different HC-05 modules in my parts bin, and every type has a different pinout ... This sucks enormously, and if I didn't have those modules lying around, I'd use a pure HC-05 module instead of the breakouts i have now.

![Image of the FatLight prototype](https://github.com/Zappes/avr-FatLight/blob/master/Doc/FatLight-Breadboard.jpg?raw=true)

How can I control it?
---------------------
It's simple. Connect to the FatLight using a serial terminal over the Bluetooth connection, connection parameters are 9600 8N1, no handshake. The modules have their default pin set to 1234, so use that pin. After connecting, the following commands are supported:

| Command    | Parameter | Description                           |
|------------|-----------|---------------------------------------|
| status     |           | Prints the current settings.          |
| mode       | 0-2       | 0: direct color, 1: fade, 2: random   |
| on         |           | Switches the light on                 | 
| off        |           | Switches the light off                |
| step       | 00-FF     | Size of the fading steps when fading  |
| set        | color     | Sets the target color in mode 0 and 1 |
| delay      | 00-FF     | Greater delays make slower fades      |
| level      | 00-FF     | Brightness in mode 2; 0 is random     |
| store      | 00-05     | Store current settings in slot 0-5    |
| load       | 00-05     | Load settings from slot 0-5           |   
| bt_getname |           | Prints the name of the BT module      |
| bt_setname | string    | Sets the name of the BT module        |
| bt_getpass |           | Prints the current BT PIN             |
| bt_setpass | string    | Sets the BT PIN; best use 4 digits    |

Color parameters are given as 24 bit hex codes, i.e. 00FF00 for green. Other numeric parameters are also in hex notation. String parameters may never contain whitespace.


Where can I learn more?
-----------------------
[There's a playlist on Youtube.](https://www.youtube.com/playlist?list=PLFFlJlvZ--Pn7IzDO5DFNhvppb0ZImLEq) It's in German, I'm afraid.

