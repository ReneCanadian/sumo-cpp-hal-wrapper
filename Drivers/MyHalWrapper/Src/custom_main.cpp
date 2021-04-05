#include <array>
#include "custom_main.h"

TIM_HandleTypeDef tim3;

extern "C" void custom_main() {

    Gpio PWM_A(GPIOA, GPIO_PIN_6, GPIO_MODE_AF_PP);
    PWM_A.alternative_funtion_selection(GPIO_AF2_TIM3);

    Gpio PWM_B(GPIOA, GPIO_PIN_7, GPIO_MODE_AF_PP);
    PWM_B.alternative_funtion_selection(GPIO_AF2_TIM3);




    Tim tim3(TIM3);
    Pwm pwm_a(PwmChannel::Channel_1, tim3);
    Pwm pwm_b(PwmChannel::Channel_2, tim3);
    pwm_a.pwm_start();
    pwm_b.pwm_start();



    while (1){
pwm_a.set_ccr(25);
HAL_Delay(1000);
pwm_a.set_ccr(50);
HAL_Delay(1000);

    }
}
