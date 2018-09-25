/*   
 * This  bitch will make us win
 * -Sanjay .S Kumar
 */

const int microLitzBicepLeft = 2; //-----------------  assigning pin 2 to the variable microLitz1:

const int microLitzBicepRight = 3;

const int microLitzDeltoidRearLeft = 4;

const int microLitzDeltoidRearRight = 5;

const int microLitzDeltoidFrontLeft = 6;

const int microLitzDeltoidFrontRight = 7;

const int microLitzDeltoidMiddleLeft = 8;

const int microLitzDeltoidMiddleRight = 9;

const int microLitzAbs1 = 10;

const int microLitzAbs2 = 11;


const int electrodeBicepLeft = A0; //---------  electode connected to the left bicep ---------|

const int electrodeBicepRight = A1; //--------  electode connected to the right bicep         | 

const int electrodeDeltoidRearLeft = A2;// -------  electode connected to the left deltoid        |    
                                                                                                    Muscle 
const int electrodeDeltoidRearRight = A3;// ------  electode connected to the right deltoid       |  

const int electrodeDeltoidMiddleLeft = A2;// -------  electode connected to the left deltoid        |    
                                                                                                    Muscle 
const int electrodeDeltoidMiddleRight = A3;

const int electrodeAbs1 = A4;// --------------  electrode connected to the 1st ab muscle

const int electrodeAbs2 = A5;// --------------  electrode connected to the 2nd ab muscle


int relaxThresholdBicepLeft = 50;//--------------------  the variable explains it

int relaxThresholdBicepRight = 50;

int relaxThresholdDeltoidRearLeft = 50;

int relaxThresholdDeltoidRearRight = 50;

int relaxThresholdDeltoidMiddleLeft = 50;

int relaxThresholdDeltoidMiddleRight = 50;

int relaxThresholdAbs1 = 50;

int relaxThresholdAbs2 = 50;

int dilay = 1; //-----------------------------  this isn't a grammatical error, you can't use the word delay so this is the closest thing to it ;)

int inputmulti = 10; //-----------------------  sets multiplication of the sensor input



unsigned long lastTriggerBicepLeft = 0; //-------------  last time the led was triggered

unsigned long lastTriggerBicepRight = 0;

unsigned long lastTriggerDeltoidRearLeft = 0;

unsigned long lastTriggerDeltoidRearRight = 0;

unsigned long lastTriggerDeltoidMiddleLeft = 0;

unsigned long lastTriggerDeltoidMiddleRight = 0;

unsigned long lastTriggerAbs1 = 0;

unsigned long lastTriggerAbs1 = 0;


void setup() { //-----------------------------  the setup routine runs once when you press reset:
  
  Serial.begin(9600); //----------------------  initialize serial communication at 9600 bits per second:
  
  pinMode(microLitz1, OUTPUT); //-------------  assigning microLitz1(pin,2) as an output pin:

}


void loop() { //----------------------------------------  the loop routine runs over and over again forever:
  
  int electrodeBicepLeftData = analogRead(electrodeBicepLeft); //--  read the input on analog pin 0:
  
  int electrodeBicepLeftDataAmp = electrodeBicepLeftData*inputmulti; //-------------  multiplies and amplifies the sensor input 
  
  int electrodeBicepRightData = analogRead(electrodeBicepLeft); //--  read the input on analog pin 0:
  
  int electrodeBicepRightDataAmp = electrodeBicepLeftData*inputmulti; //-------------  multiplies and amplifies the sensor input 
  
  
  if((millis() - lastTriggerBicepLeft) > dilay) { //---  Custom Debounce Code
  
  Serial.println(sensorValue); //--------------  Prints out the value you read:
  
  if(electrodeBicepLeftDataAmp >= relaxThresholdBicepLeft){ //----------  Triggering the led
    
    digitalWrite(microLitzBicepLeft, 1); //------------  Turns led on
    
    digitalWrite(microLitzTricepRight, 0);
    
    unsigned long lastTriggerBicepLeft = millis(); //--  Resets the time to the lastTigger 
  
   }else{
  
    digitalWrite(microLitzBicepLeft, 0); //---------------  If not triggered keeps the led off

    digitalWrite(microLitzBicepRight, 1);
    
}
                    
}
  
  if((millis() - lastTriggerBicepRight) > dilay) { //---  Custom Debounce Code
  
  Serial.println(sensorValue); //--------------  Prints out the value you read:
  
  if(electrodeBicepRightDataAmp >= relaxThresholdBicepRight){ //----------  Triggering the led
    
    digitalWrite(microLitzBicepRight, 1); //------------  Turns led on
    
    digitalWrite(microLitzTricepLeft, 0);
    
    unsigned long lastTriggerBicepRight = millis(); //--  Resets the time to the lastTigger 
  
   }else{
  
    digitalWrite(microLitzBicepRight, 0); //---------------  If not triggered keeps the led off

    digitalWrite(microLitzTricepLeft, 1);
    
}
                    
}

}                                                                                                                                       
