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
# @file        coder.py
#
# Change Logs:
# Date           Author       Notes
# ------------   ----------   -----------------------------------------------
# 2024-03-22     xqyjlj       initial version
#

import os
import glob
import shutil
import xml.etree.ElementTree as etree

script_dir = os.path.dirname(__file__)
root_dir = os.path.join(script_dir, "..", "..")

files_map = {
    "Src": {
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
    },
    "Inc": [
        "core/inc",
        "hal/libraries/cmsis/inc",
        "hal/libraries/cmsis_core/inc",
        "hal/libraries/drivers/inc",
    ]
}

link_script_map = {"APM32F103ZET6": f"{root_dir}/tools/coder/res/gcc/APM32F10xxE.lds"}

device_map = {
    "APM32F103C8T6": "APM32F10X_MD",
    "APM32F103ZET6": "APM32F10X_HD",
}


def parse_startup_file(project: dict) -> dict:
    name = device_map[project["TargetChip"]].lower()
    name = f"startup_{name}.s"
    startup = {"Path": "", "Name": name}

    if project["TargetProject"] == "MDK-Arm":
        startup["Path"] = f"{root_dir}/tools/coder/res/mdk/{name}"
    elif project["TargetProject"] == "XMake" or project["TargetProject"] == "CMake":
        startup["Path"] = f"{root_dir}/tools/coder/res/gcc/{name}"
    else:
        startup["Path"] = f"{root_dir}/tools/coder/res/gcc/{name}"
    return startup


def parse_files(project: dict) -> dict:
    files = {"Src": [], "Inc": files_map["Inc"]}
    if project["TargetProject"] == "MDK-Arm":
        files = files_map
        for module in project["Modules"]:
            files["Src"]["application/user/core"].append(f"core/src/{module.lower()}.c")
    else:
        for _, value in files_map["Src"].items():
            files["Src"].extend(value)
        for module in project["Modules"]:
            files["Src"].append(f"core/src/{module.lower()}.c")
    return files


def parse_marco(project: dict) -> list:
    array = []
    array.append(device_map[project["TargetChip"]])
    return array


def parse_gpio(project: dict) -> dict:
    level_map = {
        "std.gpio_level_low": "BIT_RESET",
        "std.gpio_level_high": "BIT_SET",
    }
    output_mode_map = {
        "std.gpio_output_pp": "GPIO_MODE_OUT_PP",
        "std.gpio_output_od": "GPIO_MODE_OUT_OD",
    }
    speed_map = {
        "std.gpio_speed_low": "GPIO_SPEED_10MHz",
        "std.gpio_speed_medium": "GPIO_SPEED_2MHz",
        "std.gpio_speed_high": "GPIO_SPEED_50MHz",
    }
    input_mode_map = {
        "std.gpio_pull_up": "GPIO_MODE_IN_PU",
        "std.gpio_pull_down": "GPIO_MODE_IN_PD",
        "std.gpio_pull_no": "GPIO_MODE_IN_FLOATING",
    }
    analog_mode_map = {
        "std.gpio_mode_analog": "GPIO_MODE_ANALOG",
    }

    gpio_configs = {"Clock": {"Names": [], "Values": []}, "Infos": {}}
    for name, pin_info in project["PinConfigs"].items():
        function = pin_info["Function"]
        if pin_info["Locked"] and str.startswith(function, "GPIO-"):
            prop = pin_info["FunctionProperty"]["gpio"]
            gpiox = f"GPIO{str(name[1])}"
            if not gpiox in gpio_configs["Infos"].keys():
                gpio_configs["Infos"][gpiox] = {}

            comment = pin_info["Comment"]
            if comment == "":
                port = gpiox
                pin = f"GPIO_PIN_{name[2:]}"
            else:
                port = f"{comment}_PORT"
                pin = f"{comment}_PIN"

            level = ""
            mode = ""
            speed = ""

            if function == "GPIO-Output":
                level = level_map[prop["std.gpio_level_t"]]  # pin level
                mode = output_mode_map[prop["std.gpio_output_type_t"]]  # pin mode
                speed = speed_map[prop["std.gpio_speed_t"]]  # pin speed
            elif function == "GPIO-Analog":
                mode = analog_mode_map[prop["std.gpio_mode_t"]]  # pin analog
            elif function == "GPIO-Input":
                mode = input_mode_map[prop["std.gpio_pull_t"]]  # pin pull
            elif function == "GPIO-EXTI":
                if "RCM_APB2_PERIPH_AFIO" not in gpio_configs["Clock"]:
                    gpio_configs["Clock"]["Names"].append("AFIO")
                    gpio_configs["Clock"]["Values"].append("RCM_APB2_PERIPH_AFIO")
                mode = input_mode_map[prop["std.gpio_pull_t"]]  # pin pull
            else:
                raise Exception(f'GPIO: This feature"{function}" is not supported at this time')

            gpio_configs["Infos"][gpiox][name] = {
                "Port": port,
                "Pin": pin,
                "Mode": mode,
                "Speed": speed,
                "Comment": comment,
                "Level": level
            }
    for gpiox in gpio_configs["Infos"].keys():
        gpio_configs["Clock"]["Names"].append(gpiox)
        gpio_configs["Clock"]["Values"].append(f"RCM_APB2_PERIPH_GPIO{gpiox[4]}")
    return gpio_configs


