#!/usr/bin/env python3
# -*- coding:utf-8 -*-

#
# ------------------------------------------------------------------------------
#  @author:            csplink coder
#  @file:              gpio.py
#  @version:           0.0.6
#  @time:              2025-11-15 17:54:10
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
import json

# isort: on
# --> user code end import, do not change this comment!

# ------------------------------------------------------------------------------
# region autogen filters
# fmt: off

_gpio_mode_t_return_type = Literal[
    "af_od",
    "af_pp",
    "analog",
    "evt_falling",
    "evt_rising",
    "evt_rising_falling",
    "input",
    "it_falling",
    "it_rising",
    "it_rising_falling",
    "output_od",
    "output_pp",
]


_gpio_pull_t_return_type = Literal[
    "nopull",
    "pulldown",
    "pullup",
]


_gpio_speed_t_return_type = Literal[
    "high",
    "low",
    "medium",
]


_gpio_state_t_return_type = Literal[
    "reset",
    "set",
]


def gpio_mode_t(
    project: Project,
    channel: str,
    instance: str = "GPIO",
    default: _gpio_mode_t_return_type = "input",
) -> _gpio_mode_t_return_type:
    return project.configs.get(f"{instance}.{channel}.gpio_mode_t", default)


def gpio_pull_t(
    project: Project,
    channel: str,
    instance: str = "GPIO",
    default: _gpio_pull_t_return_type = "nopull",
) -> _gpio_pull_t_return_type:
    return project.configs.get(f"{instance}.{channel}.gpio_pull_t", default)


def gpio_speed_t(
    project: Project,
    channel: str,
    instance: str = "GPIO",
    default: _gpio_speed_t_return_type = "low",
) -> _gpio_speed_t_return_type:
    return project.configs.get(f"{instance}.{channel}.gpio_speed_t", default)


def gpio_state_t(
    project: Project,
    channel: str,
    instance: str = "GPIO",
    default: _gpio_state_t_return_type = "reset",
) -> _gpio_state_t_return_type:
    return project.configs.get(f"{instance}.{channel}.gpio_state_t", default)


def gpio_channels(
    project: Project,
    instance: str = "GPIO",
) -> list[str]:
    return list(project.configs.get(instance, {}).keys())


def pin_function(
    project: Project,
    channel: str,
    default: str = "",
) -> str:
    return project.configs.get(f"pins.{channel}.function", default)


def pin_label(
    project: Project,
    channel: str,
    default: str = "",
) -> str:
    return project.configs.get(f"pins.{channel}.label", default)


def pin_locked(
    project: Project,
    channel: str,
    default: bool = False,
) -> bool:
    return project.configs.get(f"pins.{channel}.locked", default)


def pin_mode(
    project: Project,
    channel: str,
    default: str = "",
) -> str:
    return project.configs.get(f"pins.{channel}.mode", default)


def pin_channels(
    project: Project,
) -> str:
    return list(project.configs.get("pins", {}).keys())


# fmt: on
# endregion
# ------------------------------------------------------------------------------


# --< user code begin code, do not change this comment!
def __hash_dict(dictionary) -> int:
    json_str = json.dumps(dictionary, sort_keys=True)
    return hash(json_str)


def gpio_used_channels(project: Project) -> list[str]:
    pins = []
    channels = gpio_channels(project)
    for channel in channels:
        locked = pin_locked(project, channel)
        function = pin_function(project, channel)
        mode = pin_mode(project, channel)

        if (
            locked  # locked == True
            and len(function) != 0  # function != ""
            and not channel.startswith("RCM-")  # name startswith "RCM-"
            and len(mode) == 0  # mode == ""
        ):
            pins.append(channel)

    pins.sort()
    return pins


def gpio_used_clocks(project: Project) -> list[str]:
    clocks = []

    channels = gpio_used_channels(project)
    for channel in channels:
        clocks.append(f"RCM_APB2_PERIPH_GPIO{str(channel[1]).upper()}")
        function = pin_function(project, channel)
        if function == "GPIO:EXTI":
            clocks.append(f"RCM_APB2_PERIPH_AFIO")
        elif function == "GPIO:EVENTOUT":
            clocks.append(f"RCM_APB2_PERIPH_AFIO")

    clocks = list(set(clocks))
    clocks.sort()

    return clocks


def gpio_clocks_to_alias(clocks: list[str]) -> list[str]:
    names = []

    for clock in clocks:
        names.append(clock.replace("RCM_APB2_PERIPH_", ""))

    names.sort()

    return names


def gpio_channel_to_clock(channel: str) -> str:
    return f"RCM_APB2_PERIPH_GPIO{str(channel[1]).upper()}"


def gpio_channel_to_port(channel: str) -> str:
    return f"GPIO{str(channel[1]).upper()}"


def gpio_channel_to_port_source(channel: str) -> str:
    return f"GPIO_PORT_SOURCE_{str(channel[1]).upper()}"


def gpio_channel_to_pin(channel: str) -> str:
    return f"GPIO_PIN_{channel[2:]}"


def gpio_channel_to_pin_source(channel: str) -> str:
    return f"GPIO_PIN_SOURCE_{channel[2:]}"


def gpio_channel_to_eint_line(channel: str) -> str:
    return f"EINT_LINE_{channel[2:]}"


