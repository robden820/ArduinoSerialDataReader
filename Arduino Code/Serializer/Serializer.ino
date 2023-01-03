#include <ArduinoJson.h>

const int capacity = 2 * JSON_OBJECT_SIZE(1);
StaticJsonDocument<capacity> doc;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  doc["sensor"] = "Analog 0";
  doc["value"] = analogRead(A0);
//  float value = analogRead(A0);
//  Serial.println(value/4);

  serializeJson(doc, Serial);
  Serial.println();

  delay(1000);
}
