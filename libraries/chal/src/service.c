/*
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        service.c
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
 *  2023-08-02     xqyjlj       initial version
 */

#include <chal/service.h>

void clink_delay_ms(uint32_t ms)
{
    __IO uint32_t tmp = SysTick->CTRL;

    CLINK_UNUSED(tmp);

    /* Add a period to guaranty minimum wait */
    if (ms < UINT32_MAX)
    {
        ms++;
    }

    while (ms)
    {
        if ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) != 0U)
        {
            ms--;
        }
    }
}
