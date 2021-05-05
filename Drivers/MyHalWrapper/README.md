###my_gpio 
To create a `Gpio` instance you need to first enable the clock for the
 given port you'll be using e.g. `__HAL_RCC_GPIOD_CLK_ENABLE()` in the `main.c` file.<br/>
Next in the `custom_main.cpp` file you may call the constructor which takes at least two arguments,
the `port` and `pin` of the GPIO you want to use, the rest of the arguments have default values <br/>
<br/>
e.g. `Gpio my_gpio{GPIOD, GPIO_PIN_15}` <br/><br/>
The Gpio class has two functions `enable()` and `disable()`

###my_tim
To create a `Tim` instance you first need to enable the proper timer in `main.c` e.g. `__HAL_RCC_TIM3_CLK_ENABLE()`. 
The constructor only needs one value - `TIM_TypeDef* TIM`. The rest of the settings have default values. 
Nevertheless you can set them up via the constructor<br/> 
The default values were chose based on my use of the timers.
<br/>
`Tim tim3(TIM3);`
<br/>
The Tim class has no functions for now.

###my_pwm
To create a `Pwm` instance you need to provide the constructor with a `Tim` instance, the `channel` on which you'll 
be using your PWM (remember that with one timmer you can usually control up to four different channels).
The constructor, also creates a default output configuration, who's vales were chosen based on my use.
<br/>
`Pwm pwm_a(PwmChannel::Channel_1, tim3);`
<br/>
The Pwm class has two functions `pwm_start()` which should be run once before using the pwm. The second is 
`set_ccr(uint32_t ccr)` which lets you set the duty cycle (with the current default setting you can set it from 0 to 100).