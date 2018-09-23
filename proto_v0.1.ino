/*   
 * This  bitch will make us win
 * -Sanjay .S Kumar
 */

const int microLitz1 = 13; //-----------------  assigning pin 13 to the variable microLitz1:

const int electrodeBicepLeft = A0; //---------  electode connected to the left bicep 

const int electrodeBicepRight = A1; //--------  electode connected to the right bicep

int relaxThreshold = 50;//--------------------  the variable explains it

int dilay = 1; //-----------------------------  this isn't a grammatical error, you can't use the word delay so this is the closest thing to it ;)

int inputmulti = 10; //-----------------------  sets multiplication of the sensor input

int

unsigned long lastTrigger = 0; //-------------  last time the led was triggered


void setup() { //-----------------------------  the setup routine runs once when you press reset:
  
  Serial.begin(9600); //----------------------  initialize serial communication at 9600 bits per second:
  
  pinMode(microLitz1, OUTPUT); //-------------  assigning microLitz1(pin,13) as an output pin:

}


void loop() { //------------------------------  the loop routine runs over and over again forever:
  
  int electrodes1 = analogRead(electrodeBicepLeft); //--  read the input on analog pin 0:
  
  int sensoramp = electrode1*inputmulti; //--  multiplies and amplifies the sensor input 
  

  
  if((millis() - lastTrigger) > dilay) { //---  Custom Debounce Code
  
  Serial.println(sensorValue); //-------------  Prints out the value you read:
  
  if(sensoramp >= relaxThreshold){ //---------  Triggering the led
    
    digitalWrite(microLitz1, 1); //---------------  Turns led on
    
    unsigned long lastTrigger = millis(); //--  Resets the time to the lastTigger 
  
   }else{
  
    digitalWrite(ledPin, 0); //---------------  If not triggered keeps the led off

}
                    
}

}                                                                                                                                       
