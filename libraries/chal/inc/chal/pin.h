/*
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        pin.h
 *  @brief
 *
 * ****************************************************************************
 *  @attention
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  You may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  Copyright (C) 2023-2023 xqyjlj<xqyjlj@126.com>
 *
 * ****************************************************************************
 *  Change Logs:
 *  Date           Author       Notes
 *  ------------   ----------   -----------------------------------------------
 *  2023-07-26     xqyjlj       initial version
 */

#ifndef __CHAL_PIN_H__
#define __CHAL_PIN_H__

#include <apm32f10x.h>
#include <apm32f10x_eint.h>
#include <apm32f10x_gpio.h>
#include <apm32f10x_misc.h>
#include <apm32f10x_rcm.h>
#include <clink/devices/pin.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup pin
 */

/**@{*/

#if defined(CLINK_USING_DEVICES_PIN) && CLINK_USING_DEVICES_PIN > 0

#define CHAL_PIN_GET(PORTx, PIN) ((uint32_t)((((GPIO##PORTx##_BASE - GPIOA_BASE) / 0x0400UL) << 4) + PIN))

void chal_pin_register();

#endif  // CLINK_USING_DEVICES_PIN

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
