#!/usr/bin/env python3
# -*- coding:utf-8 -*-

#
# ------------------------------------------------------------------------------
#  @author:            csplink coder
#  @file:              rcm.py
#  @version:           0.0.6
#  @time:              2025-11-14 15:39:42
#
# ------------------------------------------------------------------------------
#  @attention
#
#  Copyright (C) 2025 csplink software.
#  All rights reserved.
#
# ------------------------------------------------------------------------------
#

from typing import Literal

from csp.project import Project

# --< user code begin import, do not change this comment!
# isort: off

# isort: on
# --> user code end import, do not change this comment!

# ------------------------------------------------------------------------------
# region autogen filters
# fmt: off

_rcm_hse_clk_div_rtc_t_return_type = Literal[
    "/128",
]


_rcm_rtc_clk_mux_t_return_type = Literal[
    "hse_div128",
    "lse",
    "lsi",
]


_rcm_system_clk_mux_t_return_type = Literal[
    "hse",
    "hsi",
    "pll",
]


_rcm_pll_clk_mux_t_return_type = Literal[
    "hse",
    "hsi_div2",
]


_rcm_mco_clk_mux_t_return_type = Literal[
    "hse",
    "hsi",
    "pll_div2",
    "system",
]


_rcm_hsi_clk_div_pll_t_return_type = Literal[
    "2",
]


_rcm_hse_clk_div_pll_t_return_type = Literal[
    "/1",
    "/2",
]


_rcm_pll_clk_mul_t_return_type = Literal[
    "*10",
    "*11",
    "*12",
    "*13",
    "*14",
    "*15",
    "*16",
    "*2",
    "*3",
    "*4",
    "*5",
    "*6",
    "*7",
    "*8",
    "*9",
]


_rcm_ahb_clk_div_hclk_t_return_type = Literal[
    "/1",
    "/128",
    "/16",
    "/2",
    "/256",
    "/4",
    "/512",
    "/64",
    "/8",
]


_rcm_hclk_div_sys_timer_clk_t_return_type = Literal[
    "/1",
    "/8",
]


_rcm_apb1_div_t_return_type = Literal[
    "/1",
    "/16",
    "/2",
    "/4",
    "/8",
]


_rcm_apb1_timers_mul_t_return_type = Literal[
    "*1",
    "*2",
]


_rcm_apb2_div_t_return_type = Literal[
    "/1",
    "/16",
    "/2",
    "/4",
    "/8",
]


_rcm_apb2_timers_mul_t_return_type = Literal[
    "*1",
    "*2",
]


_rcm_adc_clk_div_t_return_type = Literal[
    "/1",
    "/16",
    "/2",
    "/4",
    "/8",
]


_rcm_fpu_clk_div_t_return_type = Literal[
    "/1",
    "/2",
]


_rcm_usb_clk_div_t_return_type = Literal[
    "/1",
    "/1.5",
    "/2",
    "/2.5",
]


_rcm_sdram_clk_div_t_return_type = Literal[
    "/1",
    "/2",
    "/4",
]


_rcm_pll_clk_div_mco_clk_t_return_type = Literal[
    "/2",
]


_rcm_flash_latency_t_return_type = Literal[
    "0",
    "1",
    "2",
    "3",
]


_rcm_css_t_return_type = Literal[
    "rcm_css_disable",
    "rcm_css_enable",
]


_rcm_hse_clock_source_t_return_type = Literal[
    "bypass",
    "disable",
    "oscillator",
]


_rcm_lse_clock_source_t_return_type = Literal[
    "bypass",
    "disable",
    "oscillator",
]


_rcm_prefetch_buffer_enabled_t_return_type = Literal[
    "rcm_prefetch_buffer_disable",
    "rcm_prefetch_buffer_enable",
]


_rcm_mco_enabled_t_return_type = Literal[
    "disabled",
    "enabled",
]


def rcm_lse_clk_input_t(
    project: Project,
    instance: str = "RCM",
    default: float = 32768,
) -> float:
    return project.configs.get(f"{instance}.rcm_lse_clk_input_t", default)


def rcm_hse_clk_input_t(
    project: Project,
    instance: str = "RCM",
    default: float = 8000000,
) -> float:
    return project.configs.get(f"{instance}.rcm_hse_clk_input_t", default)


def rcm_hse_clk_div_rtc_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_hse_clk_div_rtc_t_return_type = "/128",
) -> _rcm_hse_clk_div_rtc_t_return_type:
    return project.configs.get(f"{instance}.rcm_hse_clk_div_rtc_t", default)


