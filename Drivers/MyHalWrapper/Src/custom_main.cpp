#include <array>
#include "custom_main.h"

TIM_HandleTypeDef tim3;

extern "C" void custom_main() {

    Gpio PWM_A(GPIOA, GPIO_PIN_6, GPIO_MODE_AF_PP); ///PA6
    PWM_A.alternative_funtion_selection(GPIO_AF2_TIM3);

    Gpio PWM_B(GPIOA, GPIO_PIN_7, GPIO_MODE_AF_PP); ///PA7
    PWM_B.alternative_funtion_selection(GPIO_AF2_TIM3);

    Gpio AIN2(GPIOB, GPIO_PIN_15); ///PB15
    Gpio AIN1(GPIOC, GPIO_PIN_13); ///PC13
    Gpio BIN2(GPIOC, GPIO_PIN_12); ///PC12
    Gpio BIN1(GPIOB, GPIO_PIN_13); ///PB13


    Tim tim3(TIM3);
    Pwm pwm_a(PwmChannel::Channel_1, tim3);
    Pwm pwm_b(PwmChannel::Channel_2, tim3);
    pwm_a.pwm_start();
    pwm_b.pwm_start();


    Tb6612fng hbridge(AIN1,AIN2, pwm_a, BIN1, BIN2, pwm_b);
    while (1){
HAL_Delay(1000);
hbridge.drive(Direction::FORWARD, 50);
HAL_Delay(1000);
hbridge.drive(Direction::FORWARD, 100);

    }
}
