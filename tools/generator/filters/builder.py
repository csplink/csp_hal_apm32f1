#!/usr/bin/env python3
# -*- coding:utf-8 -*-

# Licensed under the Apache License v. 2 (the "License")
# You may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0.html
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Copyright (C) 2025-2025 xqyjlj<xqyjlj@126.com>
#
# @author      xqyjlj
# @file        builder.py
#
# Change Logs:
# Date           Author       Notes
# ------------   ----------   -----------------------------------------------
# 2024-12-15     xqyjlj       initial version
#

import copy

from csp.project import Project
import filters.chip as chip

inc_dirs = [
    "core/inc",
    "hal/libraries/cmsis/device",
    "hal/libraries/cmsis/inc",
    "hal/libraries/std_drivers/inc",
]

src_files_group = {
    "application/core": [
        "core/src/main.c",
        "core/src/isr.c",
    ],
    "std_drivers/hal": [
        "hal/libraries/std_drivers/src/apm32f10x_adc.c",
        "hal/libraries/std_drivers/src/apm32f10x_bakpr.c",
        "hal/libraries/std_drivers/src/apm32f10x_can.c",
        "hal/libraries/std_drivers/src/apm32f10x_crc.c",
        "hal/libraries/std_drivers/src/apm32f10x_dac.c",
        "hal/libraries/std_drivers/src/apm32f10x_dbgmcu.c",
        "hal/libraries/std_drivers/src/apm32f10x_dma.c",
        "hal/libraries/std_drivers/src/apm32f10x_dmc.c",
        "hal/libraries/std_drivers/src/apm32f10x_eint.c",
        "hal/libraries/std_drivers/src/apm32f10x_fmc.c",
        "hal/libraries/std_drivers/src/apm32f10x_gpio.c",
        "hal/libraries/std_drivers/src/apm32f10x_i2c.c",
        "hal/libraries/std_drivers/src/apm32f10x_iwdt.c",
        "hal/libraries/std_drivers/src/apm32f10x_misc.c",
        "hal/libraries/std_drivers/src/apm32f10x_pmu.c",
        "hal/libraries/std_drivers/src/apm32f10x_qspi.c",
        "hal/libraries/std_drivers/src/apm32f10x_rcm.c",
        "hal/libraries/std_drivers/src/apm32f10x_rtc.c",
        "hal/libraries/std_drivers/src/apm32f10x_sci2c.c",
        "hal/libraries/std_drivers/src/apm32f10x_sdio.c",
        "hal/libraries/std_drivers/src/apm32f10x_smc.c",
        "hal/libraries/std_drivers/src/apm32f10x_spi.c",
        "hal/libraries/std_drivers/src/apm32f10x_tmr.c",
        "hal/libraries/std_drivers/src/apm32f10x_usart.c",
        "hal/libraries/std_drivers/src/apm32f10x_wwdt.c",
    ],
    "std_drivers/cmsis": [
        "core/src/system_apm32f10x.c",
    ],
}

device_map = {
    "APM32F10X_MD": ["APM32F103C8T6"],
    "APM32F10X_HD": ["APM32F103ZET6"],
}


def builder_defines(project: Project) -> list[str]:
    cl = chip.chip_info(project)
    li = [cl["class"]]
    return li


def builder_inc_dirs(project: Project) -> list:
    return inc_dirs


def builder_src_files_group(project: Project) -> dict:
    group = copy.deepcopy(src_files_group)

    builder = project.gen.builder
    toolchains = project.gen.toolchains

    if builder == "MDK-Arm":
        group["application/core"].append("startup_arm.s")
    elif toolchains == "arm-none-eabi":
        group["application/core"].append("startup_gcc.S")

    for module in project.modules:
        group["application/core"].append(f"core/src/{module.lower()}.c")

    for key in group.keys():
        group[key].sort()

    return group


def builder_src_files(project: Project) -> list:
    files = []

    for _, value in builder_src_files_group(project).items():
        files.extend(value)

    files = list(set(files))
    files.sort()

    return files
