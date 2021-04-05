#include "my_tim.hpp"

Tim::Tim(TIM_TypeDef* TIM, uint32_t period, uint32_t prescaler, uint32_t clock_division, uint32_t counter_mode,
              uint32_t repetition_counter, uint32_t auto_reload_preload) {
    TIM_HandleTypeDef my_tim;
    my_tim.Instance = TIM;
    my_tim.Init.Period = period;
    my_tim.Init.Prescaler = prescaler;
    my_tim.Init.ClockDivision = clock_division;
    my_tim.Init.CounterMode = counter_mode;
    my_tim.Init.RepetitionCounter = repetition_counter;
    my_tim.Init.AutoReloadPreload = auto_reload_preload;
    HAL_TIM_Base_Init(&my_tim);
    tim = my_tim;
}

