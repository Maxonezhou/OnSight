#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <FirebaseArduino.h>

#include <PatrickVector.h>

#define SSID "HackWestern6"
#define PASSWORD "42259378376"

#define FIREBASE_HOST "onsight-88888.firebaseio.com"
#define FIREBASE_AUTH "EVixsuIwzMaTEtOcECwnvSoTiI0Mb7NcRBCM7Hjs"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>

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


struct PQ
{
  Vector<Data> storage;
  int size;
  
  PQ()
  {
    size = 0;
  }
  void Min_Heapify(int indx)
  {
    int min = indx;
		int left = 2 * indx + 1;
		int right = 2 * indx + 2;
		if ((left <= size - 1) && (storage[left].emergency_level < storage[indx].emergency_level))
		{
			min = left;
		}
		else
		{
			min = indx;
		}
		if ((right <= size - 1) && (storage[right].emergency_level < storage[min].emergency_level))
		{
			min = right;
		}
		if (min != indx)
		{
			Data temp;
			temp = storage[min];
			storage[min] = storage[indx];
			storage[indx] = temp;
			Min_Heapify(min);
		}
  }
};

void drawchar(String s, int size) {
  display.clearDisplay();

  display.setTextSize(size);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  for (int i = 0; i < s.length(); i++) {
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

void displayMessage(struct Data* data) {
    String details = String(data->details);
    int emergencyInt = data->emergency_level;
    String location = String(data->location);
    String situation = String(data->situation);

    char d[details.length() + 1];
	  strcpy(d, details.c_str());

    char l[location.length() + 1];
	  strcpy(l, location.c_str());

    char s[situation.length() + 1];
	  strcpy(s, situation.c_str());

    drawchar(details, 2);

    delay(5000);

    String emergency = "Emergency Level: " + String(emergencyInt); //concatenate to make emergency string
    char e[emergency.length() + 1];
	  strcpy(e, emergency.c_str());
    drawchar(e, 2);

    delay(5000);

    drawchar(location, 2);

    delay(5000);

    drawchar(situation, 2);

    delay(3000);
}

void ConnectToWiFi()
{
    delay(100);
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.print(SSID);
    /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
    would try to act as both a client and an access-point and could cause
    network-issues with your other WiFi-devices on your WiFi-network. */
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    Serial.println("Begin connecting to wifi");
    //start connecting to WiFi
    WiFi.begin(SSID, PASSWORD);
    //while client is not connected to WiFi keep loading
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("WiFi connected to ");
    Serial.println(SSID);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println("");
}

  PQ* glasses = new PQ();
  int counter = 0;
  int for_counter = 0;
  String details = "";
  String emergency_level = "";
  String location = "";
  String situation = "";

  char emergency_arr[] = "emergency_level";
  char* emergency_comp = emergency_arr;
  char details_arr[] = "details";
  char* details_comp = details_arr;
  char location_arr[] = "location";
  char* location_comp = location_arr;
  char situation_arr[] = "situation";
  char* situation_comp = situation_arr;

void setup() 
{
  Serial.begin(115200);
  Wire.begin();

  // ESP8266
  ConnectToWiFi();
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
  { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  Firebase.stream("/list");
  
}
 
void loop() 
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Hello, World!");
  
  if (Firebase.failed()) 
  {
     Serial.println("streaming error");
    Serial.println(Firebase.error());
  }

  if (Firebase.available()) 
  {
     FirebaseObject event = Firebase.readEvent();
     JsonObject& obj = event.getJsonVariant();
     for (JsonObject::iterator it=obj.begin(); it != obj.end(); ++it)
     {
       Serial.print("[INFO] it->key: ");
       Serial.println(it->key);
       Serial.print("[INFO] it->value: ");
       Serial.println(it->value.as<char*>());
       for(const auto& kv : it->value.as<JsonObject>()) {
          Serial.print("[INFO] kv.key: ");
          Serial.println(kv.key);
          Serial.print("[INFO] kv.value: ");
          Serial.println(kv.value.as<String>());

          if (strcmp(kv.key, emergency_comp) == 0)
          {
            Serial.println("1");
            emergency_level = kv.value.as<String>();
          }
          if (strcmp(kv.key, location_comp) == 0)
          {
            Serial.println("2");
            location = kv.value.as<String>();
          }
          if (strcmp(kv.key, situation_comp) == 0)
          {
            Serial.println("3");
            situation = kv.value.as<String>();
          }
          if (strcmp(kv.key, details_comp) == 0)
          {
            Serial.println("4");
            details = kv.value.as<String>();
          }
          if ((emergency_level != "") && 
              (location != "") &&
              (situation != "") &&
              (details != ""))
          {
            Data* temp = new Data();
             temp->details = details;
             temp->emergency_level = emergency_level.toInt();
             temp->situation = situation;
             temp->location = location;

             glasses->storage.push_back(*temp);
             for (int i = glasses->storage.size() - 1; i >= 0; i--)
             {
               glasses->Min_Heapify(i);
             }
             Serial.println(glasses->storage.size());

            Serial.print("details: ");
            Serial.println(glasses->storage[0].details);
            Serial.print("emergency_level: ");
            Serial.println(glasses->storage[0].emergency_level);
            Serial.print("situation: ");
            Serial.println(glasses->storage[0].situation);
            Serial.print("location: ");
            Serial.println(glasses->storage[0].location);
          }
      }
    }

  }
  if (glasses->storage.size() == 0)
  {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("Hello, World!");
    Serial.println("enter");
  }
  else
  {
    for (int i = 0; i < glasses->storage.size(); i++)
    {
      displayMessage(&(glasses->storage[i]));

    }
  }
  delay(1000);
}