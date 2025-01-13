#!/usr/bin/env python3
# -*- coding:utf-8 -*-

# Licensed under the GNU General Public License v. 3 (the "License")
# You may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.gnu.org/licenses/gpl-3.0.html
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Copyright (C) 2024-2024 xqyjlj<xqyjlj@126.com>
#
# @author      xqyjlj
# @file        rcm.py
#
# Change Logs:
# Date           Author       Notes
# ------------   ----------   -----------------------------------------------
# 2024-12-27     xqyjlj       initial version
#

import csp_project_helper


# ------------------------------------------------------------------------------
def rcm_adc_clk_div_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_adc_clk_div_t', default)


def rcm_adc_clk_out_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_adc_clk_out_t', default)


def rcm_ahb_div_sdio_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_ahb_div_sdio_t', default)


def rcm_ahb_div_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_ahb_div_t', default)


def rcm_apb1_div_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_apb1_div_t', default)


def rcm_apb1_peripherals_out_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_apb1_peripherals_out_t', default)


def rcm_apb1_timers_mul_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_apb1_timers_mul_t', default)


def rcm_apb1_timers_out_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_apb1_timers_out_t', default)


def rcm_apb2_div_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_apb2_div_t', default)


def rcm_apb2_peripherals_out_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_apb2_peripherals_out_t', default)


def rcm_apb2_timers_mul_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_apb2_timers_mul_t', default)


def rcm_apb2_timers_out_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_apb2_timers_out_t', default)


def rcm_css_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_css_t', default)


def rcm_emmc_clk_out_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_emmc_clk_out_t', default)


def rcm_fclk_out_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_fclk_out_t', default)


def rcm_flash_latency_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_flash_latency_t', default)


def rcm_fmc_clk_value_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_fmc_clk_value_t', default)


def rcm_fpu_clk_div_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_fpu_clk_div_t', default)


def rcm_fpu_clk_out_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_fpu_clk_out_t', default)


def rcm_hclk_out_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_hclk_out_t', default)


def rcm_hclk_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_hclk_t', default)


def rcm_hse_clock_source_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_hse_clock_source_t', default)


def rcm_hse_div_pll_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_hse_div_pll_t', default)


def rcm_hse_div_rtc_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_hse_div_rtc_t', default)


def rcm_hse_value_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_hse_value_t', default)


def rcm_hsi_calibration_t(project: dict, default: int | None = None) -> int:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_hsi_calibration_t', default)


def rcm_hsi_div_pll_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_hsi_div_pll_t', default)


def rcm_hsi_value_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_hsi_value_t', default)


def rcm_i2s2_clk_freq_value_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_i2s2_clk_freq_value_t', default)


def rcm_i2s3_clk_freq_value_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_i2s3_clk_freq_value_t', default)


def rcm_iwdg_clk_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_iwdg_clk_t', default)


def rcm_lse_clock_source_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_lse_clock_source_t', default)


def rcm_lse_value_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_lse_value_t', default)


def rcm_lsi_value_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_lsi_value_t', default)


def rcm_mco_clk_selector_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_mco_clk_selector_t', default)


def rcm_mco_clk_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_mco_clk_t', default)


def rcm_mco_enabled_t(project: dict, default: bool | None = None) -> bool:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_mco_enabled_t', default)


def rcm_mco_out_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_mco_out_t', default)


def rcm_pll_clk_selector_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_pll_clk_selector_t', default)


def rcm_pll_div_mco_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_pll_div_mco_t', default)


def rcm_pll_mul_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_pll_mul_t', default)


def rcm_pll_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_pll_t', default)


def rcm_prefetch_buffer_enabled_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_prefetch_buffer_enabled_t', default)


def rcm_rtc_clk_selector_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_rtc_clk_selector_t', default)


def rcm_rtc_clk_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_rtc_clk_t', default)


def rcm_sdio_ahb_clk_out_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_sdio_ahb_clk_out_t', default)


def rcm_sdio_clk_out_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_sdio_clk_out_t', default)


def rcm_sys_clk_freq_value_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_sys_clk_freq_value_t', default)


def rcm_sys_timer_clk_div_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_sys_timer_clk_div_t', default)


def rcm_sys_timer_clk_out_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_sys_timer_clk_out_t', default)


def rcm_system_clk_selector_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_system_clk_selector_t', default)


