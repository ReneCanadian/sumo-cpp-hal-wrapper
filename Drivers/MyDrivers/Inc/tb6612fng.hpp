#pragma once
#include "stm32l0xx.h"
#include "my_pwm.hpp"
#include "my_gpio.h"

enum class Direction : uint8_t {
    RIGHT,
    LEFT,
    FORWARD,
    REVERSE
};

enum class Angle : uint8_t {
    _0_DEGREES,
    _30_DEGREES,
    _60_DEGREES,
    _90_DEGREES,
    _120_DEGREES,
    _150_DEGREES,
    _180_DEGREES,
};
///Plan to add Standby functionality in the future
class Tb6612fng {
public:
    Tb6612fng(Gpio &AIN1_, Gpio &AIN2_, Pwm &PWMA_, Gpio &BIN1_, Gpio &BIN2_, Pwm &PWMB_);
    void drive(const Direction direction, const uint8_t speed, const Angle angle = Angle::_0_DEGREES);
    void stop();
private:
    void turn(const Direction direction, const Angle angle);
    Gpio &AIN1;
    Gpio &AIN2;
    Pwm &PWMA;
    Gpio &BIN1;
    Gpio &BIN2;
    Pwm &PWMB;
};
