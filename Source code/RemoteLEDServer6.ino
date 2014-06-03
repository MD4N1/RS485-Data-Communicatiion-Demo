#include <Arduino.h>
#include <ICSC.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 10, 5, 4, 3, 2);

void pressed(unsigned char src, char command, unsigned char len, char *data)
{
  digitalWrite(13, HIGH);
  lcd.clear();
  lcd.print("dari -> ");
  lcd.print(src);
  lcd.setCursor(0,2);
  lcd.print(data);
}

void released(unsigned char src, char command, unsigned char len, char *data)
{
  digitalWrite(13, LOW);
  lcd.clear();
  lcd.print("dari -> ");
  lcd.print(src);
  lcd.setCursor(0,2);
  lcd.print(data);
}

void setup()
{
  ICSC.begin(7, 115200,7);
  ICSC.registerCommand('P', &pressed);
  ICSC.registerCommand('R', &released);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  pinMode(8, INPUT_PULLUP);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
}

void loop()
{
  static unsigned char lastPress = digitalRead(8);
  if (lastPress != digitalRead(8))
    {
        lastPress = digitalRead(8);

        if (lastPress == LOW)
            {
                //ICSC.broadcast('P', 0);
                ICSC.broadcast('P',20,"DODOL GARUT");
            }
        else
            {
                //ICSC.broadcast('R', 0);
                ICSC.broadcast('R',20,"OKE PISAN");

            }
    }
  ICSC.process();

}
