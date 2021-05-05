#pragma once
#include "stm32l0xx.h"


enum class AdcChannel : uint32_t {
    Channel_11 = ADC_CHANNEL_11,
    Channel_8 = ADC_CHANNEL_8,
    Channel_4 = ADC_CHANNEL_4
};

class DmaAdc{
    DMA_HandleTypeDef dma;
    ADC_HandleTypeDef adc;
public:
    DmaAdc(AdcChannel const channel_, uint8_t const number_of_channels_);
    void init();
    bool start();
private:
    AdcChannel channel;
    uint8_t number_of_channels;
public:
    uint16_t data[1];
};
