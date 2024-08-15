#include <ESP8266WiFi.h>
#include <PubSubClient.h>

//#define WIFI_SSID
const char* ssid = "Pas de connection :(";
const char* password = "men1lel9";
const char* mqtt_server = "<e22f6f30caa64f7d9f93f78b12f79d04.s1.eu.hivemq.cloud>";



void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");

  // Connect to WiFi
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to WiFi, IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  for (int i = 0; i < numLeds; i++) {
    String data = dataInit + String(i);
    ledState[i] = Firebase.getBool(data);
  }

  for (int i = 0; i < numLeds; i++) {
    if (ledState[i]) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }
}
