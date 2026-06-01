#include <Arduino.h>
#include "wiring_private.h"

#define DEBUG_PORT SerialUSB

#define ESP_PIN_TX 15
#define ESP_PIN_RX 16

Uart ESP32Serial(&sercom0,
                 ESP_PIN_RX,
                 ESP_PIN_TX,
                 SERCOM_RX_PAD_3,
                 UART_TX_PAD_2);

void SERCOM0_Handler()
{
    ESP32Serial.IrqHandler();
}

void setup()
{
    DEBUG_PORT.begin(115200);
    while (!DEBUG_PORT);

    DEBUG_PORT.println("SAMD21 START");

    ESP32Serial.begin(9600);

    pinPeripheral(ESP_PIN_RX, PIO_SERCOM);
    pinPeripheral(ESP_PIN_TX, PIO_SERCOM);

    DEBUG_PORT.println("UART STARTED");
}

void loop()
{
    ESP32Serial.println("HELLO FROM SAMD21");
    delay(1000);
}
