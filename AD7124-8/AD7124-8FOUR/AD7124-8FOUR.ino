  #define BLYNK_TEMPLATE_ID "" //Template ID från blynk
  #define BLYNK_TEMPLATE_NAME "Weighing Scale"
  #define BLYNK_AUTH_TOKEN "" //Lägg till AUTH TOKEN från Blynk
  #define BLYNK_PRINT Serial
  
  
  #include <WiFi.h>
  #include <WiFiClient.h>
  #include <BlynkSimpleEsp32.h>

    // Your WiFi credentials.
  // Set password to "" for open networks.
  char ssid[] = "WIFI_name";
  char pass[] = "WIFI_password";
  
  
  #include "NHB_AD7124.h"
  
  
  const uint8_t ssPin = 5;
  const int ledPin = 2;

  / Filter output rate selection bits, needs to be between 1 and 2047
  uint16_t filterSelectVal = 40;

  Ad7124 adc(ssPin, 4000000);
  
  void setup() {
  
   
    Serial.begin (115200);
    while (!Serial) {
      ; // wait for serial port to connect. Needed for native USB port only
    }
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
    delay(1000);
    
  
  
    adc.begin();
  
  adc.setAdcControl(AD7124_OpMode_Continuous, AD7124_FullPower, true);

  adc.setup[0].setConfig(AD7124_Ref_ExtRef1, AD7124_Gain_128, true);
  adc.setup[0].setFilter(AD7124_Filter_SINC4, filterSelectVal);

  adc.setChannel(0, 0, AD7124_Input_AIN0, AD7124_Input_AIN1, true);
  adc.setChannel(1, 0, AD7124_Input_AIN2, AD7124_Input_AIN3, true);
  adc.setChannel(2, 0, AD7124_Input_AIN4, AD7124_Input_AIN5, true);
  adc.setChannel(3, 0, AD7124_Input_AIN6, AD7124_Input_AIN7, true);

  adc.setPWRSW(1);
  }
  
 
  

  void loop() {
  
    double value1, value2, value3, value4;
    double offsetCoeff1 = 0.2188;
  
    digitalWrite (ledPin, 0);
    value1 = adc.readVolts(0);
    digitalWrite (ledPin, 1);

    Serial.println((((-value1)*1000)+offsetCoeff1)*48309, 3);
    Blynk.virtualWrite(V0, value1);

    double offsetCoeff2 = 0.2188;
    digitalWrite (ledPin, 0);
    value2 = adc.readVolts(1);
    digitalWrite (ledPin, 1);

    Serial.println((((-value2)*1000)+offsetCoeff2)*48309, 3);
    Blynk.virtualWrite(V0, value2);

    double offsetCoeff3 = 0.2188;
    digitalWrite (ledPin, 0);
    value3 = adc.readVolts(2);
    digitalWrite (ledPin, 1);

    Serial.println((((-value3)*1000)+offsetCoeff3)*48309, 3);
    Blynk.virtualWrite(V0, value3);

    double offsetCoeff4 = 0.2188;
    digitalWrite (ledPin, 0);
    value4 = adc.readVolts(3);
    digitalWrite (ledPin, 1);

    Serial.println((((-value4)*1000)+offsetCoeff4)*48309, 3);
    Blynk.virtualWrite(V0, value4);
  
  }
  
  
  
  
  
