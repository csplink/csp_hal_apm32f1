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


def __hash_dict(dictionary) -> int:
    json_str = json.dumps(dictionary, sort_keys=True)
    return hash(json_str)


def __pin_config(project: dict) -> dict[str, dict[str, str]]:
    return project["configs"]["pin"]


def __gpio_config(project: dict) -> dict[str, dict[str, str]]:
    return project["configs"]["GPIO"]


def gpio_pin_names(project: dict) -> list[str]:
    pins = []
    for key, value in __pin_config(project).items():
        if value.get("locked", False) and len(value.get("function", "")) != 0 and not key.startswith(
                'RCM-') and not value.get("unsupported", False):
            pins.append(key)

    pins.sort()
    return pins


def gpio_clocks(project: dict) -> list[str]:
    clocks = []

    pins = gpio_pin_names(project)
    for pin in pins:
        clocks.append(f"RCM_APB2_PERIPH_GPIO{str(pin[1]).upper()}")
        if __pin_config(project)[pin].get("function", "") == "GPIO:EXTI":
            clocks.append(f"RCM_APB2_PERIPH_AFIO")
        elif __pin_config(project)[pin].get("function", "") == "GPIO:EVENTOUT":
            clocks.append(f"RCM_APB2_PERIPH_AFIO")

    clocks = list(set(clocks))
    clocks.sort()

    return clocks


def gpio_clock_names(project: dict) -> list[str]:
    names = []

    clocks = gpio_clocks(project)
    for clock in clocks:
        names.append(clock.replace("RCM_APB2_PERIPH_", ""))

    names.sort()

    return names


def gpio_ports(project: dict) -> list[str]:
    ports = []

    pins = gpio_pin_names(project)
    for pin in pins:
        ports.append(f"GPIO{str(pin[1]).upper()}")

    ports = list(set(ports))
    ports.sort()

    return ports


def gpio_pins_by_port(project: dict, port: str) -> list[str]:
    ports = []

    pins = gpio_pin_names(project)
    for pin in pins:
        if port[4] == pin[1]:
            ports.append(f"GPIO_PIN_{pin[2:]}")

    ports = list(set(ports))
    ports.sort()

    return ports


def gpio_pin_groups_by_port(project: dict, port: str) -> list[list[str]]:
    pin_groups_map = {}
    pin_groups = []
    pins = gpio_pin_names(project)
    for pin in pins:
        config = {}
        if port[4] == pin[1]:
            config["function"] = __pin_config(project)[pin].get("function", "")
            config["config"] = __gpio_config(project)[pin]

            # group according to different configurations, pins with the same configuration are in the same group
            hash_str = __hash_dict(config)
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


def gpio_pin_alias(project: dict, port: str, pin: str) -> str:
    pin_name = f'P{port.replace("GPIO", "")}{pin.replace("GPIO_PIN_", "")}'
    alias = __pin_config(project)[pin_name].get("label", None)

    return alias


def gpio_pin_level(project: dict, port: str, pin: str) -> str | None:
    level_map = {
        "geehy.gpio_level_low": "BIT_RESET",
        "geehy.gpio_level_high": "BIT_SET",
    }

    pin_name = f'P{port.replace("GPIO", "")}{pin.replace("GPIO_PIN_", "")}'
    gpio_config = __gpio_config(project).get(pin_name, {})

    if not "geehy.gpio_level_t" in gpio_config:
        return None

    return level_map[gpio_config["geehy.gpio_level_t"]]


def gpio_pin_level_map(project: dict, port: str, pins: list) -> dict:
    if not gpio_pin_level(project, port, pins[0]):
        return {}
    level_groups_map = {}

    for pin in pins:
        level = gpio_pin_level(project, port, pin)
        if not level in level_groups_map:
            level_groups_map[level] = [pin]
        else:
            level_groups_map[level].append(pin)

    for level_groups in level_groups_map.keys():
        level_groups_map[level_groups].sort()

    return level_groups_map


def gpio_pin_mode(project: dict, port: str, pin: str) -> str:
    output_mode_map = {
        "geehy.gpio_output_pp": "GPIO_MODE_OUT_PP",
        "geehy.gpio_output_od": "GPIO_MODE_OUT_OD",
    }
    input_mode_map = {
        "geehy.gpio_pull_up": "GPIO_MODE_IN_PU",
        "geehy.gpio_pull_down": "GPIO_MODE_IN_PD",
        "geehy.gpio_pull_no": "GPIO_MODE_IN_FLOATING",
    }
    analog_mode_map = {
        "geehy.gpio_mode_analog": "GPIO_MODE_ANALOG",
    }
    alternate_mode_map = {
        "geehy.gpio_output_pp": "GPIO_MODE_AF_PP",
        "geehy.gpio_output_od": "GPIO_MODE_AF_OD",
    }

    pin_name = f'P{port.replace("GPIO", "")}{pin.replace("GPIO_PIN_", "")}'
    function = __pin_config(project).get(pin_name, {}).get("function", "")
    gpio_config = __gpio_config(project).get(pin_name, {})

    if function == "GPIO:Output":
        mode = output_mode_map[gpio_config["geehy.gpio_output_type_t"]]
    elif function == "GPIO:Analog":
        mode = analog_mode_map[gpio_config["geehy.gpio_mode_t"]]
    elif function == "GPIO:Input":
        mode = input_mode_map[gpio_config["geehy.gpio_pull_t"]]
    elif function == "GPIO:EXTI":
        mode = input_mode_map[gpio_config["geehy.gpio_pull_t"]]
    elif function == "GPIO:EVENTOUT":
        mode = alternate_mode_map[gpio_config["geehy.gpio_output_type_t"]]
    else:
        mode = "_N_O_N_E_ /** error: Unexpected Error. */"

    return mode


def gpio_pin_speed(project: dict, port: str, pin: str) -> str:
    speed_map = {
        "geehy.gpio_speed_2mhz": "GPIO_SPEED_2MHz",
        "geehy.gpio_speed_10mhz": "GPIO_SPEED_10MHz",
        "geehy.gpio_speed_50mhz": "GPIO_SPEED_50MHz",
    }

    pin_name = f'P{port.replace("GPIO", "")}{pin.replace("GPIO_PIN_", "")}'
    gpio_config = __gpio_config(project).get(pin_name, {})

    if not "geehy.gpio_speed_t" in gpio_config:
        return ""

    return speed_map[gpio_config["geehy.gpio_speed_t"]]


def gpio_eventout(project: dict) -> dict[str, list[str]]:
    eventout = {}

    ports = gpio_ports(project)

    for port in ports:
        pins = gpio_pins_by_port(project, port)
        for pin in pins:
            pin_name = f'P{port.replace("GPIO", "")}{pin.replace("GPIO_PIN_", "")}'
            function = __pin_config(project).get(pin_name, {}).get("function", "")
            if function == "GPIO:EVENTOUT":
                if eventout.get(port) is None:
                    eventout[port] = []
                eventout[port].append(pin)

    return eventout
