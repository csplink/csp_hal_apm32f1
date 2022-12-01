/* header for chal_power.c.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
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
 * Copyright (C) 2022-present xqyjlj<xqyjlj@126.com>, csplink.github.io
 *
 * @author      xqyjlj
 * @file        power.h
 *
 */

#ifndef __CHAL_POWER_H__
#define __CHAL_POWER_H__

#include <chal/hal.h>

#ifdef __cplusplus
extern "C" {
#endif

__chal_inline void chal_power_enable_clk()
{
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
}

__chal_inline uint32_t chal_power_is_clk_enabled()
{
    return LL_APB1_GRP1_IsEnabledClock(LL_APB1_GRP1_PERIPH_PWR);
}

__chal_inline void chal_power_disable_clk()
{
    LL_APB1_GRP1_DisableClock(LL_APB1_GRP1_PERIPH_PWR);
}

#ifdef __cplusplus
}
#endif

#endif
