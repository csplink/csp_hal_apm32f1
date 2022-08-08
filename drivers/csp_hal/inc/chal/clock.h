/**
 * @file clock.h
 * @author xqyjlj (xqyjlj@126.com)
 * @brief
 * @version 0.1
 * @date 2022-07-27
 *
 * @copyright Copyright (c) 2022-2022, xqyjlj
 *
 * @SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-07-27     xqyjlj      the first version
 *
 */

#ifndef __CHAL_CLOCK_H__
#define __CHAL_CLOCK_H__

#include <chal/hal.h>

#ifdef __cplusplus
extern "C" {
#endif

rt_inline void chal_clock_hsi_enable(void)
{
    RCM->CTRL_B.HSIEN = 1;
}

rt_inline void chal_clock_hsi_disable(void)
{
    RCM->CTRL_B.HSIEN = 0;
}

rt_inline rt_bool_t chal_clock_hsi_is_ready(void)
{
    return RCM->CTRL_B.HSIRDYFLG;
}

rt_inline void chal_clock_hsi_set_calib_trimming(rt_uint32_t Trim)
{
    RCM->CTRL_B.HSITRIM = Trim;
}

rt_inline rt_uint32_t chal_clock_hsi_get_calib_trimming(void)
{
    return (rt_uint32_t)RCM->CTRL_B.HSITRIM;
}

rt_inline rt_uint32_t chal_clock_hsi_get_calibration(void)
{
    return (rt_uint32_t)RCM->CTRL_B.HSICAL;
}

rt_inline void chal_clock_hse_enable(void)
{
    RCM->CTRL_B.HSEEN = 1;
}

rt_inline void chal_clock_hse_disable(void)
{
    RCM->CTRL_B.HSEEN = 0;
}

rt_inline rt_bool_t chal_clock_hse_is_ready(void)
{
    return RCM->CTRL_B.HSERDYFLG;
}

rt_inline void chal_clock_hse_enable_bypass(void)
{
    RCM->CTRL_B.HSEBCFG = 1;
}

rt_inline void chal_clock_hse_disable_bypass(void)
{
    RCM->CTRL_B.HSEBCFG = 0;
}

rt_inline void chal_clock_enable_css(void)
{
    RCM->CTRL_B.CSSEN = 1;
}

rt_inline void chal_clock_disable_css(void)
{
    RCM->CTRL_B.CSSEN = 0;
}

rt_inline void chal_clock_pll_enable(void)
{
    RCM->CTRL_B.PLLEN = 1;
}

rt_inline void chal_clock_pll_disable(void)
{
    RCM->CTRL_B.PLLEN = 0;
}

rt_inline rt_bool_t chal_clock_pll_is_ready(void)
{
    return RCM->CTRL_B.PLLRDYFLG;
}

#ifdef __cplusplus
}
#endif

#endif
