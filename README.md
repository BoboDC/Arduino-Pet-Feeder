# Arduino-Pet-Feeder


Description:
The project that will make feeding the dogs or any pet a matter of the past. Now with this build they will automatically get food even if there’s no one home, but only if the machine still powers.


Materials:
Arduino Board
Servo Motor
Breadboard
Wires
LCD Screen
RTC Module
4x4 Matrix Keyboard

The project diagram:

![image](https://user-images.githubusercontent.com/112874778/191435227-e51c2b24-999b-431c-a091-8de451e5713a.png)

How it works?
The human will fill the tube with the chosen food and then hit “#” on the keypad. After this on the screen it will appear “”HH:MM” which means the owner has to choose the hour and minutes where the machine to feed the pet. It will go when the internal real time clock hits the chosen timeline and the seconds to hit 40.


Schematics:

![image](https://user-images.githubusercontent.com/112874778/191435269-cb859f11-587f-420b-9e5c-c46b04185502.png)


Problems and future development
One of the biggest problems with the project right now is the keypad. It’s not working all the time when I press, it takes several tries or pressing more times on the buttons. An update I would like to do is to use plastic for the servo motor instead of cardboard and upgrade the entire structure to look good. 

