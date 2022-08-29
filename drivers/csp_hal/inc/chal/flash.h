/**
 * @file flash.h
 * @author xqyjlj (xqyjlj@126.com)
 * @brief
 * @version 0.1
 * @date 2022-08-08
 *
 * @copyright Copyright (c) 2022-2022, xqyjlj
 *
 * @SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-08-08     xqyjlj       the first version
 *
 */
#ifndef __CHAL_FLASH_H__
#define __CHAL_FLASH_H__

#include <chal/hal.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CHAL_FLASH_LATENCY_0 FMC_LATENCY_0
#define CHAL_FLASH_LATENCY_1 FMC_LATENCY_1
#define CHAL_FLASH_LATENCY_2 FMC_LATENCY_2

rt_inline void chal_flash_set_latency(rt_uint32_t latency)
{
    FMC->CTRL1_B.WS = latency;
}

rt_inline rt_uint32_t chal_flash_get_latency()
{
    return (FMC->CTRL1_B.WS);
}

#ifdef __cplusplus
}
#endif

#endif