#include <Servo.h> 
const int  buttonPin = 2;    
const int ledPin = 13;      

int buttonPushCounter = 1;   
int buttonState = 0;         
int lastButtonState = 0;     

Servo servo_0;
Servo servo_1;
Servo servo_2;

int sensorPin0 = A0;    // Finger
int sensorPin1 = A1;    // Hand
int sensorPin2 = A2;    // Hinge
int SensVal[3];
float state_0[3],state_1[3],state_2[3];
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  servo_0.attach(3);
  servo_1.attach(5);
  servo_2.attach(10);
  Serial.begin(9600);
  Serial.println("mini robot ready...");  
}
void readPot()
{
   SensVal[0] = analogRead(sensorPin0); 
   SensVal[1] = analogRead(sensorPin1); 
   SensVal[2] = analogRead(sensorPin2); 
}
void mapping(float state[])
{
  state[0] = map(SensVal[0], 0, 512, 180, 0);
  state[1] = map(SensVal[1], 1024, 0, 270, 0);
  state[2] = map(SensVal[2], 1023, 0, 100, 270);
}
void Servowrite(float state[])
{
  servo_0.write(state[0]);
  servo_1.write(state[1]);
  servo_2.write(state[2]);        
}
void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonPushCounter++;
      Serial.print("Number of button pushes: ");
      Serial.println(buttonPushCounter);
    }
    delay(1000); 
  }
  lastButtonState = buttonState;
  if (buttonPushCounter % 4 == 0) {
    Serial.println("Playing Steps....");
    digitalWrite(ledPin, HIGH);
    Servowrite(state_0);
    delay(1000);
    Servowrite(state_1);
    delay(1000);
    Servowrite(state_2);
    delay(1000);
  }
  else if(buttonPushCounter % 2 == 0){
    Serial.println("Recording Step 2:");
    digitalWrite(ledPin,LOW);
    readPot();
    mapping(state_1);
    Servowrite(state_1);
  }
  else if(buttonPushCounter % 3 == 0){
    Serial.println("Recording Step 3:");
    digitalWrite(ledPin,LOW);
    readPot();
    mapping(state_2);
    Servowrite(state_2);
  }
  else {
    Serial.println("Recording Step 1:");
    digitalWrite(ledPin,LOW);
    readPot();
    mapping(state_0);
    Servowrite(state_0);
  }

}
