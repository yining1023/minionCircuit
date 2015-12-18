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
  int rgbState = map(potState, 0, 1023, 1, 3);
  
  if(circuitState < 700 && circuitState > 400){
    cState = 1;
    switch(rgbState){
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

 
//  Serial.print(cState);
Serial.println(bothState);
//  Serial.println(1000);

//  Serial.print("potState: ");
//  Serial.println(potState);
delay(1);
}
