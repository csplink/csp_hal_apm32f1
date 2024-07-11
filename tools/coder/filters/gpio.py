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
# @file        gpio.py
#
# Change Logs:
# Date           Author       Notes
# ------------   ----------   -----------------------------------------------
# 2024-05-31     xqyjlj       initial version
#

import json


def _hash_dict(dictionary):
    json_str = json.dumps(dictionary, sort_keys=True)
    return hash(json_str)


def gpio_pin_names(project: dict) -> list:
    pins = []

    for key, value in project["Config"]["GPIO"].items():
        if value["Locked"] == True and len(value["FunctionProperty"]) != 0:
            pins.append(key)

    pins.sort()

    return pins


def gpio_clocks(project: dict) -> list:
    clocks = []

    pins = gpio_pin_names(project)
    for pin in pins:
        clocks.append(f"RCM_APB2_PERIPH_GPIO{str(pin[1]).upper()}")
        if project["Config"]["GPIO"][pin]["Function"] == "GPIO-EXTI":
            clocks.append(f"RCM_APB2_PERIPH_AFIO")

    clocks = list(set(clocks))
    clocks.sort()

    return clocks


def gpio_clock_names(project: dict) -> list:
    names = []

    clocks = gpio_clocks(project)
    for clock in clocks:
        names.append(clock.replace("RCM_APB2_PERIPH_", ""))

    names.sort()

    return names


def gpio_ports(project: dict) -> list:
    ports = []

    pins = gpio_pin_names(project)
    for pin in pins:
        ports.append(f"GPIO{str(pin[1]).upper()}")

    ports = list(set(ports))
    ports.sort()

    return ports


def gpio_pins_by_port(project: dict, port: str) -> list:
    ports = []

    pins = gpio_pin_names(project)
    for pin in pins:
        if port[4] == pin[1]:
            ports.append(f"GPIO_PIN_{pin[2:]}")

    ports = list(set(ports))
    ports.sort()

    return ports


def gpio_pin_groups_by_port(project: dict, port: str) -> list:
    pin_groups_map = {}
    pin_groups = []
    pins = gpio_pin_names(project)
    for pin in pins:
        config = {}
        if port[4] == pin[1]:
            config["Function"] = project["Config"]["GPIO"][pin]["Function"]
            config["Config"] = project["Config"]["GPIO"][pin]["FunctionProperty"]["GPIO"]
            hash_str = _hash_dict(config)
            if not hash_str in pin_groups_map:
                pin_groups_map[hash_str] = [f"GPIO_PIN_{pin[2:]}"]
            else:
                pin_groups_map[hash_str].append(f"GPIO_PIN_{pin[2:]}")

    for _, value in pin_groups_map.items():
        group = list(set(value))
        group.sort()
        pin_groups.append(group)

    pin_groups.sort()

    return pin_groups


def gpio_pin_alias(project: dict, port: str, pin: str) -> bool:
    pin_name = f'P{port.replace("GPIO", "")}{pin.replace("GPIO_PIN_", "")}'
    alias = project["Config"]["GPIO"][pin_name]["Comment"]

    if alias == "":
        return None

    return alias


def gpio_pin_level(project: dict, port: str, pin: str) -> bool:
    level_map = {
        "std.gpio_level_low": "BIT_RESET",
        "std.gpio_level_high": "BIT_SET",
    }

    pin_name = f'P{port.replace("GPIO", "")}{pin.replace("GPIO_PIN_", "")}'
    gpio_config = project["Config"]["GPIO"][pin_name]["FunctionProperty"]["GPIO"]

    if not "std.gpio_level_t" in gpio_config:
        return None

    return level_map[gpio_config["std.gpio_level_t"]]


def gpio_pin_level_map(project: dict, port: str, pins: list) -> bool:
    if not gpio_pin_level(project, port, pins[0]):
        return None
    level_groups_map = {}

    for pin in pins:
        level = gpio_pin_level(project, port, pin)
        if not level in level_groups_map:
            level_groups_map[level] = [pin]
        else:
            level_groups_map[level].append(pin)
        level_groups_map[level]

    for level_groups in level_groups_map.keys():
        level_groups_map[level_groups].sort()

    return level_groups_map


def gpio_pin_mode(project: dict, port: str, pin: str) -> bool:
    output_mode_map = {
        "std.gpio_output_pp": "GPIO_MODE_OUT_PP",
        "std.gpio_output_od": "GPIO_MODE_OUT_OD",
    }
    input_mode_map = {
        "std.gpio_pull_up": "GPIO_MODE_IN_PU",
        "std.gpio_pull_down": "GPIO_MODE_IN_PD",
        "std.gpio_pull_no": "GPIO_MODE_IN_FLOATING",
    }
    analog_mode_map = {
        "std.gpio_mode_analog": "GPIO_MODE_ANALOG",
    }

    pin_name = f'P{port.replace("GPIO", "")}{pin.replace("GPIO_PIN_", "")}'
    function = project["Config"]["GPIO"][pin_name]["Function"]
    gpio_config = project["Config"]["GPIO"][pin_name]["FunctionProperty"]["GPIO"]

    mode = None

    if function == "GPIO-Output":
        mode = output_mode_map[gpio_config["std.gpio_output_type_t"]]
    elif function == "GPIO-Analog":
        mode = analog_mode_map[gpio_config["std.gpio_mode_t"]]
    elif function == "GPIO-Input":
        mode = input_mode_map[gpio_config["std.gpio_pull_t"]]
    elif function == "GPIO-EXTI":
        mode = input_mode_map[gpio_config["std.gpio_pull_t"]]
    else:
        mode = None

    return mode


def gpio_pin_speed(project: dict, port: str, pin: str) -> bool:
    speed_map = {
        "std.gpio_speed_low": "GPIO_SPEED_10MHz",
        "std.gpio_speed_medium": "GPIO_SPEED_2MHz",
        "std.gpio_speed_high": "GPIO_SPEED_50MHz",
    }

    pin_name = f'P{port.replace("GPIO", "")}{pin.replace("GPIO_PIN_", "")}'
    gpio_config = project["Config"]["GPIO"][pin_name]["FunctionProperty"]["GPIO"]

    if not "std.gpio_speed_t" in gpio_config:
        return None

    return speed_map[gpio_config["std.gpio_speed_t"]]
