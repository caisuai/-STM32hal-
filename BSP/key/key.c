#include "key.h"


#define IS_KEY_PRESSED() (HAL_GPIO_ReadPin(KEY_GPIO_Port, KEY_Pin) == GPIO_PIN_RESET)

uint8_t isKeyClicked() {
  static uint8_t pressed = 0; // 用于每次按键只返回一次点击事件
  if (IS_KEY_PRESSED() && !pressed) {
    HAL_Delay(10);
    if (IS_KEY_PRESSED()) {
      pressed = 1;
      return 1; // 按键被点击
    }
  }
  if (pressed && !IS_KEY_PRESSED()) {
    pressed = 0; // 按键释放，重置状态
  }
  return 0;
}

