//Anthony Persaud (500996358)
//L293D dual motor control w/ Dip switch and Potentiometer

//Motor A (top)
const int motorPin1  = 7;  // Pin 15 of L293D
const int motorPin2  = 6;  // Pin 10 of L293D
//Motor B (bottom)
const int motorPin3  = 5; // Pin  7 of L293D
const int motorPin4  = 4;  // Pin  2 of L293D
//Potentiometer (analog)
const int PotValue = 0; // Potentiometer value
const int pwm = 2; //PWM


void setup(){
  
    //Set switch pins as inputs
    pinMode(8, INPUT_PULLUP);
    pinMode(9, INPUT_PULLUP);
    pinMode(10, INPUT_PULLUP);
    pinMode(11, INPUT_PULLUP);
  
  	Serial.begin(9600); // initialize serial communication
   
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
	pinMode(pwm, OUTPUT);
   
}

void loop(){
   
   //reading analog voltage and storing it in an integer
 	int PotValue  = analogRead(0) ; 
   //map the Potentiometer reading from 0-1023 to 0-255,
   //a range of values understood by analogWrite
    PotValue = map(PotValue, 0, 1023, 0, 255);
  	analogWrite(pwm,PotValue);
    
  if(digitalRead(8)==LOW and digitalRead(9)==HIGH and digitalRead(10)==HIGH and digitalRead(11)==HIGH){ 
   // turn Motor A and Motor B clockwise
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    //delay(2000);
  }
 
  else if(digitalRead(9)==LOW and digitalRead(8)==HIGH and digitalRead(10)==HIGH and digitalRead(11)==HIGH){ 
    // turn Motor A and Motor B counter-clockwise.
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    //delay(2000);
 }
  	
  else if(digitalRead(10)==LOW and digitalRead(9)==HIGH and digitalRead(8)==HIGH and digitalRead(11)==HIGH){ 
    // turn Motor B clockwise, turn Motor A counter-clockwise
  	// (turn left)
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    //delay(2000);
  } 
  
  else if(digitalRead(11)==LOW and digitalRead(9)==HIGH and digitalRead(10)==HIGH and digitalRead(8)==HIGH){ 
    // turn Motor A clockwise, turn Motor B counter-clockwise
  	// (turn right)
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    //delay(2000);
  }   
  
  else if (digitalRead(8)==HIGH and digitalRead(9)==HIGH and digitalRead(10)==HIGH and digitalRead(11)==HIGH){
    // stop motors
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    //delay(2000);
  }
}
