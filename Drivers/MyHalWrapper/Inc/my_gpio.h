#pragma once
#include "stm32f4xx.h"

enum class GpioState {SET , RESET};


class Gpio{
public:
    Gpio(GPIO_TypeDef *port_, const uint16_t pin, const uint8_t mode = GPIO_MODE_OUTPUT_PP, const uint8_t pull_up = GPIO_NOPULL, uint8_t speed = GPIO_SPEED_FREQ_LOW);

    void enable();
    void disable();


private:
    GPIO_InitTypeDef gpio;
    GPIO_TypeDef* port;
};
