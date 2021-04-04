#include "my_gpio.h"
Gpio::Gpio(GPIO_TypeDef* port_, const uint16_t pin, const uint8_t mode, const uint8_t pull_up, const uint8_t speed) :
port(port_) {
    GPIO_InitTypeDef my_gpio;      // initialize gpio
    my_gpio.Pin = pin; 	        // configure pin
    my_gpio.Mode = mode;	        // define it as output or input
    my_gpio.Pull = pull_up;	    // define pull up on or off
    my_gpio.Speed = speed;	        // define needed speed LOW HIGH MEDIUM
    HAL_GPIO_Init(port, &my_gpio); // initialize GPIOx module
    gpio = my_gpio;
}

void Gpio::enable() {
    HAL_GPIO_WritePin(port, gpio.Pin, GPIO_PinState::GPIO_PIN_SET);
}

void Gpio::disable() {
    HAL_GPIO_WritePin(port, gpio.Pin, GPIO_PinState::GPIO_PIN_RESET);
}
