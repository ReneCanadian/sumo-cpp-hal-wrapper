#pragma once
#include "stm32f4xx.h"
#include "my_gpio.h"

enum class Direction : uint8_t{
    RIGHT,
    LEFT
};

class tb6612fng {

    void turn(Direction direction);
private:
    Gpio &AIN1;
    Gpio &AIN2;
    Gpio &PWMA;
    Gpio &BIN1;
    Gpio &BIN2;
    Gpio &PWMB;
};
