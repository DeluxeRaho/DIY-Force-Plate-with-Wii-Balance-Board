  
  #include <ad7124.h>
  
  
  const int ledPin = 9;
  const int ssPin = 5;
  
  
  Ad7124Chip adc;
  
  
  
  void setup() {
  
    pinMode (ledPin, OUTPUT);
    digitalWrite (ledPin, 1); // clear the LED
  
    //Initialize serial and wait for port to open:
    Serial.begin (115200);
    while (!Serial) {
      ; // wait for serial port to connect. Needed for native USB port only
    }
  
  
    Serial.println ("AD7124 Voltmeter");
  
    adc.begin (ssPin);
  
    adc.setConfig (0, Ad7124::RefInternal, Ad7124::Pga1, true);

    adc.setConfigFilter(0, Ad7124::Sinc4Filter, Ad7124::dB47PostFilter, 1, false, false);

    //adc.setConfigFilter(0, Ad7124::Sinc4FastFilter, Ad7124::dB47PostFilter, 1, false, false);
  
    adc.setChannel (0, 0, Ad7124::AIN1Input, Ad7124::AIN0Input);
  
    adc.setAdcControl (Ad7124::ContinuousMode, Ad7124::FullPower, true);
  }
  
 
  void loop() {
  
    long value1;
    double voltage1;
  
  
    digitalWrite (ledPin, 0);
    value1 = adc.read (0);
    digitalWrite (ledPin, 1);
  
    if (value1 >= 0) {
  
  
      voltage1 = Ad7124Chip::toVoltage (value1, 1, 2.5, true);
      // Print result
  
      Serial.println(((voltage1*1000000)+524)/0.0208, 3);
      //Serial.println();
      //delay(1000);
    }
    else {
  
      Serial.println ("FAIL1");
    }
  }
  
  
  
  
  
