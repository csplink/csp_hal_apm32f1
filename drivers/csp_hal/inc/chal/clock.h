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
 * 2022-07-27     xqyjlj       the first version
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

rt_inline void chal_clock_hsi_set_calib_trimming(rt_uint32_t trim)
{
    RCM->CTRL_B.HSITRIM = trim;
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

rt_inline void chal_clock_set_sysclk_source(rt_uint32_t source)
{
    RCM->CFG_B.SCLKSEL = source;
}

rt_inline rt_uint32_t chal_clock_get_sysclk_source(void)
{
    return RCM->CFG_B.SCLKSELSTS;
}

rt_inline void chal_clock_set_ahb_prescaler(rt_uint32_t prescaler)
{
    RCM->CFG_B.AHBPSC = prescaler;
}

rt_inline rt_uint32_t chal_clock_get_ahb_prescaler(void)
{
    return RCM->CFG_B.AHBPSC;
}

rt_inline void chal_clock_set_apb1_prescaler(rt_uint32_t prescaler)
{
    RCM->CFG_B.APB1PSC = prescaler;
}

rt_inline rt_uint32_t chal_clock_get_apb1_prescaler(void)
{
    return RCM->CFG_B.APB1PSC;
}

rt_inline void chal_clock_set_apb2_prescaler(rt_uint32_t prescaler)
{
    RCM->CFG_B.APB2PSC = prescaler;
}

rt_inline rt_uint32_t chal_clock_get_apb2_prescaler(void)
{
    return RCM->CFG_B.APB2PSC;
}

rt_inline void chal_clock_set_adc_clock_prescaler(uint32_t prescaler)
{
    RCM->CFG_B.ADCPSC = prescaler;
}

rt_inline rt_uint32_t chal_clock_get_adc_clock_prescaler(void)
{
    return RCM->CFG_B.ADCPSC;
}

rt_inline void chal_clock_set_pll_source(rt_uint32_t source)
{
    RCM->CFG_B.PLLSRCSEL = source;
}

rt_inline rt_uint32_t chal_clock_get_pll_source(void)
{
    return RCM->CFG_B.PLLSRCSEL;
}

rt_inline void chal_clock_set_pll_prediv(rt_uint32_t prediv)
{
    RCM->CFG_B.PLLHSEPSC = prediv;
}

rt_inline rt_uint32_t chal_clock_get_pll_prediv(void)
{
    return RCM->CFG_B.PLLHSEPSC;
}

rt_inline void chal_clock_set_pll_mul(rt_uint32_t mul)
{
    RCM->CFG_B.PLLMULCFG = mul;
}

rt_inline rt_uint32_t chal_clock_get_pll_mul(void)
{
    return RCM->CFG_B.PLLMULCFG;
}

rt_inline void chal_clock_set_usb_clock_prescaler(uint32_t prescaler)
{
    RCM->CFG_B.USBDPSC = prescaler;
}

rt_inline rt_uint32_t chal_clock_get_usb_clock_prescaler(void)
{
    return RCM->CFG_B.USBDPSC;
}

rt_inline void chal_clock_set_mco(rt_uint32_t source)
{
    RCM->CFG_B.MCOSEL = source;
}

rt_inline rt_uint32_t chal_clock_get_mco(void)
{
    return RCM->CFG_B.MCOSEL;
}

rt_inline void chal_clock_set_fpu_clock_prescaler(uint32_t prescaler)
{
    RCM->CFG_B.FPUPSC = prescaler;
}

rt_inline rt_uint32_t chal_clock_get_fpu_clock_prescaler(void)
{
    return RCM->CFG_B.FPUPSC;
}

#ifdef __cplusplus
}
#endif

#endif
