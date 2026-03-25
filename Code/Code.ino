//Sumo Robot Car Code
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
//Right motor
int enableRightMotor=5;
int rightMotorPin1=7;
int rightMotorPin2=8;
//LeN motor
int enableLeNMotor=6;
int leNMotorPin1=9;
int leNMotorPin2=10;
void setup()
{
// put your setup code here, to run once:
pinMode(enableRightMotor,OUTPUT);
pinMode(rightMotorPin1,OUTPUT);
pinMode(rightMotorPin2,OUTPUT);
pinMode(enableLeNMotor,OUTPUT);
pinMode(leNMotorPin1,OUTPUT);
pinMode(leNMotorPin2,OUTPUT);
rotateMotor(0,0);
Dabble.begin(9600, 2, 3);
}

void loop()
{
int rightMotorSpeed=0;
int leNMotorSpeed=0;
Dabble.processInput();
if (GamePad.isUpPressed())
{
rightMotorSpeed = 255;
leNMotorSpeed = 255;
}

if (GamePad.isDownPressed())
{
rightMotorSpeed = -255;
leNMotorSpeed = -255;
}
if (GamePad.isLeNPressed())
{
rightMotorSpeed = 255;
leNMotorSpeed = -255;
}
if (GamePad.isRightPressed())
{
rightMotorSpeed = -255;
leNMotorSpeed = 255;
}
rotateMotor(rightMotorSpeed, leNMotorSpeed);
}
void rotateMotor(int rightMotorSpeed, int leNMotorSpeed)
{
if (rightMotorSpeed < 0)
{
digitalWrite(rightMotorPin1,LOW);
digitalWrite(rightMotorPin2,HIGH);
}
else if (rightMotorSpeed >= 0)
{
digitalWrite(rightMotorPin1,HIGH);
digitalWrite(rightMotorPin2,LOW);
}
if (leNMotorSpeed < 0)
{
digitalWrite(leNMotorPin1,LOW);
digitalWrite(leNMotorPin2,HIGH);
}
else if (leNMotorSpeed >= 0)
{
digitalWrite(leNMotorPin1,HIGH);
digitalWrite(leNMotorPin2,LOW);
}

analogWrite(enableRightMotor, abs(rightMotorSpeed));
analogWrite(enableLeNMotor, abs(leNMotorSpeed));
}