def rcm_usb_clk_div_t(project: dict, default: str | None = None) -> str:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_usb_clk_div_t', default)


def rcm_usb_clk_out_t(project: dict, default: float | None = None) -> float:
    return csp_project_helper.get(project, 'configs/RCM/geehy.rcm_usb_clk_out_t', default)


# ------------------------------------------------------------------------------


def rcm_flash_latency(project: dict) -> str:
    m = {
        'geehy.rcm_flash_latency_0': '0',
        'geehy.rcm_flash_latency_1': '1',
        'geehy.rcm_flash_latency_2': '2',
        'geehy.rcm_flash_latency_3': '3',
    }
    latency = rcm_flash_latency_t(project, 'geehy.rcm_flash_latency_3')
    return m.get(latency, '3')


def rcm_hse_used(project: dict) -> bool:
    pll_clk_selector = rcm_pll_clk_selector_t(project)
    system_clk_selector = rcm_system_clk_selector_t(project)
    mco_clk_selector = rcm_mco_clk_selector_t(project)
    rtc_clk_selector = rcm_rtc_clk_selector_t(project)

    hse_clock_source = rcm_hse_clock_source_t(project, 'geehy.rcm_hse_clock_source_disable')

    use_rtc = True  # TODO:
    use_pll = rcm_pll_used(project)
    use_mco = True  # TODO:

    if hse_clock_source == 'geehy.rcm_hse_clock_source_disable':
        return False

    if use_rtc and rtc_clk_selector == 'geehy.rcm_rtc_clk_hse_div128_t':
        return True

    if use_pll and pll_clk_selector == 'geehy.rcm_pll_hse_t':
        return True

    if system_clk_selector == 'geehy.rcm_system_clk_hse_t':
        return True

    if use_mco and mco_clk_selector == 'geehy.rcm_mco_clk_hse_t':
        return True

    return False


def rcm_hsi_used(project: dict) -> bool:
    pll_clk_selector = rcm_pll_clk_selector_t(project)
    system_clk_selector = rcm_system_clk_selector_t(project)
    mco_clk_selector = rcm_mco_clk_selector_t(project)

    use_pll = rcm_pll_used(project)
    use_mco = True  # TODO:

    if use_pll and pll_clk_selector == 'geehy.rcm_pll_hsi_div2_t':
        return True

    if system_clk_selector == 'geehy.rcm_system_clk_hsi_t':
        return True

    if use_mco and mco_clk_selector == 'geehy.rcm_mco_clk_hsi_t':
        return True

    return False


def rcm_lse_used(project: dict) -> bool:
    rtc_clk_selector = rcm_rtc_clk_selector_t(project)

    lse_clock_source = rcm_lse_clock_source_t(project, 'geehy.rcm_lse_clock_source_disable')

    use_rtc = True  # TODO:

    if lse_clock_source == 'geehy.rcm_lse_clock_source_disable':
        return False

    if use_rtc and rtc_clk_selector == 'geehy.rcm_rtc_clk_lse_t':
        return True

    return False


def rcm_lsi_used(project: dict) -> bool:
    rtc_clk_selector = rcm_rtc_clk_selector_t(project)

    use_iwdg = True  # TODO:

    if use_iwdg:
        return True

    if rtc_clk_selector == 'geehy.rcm_rtc_clk_lsi_t':
        return True

    return False


def rcm_pll_used(project: dict) -> bool:
    system_clk_selector = rcm_system_clk_selector_t(project)
    mco_clk_selector = rcm_mco_clk_selector_t(project)

    use_mco = True  # TODO:
    use_usb = True  # TODO:

    if system_clk_selector == 'geehy.rcm_system_clk_pll_t':
        return True

    if use_mco and mco_clk_selector == 'geehy.rcm_mco_clk_pll_div2_t':
        return True

    if use_usb:
        return True

    return False


def rcm_pll_clk_selector(project: dict) -> str:
    selector = rcm_pll_clk_selector_t(project)
    div = rcm_hse_div_pll_t(project)

    if selector == 'geehy.rcm_pll_hsi_div2_t':
        return 'RCM_PLLSEL_HSI_DIV_2'
    else:
        if div == 'geehy.rcm_hse_div_pll_div1':
            return 'RCM_PLLSEL_HSE'
        else:
            return 'RCM_PLLSEL_HSE_DIV2'