def gpio_channels_to_pins(channels: list[str]) -> list[str]:
    pins = []

    for channel in channels:
        pins.append(gpio_channel_to_pin(channel))

    pins.sort()

    return pins


def gpio_used_ports(channels: list[str]) -> list[str]:
    ports = []

    for channel in channels:
        ports.append(gpio_channel_to_port(channel))

    ports = list(set(ports))
    ports.sort()

    return ports


def gpio_channels_group_by_port(
    project: Project, channels: list[str], port: str
) -> list[list[str]]:
    channels_group_map: dict[str, list[str]] = {}
    channels_group = []
    for channel in channels:
        config = {}
        if port[4] == channel[1]:
            config["function"] = pin_function(project, channel)
            config["gpio_mode_t"] = gpio_mode_t(project, channel)
            config["gpio_pull_t"] = gpio_pull_t(project, channel)
            config["gpio_speed_t"] = gpio_speed_t(project, channel)

            # group according to different configurations, pins with the same configuration are in the same group
            hash_str = __hash_dict(config)
            if not hash_str in channels_group_map:
                channels_group_map[hash_str] = [channel]
            else:
                channels_group_map[hash_str].append(channel)

    for _, value in channels_group_map.items():
        group = list(set(value))
        group.sort()
        channels_group.append(group)

    channels_group.sort()

    return channels_group


def gpio_channel_alias(project: Project, channel: str) -> str:
    return pin_label(project, channel)


def gpio_channel_state(project: Project, channel: str) -> str | None:
    state_map = {
        "reset": "BIT_RESET",
        "set": "BIT_SET",
    }

    state = gpio_state_t(project, channel)

    return state_map[state]


def gpio_channels_classify_by_state(
    project: Project, channels: list
) -> dict[str, list[str]]:
    if not gpio_channel_state(project, channels[0]):
        return {}  # 代表这组通道并非输出类型的
    state_groups_map: dict[str, list[str]] = {}

    for channel in channels:
        state = gpio_channel_state(project, channel)
        if not state in state_groups_map:
            state_groups_map[state] = [channel]
        else:
            state_groups_map[state].append(channel)

    for level_groups in state_groups_map.keys():
        state_groups_map[level_groups].sort()

    return state_groups_map


def gpio_channel_mode(project: Project, channel: str) -> str:
    mode = gpio_mode_t(project, channel)
    pull = gpio_pull_t(project, channel)

    result = ""

    if mode in [
        "input",
        "it_rising",
        "it_falling",
        "it_rising_falling",
        "evt_rising",
        "evt_falling",
        "evt_rising_falling",
    ]:
        if pull == "nopull":
            result = "GPIO_MODE_IN_FLOATING"
        elif pull == "pullup":
            result = "GPIO_MODE_IN_PU"
        elif pull == "pulldown":
            result = "GPIO_MODE_IN_PD"
    elif mode == "output_pp":
        result = "GPIO_MODE_OUT_PP"
    elif mode == "output_od":
        result = "GPIO_MODE_OUT_OD"
    elif mode == "af_pp":
        result = "GPIO_MODE_AF_PP"
    elif mode == "af_od":
        result = "GPIO_MODE_AF_OD"
    elif mode == "analog":
        result = "GPIO_MODE_ANALOG"

    assert result != "", f"failed to get gpio mode, {mode!r}, {pull!r}"

    return result


def gpio_channel_speed(project: Project, channel: str) -> str:
    speed_map = {
        "low": "GPIO_SPEED_2MHz",
        "medium": "GPIO_SPEED_10MHz",
        "high": "GPIO_SPEED_50MHz",
    }

    speed = gpio_speed_t(project, channel, default="")
    if speed == "":
        return ""

    return speed_map[speed]


def gpio_channel_eint_mode(project: Project, channel: str) -> str:
    mode = gpio_mode_t(project, channel)
    result = ""

    if mode in [
        "it_rising",
        "it_falling",
        "it_rising_falling",
    ]:
        result = "EINT_MODE_INTERRUPT"
    elif mode in [
        "evt_rising",
        "evt_falling",
        "evt_rising_falling",
    ]:
        result = "EINT_MODE_EVENT"

    assert result != "", f"failed to get gpio eint mode, {mode!r}"

    return result


def gpio_channel_eint_trigger(project: Project, channel: str) -> str:
    mode = gpio_mode_t(project, channel)
    result = ""

    if mode in [
        "it_rising",
        "evt_rising",
    ]:
        result = "EINT_TRIGGER_RISING"
    elif mode in [
        "it_falling",
        "evt_falling",
    ]:
        result = "EINT_TRIGGER_FALLING"
    elif mode in [
        "it_rising_falling",
        "evt_rising_falling",
    ]:
        result = "EINT_TRIGGER_RISING_FALLING"

    assert result != "", f"failed to get gpio eint trigger, {mode!r}"

    return result


def gpio_eventout_channels(project: Project, channels: list[str]) -> list[str]:
    result = []

    for channel in channels:
        function = pin_function(project, channel)
        if function == "GPIO:EVENTOUT":
            result.append(channel)

    return result


def gpio_eint_channels(project: Project, channels: list[str]) -> list[str]:
    result = []

    for channel in channels:
        function = pin_function(project, channel)
        if function.startswith("GPIO:EINT"):
            result.append(channel)

    return result


# --> user code end code, do not change this comment!
