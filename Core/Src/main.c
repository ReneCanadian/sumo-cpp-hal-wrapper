#include "stm32f4xx.h"

void custom_main();


int main(void)
{

    HAL_Init();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    __HAL_RCC_TIM3_CLK_ENABLE();

    custom_main();
}