#include <MHZ19.h>

HardwareSerial Serial2(2);

MHZ19 mhz(&Serial2);

void setup()
{
  Serial.begin(115200);
  Serial.println(F("Starting..."));

  Serial2.begin(9600);
}

void loop()
{
  MHZ19_RESULT response = mhz.retrieveData();
  if (response == MHZ19_RESULT_OK)
  {
    Serial.print(F("CO2: "));
    Serial.println(mhz.getCO2());
    Serial.print(F("Temperature: "));
    Serial.println(mhz.getTemperature());
    Serial.print(F("Accuracy: "));
    Serial.println(mhz.getAccuracy());
  }
  else
  {
    Serial.print(F("Error, code: "));
    Serial.println(response);
  }
  
  delay(15000);
}