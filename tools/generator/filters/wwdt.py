#!/usr/bin/env python3
# -*- coding:utf-8 -*-

#
# ------------------------------------------------------------------------------
#  @author:            csplink coder
#  @file:              wwdt.py
#  @version:           0.0.6
#  @time:              2025-11-14 15:40:59
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

_wwdt_ewi_mode_t_return_type = Literal[
    "disable",
    "enable",
]


_wwdt_prescaler_t_return_type = Literal[
    "/1",
    "/2",
    "/4",
    "/8",
]


def wwdt_counter_t(
    project: Project,
    instance: str = "WWDT",
    default: int = 64,
) -> int:
    return project.configs.get(f"{instance}.wwdt_counter_t", default)


def wwdt_ewi_mode_t(
    project: Project,
    instance: str = "WWDT",
    default: _wwdt_ewi_mode_t_return_type = "disable",
) -> _wwdt_ewi_mode_t_return_type:
    return project.configs.get(f"{instance}.wwdt_ewi_mode_t", default)


def wwdt_prescaler_t(
    project: Project,
    instance: str = "WWDT",
    default: _wwdt_prescaler_t_return_type = "/1",
) -> _wwdt_prescaler_t_return_type:
    return project.configs.get(f"{instance}.wwdt_prescaler_t", default)


def wwdt_window_t(
    project: Project,
    instance: str = "WWDT",
    default: int = 64,
) -> int:
    return project.configs.get(f"{instance}.wwdt_window_t", default)


def wwdt_ctrl_state_t(
    project: Project,
    instance: str = "WWDT",
    default: bool = False,
) -> bool:
    return project.configs.get(f"{instance}.wwdt_ctrl_state_t", default)


# fmt: on
# endregion
# ------------------------------------------------------------------------------

# --< user code begin code, do not change this comment!
def wwdt_prescaler(project: Project) -> str:
    m = {
        "/1": "WWDT_TIME_BASE_1",
        "/2": "WWDT_TIME_BASE_2",
        "/4": "WWDT_TIME_BASE_4",
        "/8": "WWDT_TIME_BASE_8",
    }

    prescaler = wwdt_prescaler_t(project)
    return m[prescaler]
# --> user code end code, do not change this comment!
