#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     LED_BUILTIN // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


struct Data
{
  String details;
  int emergency_level;
  String location;
  String situation;

  Data()
  {
    details = "";
    emergency_level = 0;
    location = "";
    situation = "";
  }
};

void displayMessage(struct Data* data) {
    String details = String(data->details);
    int emergency_level = String(data->emergency_level);
    String location = String(data->location);
    String situation = String(data->situation);

    char d[details.size() + 1];
	strcpy(d, details.c_str());

    char e[emergency.size() + 1];
	strcpy(e, emergency.c_str());

    char e[1];
    sprintf(e, "%d", emergency_level);

    char l[10];
	strcpy(l, location.c_str());

    char s[situation.size() + 1];
	strcpy(s, situation.c_str());

    drawchar(details);

    delay(5000);

    String emergency = "Emergency Level: " + emergency_level; //concatenate to make emergency string
    drawchar(emergency);

    delay(5000);

    drawchar(location);

    delay(5000);

    drawchar(situation);
}


void drawchar(String s) {
  display.clearDisplay();

  display.setTextSize(3);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  for (int i = 0; i < s.size(); i++) {
      display.write(s[i]);
  }
  display.display();
}

void drawstyles(String s) {
  display.clearDisplay();

  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
//   display.println(F(s));
  display.display();
  delay(2000);
}

void drawscroll(String s) {
  display.clearDisplay();

  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
//   display.println(F(s));
  display.display();      // Show initial text
  delay(100);

  // Scroll in various directions, pausing in-between:
  display.startscrollright(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrolldiagright(0x00, 0x07);
  delay(2000);
  display.startscrolldiagleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
  delay(1000);
}