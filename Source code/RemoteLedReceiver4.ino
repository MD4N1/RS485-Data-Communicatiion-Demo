#include <Arduino.h>
#include <ICSC.h>

void pressed(unsigned char src, char command, unsigned char len, char *data)
{
  digitalWrite(13, HIGH);
}

void released(unsigned char src, char command, unsigned char len, char *data)
{
  digitalWrite(13, LOW);
}

void setup()
{
  ICSC.begin(5, 115200,2);
  ICSC.registerCommand('P', &pressed);
  ICSC.registerCommand('R', &released);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  pinMode(11,INPUT_PULLUP);
}

void loop()
{
  static unsigned char lastPress = digitalRead(11);

  if (lastPress != digitalRead(11))
    {
        lastPress = digitalRead(11);

        if (lastPress == LOW)
            {
              ICSC.broadcast('P',20,"SUPERMAN");

            }
        else
            {
               ICSC.broadcast('R',20,"SUPARMAN");
            }
    }
    ICSC.process();
}
