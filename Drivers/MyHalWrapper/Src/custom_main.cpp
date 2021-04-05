#include <array>
#include "custom_main.h"

TIM_HandleTypeDef tim3;

extern "C" void custom_main() {

    Gpio PWM_A(GPIOA, GPIO_PIN_6, GPIO_MODE_AF_PP);
    PWM_A.alternative_funtion_selection(GPIO_AF2_TIM3);

    Gpio PWM_B(GPIOA, GPIO_PIN_7, GPIO_MODE_AF_PP);
    PWM_A.alternative_funtion_selection(GPIO_AF2_TIM3);


//    tim3.Instance = TIM3;
//    tim3.Init.Period = 100 - 1;
//    tim3.Init.Prescaler = 5000 -1;
//    tim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
//    tim3.Init.CounterMode = TIM_COUNTERMODE_UP;
//    tim3.Init.RepetitionCounter = 0;
//    tim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
//    HAL_TIM_Base_Init(&tim3);


    Tim tim3(TIM3);

    TIM_OC_InitTypeDef oc;
    oc.OCMode = TIM_OCMODE_PWM1;
    oc.Pulse = 0;
    oc.OCPolarity = TIM_OCPOLARITY_HIGH;
    oc.OCNPolarity = TIM_OCNPOLARITY_LOW;
    oc.OCFastMode = TIM_OCFAST_DISABLE;
    oc.OCIdleState = TIM_OCIDLESTATE_SET;
    oc.OCNIdleState = TIM_OCNIDLESTATE_RESET;

    HAL_TIM_PWM_ConfigChannel(reinterpret_cast<TIM_HandleTypeDef *>(&tim3), &oc, TIM_CHANNEL_1);
    HAL_TIM_PWM_ConfigChannel(reinterpret_cast<TIM_HandleTypeDef *>(&tim3), &oc, TIM_CHANNEL_2);


    HAL_TIM_PWM_Start(reinterpret_cast<TIM_HandleTypeDef *>(&tim3), TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(reinterpret_cast<TIM_HandleTypeDef *>(&tim3), TIM_CHANNEL_2);

    while (1){
        TIM3->CCR1 = 25;
        HAL_Delay(1000);
        TIM3->CCR1 = 50;
        HAL_Delay(1000);
        TIM3->CCR1 = 75;
        HAL_Delay(1000);
        TIM3->CCR1 = 100;
        HAL_Delay(1000);
        TIM3->CCR2 = 25;
        HAL_Delay(1000);
        TIM3->CCR2 = 50;
        HAL_Delay(1000);
        TIM3->CCR2 = 75;
        HAL_Delay(1000);
        TIM3->CCR2 = 100;
        HAL_Delay(1000);

    }
}
