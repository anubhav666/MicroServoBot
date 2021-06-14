#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define  buttonPin 2
#define ledPin 13
#define numServo 3
#define numStep 5        
#define servoMIN 150
#define servoMAX 750


int buttonPushCounter = 1;   
bool buttonState ;   
int pot[]={A0,A1,A2,A3,A4,A5};

int val[numStep][numServo];

void buttonTicker()
{
  buttonState = HIGH; // Sets the state as HIGH
}
void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);
  Serial.println("mini robot ready...");
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonTicker, FALLING); 
}
void mapServo(int val[],int x)
{
  Serial.print("Recording Step :");
  Serial.println(x);
  for(int i=0;i<numServo;i++)
  {
    val[i] = analogRead(pot[i]);            
    val[i] = map(val[i], 0, 1023, servoMIN, servoMAX);
  }
}
void setServo(int val[])
{
  for(int i=0;i<numServo;i++)
  {
    pwm.setPWM(i, 0, val[i]);
    Serial.println(val[i]);    
  }
}
void loop() {
if (buttonState) { // if button is pressed
    buttonPushCounter++;         
    Serial.print("Number of button pushes: ");
    Serial.println(buttonPushCounter);
    delay(1000);
    buttonState = LOW;// Resets buttonState
    if (buttonPushCounter > (numStep+1)) 
      buttonPushCounter %= (numStep+1);
  }
  if (buttonPushCounter == (numStep+1)) {
    Serial.println("Playing Steps....");
    for(int i=0;i<numStep;i++)
    {     
      setServo(val[i]);
      delay(1000);                       
    }
  }
  else
  {
    mapServo(val[buttonPushCounter-1],buttonPushCounter);
    setServo(val[buttonPushCounter-1]);      
  }
}
