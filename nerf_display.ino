#include <OLED_I2C.h>
#include <avr/pgmspace.h>
int BRIGHT = 255;
int AMMO;
int BAT;
OLED  myOLED(SDA, SCL);

extern uint8_t SmallFont[];
extern uint8_t sevenseg_xxxl_num[];
extern uint8_t battery[];

void setup()
{
    myOLED.begin();
    myOLED.setBrightness(BRIGHT);
}

void renderOLED(int ammo, int bat, bool light=false, bool laser=false)
{
    myOLED.clrScr();
    myOLED.setFont(SmallFont);
    if (light)
    {
      myOLED.print("LIGHT", RIGHT, 23);
    }
    if (laser)
    {
      myOLED.print("LASER", RIGHT, 39);
    }    
    
    // Fire mode indicator
    myOLED.invertText(true);
    myOLED.print("AUTO ", RIGHT, 55);
    myOLED.invertText(false);
    
    // Battery indicator
    myOLED.setFont(battery);
    myOLED.printNumI(bat, RIGHT, 0);

    // Ammo count
    myOLED.setFont(sevenseg_xxxl_num);
    myOLED.printNumI(ammo, LEFT, 0, 2, '0');
  
  
  
  
    myOLED.update();
}

void loop()
{
  for (BAT=0; BAT<10; BAT++)
  {
    renderOLED(BAT*2, BAT, true, true);
    delay(1000);
  }  
  delay(1000);
}
