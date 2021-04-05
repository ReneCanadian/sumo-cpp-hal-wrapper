#pragma once
#include "stm32f4xx.h"


class Tim{
public:
    Tim( TIM_TypeDef* TIM, uint32_t period = 99, uint32_t prescaler = 5000 -1,
         uint32_t clock_division = TIM_CLOCKDIVISION_DIV1, uint32_t counter_mode = TIM_COUNTERMODE_UP,
         uint32_t repetition_counter = 0, uint32_t auto_reload_preload = TIM_AUTORELOAD_PRELOAD_DISABLE);

private:
    TIM_HandleTypeDef tim;
};