def rcm_rtc_clk_mux_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_rtc_clk_mux_t_return_type = "lsi",
) -> _rcm_rtc_clk_mux_t_return_type:
    return project.configs.get(f"{instance}.rcm_rtc_clk_mux_t", default)


def rcm_rtc_clk_output_t(
    project: Project,
    instance: str = "RCM",
    default: float = 40000,
) -> float:
    return project.configs.get(f"{instance}.rcm_rtc_clk_output_t", default)


def rcm_lsi_clk_input_t(
    project: Project,
    instance: str = "RCM",
    default: float = 40000,
) -> float:
    return project.configs.get(f"{instance}.rcm_lsi_clk_input_t", default)


def rcm_iwdt_clk_output_t(
    project: Project,
    instance: str = "RCM",
    default: float = 40000,
) -> float:
    return project.configs.get(f"{instance}.rcm_iwdt_clk_output_t", default)


def rcm_hsi_clk_input_t(
    project: Project,
    instance: str = "RCM",
    default: float = 8000000,
) -> float:
    return project.configs.get(f"{instance}.rcm_hsi_clk_input_t", default)


def rcm_system_clk_mux_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_system_clk_mux_t_return_type = "hsi",
) -> _rcm_system_clk_mux_t_return_type:
    return project.configs.get(f"{instance}.rcm_system_clk_mux_t", default)


def rcm_fmc_clk_output_t(
    project: Project,
    instance: str = "RCM",
    default: float = 8000000,
) -> float:
    return project.configs.get(f"{instance}.rcm_fmc_clk_output_t", default)


def rcm_pll_clk_mux_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_pll_clk_mux_t_return_type = "hsi_div2",
) -> _rcm_pll_clk_mux_t_return_type:
    return project.configs.get(f"{instance}.rcm_pll_clk_mux_t", default)


def rcm_mco_clk_mux_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_mco_clk_mux_t_return_type = "hsi",
) -> _rcm_mco_clk_mux_t_return_type:
    return project.configs.get(f"{instance}.rcm_mco_clk_mux_t", default)


def rcm_hsi_clk_div_pll_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_hsi_clk_div_pll_t_return_type = "2",
) -> _rcm_hsi_clk_div_pll_t_return_type:
    return project.configs.get(f"{instance}.rcm_hsi_clk_div_pll_t", default)


def rcm_hse_clk_div_pll_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_hse_clk_div_pll_t_return_type = "/1",
) -> _rcm_hse_clk_div_pll_t_return_type:
    return project.configs.get(f"{instance}.rcm_hse_clk_div_pll_t", default)


def rcm_pll_clk_t(
    project: Project,
    instance: str = "RCM",
    default: float = 4000000,
) -> float:
    return project.configs.get(f"{instance}.rcm_pll_clk_t", default)


def rcm_pll_clk_mul_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_pll_clk_mul_t_return_type = "*2",
) -> _rcm_pll_clk_mul_t_return_type:
    return project.configs.get(f"{instance}.rcm_pll_clk_mul_t", default)


def rcm_sys_clk_t(
    project: Project,
    instance: str = "RCM",
    default: float = 8000000,
) -> float:
    return project.configs.get(f"{instance}.rcm_sys_clk_t", default)


def rcm_i2s_clk_out_t(
    project: Project,
    instance: str = "RCM",
    default: float = 8000000,
) -> float:
    return project.configs.get(f"{instance}.rcm_i2s_clk_out_t", default)


def rcm_ahb_clk_div_hclk_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_ahb_clk_div_hclk_t_return_type = "/1",
) -> _rcm_ahb_clk_div_hclk_t_return_type:
    return project.configs.get(f"{instance}.rcm_ahb_clk_div_hclk_t", default)


def rcm_hclk_t(
    project: Project,
    instance: str = "RCM",
    default: float = 8000000,
) -> float:
    return project.configs.get(f"{instance}.rcm_hclk_t", default)


def rcm_hclk_out_t(
    project: Project,
    instance: str = "RCM",
    default: float = 8000000,
) -> float:
    return project.configs.get(f"{instance}.rcm_hclk_out_t", default)


def rcm_fclk_out_t(
    project: Project,
    instance: str = "RCM",
    default: float = 8000000,
) -> float:
    return project.configs.get(f"{instance}.rcm_fclk_out_t", default)