def parse(project: dict) -> dict:
    gpio_configs = parse_gpio(project)
    marco = parse_marco(project)
    startup_file = parse_startup_file(project)
    files = parse_files(project)
    return {"GpioConfigs": gpio_configs, "Marco": marco, "StartupFile": startup_file, "Files": files}


def deploy(project: dict, output_dir: str):
    file_list = [
        "libraries/cmsis/inc/*.h",  #
        "libraries/cmsis_core/inc/*.h",
        "libraries/cmsis_core/LICENSE.txt",
        "libraries/drivers/inc/*.h",
        "libraries/drivers/src/*.c",
        ".clang-format",
        ".gitattributes",
        ".gitignore",
        "LICENSE",
        "README*.md"
    ]

    # libraries
    for match in file_list:
        for source in glob.glob(f"{root_dir}/{match}"):
            dest = f"{output_dir}/hal/{os.path.relpath(source, root_dir)}"
            if not os.path.exists(dest):
                if not os.path.isdir(os.path.dirname(dest)):
                    os.makedirs(os.path.dirname(dest))
                shutil.copy(source, dest)

    # startup file
    startup_file_path = parse_startup_file(project)["Path"]
    startup_file_name = parse_startup_file(project)["Name"]
    if project["TargetProject"] == "MDK-Arm":
        dest = f"{output_dir}/mdk-arm/{startup_file_name}"
    else:
        dest = f"{output_dir}/{startup_file_name}"
    if not os.path.exists(dest):
        shutil.copy(startup_file_path, dest)

    # link script
    if project["TargetProject"] == "XMake" or project["TargetProject"] == "CMake":
        dest = f"{output_dir}/{project['TargetChip']}.lds"
        if not os.path.exists(dest):
            shutil.copy(f"{link_script_map[project['TargetChip']]}", dest)

    # system_apm32f10x.c
    dest = f"{output_dir}/core/src/system_apm32f10x.c"
    if not os.path.exists(dest):
        shutil.copy(f"{root_dir}/tools/coder/res/system_apm32f10x.c", dest)


def generate_mdk_arm_project(project: dict, keil_utils) -> str:
    """
    Generate MDK project files for ARM.

    Args:
        project (dict): Project information.
        output_dir (str): Output directory.
    """

    # version = project["TargetProjectMinVersion"]
    chip = project["TargetChip"][:11]
    chip_type = chip[:9]

    template_file = f"{script_dir}/templates/MDK-Arm/{chip_type}/{chip}.uvprojx"
    if os.path.isfile(template_file) is False:
        Exception(f"Template file {template_file} not found.")

    tree = etree.parse(template_file)
    target_name = project['Name']

    root = tree.getroot()
    out = []
    out.append('<?xml version="1.0" encoding="UTF-8" standalone="no" ?>\n')

    tree.find('Targets/Target/TargetName').text = target_name
    tree.find('Targets/Target/TargetOption/TargetCommonOption/OutputName').text = target_name
    tree.find('Targets/Target/TargetOption/TargetCommonOption/AfterMake/RunUserProg1').text = "1"
    tree.find('Targets/Target/TargetOption/TargetCommonOption/AfterMake/UserProg1Name'
              ).text = f"fromelf --bin !L --output {target_name}.bin"
    tree.find('Targets/Target/TargetOption/TargetArmAds/Cads/VariousControls/Define').text = ', '.join(
        parse_marco(project))

    files = parse_files(project)

    incs = []
    for inc in files["Inc"]:
        incs.append(f'../{inc}'.replace('/', '\\'))
    tree.find('Targets/Target/TargetOption/TargetArmAds/Cads/VariousControls/IncludePath').text = ';'.join(incs)

    groups = tree.find('Targets/Target/Groups')
    if groups is None:
        groups = etree.SubElement(tree.find('Targets/Target'), 'Groups')

    startup_file = parse_startup_file(project)
    keil_utils.add_group(groups, "application/mdk", [startup_file["Name"]], "")

    for key, value in files_map["Src"].items():
        keil_utils.add_group(groups, key, value, "../")

    keil_utils.xml_indent(root)
    out.append(etree.tostring(root, encoding='utf-8', short_empty_elements=False).decode())

    return "\n".join(out)
