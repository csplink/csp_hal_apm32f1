/**
 *****************************************************************************
 * @author      xqyjlj
 * @file        hal.h
 * @brief       header for csp_hal library
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

#ifndef __CHAL_HAL_H__
#define __CHAL_HAL_H__

#include "csp_conf.h"

#include "stm32f1xx_ll_adc.h"
#include "stm32f1xx_ll_bus.h"
#include "stm32f1xx_ll_cortex.h"
#include "stm32f1xx_ll_crc.h"
#include "stm32f1xx_ll_dac.h"
#include "stm32f1xx_ll_dma.h"
#include "stm32f1xx_ll_exti.h"
#include "stm32f1xx_ll_fsmc.h"
#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_i2c.h"
#include "stm32f1xx_ll_iwdg.h"
#include "stm32f1xx_ll_pwr.h"
#include "stm32f1xx_ll_rcc.h"
#include "stm32f1xx_ll_rtc.h"
#include "stm32f1xx_ll_sdmmc.h"
#include "stm32f1xx_ll_spi.h"
#include "stm32f1xx_ll_system.h"
#include "stm32f1xx_ll_tim.h"
#include "stm32f1xx_ll_usart.h"
#include "stm32f1xx_ll_usb.h"
#include "stm32f1xx_ll_utils.h"
#include "stm32f1xx_ll_wwdg.h"

#ifdef __cplusplus
extern "C" {
#endif

#define __chal_inline __STATIC_INLINE
#define __chal_weak   __weak

#define CHAL_UNUSED   UNUSED

/**
 * @brief chal error code enumeration
 */
typedef enum
{
    CHAL_OK = 0U,
    CHAL_ERROR
} chal_status_t;

#ifdef __cplusplus
}
#endif

#endif
