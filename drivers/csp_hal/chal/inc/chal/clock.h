/**
 *****************************************************************************
 * @author      xqyjlj
 * @file        clock.h
 * @brief       header for chal_clock.c
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

#ifndef __CHAL_CLOCK_H__
#define __CHAL_CLOCK_H__

#include <chal/hal.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CGEN_HCLK_FREQ
#define CGEN_HCLK_FREQ (8000000UL) /* the default HCLK frequency is 8MHz. */
#endif

void chal_clock_mdelay(uint32_t delay);
void chal_clock_init(void);

#ifdef __cplusplus
}
#endif

#endif
