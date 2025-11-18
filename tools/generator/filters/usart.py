#!/usr/bin/env python3
# -*- coding:utf-8 -*-

#
# ------------------------------------------------------------------------------
#  @author:            csplink coder
#  @file:              usart.py
#  @version:           0.0.6
#  @time:              2025-11-14 15:41:04
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

_usart_break_detect_length_t_return_type = Literal[
    "10_b",
    "11_b",
]


_usart_clk_last_bit_t_return_type = Literal[
    "smartcard_lastbit_disable",
    "smartcard_lastbit_enable",
    "usart_lastbit_disable",
    "usart_lastbit_enable",
]


_usart_clk_phase_t_return_type = Literal[
    "smartcard_phase_1_edge",
    "smartcard_phase_2_edge",
    "usart_phase_1_edge",
    "usart_phase_2_edge",
]


_usart_clk_polarity_t_return_type = Literal[
    "smartcard_polarity_high",
    "smartcard_polarity_low",
    "usart_polarity_high",
    "usart_polarity_low",
]


_usart_hw_flow_ctl_t_return_type = Literal[
    "cts",
    "none",
    "rts",
    "rts_cts",
]


_usart_ir_da_mode_t_return_type = Literal[
    "lowpower",
    "normal",
]


_usart_mode_t_return_type = Literal[
    "rx",
    "tx",
    "tx_rx",
]


_usart_nack_state_t_return_type = Literal[
    "disable",
    "enable",
]


_usart_over_sampling_t_return_type = Literal[
    "null",
    "uart_oversampling_16",
]


_usart_parity_t_return_type = Literal[
    "even",
    "none",
    "odd",
]


_usart_stop_bits_t_return_type = Literal[
    "0_5",
    "1",
    "1_5",
    "2",
]


_usart_virtual_clock_mode_t_return_type = Literal[
    "smartcard",
    "sync",
]


_usart_virtual_mode_t_return_type = Literal[
    "async",
    "irda",
    "smartcard",
    "sync",
]


_usart_wake_up_methode_t_return_type = Literal[
    "addressmark",
    "idleline",
]


_usart_word_length_t_return_type = Literal[
    "8_b",
    "9_b",
]


_usart_ctrl_mode_t_return_type = Literal[
    "asynchronous",
    "disable",
    "half_duplex_single_wire_mode",
    "ir_da",
    "lin",
    "multiprocessor_communication",
    "smart_card",
    "smart_card_with_clock",
    "synchronous",
]


_usart_ctrl_hardware_flow_control_rs232_t_return_type = Literal[
    "cts_only",
    "cts_rts",
    "disable",
    "rts_only",
]


def usart_address_t(
    project: Project,
    instance: str = "USART",
    default: int = 0,
) -> int:
    return project.configs.get(f"{instance}.usart_address_t", default)


def usart_baud_rate_t(
    project: Project,
    instance: str = "USART",
    default: int = 115200,
) -> int:
    return project.configs.get(f"{instance}.usart_baud_rate_t", default)


def usart_break_detect_length_t(
    project: Project,
    instance: str = "USART",
    default: _usart_break_detect_length_t_return_type = "10_b",
) -> _usart_break_detect_length_t_return_type:
    return project.configs.get(f"{instance}.usart_break_detect_length_t", default)


def usart_clk_last_bit_t(
    project: Project,
    instance: str = "USART",
    default: _usart_clk_last_bit_t_return_type | int = "smartcard_lastbit_disable",
) -> _usart_clk_last_bit_t_return_type | int:
    return project.configs.get(f"{instance}.usart_clk_last_bit_t", default)


def usart_clk_phase_t(
    project: Project,
    instance: str = "USART",
    default: _usart_clk_phase_t_return_type | int = "smartcard_phase_1_edge",
) -> _usart_clk_phase_t_return_type | int:
    return project.configs.get(f"{instance}.usart_clk_phase_t", default)