def rcm_hclk_div_sys_timer_clk_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_hclk_div_sys_timer_clk_t_return_type = "/1",
) -> _rcm_hclk_div_sys_timer_clk_t_return_type:
    return project.configs.get(f"{instance}.rcm_hclk_div_sys_timer_clk_t", default)


def rcm_sys_timer_clk_out_t(
    project: Project,
    instance: str = "RCM",
    default: float = 8000000,
) -> float:
    return project.configs.get(f"{instance}.rcm_sys_timer_clk_out_t", default)


def rcm_apb1_div_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_apb1_div_t_return_type = "/1",
) -> _rcm_apb1_div_t_return_type:
    return project.configs.get(f"{instance}.rcm_apb1_div_t", default)


def rcm_apb1_peripherals_out_t(
    project: Project,
    instance: str = "RCM",
    default: float = 8000000,
) -> float:
    return project.configs.get(f"{instance}.rcm_apb1_peripherals_out_t", default)


def rcm_apb1_timers_mul_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_apb1_timers_mul_t_return_type = "*1",
) -> _rcm_apb1_timers_mul_t_return_type:
    return project.configs.get(f"{instance}.rcm_apb1_timers_mul_t", default)


def rcm_apb1_timers_out_t(
    project: Project,
    instance: str = "RCM",
    default: float = 8000000,
) -> float:
    return project.configs.get(f"{instance}.rcm_apb1_timers_out_t", default)


def rcm_apb2_div_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_apb2_div_t_return_type = "/1",
) -> _rcm_apb2_div_t_return_type:
    return project.configs.get(f"{instance}.rcm_apb2_div_t", default)


def rcm_apb2_peripherals_out_t(
    project: Project,
    instance: str = "RCM",
    default: float = 8000000,
) -> float:
    return project.configs.get(f"{instance}.rcm_apb2_peripherals_out_t", default)


def rcm_apb2_timers_mul_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_apb2_timers_mul_t_return_type = "*1",
) -> _rcm_apb2_timers_mul_t_return_type:
    return project.configs.get(f"{instance}.rcm_apb2_timers_mul_t", default)


def rcm_apb2_timers_out_t(
    project: Project,
    instance: str = "RCM",
    default: float = 8000000,
) -> float:
    return project.configs.get(f"{instance}.rcm_apb2_timers_out_t", default)


def rcm_adc_clk_div_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_adc_clk_div_t_return_type = "/1",
) -> _rcm_adc_clk_div_t_return_type:
    return project.configs.get(f"{instance}.rcm_adc_clk_div_t", default)


def rcm_adc_clk_out_t(
    project: Project,
    instance: str = "RCM",
    default: float = 4000000,
) -> float:
    return project.configs.get(f"{instance}.rcm_adc_clk_out_t", default)


def rcm_fpu_clk_div_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_fpu_clk_div_t_return_type = "/1",
) -> _rcm_fpu_clk_div_t_return_type:
    return project.configs.get(f"{instance}.rcm_fpu_clk_div_t", default)


def rcm_fpu_clk_out_t(
    project: Project,
    instance: str = "RCM",
    default: float = 8000000,
) -> float:
    return project.configs.get(f"{instance}.rcm_fpu_clk_out_t", default)


def rcm_sdio_clk_out_t(
    project: Project,
    instance: str = "RCM",
    default: float = 8000000,
) -> float:
    return project.configs.get(f"{instance}.rcm_sdio_clk_out_t", default)


def rcm_usb_clk_div_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_usb_clk_div_t_return_type = "/1",
) -> _rcm_usb_clk_div_t_return_type:
    return project.configs.get(f"{instance}.rcm_usb_clk_div_t", default)


def rcm_usb_clk_out_t(
    project: Project,
    instance: str = "RCM",
    default: float = 48000000,
) -> float:
    return project.configs.get(f"{instance}.rcm_usb_clk_out_t", default)


def rcm_smc_clk_out_t(
    project: Project,
    instance: str = "RCM",
    default: float = 8000000,
) -> float:
    return project.configs.get(f"{instance}.rcm_smc_clk_out_t", default)


def rcm_dmc_clk_out_t(
    project: Project,
    instance: str = "RCM",
    default: float = 8000000,
) -> float:
    return project.configs.get(f"{instance}.rcm_dmc_clk_out_t", default)


def rcm_sdram_clk_div_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_sdram_clk_div_t_return_type = "/1",
) -> _rcm_sdram_clk_div_t_return_type:
    return project.configs.get(f"{instance}.rcm_sdram_clk_div_t", default)


