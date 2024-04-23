
#define BLYNK_TEMPLATE_ID "TMPL4qI-BPtpu"
#define BLYNK_TEMPLATE_NAME "Weighing Scale"
#define BLYNK_AUTH_TOKEN "AUTH TOKEN FROM BLYNK"
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "WIFI_name";
char pass[] = "WIFI_password";


#include "HX711.h"
#include <Wire.h>

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 18;
const int LOADCELL_SCK_PIN = 4;

HX711 scale;
int reading;
int lastReading;
//REPLACE WITH YOUR CALIBRATION FACTOR
#define CALIBRATION_FACTOR 13.4


void setup() {
  Serial.begin(57600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  delay(1000);



  Serial.println("Initializing the scale");
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  scale.set_scale(CALIBRATION_FACTOR);  // this value is obtained by calibrating the scale with known weights
  scale.tare();   // reset the scale to 0
  
  Serial.println("5 sec");
  //delay(5000);                     
}

void loop() {
  Blynk.run();
  


  if (scale.wait_ready_timeout(200)) {
    reading = round(scale.get_units());
    //Serial.print("Weight: ");
    Serial.print(reading);
    //Serial.print("Gram");
    Serial.println();
    Blynk.virtualWrite(V0,reading);

    lastReading = reading;
    delay(1000);
  } else {
    Serial.println("HX711 not found.");
  }
}
