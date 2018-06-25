int redIN = 1;
int yellowIN = 2;
int greenIN = 3;
#define redOUT 4
#define yellowOUT 5
#define greenOUT 6
#define segA 7
#define segB 8
#define segC 9
#define segD 10
#define segE 11
#define segF 12
#define segG 13


void setup()
{
  for(int z=4;z<=13;z++)
  {
    pinMode(z, OUTPUT);
  }

  pinMode(redIN, INPUT);
  pinMode(yellowIN, INPUT);
  pinMode(greenIN, INPUT);

}

void loop()
{
  digitalWrite(redIN, LOW);
  int g = digitalRead(redIN); //green start when lane 1 red
  if(g == HIGH)
  {
    printf(g);
    digitalWrite(redOUT, LOW);
    digitalWrite(yellowOUT, LOW);
    digitalWrite(greenOUT, HIGH);
    for (int i=1;i>=0;i--)
    {
      switch(i)
      {
        case 1:
        digitalWrite(segA, LOW);
        digitalWrite(segB, HIGH);
        digitalWrite(segC, HIGH);
        digitalWrite(segD, LOW);
        digitalWrite(segE, LOW);
        digitalWrite(segF, LOW);
        digitalWrite(segG, LOW);
        delay(5000);
        break;

        case 0:
        digitalWrite(segA, HIGH);
        digitalWrite(segB, HIGH);
        digitalWrite(segC, HIGH);
        digitalWrite(segD, HIGH);
        digitalWrite(segE, HIGH);
        digitalWrite(segF, HIGH);
        digitalWrite(segG, LOW);
        delay(9000);
        break;

        break;
      }
    }
  }

  int y = digitalRead(yellowIN);
  if(y == HIGH)
  {
    digitalWrite(redOUT, LOW);
    digitalWrite(yellowOUT, HIGH);
    digitalWrite(greenOUT, LOW);
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, LOW);
    delay(3000);
  }

  int r = digitalRead(greenIN);
  if(r == HIGH)
  {
    digitalWrite(redOUT, HIGH);
    digitalWrite(yellowOUT, LOW);
    digitalWrite(greenOUT, LOW);
    for(int b=2;b>=0;b--)
    {
      switch(b)
      {
        case 2:
        digitalWrite(segA, HIGH);
        digitalWrite(segB, HIGH);
        digitalWrite(segC, LOW);
        digitalWrite(segD, HIGH);
        digitalWrite(segE, HIGH);
        digitalWrite(segF, LOW);
        digitalWrite(segG, HIGH);
        delay(1000);
        break;

        case 1:
        digitalWrite(segA, LOW);
        digitalWrite(segB, HIGH);
        digitalWrite(segC, HIGH);
        digitalWrite(segD, LOW);
        digitalWrite(segE, LOW);
        digitalWrite(segF, LOW);
        digitalWrite(segG, LOW);
        delay(10000);
        break;

        case 0:
        digitalWrite(segA, HIGH);
        digitalWrite(segB, HIGH);
        digitalWrite(segC, HIGH);
        digitalWrite(segD, HIGH);
        digitalWrite(segE, HIGH);
        digitalWrite(segF, HIGH);
        digitalWrite(segG, LOW);
        delay(9000);
        break;

        break;
      }
    }
  }
}

