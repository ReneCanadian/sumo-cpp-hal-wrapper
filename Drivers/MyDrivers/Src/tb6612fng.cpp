#include "tb6612fng.hpp"


Tb6612fng::Tb6612fng(Gpio &AIN1_, Gpio &AIN2_, Pwm &PWMA_, Gpio &BIN1_, Gpio &BIN2_, Pwm &PWMB_) :
AIN1(AIN1_), AIN2(AIN2_), PWMA(PWMA_), BIN1(BIN1_), BIN2(BIN2_), PWMB(PWMB_){}

void Tb6612fng::drive(const Direction direction, const uint8_t speed, const Angle angle) {
    switch (direction) {
        case Direction::FORWARD:
            ///setting output for turning motors clockwise
            AIN1.enable();
            AIN2.disable();
            ///setting output for turning motors counter-clockwise
            BIN1.disable();
            BIN2.enable();
            ///enabling motor speeds
            PWMA.set_ccr(speed);
            PWMB.set_ccr(speed);
            break;
        case Direction::RIGHT:
            break;
        case Direction::LEFT:
            break;
        case Direction::REVERSE:
            ///setting output for turning motors counter-clockwise
            AIN1.disable();
            AIN2.enable();
            ///setting output for turning motors clockwise
            BIN1.enable();
            BIN2.disable();
            ///enabling motor speeds
            PWMA.set_ccr(speed);
            PWMB.set_ccr(speed);
            break;
    }
}