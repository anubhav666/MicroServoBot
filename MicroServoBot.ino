#include <Servo.h>

#define buttonPin 2 //can only be D2 or D3 on Arduino Uno
//check https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/ for other boards
#define ledPin 13

#define sensorPin0 A0    // Finger
#define sensorPin1 A1    // Hand
#define sensorPin2 A2    // Hinge   

int buttonPushCounter = 1;   
bool buttonState;  

Servo servo_0;
Servo servo_1;
Servo servo_2;

int SensVal[3];
float state_0[3],state_1[3],state_2[3];

void buttonTicker() {
  buttonState = HIGH;
}

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
 
  servo_0.attach(3);
  servo_1.attach(5);
  servo_2.attach(10);
 
  Serial.begin(9600);
  Serial.println("mini robot ready...");

  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonTicker, FALLING);
  // Manual Debouncing capacitor expected! Else Circuit may malfunction!
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
  if (buttonState) {
    buttonPushCounter++;
    Serial.print("Number of button pushes: ");
    Serial.println(buttonPushCounter);
    delay(1000);
    buttonState = LOW;
  }
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
