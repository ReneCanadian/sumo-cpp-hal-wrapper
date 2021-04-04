#include "stm32f4xx.h"

void custom_main();

int main(void) {
    HAL_Init();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    custom_main();
}