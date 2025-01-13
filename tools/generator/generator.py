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
# @file        generator.py
#
# Change Logs:
# Date           Author       Notes
# ------------   ----------   -----------------------------------------------
# 2024-10-12     xqyjlj       initial version
#

import glob
import os
import shutil
from typing import Callable

script_dir = os.path.dirname(__file__)
root_dir = os.path.join(script_dir, "..", "..")


def files_table(project: dict) -> dict[str, dict[str, str]]:
    all_modules = [
        'ADC1', 'ADC2', 'ADC3', 'DAC',
        'CRC',
        'CAN', 'EMMC', 'I2C1', 'I2C2', 'SDIO', 'SPI1', 'SPI2', 'SPI3', 'UART4', 'UART5', 'USART1', 'USART2', 'USART3',
        'USBD',

        'I2S2', 'I2S3',
        'DMA', 'GPIO', 'IWDT', 'NVIC', 'RCM', 'SYS', 'WWDT',
        'RTC', 'TMR1', 'TMR2', 'TMR3', 'TMR4', 'TMR5', 'TMR6', 'TMR7', 'TMR8',
    ]
    files = {
        "core/inc/main.h": {"brief": "main program body"},
        "core/src/main.c": {"brief": "main program body"},
        "core/src/isr_vector.c": {"brief": "interrupt vector table"},
        "core/src/system_apm32f10x.c": {"brief": "CMSIS Cortex-M3 Device Peripheral Access Layer System Source File"},
    }

    modules: list[str] = project.get("modules", [])
    for module in all_modules:
        mod = module.lower()
        files[f"core/inc/csp/{mod}.h"] = {"brief": f"this file provides code for the {mod} initialization"}
        files[f"core/src/{mod}.c"] = {"brief": f"this file provides code for the {mod} initialization"}
        if module not in modules:
            files[f"core/inc/csp/{mod}.h"]['gen'] = False
            files[f"core/src/{mod}.c"]['gen'] = False

    builder = project.get("gen", {}).get("builder", '')
    if builder == "CMake":
        files[f"CMakeLists.txt"] = {"brief": "this file provides code for the cmake build system"}
    elif builder == "XMake":
        files[f"xmake.lua"] = {"brief": "this file provides code for the xmake build system"}

    targetChip = project.get("targetChip", 'linker_script')
    toolchains = project.get("gen", {}).get("toolchains", '')
    if toolchains == 'arm-none-eabi':
        files[f"{targetChip}.lds"] = {
            "brief": f"this file provides linker script for the {targetChip} device",
            "template": "linker_script.lds.j2"
        }
        files[f"startup_gcc.S"] = {"brief": f"CMSIS Cortex-M3 based Core Device Startup File for Device {targetChip}"}

    return files


def copy_library(project: dict, output: str, callback: Callable[[str, int, int, bool, str], None]):
    file_list = [
        "libraries/cmsis/device/*",
        "libraries/cmsis/inc/*",
        "libraries/std_drivers/inc/*.h",
        "libraries/std_drivers/src/*.c",
        ".clang-format",
        ".gitattributes",
        ".gitignore",
        "LICENSE",
        "README*.md"
    ]

    li = {}

    # libraries
    for match in file_list:
        for source in glob.glob(f"{root_dir}/{match}"):
            dest = f"{output}/hal/{os.path.relpath(source, root_dir)}"
            dest = dest.replace("\\", "/")
            li[source] = dest

    count = len(li)
    for index, (source, dest) in enumerate(li.items(), start=1):
        if not os.path.exists(dest):
            if not os.path.isdir(os.path.dirname(dest)):
                os.makedirs(os.path.dirname(dest))
            shutil.copy(source, dest)
            callback(dest, index, count, True, 'because the file does not exist')
        else:
            callback(dest, index, count, False, 'because the file already exists')
