#include <Stepper.h>
#include <SoftwareSerial.h>

 //Written Code for Minor project

//color of lcd 
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;


 #define STEPS 2038 // the number of steps in one revolution of your motor (28BYJ-48)

 //pins of motor
 Stepper stepper(STEPS, 8, 10, 9, 11);

  //touch sensor pins
  const int TouchPin1=3;
  const int TouchPin2=4;

  //var to calculate the time
  
  int timer = 0;

  
  //distance is constante
  int distance = 60;

  //var to store the speed 
  int v = 0;
  
  void setup() {


 

  Serial.begin(9600);

  //touch sensors input pins 
  pinMode(TouchPin1, INPUT);
  pinMode(TouchPin2, INPUT);


  
  }

void loop() {


  //read the 1st sensor value 
  int sensorValue2 = digitalRead(TouchPin2);

  //while loop .. while the 1st sensor is high   
  while(sensorValue2 == HIGH  ){
    //read the value of 2nd sensor 
    int sensorValue1 = digitalRead(TouchPin1);
     //print 
    Serial.print("time is ");
    Serial.print(timer);
    Serial.println("s");

    //increase the time (t)
    timer++;

    //if 2nd sensor is on 
     if(sensorValue1 == HIGH){

      //breake the while loop 
         sensorValue2 = digitalRead(TouchPin2);
        sensorValue2 == LOW;
        //cal the speed 
        v= distance/timer;

        //print the speed
        Serial.print("Speed is ");
        Serial.println( v);

        //reset the time(t)
        delay(15);
        timer =0;

        //check is the car is speeding 
        if(v>10){
          Serial.println("YOU ARE SPEEDING! SLOW DOWN!!");

          //motor on 
          stepper.setSpeed(10); // 1 rpm
       stepper.step(2038); 
       delay(2000);
      stepper.setSpeed(10); // 1 rpm
       stepper.step(-2038); 

        }
        //the car is not speeding 
        else{
          Serial.println("YOU ARE AMAZING! KEEP UP");
          }
        
      }
      
    
    

    Serial.println("----------------------");
    delay(1000);

    }



    

}
