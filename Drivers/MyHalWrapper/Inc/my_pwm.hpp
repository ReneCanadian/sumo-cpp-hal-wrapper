#pragma once
#include "stm32f4xx.h"
#include "my_tim.hpp"
#include "my_gpio.h"

enum class PwmChannel : uint32_t {
    Channel_1 = TIM_CHANNEL_1,
    Channel_2 = TIM_CHANNEL_2,
    Channel_3 = TIM_CHANNEL_3,
    Channel_4 = TIM_CHANNEL_4
};

class Pwm {
public:
    Pwm(PwmChannel channel_, Tim &tim_);
    void set_ccr(uint16_t CCR);
    void pwm_start();
private:
   PwmChannel channel;
   Tim &tim;
   TIM_OC_InitTypeDef output_config;
};
