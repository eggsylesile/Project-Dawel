
//define scope for RYG
#define RED 2
#define YELLOW 3
#define GREEN 4

//define scope for segments
#define segA 5 //segment A to PIN5
#define segB 6 //segment B to PIN6
#define segC 7 //segment C to PIN7
#define segD 8 //segment D to PIN8
#define segE 9 //segment E to PIN9
#define segF 10 //segmen F to PIN10
#define segG 11 //segment G to PIN10

//define buttons 
#define gbutton 12
#define rbutton 13

void setup() {
  // LED SCOPE
  pinMode(RED, OUTPUT); // RED LED
  pinMode(YELLOW, OUTPUT); // YELLOW LED
  pinMode(GREEN, OUTPUT); // GREEN LED

  //Button 
  pinMode(gbutton, INPUT);
  pinMode(rbutton, INPUT);

  // SEVEN SEGMENTS SCOPE
  for (int i=5;i<12;i++)
    {
      pinMode(i, OUTPUT); //taking all pins from 5-11 as output
    }
 
}
  



void loop() {
  if(digitalRead(gbutton) == HIGH)
  {
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, HIGH);
    
  }else if(digitalRead(rbutton) == HIGH)
  {
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);
    
  }else {
    
  for (int r=2;r>=0;r--)  //RED LED on for 20 sec and count in disp
   {
     rBypass:
      while(digitalRead(gbutton) == HIGH)
     {
      digitalWrite(RED, LOW);
      digitalWrite(YELLOW, LOW);
      digitalWrite(GREEN, HIGH);
      digitalWrite(segA, LOW);
      digitalWrite(segB, LOW);
      digitalWrite(segC, LOW);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segG, HIGH);
     }

     rrBypass:
      while(digitalRead(rbutton) == HIGH)
     {
      digitalWrite(RED, HIGH);
      digitalWrite(YELLOW, LOW);
      digitalWrite(GREEN, LOW);
      digitalWrite(segA, LOW);
      digitalWrite(segB, LOW);
      digitalWrite(segC, LOW);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segG, HIGH);
     }
          
     digitalWrite(RED, HIGH);
     digitalWrite(YELLOW, LOW);
     digitalWrite(GREEN, LOW);
     
     switch(r)
      {
        case 0: //when r value is zero show "0" on disp for 10 seconds
        digitalWrite(segA, HIGH);
        digitalWrite(segB, HIGH);
        digitalWrite(segC, HIGH);
        digitalWrite(segD, HIGH);
        digitalWrite(segE, HIGH);
        digitalWrite(segF, HIGH);
        digitalWrite(segG, LOW);
        if(digitalRead(gbutton) == HIGH)
        { 
          goto rBypass; 
        }else if(digitalRead(rbutton) == HIGH)
        {
          goto rrBypass;
        }
        delay(9000);
        break;

        case 1: //when r value is 1 show "1" on disp for 10 seconds
        digitalWrite(segA, LOW);
        digitalWrite(segB, HIGH);
        digitalWrite(segC, HIGH);
        digitalWrite(segD, LOW);
        digitalWrite(segE, LOW);
        digitalWrite(segF, LOW);
        digitalWrite(segG, LOW);
        if(digitalRead(gbutton) == HIGH)
        {
          goto rBypass; 
        }else if(digitalRead(rbutton) == HIGH)
        {
          goto rrBypass;
        }
        delay(10000);
        break;

        case 2: //when r value is 2 show "2" on disp for one second
        digitalWrite(segA, HIGH);
        digitalWrite(segB, HIGH);
        digitalWrite(segC, LOW);
        digitalWrite(segD, HIGH);
        digitalWrite(segE, HIGH);
        digitalWrite(segF, LOW);
        digitalWrite(segG, HIGH);
        if(digitalRead(gbutton) == HIGH)
        { 
          goto rBypass; 
        }else if(digitalRead(rbutton) == HIGH)
        {
          goto rrBypass;
        }
        delay(1000);
        break;


        break;
      }
   }
   
   for (int g=1;g>=0;g--)  //GREEN LED on for 15 sec
    {

       gBypass:
       while(digitalRead(gbutton) == HIGH)
         {
          digitalWrite(RED, LOW);
          digitalWrite(YELLOW, LOW);
          digitalWrite(GREEN, HIGH);
          digitalWrite(segA, LOW);
          digitalWrite(segB, LOW);
          digitalWrite(segC, LOW);
          digitalWrite(segD, LOW);
          digitalWrite(segE, LOW);
          digitalWrite(segF, LOW);
          digitalWrite(segG, HIGH);
         }

        ggBypass:
        while(digitalRead(rbutton) == HIGH)
        {
          digitalWrite(RED, HIGH);
          digitalWrite(YELLOW, LOW);
          digitalWrite(GREEN, LOW);
          digitalWrite(segA, LOW);
          digitalWrite(segB, LOW);
          digitalWrite(segC, LOW);
          digitalWrite(segD, LOW);
          digitalWrite(segE, LOW);
          digitalWrite(segF, LOW);
          digitalWrite(segG, HIGH);
        }
      digitalWrite(RED, LOW);
      digitalWrite(YELLOW, LOW);
      digitalWrite(GREEN, HIGH);

      switch(g)
      {

        case 1: //when g value is one show "1" on disp for 5 seconds
        digitalWrite(segA, LOW);
        digitalWrite(segB, HIGH);
        digitalWrite(segC, HIGH);
        digitalWrite(segD, LOW);
        digitalWrite(segE, LOW);
        digitalWrite(segF, LOW);
        digitalWrite(segG, LOW);
        if(digitalRead(gbutton) == HIGH)
        { 
          goto gBypass;
        }else if(digitalRead(rbutton) == HIGH)
        {
          goto ggBypass;
        }
        delay(6000);
        break;
  
        case 0: //when g value is zero show "0" on disp for 10 seconds
        digitalWrite(segA, HIGH);
        digitalWrite(segB, HIGH);
        digitalWrite(segC, HIGH);
        digitalWrite(segD, HIGH);
        digitalWrite(segE, HIGH);
        digitalWrite(segF, HIGH);
        digitalWrite(segG, LOW);
        if(digitalRead(gbutton) == HIGH)
        { 
          goto gBypass; 
        }else if(digitalRead(rbutton) == HIGH)
        {
          goto ggBypass;
        }
        delay(9000);
        break;


        break;
      }
    }

  yBypass:  
  while(digitalRead(gbutton) == HIGH)
     {
      digitalWrite(RED, LOW);
      digitalWrite(YELLOW, LOW);
      digitalWrite(GREEN, HIGH);
      digitalWrite(segA, LOW);
      digitalWrite(segB, LOW);
      digitalWrite(segC, LOW);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segG, HIGH);
     }

   yyBypass:
   while(digitalRead(rbutton) == HIGH)
   {
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(segA, LOW);
    digitalWrite(segB, LOW);
    digitalWrite(segC, LOW);
    digitalWrite(segD, LOW);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, HIGH);
   }
  //YELLOW LED on for 4 sec
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);
  //set first digit to "0" on disp play for 4 seconds
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, LOW);
  if(digitalRead(gbutton) == HIGH)
  { 
    goto yBypass; 
  }else if(digitalRead(rbutton) == HIGH)
  {
    goto yyBypass;
  }
  delay(4000);
  
  }
}
 
