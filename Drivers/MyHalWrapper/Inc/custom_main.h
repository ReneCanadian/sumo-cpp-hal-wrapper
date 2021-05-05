#pragma once
#include "my_gpio.h"
#include "my_pwm.hpp"
#include "tb6612fng.hpp"
#include "main.h"
#include "stm32l0xx.h"
#include "dma_adc_setup.hpp"
extern "C" {
[[noreturn]] void custom_main();
}
