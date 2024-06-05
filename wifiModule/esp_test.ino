
#define BLYNK_TEMPLATE_ID           "TMPL2eRLZ3I_-"
#define BLYNK_TEMPLATE_NAME         "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "10qHSXj4L1k_CwFgO4PuH8KElGy1jHOj"

#define BLYNK_PRINT Serial


#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "passwords.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = WIFI_SSID;
char pass[] = WIFI_PASSWORD;

// Hardware Serial 
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(3, 4); // RX, TX

#define ESP8266_BAUD 115200

ESP8266 wifi(&EspSerial);

const int buttonPin = 2;

void setup()
{
  // Debug console
  pinMode(buttonPin, INPUT);
  lcd.begin();
  lcd.backlight();

  Serial.begin(9600);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(BLYNK_AUTH_TOKEN, wifi, ssid, pass);
}

void loop()
{
  int buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH){
    lcd.print("Exiting");
    digitalWrite(9, HIGH);
    return;
  }
  Blynk.run();
  lcd.clear();
  lcd.print("Balls in your");
  lcd.setCursor(0,1);
  lcd.print("Mouth");
  delay(1000);
  lcd.clear();
  lcd.print("PLANTER");
  lcd.setCursor(0,1);
  lcd.print("PLANTER");
  delay(1000);

}
