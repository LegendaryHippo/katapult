#include <Servo.h>
Servo servo1;
Servo servo2;

int test = 123;

int ledPins[] = {11,12,13};
const int button1Pin = 2;
const int button2Pin = 3;
const int button3Pin = 4;

const int buzzerPin = 8;
const int songLength = 8;
char notes[] = "abcdefghj";
int beats[] = {2,2,2,2,2,2,2,2,2};
int tempo = 150;


void setup() {
  // put your setup code here, to run once:
  servo1.attach(9);
  servo2.attach(7);

  pinMode(buzzerPin, OUTPUT);
  
  int index;
  for(index = 0; index <= 2; index++)
  {
    pinMode(ledPins[index],OUTPUT);
  }
  servo2.write(10);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //buttons();
  buttons2();
  //buttontest();
}

void buttontest(){
  int button1State, button2State, button3State;
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button2State = digitalRead(button3Pin);

  if(button1State == LOW){
    digitalWrite(11, HIGH);
    }

    else if (button2State == LOW){
      digitalWrite(12, HIGH);
      }

    else if(button3State == LOW)
    {
      digitalWrite(13, HIGH);
      }

      else{
//        digitalWrite(11, LOW);
//        digitalWrite(12, LOW);
//        digitalWrite(13, LOW);
        }
  }

void buttons2(){
  int button1State, button2State, button3State;
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);

  if(button1State == LOW){
    servo1.write(10);
    delay(1000);
    }

  if(button2State == LOW){
    servo1.write(150);
    delay(1000);
    }

   if(button3State == LOW){
    fire();
    } 
}

void buttons(){
  
  int button1State, button2State, button3State;
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);
  
  if(button1State == LOW && button2State == HIGH &&! (button1State == LOW && button2State == LOW)){
    servo1.write(90);
    }
   
    else if(button2State == LOW && button1State == HIGH &&! (button1State == LOW && button2State == LOW)){
      
      servo1.write(100);
      }

    else if(button1State == LOW && button2State == LOW){
      //digitalWrite(13, HIGH);
      //fire();
      //servo1.write(95);
      }

    else if (button3State == LOW){
      fire();
      }
      
//    else if(button1State == HIGH && button2State == HIGH){
      else if(button3State == HIGH){
      servo1.write(95);
      digitalWrite(ledPins[0], HIGH);  //Turns on LED #0 (pin 2)
      digitalWrite(ledPins[1], HIGH);  //Turns on LED #1 (pin 3)
      digitalWrite(ledPins[2], LOW);  //Turns on LED #2 (pin 4)
      }
    
    
    else{
      
    }

    
}

void fire()
{
  int delayTime = 250;

  digitalWrite(ledPins[0], LOW);   //Turn off LED #2 (pin 4)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(ledPins[1], LOW);   //Turn off LED #1 (pin 3)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(ledPins[2], HIGH);   //Turn off LED #0 (pin 2)
  delay(delayTime);                //wait delayTime milliseconds  
  //sirene();
  servo2.write(100);    // Tell servo to go to 90 degrees

  delay(1000);         // Pause to get it time to move
  servo2.write(10);
}

void sirene() 
{
  int i, duration;
  
  for (i = 0; i < songLength; i++) // step through the song arrays
  {
    duration = beats[i] * tempo;  // length of note/rest in ms
    
    if (notes[i] == ' ')          // is this a rest? 
    {
      delay(duration);            // then pause for a moment
    }
    else                          // otherwise, play the note
    {
      tone(buzzerPin, frequency(notes[i]), duration);
      delay(duration - 1);            // wait for tone to finish
    }
  }
}

int frequency(char note){
  int i;
  const int numNotes = 8;  // number of notes we're storing
  
  //char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  char names[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j'};
  int frequencies[] = {1550, 1570, 1590, 1610, 1630, 1610, 1590, 1570, 1550};
  
  for (i = 0; i < numNotes; i++)  // Step through the notes
  {
    if (names[i] == note)         // Is this the one?
    {
      return(frequencies[i]);     // Yes! Return the frequency
    }
  }
  return(0);  // We looked through everything and didn't find it,
              // but we still need to return a value, so return 0.
}



//void servotest(){
//  int posisjon;
//  while(button1State == LOW){
//    if(posisjon <= 360 && posisjon >= 0){
//      posisjon + 10 = posisjon;
//      servo2.write(posisjon);     
//      }
//
//     else
//     {
//      
//      }
//    }
//
//    while(button2State == LOW){
//      
//      }
//  }