def rcm_sdram_clk_out_t(
    project: Project,
    instance: str = "RCM",
    default: float = 8000000,
) -> float:
    return project.configs.get(f"{instance}.rcm_sdram_clk_out_t", default)


def rcm_pll_clk_div_mco_clk_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_pll_clk_div_mco_clk_t_return_type = "/2",
) -> _rcm_pll_clk_div_mco_clk_t_return_type:
    return project.configs.get(f"{instance}.rcm_pll_clk_div_mco_clk_t", default)


def rcm_mco_clk_out_t(
    project: Project,
    instance: str = "RCM",
    default: float = 8000000,
) -> float:
    return project.configs.get(f"{instance}.rcm_mco_clk_out_t", default)


def rcm_hsi_calibration_t(
    project: Project,
    instance: str = "RCM",
    default: int = 16,
) -> int:
    return project.configs.get(f"{instance}.rcm_hsi_calibration_t", default)


def rcm_flash_latency_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_flash_latency_t_return_type = "0",
) -> _rcm_flash_latency_t_return_type:
    return project.configs.get(f"{instance}.rcm_flash_latency_t", default)


def rcm_css_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_css_t_return_type = "rcm_css_disable",
) -> _rcm_css_t_return_type:
    return project.configs.get(f"{instance}.rcm_css_t", default)


def rcm_hse_clock_source_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_hse_clock_source_t_return_type = "disable",
) -> _rcm_hse_clock_source_t_return_type:
    return project.configs.get(f"{instance}.rcm_hse_clock_source_t", default)


def rcm_lse_clock_source_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_lse_clock_source_t_return_type = "disable",
) -> _rcm_lse_clock_source_t_return_type:
    return project.configs.get(f"{instance}.rcm_lse_clock_source_t", default)


def rcm_prefetch_buffer_enabled_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_prefetch_buffer_enabled_t_return_type = "rcm_prefetch_buffer_enable",
) -> _rcm_prefetch_buffer_enabled_t_return_type:
    return project.configs.get(f"{instance}.rcm_prefetch_buffer_enabled_t", default)


def rcm_mco_enabled_t(
    project: Project,
    instance: str = "RCM",
    default: _rcm_mco_enabled_t_return_type = "disabled",
) -> _rcm_mco_enabled_t_return_type:
    return project.configs.get(f"{instance}.rcm_mco_enabled_t", default)


# fmt: on
# endregion
# ------------------------------------------------------------------------------

# --< user code begin code, do not change this comment!
def rcm_flash_latency(project: Project) -> str:
    m = {
        "0": "0",
        "1": "1",
        "2": "2",
        "3": "3",
    }
    latency = rcm_flash_latency_t(project)
    return m[latency]


def rcm_hse_used(project: Project) -> bool:
    pll_clk_mux = rcm_pll_clk_mux_t(project)
    system_clk_mux = rcm_system_clk_mux_t(project)
    mco_clk_mux = rcm_mco_clk_mux_t(project)
    rtc_clk_mux = rcm_rtc_clk_mux_t(project)

    hse_clock_source = rcm_hse_clock_source_t(project)

    use_rtc = True  # TODO:
    use_pll = rcm_pll_used(project)
    use_mco = True  # TODO:

    if hse_clock_source == "disable":
        return False

    if use_rtc and rtc_clk_mux == "hse_div128":
        return True

    if use_pll and pll_clk_mux == "hse":
        return True

    if system_clk_mux == "hse":
        return True

    if use_mco and mco_clk_mux == "hse":
        return True

    return False


def rcm_hsi_used(project: Project) -> bool:
    pll_clk_mux = rcm_pll_clk_mux_t(project)
    system_clk_mux = rcm_system_clk_mux_t(project)
    mco_clk_mux = rcm_mco_clk_mux_t(project)

    use_pll = rcm_pll_used(project)
    use_mco = True  # TODO:

    if use_pll and pll_clk_mux == "hsi_div2":
        return True

    if system_clk_mux == "hsi":
        return True

    if use_mco and mco_clk_mux == "hsi":
        return True

    return False


def rcm_lse_used(project: Project) -> bool:
    rtc_clk_mux = rcm_rtc_clk_mux_t(project)

    lse_clock_source = rcm_lse_clock_source_t(project)

    use_rtc = True  # TODO:

    if lse_clock_source == "disable":
        return False

    if use_rtc and rtc_clk_mux == "lse":
        return True

    return False


