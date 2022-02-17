/*
Arduino Framework ESP32 test:
platform = https://github.com/platformio/platform-espressif32.git#feature/arduino-upstream
platform_packages = 
   framework-arduinoespressif32 @ https://github.com/espressif/arduino-esp32.git#idf-release/v4.4

Board Support:
; board = esp32dev
; board = esp32-s2-saola-1
board = esp32-c3-devkitm-1
; board_build.mcu = esp32s2
; board_build.mcu = esp32c3

For ESP-C3-12F(4M) the flash connected using DIO mode
  board_build.flash_mode = dio

*/
#include <Arduino.h>
#define LED_ON  1
#define LED_OFF 0

#if defined(NODEMCU_ESP32_C3_13)
  #define LED_BUILTIN_RED GPIO_NUM_3
  #define LED_BUILTIN_GREEN GPIO_NUM_4
  #define LED_BUILTIN_BLUE GPIO_NUM_5
  #define LED_BUILTIN_COOL GPIO_NUM_19
  #define LED_BUILTIN_WARM GPIO_NUM_18
  #define LED_BUILTIN LED_BUILTIN_WARM
#elif defined(NODEMCU_ESP32_S2_ESP_12K)  
  #define LED_BUILTIN 2
#endif

void setup() {
  Serial.begin(115200);
#if defined(NODEMCU_ESP32_C3_13)  
  pinMode(LED_BUILTIN_COOL, OUTPUT);
#endif  
  pinMode(LED_BUILTIN, OUTPUT);
  delay(1000);

  Serial.printf("Arduino Board: %s variant: %s\n", ARDUINO_BOARD, ARDUINO_VARIANT);
  Serial.printf("Chip model: %s, Core: %d, CPU Freq: %u\n", 
    ESP.getChipModel(), ESP.getChipCores(), ESP.getCpuFreqMHz());
  Serial.printf("Flash size: %u, speed: %u, mode: %d\n", ESP.getFlashChipSize(), ESP.getFlashChipSpeed(), ESP.getFlashChipMode());
  Serial.printf("PSRAM size: %u, free: %u\n", ESP.getPsramSize(), ESP.getFreePsram());
  Serial.printf("Heap size: %u, free: %u\n", ESP.getHeapSize(), ESP.getFreeHeap());
}

int nCount=0;
void loop() {
  digitalWrite(LED_BUILTIN, LED_ON);
  Serial.printf("Hello World %d\n", nCount++);
  delay(100);
  digitalWrite(LED_BUILTIN, LED_OFF);
  delay(3000);
}