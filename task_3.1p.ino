
#include <BH1750FVI.h>

BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);

#include "thingProperties.h"

void setup() {

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  pinMode(LED_BUILTIN, OUTPUT);
  
  LightSensor.begin();
}

void loop() {
  ArduinoCloud.update();
  onLedChange();
  onLightChange();
}

void onLedChange()  {
  digitalWrite(LED_BUILTIN, led);
}

void onLightChange()  {
  light = LightSensor.GetLightIntensity();
  delay(1000);
}
