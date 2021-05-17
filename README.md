# MicroServoBot
Basic Implementation of Servo motors in automation
<ul>
<li>Download Arduino IDE from https://www.arduino.cc/en/software</li>
</ul>
<br>

![image](https://user-images.githubusercontent.com/56502015/116350433-9011e600-a80f-11eb-842e-66fe4a754afd.png)

<br>
<ul>
<li>Install Arduino IDE</li>
<li>Download/Clone this Repository in an accessible location</li>
</ul>
<br><br><br>

![image](https://user-images.githubusercontent.com/56502015/116349956-bc793280-a80e-11eb-9b92-45c79588817b.png)

## Libraries Required
1.Servo.h<br>

![image](https://user-images.githubusercontent.com/56502015/116350047-e3cfff80-a80e-11eb-9ec2-4b95c1a241eb.png)

(Install these libraries from this Repository)

## Installing libraries
You can either use the already pre-installed libraries of Arduino or you can find the libraries by searching them on Library Manager
Incase that didn't work I'm also providing the library files which you can isntall by following the below steps:
<ol>
  <li>After downloading the repository→Extract the library zip files</li>
  <li>Go to Sketch→Include library→Add .ZIP Library</li>
  <li>Select the the library.zip files</li>
  </ol>
  
![image](https://user-images.githubusercontent.com/64885833/81465777-25286300-91ea-11ea-97d5-b2a5463cd2d5.png) 

## Default Pin Configurations:
<ul>
  <li>A0 - Pot1</li>
  <li>A1 - Pot2</li>
  <li>A2 - Pot3</li>
  <li>2  - Push Button</li>
  <li>3  - Servo1</li>
  <li>5  - Servo2</li>
  <li>10 - Servo3</li>
</ul>
Here's the Schematic below:

![MicroServoBot](https://user-images.githubusercontent.com/56502015/116349816-7d4ae180-a80e-11eb-90ac-6faccd3d779b.png)

→Choose your port where you've plugged your Arduino UNO<br>
→Check if the baud rate is set to 9600 bps(for serial monitor)<br>
→Select the board to your desired Arduino(UNO for this project)<br>
→You can also Code/Upload Online using Online Code Editor(IDE) at https://create.arduino.cc/editor
![image](https://user-images.githubusercontent.com/56502015/116350574-c7809280-a80f-11eb-871b-a367dcbda26d.png)<br>
Here's a live demonstration:<br>
[![Micro Servo Bot](https://img.youtube.com/vi/86RMcUjELao/0.jpg)](https://www.youtube.com/watch?v=86RMcUjELao)