def rcm_lsi_used(project: Project) -> bool:
    rtc_clk_mux = rcm_rtc_clk_mux_t(project)

    use_iwdg = True  # TODO:

    if use_iwdg:
        return True

    if rtc_clk_mux == "lsi":
        return True

    return False


def rcm_pll_used(project: Project) -> bool:
    system_clk_mux = rcm_system_clk_mux_t(project)
    mco_clk_mux = rcm_mco_clk_mux_t(project)

    use_mco = True  # TODO:
    use_usb = True  # TODO:

    if system_clk_mux == "pll":
        return True

    if use_mco and mco_clk_mux == "pll_div2":
        return True

    if use_usb:
        return True

    return False


def rcm_mco_enabled(project: Project) -> bool:
    mco_enabled = rcm_mco_enabled_t(project)
    return mco_enabled == "enabled"


def rcm_pll_clk_mux(project: Project) -> str:
    mux = rcm_pll_clk_mux_t(project)
    div = rcm_hse_clk_div_pll_t(project)

    if mux == "hsi_div2":
        return "RCM_PLLSEL_HSI_DIV_2"
    else:
        if div == "/1":
            return "RCM_PLLSEL_HSE"
        else:
            return "RCM_PLLSEL_HSE_DIV2"


def rcm_system_clk_mux(project: Project) -> str:
    m = {
        "hsi": "RCM_SYSCLK_SEL_HSI",
        "hse": "RCM_SYSCLK_SEL_HSE",
        "pll": "RCM_SYSCLK_SEL_PLL",
    }
    mux = rcm_system_clk_mux_t(project)
    return m[mux]


def rcm_mco_clk_mux(project: Project) -> str:
    m = {
        "pll_div2": "RCM_MCOCLK_PLLCLK_DIV_2",
        "hsi": "RCM_MCOCLK_HSI",
        "hse": "RCM_MCOCLK_HSE",
        "system": "RCM_MCOCLK_SYSCLK",
    }
    mux = rcm_mco_clk_mux_t(project)
    return m[mux]


def rcm_pll_clk_mul(project: Project) -> str:
    m = {
        "*2": "RCM_PLLMF_2",
        "*3": "RCM_PLLMF_3",
        "*4": "RCM_PLLMF_4",
        "*5": "RCM_PLLMF_5",
        "*6": "RCM_PLLMF_6",
        "*7": "RCM_PLLMF_7",
        "*8": "RCM_PLLMF_8",
        "*9": "RCM_PLLMF_9",
        "*10": "RCM_PLLMF_10",
        "*11": "RCM_PLLMF_11",
        "*12": "RCM_PLLMF_12",
        "*13": "RCM_PLLMF_13",
        "*14": "RCM_PLLMF_14",
        "*15": "RCM_PLLMF_15",
        "*16": "RCM_PLLMF_16",
    }
    mul = rcm_pll_clk_mul_t(project)
    return m[mul]


def rcm_ahb_clk_div_hclk(project: Project) -> str:
    m = {
        "/1": "RCM_AHB_DIV_1",
        "/2": "RCM_AHB_DIV_2",
        "/4": "RCM_AHB_DIV_4",
        "/8": "RCM_AHB_DIV_8",
        "/16": "RCM_AHB_DIV_16",
        "/64": "RCM_AHB_DIV_64",
        "/128": "RCM_AHB_DIV_128",
        "/256": "RCM_AHB_DIV_256",
        "/512": "RCM_AHB_DIV_512",
    }
    div = rcm_ahb_clk_div_hclk_t(project)
    return m[div]


def rcm_apb1_div(project: Project) -> str:
    m = {
        "/1": "RCM_APB_DIV_1",
        "/2": "RCM_APB_DIV_2",
        "/4": "RCM_APB_DIV_4",
        "/8": "RCM_APB_DIV_8",
        "/16": "RCM_APB_DIV_16",
    }
    div = rcm_apb1_div_t(project)
    return m[div]


def rcm_apb2_div(project: Project) -> str:
    m = {
        "/1": "RCM_APB_DIV_1",
        "/2": "RCM_APB_DIV_2",
        "/4": "RCM_APB_DIV_4",
        "/8": "RCM_APB_DIV_8",
        "/16": "RCM_APB_DIV_16",
    }
    div = rcm_apb2_div_t(project)
    return m[div]


def rcm_mco_io(project: Project) -> str | None:
    return None
    ios = csp_project_helper.find_pins_by_function(project, "RCM:MCO")
    if ios:
        return ios[0]
    else:
        return None

# --> user code end code, do not change this comment!
