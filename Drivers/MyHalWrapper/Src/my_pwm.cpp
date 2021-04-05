#include "my_pwm.hpp"

Pwm::Pwm(PwmChannel channel_, Tim &tim_) : channel(channel_),
tim(tim_){
    TIM_OC_InitTypeDef oc;
    oc.OCMode = TIM_OCMODE_PWM1;
    oc.Pulse = 0;
    oc.OCPolarity = TIM_OCPOLARITY_HIGH;
    oc.OCNPolarity = TIM_OCNPOLARITY_LOW;
    oc.OCFastMode = TIM_OCFAST_DISABLE;
    oc.OCIdleState = TIM_OCIDLESTATE_SET;
    oc.OCNIdleState = TIM_OCNIDLESTATE_RESET;
    output_config = oc;
}

void Pwm::pwm_start() {
    HAL_TIM_PWM_ConfigChannel(reinterpret_cast<TIM_HandleTypeDef *>(&tim), &output_config,static_cast<uint32_t>(channel));
    HAL_TIM_PWM_Start(reinterpret_cast<TIM_HandleTypeDef *>(&tim), static_cast<uint32_t>(channel));
}

void Pwm::set_ccr(uint16_t CCR_value) {
    switch (channel) {
        case PwmChannel::Channel_1:
            tim.tim.Instance->CCR1 = CCR_value;
            break;
        case PwmChannel::Channel_2:
            tim.tim.Instance->CCR2 = CCR_value;
            break;
        case PwmChannel::Channel_3:
            tim.tim.Instance->CCR3 = CCR_value;
            break;
        case PwmChannel::Channel_4:
            tim.tim.Instance->CCR4 = CCR_value;
            break;
    }
}