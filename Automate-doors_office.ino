//defines pins
const int stepPin = 16;  //PUL -Pulse
const int dirPin = 5; //DIR -Direction
const int enPin = 4;  //ENA -Enable
const int buttonPin = 1;
const int stopbutt = 3;
int buttonState = 0;
int pos = 0;
int stopbuttState = 0;

void setup(){
  //Sets the pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(enPin,OUTPUT);
  pinMode(buttonPin, INPUT);
}


void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  
   if (buttonState == LOW && pos == 0) {
          delay(400);
          digitalWrite(enPin,LOW);
          digitalWrite(dirPin,HIGH);
          pos = 1;
          for(int x = 0; x < 1;) {
          digitalWrite(stepPin,HIGH);
          delayMicroseconds(500); 
          digitalWrite(stepPin,LOW); 
          delayMicroseconds(500);
          stopbuttState = digitalRead(stopbutt);
          buttonState = digitalRead(buttonPin);
          if (stopbuttState == LOW){
            digitalWrite(enPin,HIGH);
            break;
          }
          if (buttonState == LOW){
            delay(400);
            digitalWrite(enPin,HIGH);
            break;
          }
          
         }
       
  }
  else if (buttonState == LOW && pos == 1){
          delay(400);
          digitalWrite(enPin,LOW);
          digitalWrite(dirPin,LOW);
          pos = 0;
          for(int x = 0; x < 1;){
          digitalWrite(stepPin,HIGH); 
          delayMicroseconds(500); 
          digitalWrite(stepPin,LOW); 
          delayMicroseconds(500);
          stopbuttState = digitalRead(stopbutt);
          buttonState = digitalRead(buttonPin);
           if (stopbuttState == LOW){
            digitalWrite(enPin,HIGH);
            break;
          } 
           if (buttonState == LOW){
            delay(400);
            digitalWrite(enPin,HIGH);
            break;
          }
    }
    
   
      } else {
     digitalWrite(enPin,HIGH);
  } 
  
}
