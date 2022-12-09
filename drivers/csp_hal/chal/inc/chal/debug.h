/* header for chal_debug.c.
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
 * @file        debug.h
 *
 */

#ifndef __CHAL_DEBUG_H__
#define __CHAL_DEBUG_H__

#include <chal/hal.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    /* SW-DP Enabled and JTAG-DP Enabled */
    CHAL_DEBUG_PORT_SWJ_ENABEL      = AFIO_MAPR_SWJ_CFG_RESET,
    /* SW-DP Enabled and JTAG-DP Enabled but without NJTRST */
    CHAL_DEBUG_PORT_SWJ_NOJNTRST    = AFIO_MAPR_SWJ_CFG_NOJNTRST,
    /* SW-DP Enabled and JTAG-DP Disabled  */
    CHAL_DEBUG_PORT_SWJ_JTAGDISABLE = AFIO_MAPR_SWJ_CFG_JTAGDISABLE,
    /* SW-DP Disabled and JTAG-DP Disabled */
    CHAL_DEBUG_PORT_SWJ_DISABLE     = AFIO_MAPR_SWJ_CFG_DISABLE
} chal_debug_port_t;

__chal_inline void chal_debug_init(chal_debug_port_t port)
{
    CLEAR_BIT(AFIO->MAPR, AFIO_MAPR_SWJ_CFG);
    SET_BIT(AFIO->MAPR, port);
}

#ifdef __cplusplus
}
#endif

#endif
