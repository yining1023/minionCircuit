/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

 This example code is in the public domain.
 */

int cState = 0;
int bothState = 0;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);


  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
}


void loop() {
 
  int circuitState = analogRead(A1);
  int potState = analogRead(A0);
//  int rgbState = map(potState, 0, 1023, 1, 3);
  
  int manuMap = 0;
  
  if(potState>=0 && potState<341){
    manuMap = 1;
  }
  if(potState>=341 && potState<682){
    manuMap = 2;
  }
  if(potState>=682 && potState<1024){
    manuMap = 3;
  }
  
  if(circuitState < 400 && circuitState > 100){
    cState = 1;
    switch(manuMap){
      case 1: 
      bothState = 1;
      //RED
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        break;
        
      case 2: 
      bothState = 2;
      //YELLOW
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        break;
      case 3: 
      bothState = 3;
      //GREEN
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW); 
        break;
    
    }//end of switch s
  } else {
   cState = 0;
   bothState = 0;
   digitalWrite(3, LOW);
   digitalWrite(4, LOW);
   digitalWrite(5, LOW);
   
  }

//  Serial.print(circuitState);
//Serial.print(potState);
//  Serial.print(", ");
//  Serial.println(cState);
//  Serial.print(", ");
//  Serial.println(manuMap);
Serial.println(bothState);
//  Serial.println(1000);

//  Serial.print("potState: ");
//  Serial.println(potState);
delay(1);
}