def usart_clk_polarity_t(
    project: Project,
    instance: str = "USART",
    default: _usart_clk_polarity_t_return_type | int = "smartcard_polarity_low",
) -> _usart_clk_polarity_t_return_type | int:
    return project.configs.get(f"{instance}.usart_clk_polarity_t", default)


def usart_calculate_speed_t(
    project: Project,
    instance: str = "USART",
    default: str = "5000000",
) -> str:
    return project.configs.get(f"{instance}.usart_calculate_speed_t", default)


def usart_guard_time_t(
    project: Project,
    instance: str = "USART",
    default: int = 0,
) -> int:
    return project.configs.get(f"{instance}.usart_guard_time_t", default)


def usart_hw_flow_ctl_t(
    project: Project,
    instance: str = "USART",
    default: _usart_hw_flow_ctl_t_return_type = "rts",
) -> _usart_hw_flow_ctl_t_return_type:
    return project.configs.get(f"{instance}.usart_hw_flow_ctl_t", default)


def usart_ir_da_mode_t(
    project: Project,
    instance: str = "USART",
    default: _usart_ir_da_mode_t_return_type = "normal",
) -> _usart_ir_da_mode_t_return_type:
    return project.configs.get(f"{instance}.usart_ir_da_mode_t", default)


def usart_mode_t(
    project: Project,
    instance: str = "USART",
    default: _usart_mode_t_return_type = "tx_rx",
) -> _usart_mode_t_return_type:
    return project.configs.get(f"{instance}.usart_mode_t", default)


def usart_nack_state_t(
    project: Project,
    instance: str = "USART",
    default: _usart_nack_state_t_return_type = "disable",
) -> _usart_nack_state_t_return_type:
    return project.configs.get(f"{instance}.usart_nack_state_t", default)


def usart_over_sampling_t(
    project: Project,
    instance: str = "USART",
    default: _usart_over_sampling_t_return_type = "null",
) -> _usart_over_sampling_t_return_type:
    return project.configs.get(f"{instance}.usart_over_sampling_t", default)


def usart_parity_t(
    project: Project,
    instance: str = "USART",
    default: _usart_parity_t_return_type = "even",
) -> _usart_parity_t_return_type:
    return project.configs.get(f"{instance}.usart_parity_t", default)


def usart_prescaler_t(
    project: Project,
    instance: str = "USART",
    default: int = 1,
) -> int:
    return project.configs.get(f"{instance}.usart_prescaler_t", default)


def usart_stop_bits_t(
    project: Project,
    instance: str = "USART",
    default: _usart_stop_bits_t_return_type = "1",
) -> _usart_stop_bits_t_return_type:
    return project.configs.get(f"{instance}.usart_stop_bits_t", default)


def usart_virtual_clock_mode_t(
    project: Project,
    instance: str = "USART",
    default: _usart_virtual_clock_mode_t_return_type = "sync",
) -> _usart_virtual_clock_mode_t_return_type:
    return project.configs.get(f"{instance}.usart_virtual_clock_mode_t", default)


def usart_virtual_mode_t(
    project: Project,
    instance: str = "USART",
    default: _usart_virtual_mode_t_return_type = "async",
) -> _usart_virtual_mode_t_return_type:
    return project.configs.get(f"{instance}.usart_virtual_mode_t", default)


def usart_wake_up_methode_t(
    project: Project,
    instance: str = "USART",
    default: _usart_wake_up_methode_t_return_type = "idleline",
) -> _usart_wake_up_methode_t_return_type:
    return project.configs.get(f"{instance}.usart_wake_up_methode_t", default)


def usart_word_length_t(
    project: Project,
    instance: str = "USART",
    default: _usart_word_length_t_return_type = "8_b",
) -> _usart_word_length_t_return_type:
    return project.configs.get(f"{instance}.usart_word_length_t", default)


