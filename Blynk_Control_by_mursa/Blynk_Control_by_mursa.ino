#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6y-7DXgO0"
#define BLYNK_TEMPLATE_NAME "ESP32"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>



// Replace these with your actual Blynk and Wi-Fi credentials
char auth[] = "9EILaaN5F-s_zFuUIVM2H-ylHtt9FFZ7";     // e.g. "mJXbDDiYGRKjpdl0dMMMkfbWSay2ePmc"
char ssid[] = "OnePlus 11R 5G";       // e.g. "MyWiFi"
char pass[] = "123456789";   // e.g. "MyPassword"




// LED pins
#define LED1 25
#define LED2 26
#define LED3 27

void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");
  Blynk.begin(auth, ssid, pass);
}

// Virtual pin V0 → LED1
BLYNK_WRITE(V0) {
  int val = param.asInt();
  digitalWrite(LED1, val);
}

// Virtual pin V1 → LED2
BLYNK_WRITE(V1) {
  int val = param.asInt();
  digitalWrite(LED2, val);
}

// Virtual pin V2 → LED3
BLYNK_WRITE(V2) {
  int val = param.asInt();
  digitalWrite(LED3, val);
}

void loop() {
  Blynk.run();
}
