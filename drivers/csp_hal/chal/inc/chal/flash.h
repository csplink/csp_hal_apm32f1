/**
 *****************************************************************************
 * @author      xqyjlj
 * @file        flash.h
 * @brief       header for chal_flash.c
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

#ifndef __CHAL_FLASH_H__
#define __CHAL_FLASH_H__

#include <chal/hal.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    CHAL_FLASH_LATENCY_0 = LL_FLASH_LATENCY_0,
    CHAL_FLASH_LATENCY_1 = LL_FLASH_LATENCY_1,
    CHAL_FLASH_LATENCY_2 = LL_FLASH_LATENCY_2,
    CHAL_FLASH_LATENCY_3 = 3
} chal_flash_latency_t;

#ifdef __cplusplus
}
#endif

#endif
