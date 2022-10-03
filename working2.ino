#include <Servo.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"

Servo myservo;  



/* we Connect SCL    to analog 5
   Connect SDA    to analog 4
   Connect VDD    to 3.3V DC
   Connect GROUND to common ground */ 

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

int in1=4;
int in2=2;
int enA=3;

int right_count=0 ;
int left_count=0;


const int trigforward = 8;
const int echoforward = 9;
const int trigright = 10;
const int echoright = 11;
const int trigleft = 12;
const int echoleft = 13;

// defines variables
long forward_duration;
int forward_distance;
long right_duration;
int right_distance;
long left_duration;
int left_distance;
uint16_t r, g, b, c, colorTemp, lux;




void setup() {
  Serial.begin(9600);
   // Starts the serial communication
  
  pinMode(trigforward, OUTPUT); // Sets the trigforward as an Output
  pinMode(echoforward, INPUT); // Sets the echoforward as an Input
  pinMode(trigright, OUTPUT);
  pinMode(echoright, INPUT);
  pinMode(trigleft, OUTPUT);
  pinMode(echoleft, INPUT);
  myservo.attach(7);
  delay(1000);
  

  
 

}

void loop() 
{

  
  
  digitalWrite(trigforward, LOW);
  delayMicroseconds(2);
 
  // Sets the trigforward on HIGH state for 10 micro seconds
  digitalWrite(trigforward, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigforward, LOW);
 
 
  // Reads the echoPin, returns the sound wave travel time in microseconds
  forward_duration = pulseIn(echoforward, HIGH);
  
 
  // Calculating the distance
  forward_distance = forward_duration * 0.034 / 2;
  
  
  // Prints the Forward_distance on the Serial Monitor
  Serial.print("forward_Distance: ");
  Serial.println(forward_distance);

 

  digitalWrite(trigright, LOW);
  delayMicroseconds(2);
  digitalWrite(trigright, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigright, LOW);
  right_duration = pulseIn(echoright, HIGH);
  right_distance = right_duration * 0.034 / 2;
  Serial.print("right_Distance: ");
  Serial.println(right_distance);

 
  digitalWrite(trigleft, LOW);
  delayMicroseconds(2);
  digitalWrite(trigleft, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigleft, LOW);
  left_duration = pulseIn(echoleft, HIGH);
  left_distance = left_duration * 0.034 / 2;
  Serial.print("left_Distance: ");
  Serial.println(left_distance);
  
  tcs.getRawData(&r, &g, &b, &c);

  Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
  Serial.println(" ");
    
  //1

  if ((forward_distance >= 15) && (right_distance >= 15) && (left_distance >= 15)) {

    Serial.println("forwoard");
    myservo.write(65);
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    analogWrite(enA,140);

    
    // الخط البرتقالي
    
      if (( r >= 168) && (r < 170)){
        if ( (g >= 119) && (g < 121)){
          if ( (b >= 89) && (b < 91 )){

      
            Serial.println("right");
             
            myservo.write(100);
            delay(60);
            right_count++ ;
            Serial.println(right_count); 

          //الخط الأزرق 
            if ( (r >= 87) && (r < 91) ){
              if ( (g >= 83) && (g < 89)){
                if ( ( b >= 71) && (b < 75)){

      
                  myservo.write(65);

                }
                
                
              }

            }        
          }

        }  
      }
  //الخط الأزرق     
      if ( (r >= 87) && (r < 91) ){
        if ( (g >= 83) && (g < 89)){
          if ( ( b >= 71) && (b < 75)){

      
            myservo.write(40);
            delay(60);
            left_count++ ;
            Serial.println(right_count); 
            }
                
                
          }

        }  

      }
          //الخط البرتقالي
           if (( r >= 168) && (r < 170)){
              if ( (g >= 119) && (g < 121)){
                if ( (b >= 89) && (b < 91 )){

      
                  
             
                  myservo.write(65);
                       
                }

              }  
            }
        
        
      }
    

  


  

  
  else if ((forward_distance >= 15) && (right_distance <= 15) && (left_distance >= 15)) {

    
    myservo.write(55);


    
    // الخط البرتقالي
    
      if (( r >= 168) && (r < 170)){
        if ( (g >= 119) && (g < 121)){
          if ( (b >= 89) && (b < 91 )){

      
            Serial.println("right");
             
            myservo.write(100);
            delay(60);
            right_count++ ;
            Serial.println(right_count); 

          //الخط الأزرق 
            if ( (r >= 87) && (r < 91) ){
              if ( (g >= 83) && (g < 89)){
                if ( ( b >= 71) && (b < 75)){

      
                  myservo.write(65);

                }
                
                
              }

            }        
          }

        }  
      }
  //الخط الأزرق     
      if ( (r >= 87) && (r < 91) ){
        if ( (g >= 83) && (g < 89)){
          if ( ( b >= 71) && (b < 75)){

      
            myservo.write(40);
            delay(60);
            left_count++ ;
            Serial.println(right_count); 
            }
                
                
          }

        }  

          //الخط البرتقالي
           if (( r >= 168) && (r < 170)){
              if ( (g >= 119) && (g < 121)){
                if ( (b >= 89) && (b < 91 )){

      
                  
             
                  myservo.write(65);
                       
                }

              }  
            }
          }
        }
      }
    }
  }

  else if ((forward_distance >= 15) && (right_distance >= 15) && (left_distance <= 15)) {

    
    myservo.write(80);


    
    // الخط البرتقالي
    
      if (( r >= 168) && (r < 170)){
        if ( (g >= 119) && (g < 121)){
          if ( (b >= 89) && (b < 91 )){

      
            Serial.println("right");
             
            myservo.write(100);
            delay(60);
            right_count++ ;
            Serial.println(right_count); 

          //الخط الأزرق 
            if ( (r >= 87) && (r < 91) ){
              if ( (g >= 83) && (g < 89)){
                if ( ( b >= 71) && (b < 75)){

      
                  myservo.write(65);

                }
                
                
              }

            }        
          }

        }  
      }
  //الخط الأزرق     
      if ( (r >= 87) && (r < 91) ){
        if ( (g >= 83) && (g < 89)){
          if ( ( b >= 71) && (b < 75)){

      
            myservo.write(40);
            delay(60);
            left_count++ ;
            Serial.println(right_count); 
            }
                
                
          }

        }  

          //الخط البرتقالي
           if (( r >= 168) && (r < 170)){
              if ( (g >= 119) && (g < 121)){
                if ( (b >= 89) && (b < 91 )){

      
                  
             
                  myservo.write(65);
                       
                }

              }  
            }
          }
        }
      }
    }
  }

  else if ((forward_distance < 15) ) {

    conect_camera();

  }
  


  if (right_count==12) {

    delay (100);
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    analogWrite(enA,0);

  }

  else if (left_count==12) {

    delay (100);
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    analogWrite(enA,0);
  }
  
  



    
                
                
              

                    
          
         
      

  
}
