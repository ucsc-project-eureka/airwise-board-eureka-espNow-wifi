// Only runs on ESP32S3 Dev Module board for debug port access.

#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>
#define WAIT_TIME 5000
#define SECOND_TIME 1000

uint8_t broadcastAddress[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
uint8_t sinkMAC[6];
bool sinkMACKnown = false;

// MAIN --------------------------------------------------------------
int lastTime = 0;
int currentTime = 0;
void setup(){
  Serial.begin(9600);
  while(!Serial){;}
  Serial.println("Serial connected!");
  WiFi.disconnect(true);
  WiFi.mode(WIFI_STA);

  if(esp_now_init() != ESP_OK){
    Serial.println("ESP-NOW init failed!");
    return;
  }

  Serial.println("ESP32 radio serial ready");
}

void loop() {
  // ping an outside ESP32 with hellos. wait every five seconds.
  while (currentTime - lastTime < WAIT_TIME){
    currentTime = millis();
  }
  // once they are equal, set to equal. then restart loop iteration.
  lastTime = currentTime;

  // execute sending task.
  esp_now_send();

}
