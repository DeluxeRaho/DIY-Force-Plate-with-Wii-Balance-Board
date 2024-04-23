  
  #define BLYNK_TEMPLATE_ID "" //Template ID from blynk
  #define BLYNK_TEMPLATE_NAME "Weighing Scale"
  #define BLYNK_AUTH_TOKEN "" //Add AUTH TOKEN from Blynk
  #define BLYNK_PRINT Serial
  
  
  #include <WiFi.h>
  #include <WiFiClient.h>
  #include <BlynkSimpleEsp32.h>
  
  // Your WiFi credentials.
  // Set password to "" for open networks.
  char ssid[] = "WIFI_name";
  char pass[] = "WIFI_pass";
  
  
  #include "HX711.h" 
  
  const int LOADCELL_DOUT_PIN1 = 18;
  const int LOADCELL_SCK_PIN1 = 4;
  
  const int LOADCELL_DOUT_PIN2 = 15;
  const int LOADCELL_SCK_PIN2 = 2;
  
  const int LOADCELL_DOUT_PIN3 = 19;
  const int LOADCELL_SCK_PIN3 = 21;
  
  const int LOADCELL_DOUT_PIN4 = 12;
  const int LOADCELL_SCK_PIN4 = 13;
  
  HX711 scale1;
  int reading1;
  int lastReading1;
  
  HX711 scale2;
  int reading2;
  int lastReading2;
  
  HX711 scale3;
  int reading3;
  int lastReading3;
  
  HX711 scale4;
  int reading4;
  int lastReading4;
  
  #define CALIBRATION_FACTOR1 0 //Add calibration factor for every load cell
  #define CALIBRATION_FACTOR2 0
  #define CALIBRATION_FACTOR3 0
  #define CALIBRATION_FACTOR4 0
  
  
  BlynkTimer timer;
  
  
  void setup() {
  
    Serial.begin(57600);
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
    delay(1000);
  
  
  
    Serial.println("Initializing the scale");
    scale1.begin(LOADCELL_DOUT_PIN1, LOADCELL_SCK_PIN1);
  
    scale1.set_scale(CALIBRATION_FACTOR1);  
    scale1.tare();               // reset the scale to 0
  
    scale2.begin(LOADCELL_DOUT_PIN2, LOADCELL_SCK_PIN2);
  
    scale2.set_scale(CALIBRATION_FACTOR2);   
    scale2.tare();               // reset the scale to 0
  
    scale3.begin(LOADCELL_DOUT_PIN3, LOADCELL_SCK_PIN3);
  
    scale3.set_scale(CALIBRATION_FACTOR3);   
    scale3.tare();               // reset the scale to 0
  
    scale4.begin(LOADCELL_DOUT_PIN4, LOADCELL_SCK_PIN4);
  
    scale4.set_scale(CALIBRATION_FACTOR4);   
    scale4.tare();               // reset the scale to 0
  
    timer.setInterval(2000L, myTimerEvent);
  
  }
  
  void loop() {
    Blynk.run();
    timer.run(); //
  }
  
  void myTimerEvent()
  {
    scale1.tare();
  
    if (scale1.wait_ready_timeout(200)) {
      reading1 = round(scale1.get_units());
      Serial.print("Weight-1: ");
      Serial.print(reading1);
      Serial.print(" gram");
      Serial.println();
      Blynk.virtualWrite(V0, reading1);
  
      lastReading1 = reading1;
    }
    else {
      Serial.println("HX711-1 not found.");
    }
  
    scale2.tare();
  
    if (scale2.wait_ready_timeout(200)) {
      reading2 = round(scale2.get_units());
      Serial.print("Weight-2: ");
      Serial.print(reading2);
      Serial.print(" gram");
      Serial.println();
      Blynk.virtualWrite(V1, reading2);
  
      lastReading2 = reading2;
    }
    else {
      Serial.println("HX711-2 not found.");
  
    }
  
    scale3.tare();
  
    if (scale3.wait_ready_timeout(200)) {
      reading3 = round(scale3.get_units());
      Serial.print("Weight-3: ");
      Serial.print(reading3);
      Serial.print(" gram");
      Serial.println();
      Blynk.virtualWrite(V2, reading3);
  
      lastReading3 = reading3;
    }
    else {
      Serial.println("HX711-3 not found.");
    }
  
    scale1.tare();
  
    if (scale4.wait_ready_timeout(200)) {
      reading4 = round(scale4.get_units());
      Serial.print("Weight-4: ");
      Serial.print(reading4);
      Serial.print(" gram");
      Serial.println();
      Blynk.virtualWrite(V3, reading4);
  
      lastReading4 = reading4;
    }
    else {
      Serial.println("HX711-4 not found.");
    }
  }
