int a = 1200;
int b = 900;
int c = 17;
int d = 2500;
int BUTTON1state = 0;
int BUTTON2state = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(15,OUTPUT);
  pinMode(21,OUTPUT);
  pinMode(22,INPUT);
  pinMode(23,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  BUTTON1state = digitalRead(22);
  BUTTON2state = digitalRead(23);

  if (BUTTON1state == HIGH){
    //1 = disable stream of pulses
    digitalWrite(21,LOW);
    digitalWrite(15,LOW);
  } 
  else{
      //0 = enable stream of pulse  
      if (BUTTON2state == HIGH){
       //1 = run with a modified waveform cycle 
       //Generate inverted form of complete Sig A waveform (from the largest pulse to the shortest)until switch 2 set back to 0

       //Sig B
       digitalWrite(21,HIGH);
       delay(50);
       digitalWrite(21,LOW);
       
       int i = 0;//Counter
       a = 2050;//Reset a
       while (i <= c){ //Do 17 times
          //Sig A
          digitalWrite(15,HIGH);
          delay(a);
          digitalWrite(15,LOW);
          delay(b);
          a = a - 50;//Decrement a
          i++;//Increment Counter
        }    
        delay(d);//Wait at end of pulse block
     }   
     else{
      //0 = run as normal mode

      //Sig B
      digitalWrite(21,HIGH);
      delay(50);
      digitalWrite(21,LOW);
      
      int i = 0;//Counter 
      a = 1200;//Reset a
      while (i <= c){ //Do 17 times
        //Sig A
        digitalWrite(15,HIGH);
        delay(a);
        digitalWrite(15,LOW);
        delay(b);
        a = a + 50;//Increment a
        i++;//Increment Counter
     }
     delay(d);//Wait at end of pulse block
   }
  }

}
