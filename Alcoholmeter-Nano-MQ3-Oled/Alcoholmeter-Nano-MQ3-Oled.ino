
#include "U8glib.h"
#include <math.h>


U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);  // I2C / TWI 

const int AOUTpin=0;
const int ledPin=13;

int limit;
int value;


void sayfaYazdir() {
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr( 0, 22, "Merhaba Cuneyt");
  
  
  value= analogRead(AOUTpin);
  Serial.println(value);

  delay(1000);
}

void setup(void) {
  Serial.begin(115200);
  pinMode(AOUTpin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop(void) {
  // picture loop
  u8g.firstPage();
  int i = 0;
  do {
    sayfaYazdir();
  } while( u8g.nextPage() );
  
  delay(1000);
}
