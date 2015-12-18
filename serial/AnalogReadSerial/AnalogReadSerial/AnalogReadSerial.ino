/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

 This example code is in the public domain.
 */

int cState = 0;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(A1, INPUT);
  pinMode(A5, INPUT);


  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
}


void loop() {
 
  int circuitState = analogRead(A1);
  int potState = analogRead(A5);
  int rgbState = map(potState, 0, 1023, 1, 3);
  
  if(circuitState < 700 && circuitState > 400){
    cState = 1;
    switch(rgbState){
      case 1: 
      //RED
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        break;
        
      case 2: 
      //YELLOW
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        break;
      case 3: 
      //GREEN
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW); 
        break;
    
    }//end of switch s
  } else {
   cState = 0;
   digitalWrite(5, LOW);
   digitalWrite(6, LOW);
   digitalWrite(6, LOW);
   
  }

  //Serial.print("circuitState: ");
  Serial.println(cState);

//  Serial.print("potState: ");
//  Serial.println(potState);
delay(1);
}
