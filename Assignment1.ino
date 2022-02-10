#define LED1 15
#define LED2 21
#define BUTTON1 22
#define BUTTON2 23

//Global Variables
int a = 1200;
int b = 900;
int c = 17;
int d = 2500;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);//Used to show what the program is doing
  
  //For the LEDs set as output
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  
  //For the buttons set as input
  pinMode(BUTTON1,INPUT);
  pinMode(BUTTON2,INPUT);
  
}


void loop() {
  // put your main code here, to run repeatedly:
  
  
  //Check whether buttons are pressed
  int BUTTON1state = digitalRead(BUTTON1);
  int BUTTON2state = digitalRead(BUTTON2);

  if (BUTTON1state == HIGH){
    //1 = disable stream of pulses
  
    Serial.println("Button1 High");
     //Turn off LEDs
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
  } 
  else{
    Serial.println("Button1 Low");
      //0 = enable stream of pulse  
      if (BUTTON2state == HIGH){
        Serial.println("Button2 High");
       //1 = run with a modified waveform cycle 
       //Generate inverted form of complete Sig A waveform (from the largest pulse to the shortest)until switch 2 set back to 0

       //Sig B
       digitalWrite(LED2,HIGH);//Send HIGH signal, turn LED on
       delayMicroseconds(20000);//50 Hz = 20000 µs
       digitalWrite(LED2,LOW);//Send LOW signal, turn LED off
       
       int i = 0;//Counter
       a = 2050;//Reset a
       while (i <= c){ //Do 17 times
          //Sig A
          digitalWrite(LED1,HIGH);
          delayMicroseconds(a);
          digitalWrite(LED1,LOW);
          delayMicroseconds(b);
          a = a - 50;//Decrement a
          i++;//Increment Counter
        }    
        delayMicroseconds(d);//Wait at end of pulse block
     }   
     else{
      Serial.println("Button2 Low");
      //0 = run as normal mode

      //Sig B
      digitalWrite(LED2,HIGH);
      delayMicroseconds(50);
      digitalWrite(LED2,LOW);
      
      int i = 0;//Counter 
      a = 1200;//Reset a
      while (i <= c){ //Do 17 times
        //Sig A
        digitalWrite(LED1,HIGH);
        delayMicroseconds(a);
        digitalWrite(LED1,LOW);
        delayMicroseconds(b);
        a = a + 50;//Increment a
        i++;//Increment Counter
     }
     delayMicroseconds(d);//Wait at end of pulse block
   }
  }

}
