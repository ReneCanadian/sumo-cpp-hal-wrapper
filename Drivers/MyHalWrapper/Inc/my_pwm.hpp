#pragma once
#include "stm32f4xx.h"

enum class PwmChannel{
    Channel_1 = TIM_CHANNEL_1,
    Channel_2 = TIM_CHANNEL_2,
    Channel_3 = TIM_CHANNEL_3,
    Channel_4 = TIM_CHANNEL_4
};

class Pwm {
public:
    void set_ccr(uint16_t CCR);

private:
   PwmChannel channel;
};
