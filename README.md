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
(Without I2C)<br>
1.Servo.h<br>
(With I2C)<br>
1.Wire.h<br>
2.Adafruit_PWMServoDriver.h<br>


![image](https://user-images.githubusercontent.com/56502015/116350047-e3cfff80-a80e-11eb-9ec2-4b95c1a241eb.png)

![image](https://user-images.githubusercontent.com/56502015/122336819-08b53900-cf5b-11eb-80b0-71f960a95d7d.png)

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
  <li>A3 - Pot4</li>
  <li>A4 - SDA(for I2C)</li>
  <li>A5 - SCL(for I2C)</li>
  <li>2  - Push Button(Attach Interrupt)</li>
  <li>3  - Servo1</li>
  <li>5  - Servo2</li>
  <li>10 - Servo3</li>
  <li>PCA9685: 3 to 16 pins available for Servos</li> 
</ul>
Here's the Schematic below:<br>
Without I2C:<br>

![MicroServoBot](https://user-images.githubusercontent.com/56502015/116349816-7d4ae180-a80e-11eb-90ac-6faccd3d779b.png)

<br>With I2C(Servo Driver):<br>

![Schematic_bb](https://user-images.githubusercontent.com/56502015/122335153-74e26d80-cf58-11eb-9775-e5645e249a27.png)


→Choose your port where you've plugged your Arduino UNO<br>
→Check if the baud rate is set to 9600 bps(for serial monitor)<br>
→Select the board to your desired Arduino(UNO for this project)<br>
→You can also Code/Upload Online using Online Code Editor(IDE) at https://create.arduino.cc/editor
![image](https://user-images.githubusercontent.com/56502015/116350574-c7809280-a80f-11eb-871b-a367dcbda26d.png)<br>
Here's a live demonstration:

https://user-images.githubusercontent.com/56502015/118628124-f32ce200-b7e9-11eb-8b24-9a5a066bc7e7.mp4

For more detailed information:<br>
Check:<br><br><br>
<p align="center">
<a href="https://www.youtube.com/watch?v=2DP5iUvnQyg">
  <img width="70%" src="https://img.youtube.com/vi/2DP5iUvnQyg/0.jpg" alt="MicroServoBot">
</a></p>


