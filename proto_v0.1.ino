/*
 * This  bitch will make us win
 * -Sanjay .S Kumar
 */
int ledPin = 13; //---------------------------  assigning pin 13 to the variable ledPin:
int relaxThreshold = 50;//--------------------  the name explains it
int dilay = 1; //-----------------------------  this isn't a grammatical error, you can't use the word delay so this is the closest thing to it ;)
int inputmulti = 10; //-----------------------  sets multiplication of the sensor input
int lastTrigger = 0; //-----------------------  last time the led was triggered


void setup() { //-----------------------------  the setup routine runs once when you press reset:
  
  Serial.begin(9600); //----------------------  initialize serial communication at 9600 bits per second:
  pinMode(ledPin, OUTPUT); //-----------------  assigning ledPin(13) as an output pin:
}


void loop() { //------------------------------  the loop routine runs over and over again forever:
  
  int sensorValue = analogRead(A0);//---------  read the input on analog pin 0:
  int sensoramp = sensorValue*inputmulti; //--  multiplies and amplifies the sensor input 
  
  if((millis()- lastTrigger) > 1){ //---------  Custom Debounce Code
  Serial.println(sensorValue); //-------------  Prints out the value you read:
  if(sensoramp >= relaxThreshold){ //---------  Triggering the led
    digitalWrite(ledPin, 1); //---------------  Turns led on
    int lastTrigger = millis(); //------------  Resets the time to the lastTigger 
  }else{
    digitalWrite(ledPin, 0); //---------------  If not triggered keeps the led off
  }
}
}
