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
# Copyright (C) 2022-2024 xqyjlj<xqyjlj@126.com>
#
# @author      xqyjlj
# @file        make.py
#
# Change Logs:
# Date           Author       Notes
# ------------   ----------   -----------------------------------------------
# 2024-06-02     xqyjlj       initial version
#

import copy

inc_dirs = [
    "core/inc",
    "hal/libraries/cmsis/inc",
    "hal/libraries/cmsis_core/inc",
    "hal/libraries/drivers/inc",
]

src_files_group = {
    "application/user/core": [
        "core/src/main.c",
    ],
    "drivers/hal": [
        "hal/libraries/drivers/src/apm32f10x_adc.c",
        "hal/libraries/drivers/src/apm32f10x_bakpr.c",
        "hal/libraries/drivers/src/apm32f10x_can.c",
        "hal/libraries/drivers/src/apm32f10x_crc.c",
        "hal/libraries/drivers/src/apm32f10x_dac.c",
        "hal/libraries/drivers/src/apm32f10x_dbgmcu.c",
        "hal/libraries/drivers/src/apm32f10x_dma.c",
        "hal/libraries/drivers/src/apm32f10x_dmc.c",
        "hal/libraries/drivers/src/apm32f10x_eint.c",
        "hal/libraries/drivers/src/apm32f10x_fmc.c",
        "hal/libraries/drivers/src/apm32f10x_gpio.c",
        "hal/libraries/drivers/src/apm32f10x_i2c.c",
        "hal/libraries/drivers/src/apm32f10x_iwdt.c",
        "hal/libraries/drivers/src/apm32f10x_misc.c",
        "hal/libraries/drivers/src/apm32f10x_pmu.c",
        "hal/libraries/drivers/src/apm32f10x_qspi.c",
        "hal/libraries/drivers/src/apm32f10x_rcm.c",
        "hal/libraries/drivers/src/apm32f10x_rtc.c",
        "hal/libraries/drivers/src/apm32f10x_sci2c.c",
        "hal/libraries/drivers/src/apm32f10x_sdio.c",
        "hal/libraries/drivers/src/apm32f10x_smc.c",
        "hal/libraries/drivers/src/apm32f10x_spi.c",
        "hal/libraries/drivers/src/apm32f10x_tmr.c",
        "hal/libraries/drivers/src/apm32f10x_usart.c",
        "hal/libraries/drivers/src/apm32f10x_wwdt.c",
    ],
    "drivers/cmsis": [
        "core/src/system_apm32f10x.c",
    ],
}

device_map = {
    "APM32F10X_MD": ["APM32F103C8T6"],
    "APM32F10X_HD": ["APM32F103ZET6"],
}


def make_marco(project: dict) -> list:
    marco = []

    for key, value in device_map.items():
        if project["TargetChip"] in value:
            marco.append(key)
            break

    return marco


def make_inc_dirs(project: dict) -> list:
    return inc_dirs


def make_src_files_group(project: dict) -> list:
    group = copy.deepcopy(src_files_group)

    for module in project["Modules"]:
        group["application/user/core"].append(f"core/src/{module.lower()}.c")

    for key in group.keys():
        group[key].sort()

    return group


def make_src_files(project: dict) -> list:
    files = []

    for _, value in make_src_files_group(project).items():
        files.extend(value)

    files = list(set(files))
    files.sort()

    return files


def make_startup_file(project: dict) -> str:
    name = None
    for key, value in device_map.items():
        if project["TargetChip"] in value:
            name = key.lower()
            break
    if name:
        name = f"startup_{name}.s"
    return name
