#include "U8glib.h"
#include <math.h>

// Nokia 5110
// U8GLIB_PCD8544 u8g(11, 10, 8, 9, 7); // Clk, Din, DC, CE, RST

// .96 OLED
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);  // I2C / TWI 


const int AOUTpin = 0;
const int DOUTpin = 8;
const int ledPin = 13;

int limit;
int value;

void draw()
{
  int num = analogRead(AOUTpin);
  int ortalama = round((num * 84) / 1024);

  char buffer[7];

  u8g.setFont(u8g_font_7x14);
  u8g.drawStr(0, 36, "Alcohol:");
  u8g.drawStr(60, 36, itoa(num, buffer, 10));

  u8g.drawRFrame(0, 0, 84, 24, 0.9);
  u8g.drawBox(0, 0, ortalama, 24);

  if (value > 100)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}

void setup()
{
  u8g.setColorIndex(1);
  //u8g.setRot180();
  Serial.begin(115200);
  pinMode(DOUTpin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  u8g.firstPage();

  do
  {
    draw();
  } while (u8g.nextPage());

  /*value = analogRead(AOUTpin);
  limit = digitalRead(DOUTpin);
  Serial.print("Alcohol value: ");
  Serial.println(value);
  Serial.print("Limit: ");
  Serial.print(limit);
  delay(1000);*/
  

  delay(1000);
}