def rcm_system_clk_selector(project: dict) -> str:
    m = {
        'geehy.rcm_system_clk_hsi_t': 'RCM_SYSCLK_SEL_HSI',
        'geehy.rcm_system_clk_hse_t': 'RCM_SYSCLK_SEL_HSE',
        'geehy.rcm_system_clk_pll_t': 'RCM_SYSCLK_SEL_PLL',
    }
    selector = rcm_system_clk_selector_t(project)
    return m.get(selector)


def rcm_mco_clk_selector(project: dict) -> str:
    m = {
        'geehy.rcm_mco_clk_pll_div2_t': 'RCM_MCOCLK_PLLCLK_DIV_2',
        'geehy.rcm_mco_clk_hse_t': 'RCM_MCOCLK_HSE',
        'geehy.rcm_mco_clk_hsi_t': 'RCM_MCOCLK_HSI',
        'geehy.rcm_mco_clk_system_t': 'RCM_MCOCLK_SYSCLK',
    }
    selector = rcm_mco_clk_selector_t(project)
    return m.get(selector)


def rcm_pll_mul(project: dict) -> str:
    m = {
        'geehy.rcm_pll_mul2': 'RCM_PLLMF_2',
        'geehy.rcm_pll_mul3': 'RCM_PLLMF_3',
        'geehy.rcm_pll_mul4': 'RCM_PLLMF_4',
        'geehy.rcm_pll_mul5': 'RCM_PLLMF_5',
        'geehy.rcm_pll_mul6': 'RCM_PLLMF_6',
        'geehy.rcm_pll_mul7': 'RCM_PLLMF_7',
        'geehy.rcm_pll_mul8': 'RCM_PLLMF_8',
        'geehy.rcm_pll_mul9': 'RCM_PLLMF_9',
        'geehy.rcm_pll_mul10': 'RCM_PLLMF_10',
        'geehy.rcm_pll_mul11': 'RCM_PLLMF_11',
        'geehy.rcm_pll_mul12': 'RCM_PLLMF_12',
        'geehy.rcm_pll_mul13': 'RCM_PLLMF_13',
        'geehy.rcm_pll_mul14': 'RCM_PLLMF_14',
        'geehy.rcm_pll_mul15': 'RCM_PLLMF_15',
        'geehy.rcm_pll_mul16': 'RCM_PLLMF_16',
    }
    mul = rcm_pll_mul_t(project)
    return m.get(mul)


def rcm_ahb_div(project: dict) -> str:
    m = {
        'geehy.rcm_ahb_div1': 'RCM_AHB_DIV_1',
        'geehy.rcm_ahb_div2': 'RCM_AHB_DIV_2',
        'geehy.rcm_ahb_div4': 'RCM_AHB_DIV_4',
        'geehy.rcm_ahb_div8': 'RCM_AHB_DIV_8',
        'geehy.rcm_ahb_div16': 'RCM_AHB_DIV_16',
        'geehy.rcm_ahb_div64': 'RCM_AHB_DIV_64',
        'geehy.rcm_ahb_div128': 'RCM_AHB_DIV_128',
        'geehy.rcm_ahb_div256': 'RCM_AHB_DIV_256',
        'geehy.rcm_ahb_div512': 'RCM_AHB_DIV_512',
    }
    div = rcm_ahb_div_t(project)
    return m.get(div)


def rcm_apb1_div(project: dict) -> str:
    m = {
        'geehy.rcm_apb1_div1': 'RCM_APB_DIV_1',
        'geehy.rcm_apb1_div2': 'RCM_APB_DIV_2',
        'geehy.rcm_apb1_div4': 'RCM_APB_DIV_4',
        'geehy.rcm_apb1_div8': 'RCM_APB_DIV_8',
        'geehy.rcm_apb1_div16': 'RCM_APB_DIV_16',
    }
    div = rcm_apb1_div_t(project)
    return m.get(div)


def rcm_apb2_div(project: dict) -> str:
    m = {
        'geehy.rcm_apb2_div1': 'RCM_APB_DIV_1',
        'geehy.rcm_apb2_div2': 'RCM_APB_DIV_2',
        'geehy.rcm_apb2_div4': 'RCM_APB_DIV_4',
        'geehy.rcm_apb2_div8': 'RCM_APB_DIV_8',
        'geehy.rcm_apb2_div16': 'RCM_APB_DIV_16',
    }
    div = rcm_apb2_div_t(project)
    return m.get(div)
