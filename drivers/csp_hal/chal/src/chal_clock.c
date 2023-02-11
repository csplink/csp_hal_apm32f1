/**
 *****************************************************************************
 * @author      xqyjlj
 * @file        chal_clock.c
 * @brief       csp hardware abstraction layer for clock
 *
 *****************************************************************************
 * @attention
 * Licensed under the Apache License, Version 2.0 (the "License");
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Copyright (C) 2022-2023 xqyjlj<xqyjlj@126.com>
 *
 *****************************************************************************
 * Change Logs:
 * Date           Author       Notes
 * ------------   ----------   -----------------------------------------------
 * 2023-01-02     xqyjlj       initial version
 */

#include <chal/clock.h>
#include <chal/flash.h>

__chal_weak void chal_clock_init(void)
{
#if (CGEN_HCLK_FREQ > 0 && CGEN_HCLK_FREQ <= 24000000)
    chal_flash_latency_t latency = CHAL_FLASH_LATENCY_0;
#elif (CGEN_HCLK_FREQ > 24000000 && CGEN_HCLK_FREQ <= 48000000)
    chal_flash_latency_t latency = CHAL_FLASH_LATENCY_1;
#elif (CGEN_HCLK_FREQ > 48000000 && CGEN_HCLK_FREQ <= 72000000)
    chal_flash_latency_t latency = CHAL_FLASH_LATENCY_2;
#elif (CGEN_HCLK_FREQ > 72000000 && CGEN_HCLK_FREQ <= 96000000)
    chal_flash_latency_t latency = CHAL_FLASH_LATENCY_3;
#else
#error "overclocking can cause some unexpected results, comment this line to enable overclocking"
    chal_flash_latency_t latency = CHAL_FLASH_LATENCY_3;
#endif
    LL_FLASH_SetLatency((uint32_t)latency);
    while (LL_FLASH_GetLatency() != (uint32_t)latency)
    {
    }

    LL_RCC_HSI_SetCalibTrimming(16);
    LL_RCC_HSI_Enable();

    /* Wait till HSI is ready */
    while (LL_RCC_HSI_IsReady() != 1)
    {
    }
    LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
    LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_2);
    LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
    LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSI);

    /* Wait till System clock is ready */
    while (LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSI)
    {
    }
    LL_Init1msTick(CGEN_HCLK_FREQ);
    LL_SetSystemCoreClock(CGEN_HCLK_FREQ);
}

void chal_clock_mdelay(uint32_t delay)
{
    LL_mDelay(delay);
}
