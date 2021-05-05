#include "dma_adc_setup.hpp"

DmaAdc::DmaAdc(AdcChannel const channel_, uint8_t const number_of_channels_) : channel(channel_),
number_of_channels(number_of_channels_){}


void DmaAdc::init() {

    adc.Instance = ADC1;
    adc.Init.OversamplingMode = DISABLE;
    adc.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV1;
    adc.Init.Resolution = ADC_RESOLUTION_12B;
    adc.Init.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
    adc.Init.ScanConvMode = ADC_SCAN_DIRECTION_FORWARD;
    adc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
    adc.Init.ContinuousConvMode = ENABLE;
    adc.Init.DiscontinuousConvMode = DISABLE;
    adc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
    adc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
    adc.Init.DMAContinuousRequests = ENABLE;
    adc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
    adc.Init.Overrun = ADC_OVR_DATA_PRESERVED;
    adc.Init.LowPowerAutoWait = DISABLE;
    adc.Init.LowPowerFrequencyMode = ENABLE;
    adc.Init.LowPowerAutoPowerOff = DISABLE;
    HAL_ADC_Init(&adc);

    ADC_ChannelConfTypeDef sConfig = {0};
    sConfig.Channel = static_cast<uint32_t>(channel);
    sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
    HAL_ADC_ConfigChannel(&adc, &sConfig);

    dma.Instance = DMA1_Channel1;
    dma.Init.Direction = DMA_PERIPH_TO_MEMORY;
    dma.Init.PeriphInc = DMA_PINC_DISABLE;
    dma.Init.MemInc = DMA_MINC_ENABLE;
    dma.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
    dma.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
    dma.Init.Mode = DMA_CIRCULAR;
    dma.Init.Priority = DMA_PRIORITY_HIGH;
    HAL_DMA_Init(&dma);
    __HAL_LINKDMA(&adc, DMA_Handle, dma);


}

bool DmaAdc::start() {
    if(not HAL_ADC_Start_DMA(&adc, reinterpret_cast<uint32_t *>(data), number_of_channels)){
        return false;
    }
    return true;
}