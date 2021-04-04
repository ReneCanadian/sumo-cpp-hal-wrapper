###my_gpio 
To create a gpio instance you need to first enable the clock for the
 given port you'll be using e.g. `__HAL_RCC_GPIOD_CLK_ENABLE()` in the `main.c` file.<br/>
Next in the `custom_main.cpp` file you may call the constructor which takes at least two arguments,
the `port` and `pin` of the GPIO you want to use, the rest of the arguments have default values <br/>
`cpp Gpio(GPIO_TypeDef *port_, const uint16_t pin, const uint8_t mode = GPIO_MODE_OUTPUT_PP, 
const uint8_t pull_up = GPIO_NOPULL, uint8_t speed = GPIO_SPEED_FREQ_LOW)`
<br/><br/>
e.g. `Gpio my_gpio{GPIOD, GPIO_PIN_15}` <br/><br/>
The Gpio class has two functions `enable()` and `disable()`