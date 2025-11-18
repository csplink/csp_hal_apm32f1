#!/usr/bin/env python3
# -*- coding:utf-8 -*-

#
# ------------------------------------------------------------------------------
#  @author:            csplink coder
#  @file:              sys.py
#  @version:           0.0.6
#  @time:              2025-11-14 15:40:50
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

_sys_instance_t_return_type = Literal[
    "sys_tick",
    "tim1",
    "tim2",
    "tim3",
    "tim4",
    "tim5",
    "tim6",
    "tim7",
    "tim8",
]


_sys_ctrl_debug_t_return_type = Literal[
    "jtag_4_pins",
    "jtag_5_pins",
    "no_debug",
    "serial_wire",
    "trace_asynchronous_sw",
    "trace_synchro_1bit_jtag",
    "trace_synchro_1bit_sw",
    "trace_synchro_2bits_jtag",
    "trace_synchro_2bits_sw",
    "trace_synchro_4bits_jtag",
    "trace_synchro_4bits_sw",
]


_sys_ctrl_time_base_t_return_type = Literal[
    "sys_tick",
    "tmr1",
    "tmr2",
    "tmr3",
    "tmr4",
    "tmr5",
    "tmr6",
    "tmr7",
    "tmr8",
]


def sys_instance_t(
    project: Project,
    instance: str = "SYS",
    default: _sys_instance_t_return_type = "tim1",
) -> _sys_instance_t_return_type:
    return project.configs.get(f"{instance}.sys_instance_t", default)


def sys_ctrl_debug_t(
    project: Project,
    instance: str = "SYS",
    default: _sys_ctrl_debug_t_return_type = "no_debug",
) -> _sys_ctrl_debug_t_return_type:
    return project.configs.get(f"{instance}.sys_ctrl_debug_t", default)


def sys_ctrl_wake_up0_t(
    project: Project,
    instance: str = "SYS",
    default: bool = False,
) -> bool:
    return project.configs.get(f"{instance}.sys_ctrl_wake_up0_t", default)


def sys_ctrl_time_base_t(
    project: Project,
    instance: str = "SYS",
    default: _sys_ctrl_time_base_t_return_type = "sys_tick",
) -> _sys_ctrl_time_base_t_return_type:
    return project.configs.get(f"{instance}.sys_ctrl_time_base_t", default)


# fmt: on
# endregion
# ------------------------------------------------------------------------------

# --< user code begin code, do not change this comment!
def sys_clocks(project: Project) -> list[str]:
    rtn = set()

    wake_up0 = sys_ctrl_wake_up0_t(project)
    if wake_up0:
        rtn.add("RCM_APB2_PERIPH_GPIOA")

    debug = sys_ctrl_debug_t(project)
    if debug == "serial_wire":
        rtn.add("RCM_APB2_PERIPH_GPIOA")
    elif debug in [
        "jtag_4_pins",
        "jtag_5_pins",
        "trace_asynchronous_sw",
    ]:
        rtn.add("RCM_APB2_PERIPH_GPIOA")
        rtn.add("RCM_APB2_PERIPH_GPIOB")
    elif debug == "no_debug":
        pass
    else:
        rtn.add("RCM_APB2_PERIPH_GPIOA")
        rtn.add("RCM_APB2_PERIPH_GPIOB")
        rtn.add("RCM_APB2_PERIPH_GPIOE")

    return sorted(rtn)


def sys_debug(project: Project) -> str:
    rtn = "GPIO_NO_REMAP_SWJ"

    debug = sys_ctrl_debug_t(project)

    if debug in [
        "serial_wire",
        "trace_asynchronous_sw",
        "trace_synchro_1bit_sw",
        "trace_synchro_1bit_sw",
        "trace_synchro_2bits_sw",
        "trace_synchro_4bits_sw",
    ]:
        rtn = "GPIO_REMAP_SWJ_JTAGDISABLE"
    elif debug in [
        "jtag_4_pins",
        "trace_synchro_1bit_jtag",
        "trace_synchro_2bits_jtag",
        "trace_synchro_4bits_jtag",
    ]:
        rtn = "GPIO_REMAP_SWJ_NOJTRST"
    elif debug in [
        "jtag_5_pins",
    ]:
        rtn = "GPIO_NO_REMAP_SWJ"
    elif debug in [
        "no_debug",
    ]:
        rtn = "GPIO_REMAP_SWJ_DISABLE"

    return rtn

# --> user code end code, do not change this comment!
