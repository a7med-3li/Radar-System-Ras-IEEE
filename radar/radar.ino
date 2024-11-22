#include<Servo.h>
const int TriggerPin = 8;
const int EchoPin = 9;
const int motorSignalPin = 10;

const int startingAngle = 90;
const int minimumAngle = 6;
const int maximumAngle = 175;
const int rotationSpeed = 1;

Servo motor;
void setup(void) 
{
    pinMode(TriggerPin, OUTPUT);
    pinMode(EchoPin, INPUT);
    motor.attach(motorSignalPin);
    Serial.begin(9600);
}
void loop(void)
{
    static int motorAngle = startingAngle;
    static int motorRotateAmount = rotationSpeed;

    motor.write(motorAngle);
    delay(100);
     SerialOutput(motorAngle, CalculateDistance());
    
motorAngle += motorRotateAmount;
    if(motorAngle <= minimumAngle || motorAngle >= maximumAngle) {
        motorRotateAmount = -motorRotateAmount;
    }}
int CalculateDistance(void)
{
   
    digitalWrite(TriggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(TriggerPin, LOW);
      long duration = pulseIn(EchoPin, HIGH);
    float distance = duration * 0.017F;
    return int(distance);
}
void SerialOutput(const int angle, const int distance)
{
    String angleString = String(angle);
    String distanceString = String(distance);
        Serial.println(angleString + "," + distanceString);
}

