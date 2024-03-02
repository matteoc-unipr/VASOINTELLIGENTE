/*
 * drv_terrain_umi.c
 *
 *
 */
#include "drv_terrain_humi.h"
#include "adc.h"
#include "stm32wlxx_hal_adc.h"
#include "stdint.h"

extern ADC_HandleTypeDef hadc;

uint16_t drv_terrain_humi_Read()
{

	MX_ADC_Init(hadc);

    /* Start Calibration */
    if (HAL_ADCEx_Calibration_Start(&hadc) != HAL_OK)
    {
      Error_Handler();
    }

    if (HAL_ADC_Start(&hadc) != HAL_OK)
    {
      /* Start Error */
      Error_Handler();
    }
    HAL_ADC_PollForConversion(&hadc, 10);

     uint16_t value = HAL_ADC_GetValue(&hadc);

     HAL_ADC_DeInit(&hadc);

     return value;
}





