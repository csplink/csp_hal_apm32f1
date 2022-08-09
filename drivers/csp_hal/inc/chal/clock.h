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

#define CHAL_CLOCK_SYSCLK_SOURCE_HSI         RCM_SYSCLK_SEL_HSI  // 选择HSI作为系统时钟
#define CHAL_CLOCK_SYSCLK_SOURCE_HSE         RCM_SYSCLK_SEL_HSE  // 选择HSE作为系统时钟
#define CHAL_CLOCK_SYSCLK_SOURCE_PLL         RCM_SYSCLK_SEL_PLL  // 选择PLL作为系统时钟

#define CHAL_CLOCK_AHBCLK_DIV_1              RCM_AHB_DIV_1
#define CHAL_CLOCK_AHBCLK_DIV_2              RCM_AHB_DIV_2
#define CHAL_CLOCK_AHBCLK_DIV_4              RCM_AHB_DIV_4
#define CHAL_CLOCK_AHBCLK_DIV_8              RCM_AHB_DIV_8
#define CHAL_CLOCK_AHBCLK_DIV_16             RCM_AHB_DIV_16
#define CHAL_CLOCK_AHBCLK_DIV_64             RCM_AHB_DIV_64
#define CHAL_CLOCK_AHBCLK_DIV_128            RCM_AHB_DIV_128
#define CHAL_CLOCK_AHBCLK_DIV_256            RCM_AHB_DIV_256
#define CHAL_CLOCK_AHBCLK_DIV_512            RCM_AHB_DIV_512

#define CHAL_CLOCK_APBCLK_DIV_1              RCM_APB_DIV_1
#define CHAL_CLOCK_APBCLK_DIV_2              RCM_APB_DIV_2
#define CHAL_CLOCK_APBCLK_DIV_4              RCM_APB_DIV_4
#define CHAL_CLOCK_APBCLK_DIV_8              RCM_APB_DIV_8
#define CHAL_CLOCK_APBCLK_DIV_16             RCM_APB_DIV_16

#define CHAL_CLOCK_ADCCLK_DIV_2              RCM_PCLK2_DIV_2
#define CHAL_CLOCK_ADCCLK_DIV_4              RCM_PCLK2_DIV_4
#define CHAL_CLOCK_ADCCLK_DIV_6              RCM_PCLK2_DIV_6
#define CHAL_CLOCK_ADCCLK_DIV_8              RCM_PCLK2_DIV_8

#define CHAL_CLOCK_PLLCLK_SOURCE_HSI_DIV_2   (0x00000000U)
#define CHAL_CLOCK_PLLCLK_SOURCE_HSE_DIV_1   (0x00010000U)
#define CHAL_CLOCK_PLLCLK_SOURCE_HSE_DIV_2   (0x00030000U)

#define CHAL_CLOCK_PLLCLK_MUL_2              RCM_PLLMF_2
#define CHAL_CLOCK_PLLCLK_MUL_3              RCM_PLLMF_3
#define CHAL_CLOCK_PLLCLK_MUL_4              RCM_PLLMF_4
#define CHAL_CLOCK_PLLCLK_MUL_5              RCM_PLLMF_5
#define CHAL_CLOCK_PLLCLK_MUL_6              RCM_PLLMF_6
#define CHAL_CLOCK_PLLCLK_MUL_7              RCM_PLLMF_7
#define CHAL_CLOCK_PLLCLK_MUL_8              RCM_PLLMF_8
#define CHAL_CLOCK_PLLCLK_MUL_9              RCM_PLLMF_9
#define CHAL_CLOCK_PLLCLK_MUL_10             RCM_PLLMF_10
#define CHAL_CLOCK_PLLCLK_MUL_11             RCM_PLLMF_11
#define CHAL_CLOCK_PLLCLK_MUL_12             RCM_PLLMF_12
#define CHAL_CLOCK_PLLCLK_MUL_13             RCM_PLLMF_13
#define CHAL_CLOCK_PLLCLK_MUL_14             RCM_PLLMF_14
#define CHAL_CLOCK_PLLCLK_MUL_15             RCM_PLLMF_15
#define CHAL_CLOCK_PLLCLK_MUL_16             RCM_PLLMF_16

#define CHAL_CLOCK_USBCLK_SOURCE_PLL_DIV_1_5 RCM_USB_DIV_1_5
#define CHAL_CLOCK_USBCLK_SOURCE_PLL_DIV_1   RCM_USB_DIV_1

#define CHAL_CLOCK_MCOCLK_NOCLOCK            RCM_MCOCLK_NO_CLOCK
#define CHAL_CLOCK_MCOCLK_SYSCLK             RCM_MCOCLK_SYSCLK
#define CHAL_CLOCK_MCOCLK_HSI                RCM_MCOCLK_HSI
#define CHAL_CLOCK_MCOCLK_HSE                RCM_MCOCLK_HSE
#define CHAL_CLOCK_MCOCLK_PLL_DIV_2          RCM_MCOCLK_PLLCLK_DIV_2

#define CHAL_CLOCK_FPUCLK_DIV_1              RCM_FPU_DIV_1
#define CHAL_CLOCK_FPUCLK_DIV_2              RCM_FPU_DIV_2

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
    CHAL_MODIFY_REG(RCM->CFG, (0x00030000U), (source & 0x00030000U));
}

rt_inline rt_uint32_t chal_clock_get_pll_source(void)
{
    return CHAL_READ_BIT(RCM->CFG, (0x00030000U));
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