def usart_ctrl_mode_t(
    project: Project,
    instance: str = "USART",
    default: _usart_ctrl_mode_t_return_type = "disable",
) -> _usart_ctrl_mode_t_return_type:
    return project.configs.get(f"{instance}.usart_ctrl_mode_t", default)


def usart_ctrl_hardware_flow_control_rs232_t(
    project: Project,
    instance: str = "USART",
    default: _usart_ctrl_hardware_flow_control_rs232_t_return_type = "disable",
) -> _usart_ctrl_hardware_flow_control_rs232_t_return_type:
    return project.configs.get(f"{instance}.usart_ctrl_hardware_flow_control_rs232_t", default)


# fmt: on
# endregion
# ------------------------------------------------------------------------------


# --< user code begin code, do not change this comment!
def usart_ctrl_hardware_flow_control_rs232(project: Project, instance: str) -> str:
    m = {
        "disable": "USART_HARDWARE_FLOW_NONE",
        "cts_only": "USART_HARDWARE_FLOW_CTS",
        "rts_only": "USART_HARDWARE_FLOW_RTS",
        "cts_rts": "USART_HARDWARE_FLOW_RTS_CTS",
    }

    rs232 = usart_ctrl_hardware_flow_control_rs232_t(project, instance)
    return m[rs232]


def usart_mode(project: Project, instance: str) -> str:
    m = {
        "tx_rx": "USART_MODE_TX_RX",
        "rx": "USART_MODE_RX",
        "tx": "USART_MODE_TX",
    }

    mode = usart_mode_t(project, instance)
    return m[mode]


def usart_parity(project: Project, instance: str) -> str:
    m = {
        "none": "USART_PARITY_NONE",
        "even": "USART_PARITY_EVEN",
        "odd": "USART_PARITY_ODD",
    }

    parity = usart_parity_t(project, instance)
    return m[parity]


def usart_stop_bits(project: Project, instance: str) -> str:
    m = {
        "1": "USART_STOP_BIT_1",
        "2": "USART_STOP_BIT_2",
        "0_5": "USART_STOP_BIT_0_5",
        "1_5": "USART_STOP_BIT_1_5",
    }

    stop_bits = usart_stop_bits_t(project, instance)
    return m[stop_bits]


def usart_word_length(project: Project, instance: str) -> str:
    m = {
        "8_b": "USART_WORD_LEN_8B",
        "9_b": "USART_WORD_LEN_9B",
    }

    word = usart_word_length_t(project, instance)
    return m[word]


def usart_clk_polarity(project: Project, instance: str) -> str:
    m = {
        "smartcard_polarity_high": "USART_CLKPOL_HIGH",
        "smartcard_polarity_low": "USART_CLKPOL_LOW",
        "usart_polarity_high": "USART_CLKPOL_HIGH",
        "usart_polarity_low": "USART_CLKPOL_LOW",
    }

    word = usart_clk_polarity_t(project, instance)
    return m[word]


def usart_clk_phase(project: Project, instance: str) -> str:
    m = {
        "smartcard_phase_1_edge": "USART_CLKPHA_1EDGE",
        "smartcard_phase_2_edge": "USART_CLKPHA_2EDGE",
        "usart_phase_1_edge": "USART_CLKPHA_1EDGE",
        "usart_phase_2_edge": "USART_CLKPHA_2EDGE",
    }

    word = usart_clk_phase_t(project, instance)
    return m[word]


def usart_clk_last_bit(project: Project, instance: str) -> str:
    m = {
        "smartcard_lastbit_disable": "USART_LBCP_DISABLE",
        "smartcard_lastbit_enable": "USART_LBCP_ENABLE",
        "usart_lastbit_disable": "USART_LBCP_DISABLE",
        "usart_lastbit_enable": "USART_LBCP_ENABLE",
    }

    word = usart_clk_last_bit_t(project, instance)
    return m[word]


# --> user code end code, do not change this comment!
