#include <array>
#include "custom_main.h"

TIM_HandleTypeDef tim2;
#define ADC_CHANNELS	1

uint16_t adc_value[ADC_CHANNELS];

extern "C" void custom_main() {

    Gpio PWM_A(GPIOA, GPIO_PIN_0, GPIO_MODE_AF_PP); ///PA0
    PWM_A.alternative_funtion_selection(GPIO_AF2_TIM2);

    Gpio PWM_B(GPIOA, GPIO_PIN_1, GPIO_MODE_AF_PP); ///PA1
    PWM_B.alternative_funtion_selection(GPIO_AF2_TIM2);

    Gpio AIN2(GPIOC, GPIO_PIN_6);
    Gpio AIN1(GPIOC, GPIO_PIN_8);
    Gpio BIN2(GPIOB, GPIO_PIN_2);
    Gpio BIN1(GPIOC, GPIO_PIN_5);

    Gpio debug_led(GPIOA, GPIO_PIN_5);

    Tim tim2(TIM2);
    Pwm pwm_a(PwmChannel::Channel_1, tim2);
    Pwm pwm_b(PwmChannel::Channel_2, tim2);
    pwm_a.pwm_start();
    pwm_b.pwm_start();

    Tb6612fng hbridge(AIN1,AIN2, pwm_a, BIN1, BIN2, pwm_b);
    DmaAdc line_detector_adc(AdcChannel::Channel_8, 1);
    line_detector_adc.init();
    line_detector_adc.start();
    while (1){
        debug_led.enable();
        hbridge.drive(Direction::FORWARD, 100);
        if (line_detector_adc.data[0] > 3900){
            hbridge.drive(Direction::FORWARD, 0);
            debug_led.disable();
            HAL_Delay(500);
        }

    }
}
