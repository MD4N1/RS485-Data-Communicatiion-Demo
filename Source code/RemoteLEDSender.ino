#include <Arduino.h>
#include <ICSC.h>
char* belekok;
void pressed(unsigned char src, char command, unsigned char len, char *data)
{
  digitalWrite(11, HIGH);
}

void released(unsigned char src, char command, unsigned char len, char *data)
{
  digitalWrite(11, LOW);
}

void setup()
{
  ICSC.begin(1, 115200,2);
  ICSC.begin()
  ICSC.registerCommand('P', &pressed);
  ICSC.registerCommand('R', &released);
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  pinMode(13, INPUT_PULLUP);

}

void loop()
{
  static unsigned char lastPress = digitalRead(13);

  if (lastPress != digitalRead(13))
    {
        lastPress = digitalRead(13);

        if (lastPress == LOW)
            {
              ICSC.broadcast('P',20,"panji");

            }
        else
            {
                ICSC.send(2, 'R', 0, NULL);
                ICSC.send(3, 'R', 0, NULL);
                ICSC.send(4, 'R', 0, NULL);
                ICSC.send(5, 'R', 0, NULL);
                ICSC.send(6, 'R', 0, NULL);
                ICSC.send(7, 'R', 0, NULL);
            }
    }
    ICSC.process();
}
