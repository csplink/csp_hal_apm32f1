#!/usr/bin/env python3
# -*- coding:utf-8 -*-

#
# ------------------------------------------------------------------------------
#  @author:            csplink coder
#  @file:              uart.py
#  @version:           0.0.6
#  @time:              2025-11-14 15:42:20
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

_uart_break_detect_length_t_return_type = Literal[
    "10_b",
    "11_b",
]


_uart_ir_da_mode_t_return_type = Literal[
    "lowpower",
    "normal",
]


_uart_mode_t_return_type = Literal[
    "rx",
    "tx",
    "tx_rx",
]


_uart_over_sampling_t_return_type = Literal[
    "null",
    "uart_oversampling_16",
]


_uart_parity_t_return_type = Literal[
    "even",
    "none",
    "odd",
]


_uart_stop_bits_t_return_type = Literal[
    "1",
    "2",
]


_uart_virtual_mode_t_return_type = Literal[
    "asynchronous",
    "ir_da",
    "lin",
]


_uart_wake_up_methode_t_return_type = Literal[
    "addressmark",
    "idleline",
]


_uart_word_length_t_return_type = Literal[
    "8_b",
    "9_b",
]


_uart_ctrl_mode_t_return_type = Literal[
    "asynchronous",
    "disable",
    "half_duplex_single_wire_mode",
    "ir_da",
    "lin",
    "multiprocessor_communication",
]


def uart_address_t(
    project: Project,
    instance: str = "UART",
    default: int = 0,
) -> int:
    return project.configs.get(f"{instance}.uart_address_t", default)


def uart_baud_rate_t(
    project: Project,
    instance: str = "UART",
    default: int = 115200,
) -> int:
    return project.configs.get(f"{instance}.uart_baud_rate_t", default)


def uart_break_detect_length_t(
    project: Project,
    instance: str = "UART",
    default: _uart_break_detect_length_t_return_type = "10_b",
) -> _uart_break_detect_length_t_return_type:
    return project.configs.get(f"{instance}.uart_break_detect_length_t", default)


def uart_ir_da_mode_t(
    project: Project,
    instance: str = "UART",
    default: _uart_ir_da_mode_t_return_type = "normal",
) -> _uart_ir_da_mode_t_return_type:
    return project.configs.get(f"{instance}.uart_ir_da_mode_t", default)


def uart_mode_t(
    project: Project,
    instance: str = "UART",
    default: _uart_mode_t_return_type = "tx_rx",
) -> _uart_mode_t_return_type:
    return project.configs.get(f"{instance}.uart_mode_t", default)


def uart_over_sampling_t(
    project: Project,
    instance: str = "UART",
    default: _uart_over_sampling_t_return_type = "null",
) -> _uart_over_sampling_t_return_type:
    return project.configs.get(f"{instance}.uart_over_sampling_t", default)


def uart_parity_t(
    project: Project,
    instance: str = "UART",
    default: _uart_parity_t_return_type = "none",
) -> _uart_parity_t_return_type:
    return project.configs.get(f"{instance}.uart_parity_t", default)


def uart_prescaler_t(
    project: Project,
    instance: str = "UART",
    default: int = 1,
) -> int:
    return project.configs.get(f"{instance}.uart_prescaler_t", default)


def uart_stop_bits_t(
    project: Project,
    instance: str = "UART",
    default: _uart_stop_bits_t_return_type = "1",
) -> _uart_stop_bits_t_return_type:
    return project.configs.get(f"{instance}.uart_stop_bits_t", default)


def uart_virtual_mode_t(
    project: Project,
    instance: str = "UART",
    default: _uart_virtual_mode_t_return_type = "asynchronous",
) -> _uart_virtual_mode_t_return_type:
    return project.configs.get(f"{instance}.uart_virtual_mode_t", default)


def uart_wake_up_methode_t(
    project: Project,
    instance: str = "UART",
    default: _uart_wake_up_methode_t_return_type = "idleline",
) -> _uart_wake_up_methode_t_return_type:
    return project.configs.get(f"{instance}.uart_wake_up_methode_t", default)


def uart_word_length_t(
    project: Project,
    instance: str = "UART",
    default: _uart_word_length_t_return_type = "8_b",
) -> _uart_word_length_t_return_type:
    return project.configs.get(f"{instance}.uart_word_length_t", default)


def uart_ctrl_mode_t(
    project: Project,
    instance: str = "UART",
    default: _uart_ctrl_mode_t_return_type = "disable",
) -> _uart_ctrl_mode_t_return_type:
    return project.configs.get(f"{instance}.uart_ctrl_mode_t", default)


# fmt: on
# endregion
# ------------------------------------------------------------------------------

# --< user code begin code, do not change this comment!


def uart_mode(project: Project, instance: str) -> str:
    m = {
        "tx_rx": "USART_MODE_TX_RX",
        "rx": "USART_MODE_RX",
        "tx": "USART_MODE_TX",
    }

    mode = uart_mode_t(project, instance)
    return m[mode]


def uart_parity(project: Project, instance: str) -> str:
    m = {
        "none": "USART_PARITY_NONE",
        "even": "USART_PARITY_EVEN",
        "odd": "USART_PARITY_ODD",
    }

    parity = uart_parity_t(project, instance)
    return m[parity]


def uart_stop_bits(project: Project, instance: str) -> str:
    m = {
        "1": "USART_STOP_BIT_1",
        "2": "USART_STOP_BIT_2",
    }

    stop_bits = uart_stop_bits_t(project, instance)
    return m[stop_bits]


def uart_word_length(project: Project, instance: str) -> str:
    m = {
        "8_b": "USART_WORD_LEN_8B",
        "9_b": "USART_WORD_LEN_9B",
    }

    word = uart_word_length_t(project, instance)
    return m[word]


def uart_wake_up_methode(project: Project, instance: str) -> str:
    m = {
        "addressmark": "USART_WAKEUP_ADDRESS_MARK",
        "idleline": "USART_WAKEUP_IDLE_LINE",
    }

    word = uart_wake_up_methode_t(project, instance)
    return m[word]


def uart_break_detect_length(project: Project, instance: str) -> str:
    m = {
        "10_b": "USART_LBDL_10B",
        "11_b": "USART_LBDL_11B",
    }

    word = uart_break_detect_length_t(project, instance)
    return m[word]


def uart_ir_da_mode(project: Project, instance: str) -> str:
    m = {
        "lowpower": "USART_IRDALP_LOWPOWER",
        "normal": "USART_IRDALP_NORMAL",
    }

    word = uart_ir_da_mode_t(project, instance)
    return m[word]


# --> user code end code, do not change this comment!
