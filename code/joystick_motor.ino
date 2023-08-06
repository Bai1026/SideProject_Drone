/*
Use arduino Nano, TB6612NRF, 18650*2(7.4V), and a joystick
*/

#include <SparkFun_TB6612.h>

#define joyX A0
#define joyY A1

int xValue, yValue;

const int AIN1 = 4;
const int AIN2 = 3;
const int pwmA = 2;
const int NC = 5;

const int offsetA = 1;
const int offsetB = 1;

Motor motor1 = Motor(AIN1, AIN2, pwmA, offsetA, NC);

void setup()
{
  Serial.begin(9600);
 //Nothing here
}


void loop()
{
   //Use of the drive function which takes as arguements the speed
   //and optional duration.  A negative speed will cause it to go
   //backwards.  Speed can be from -255 to 255.  Also use of the 
   //brake function which takes no arguements.
  //  motor1.drive(255,1000);
  //  motor1.drive(-255,1000);
  //  motor1.brake();
  //  delay(2000);
   
   xValue = analogRead(joyX);
   yValue = analogRead(joyY);

  //  Serial.print("X axis: ");
  //  Serial.print(xValue);
  //  Serial.print("\t");
  //  Serial.print("Y Axis: ");
  //  Serial.print(yValue);
  //  Serial.print("\n");
  //  delay(200);

   if(xValue > 502){
     motor1.drive(255, 1000);
     Serial.print("X axis: ");
     Serial.print(xValue);
     Serial.print("\n");
    //  printf(xValue);
   }
   else if(xValue < 502){
     motor1.drive(-255, 1000);
     Serial.print("X axis: ");
     Serial.print(xValue);
     Serial.print("\n");
    //  printf(xValue);
   }
   else{
     motor1.brake();
    //  delay(2000);
   }

   //Use of the drive function which takes as arguements the speed
   //and optional duration.  A negative speed will cause it to go
   //backwards.  Speed can be from -255 to 255.  Also use of the 
   //brake function which takes no arguements.
  //  motor2.drive(255,1000);
  //  motor2.drive(-255,1000);
  //  motor2.brake();
  //  delay(1000);
   
   //Use of the forward function, which takes as arguements two motors
   //and optionally a speed.  If a negative number is used for speed
   //it will go backwards
  //  forward(motor1, motor2, 150);
  //  forward(motor1, 150);
  //  delay(1000);
   
  //  //Use of the back function, which takes as arguments two motors 
  //  //and optionally a speed.  Either a positive number or a negative
  //  //number for speed will cause it to go backwards
  //  back(motor1,  -150);
  //  delay(1000);
   
   //Use of the brake function which takes as arguments two motors.
   //Note that functions do not stop motors on their own.
  //  brake(motor1, motor2);
  //  delay(1000);
   
  //  //Use of the left and right functions which take as arguements two
  //  //motors and a speed.  This function turns both motors to move in 
  //  //the appropriate direction.  For turning a single motor use drive.
  //  left(motor1, motor2, 100);
  //  delay(1000);
  //  right(motor1, motor2, 100);
  //  delay(1000);
   
  //  //Use of brake again.
  //  brake(motor1, motor2);
  //  delay(1000);
   
}