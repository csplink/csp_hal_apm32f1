#!/usr/bin/env python3
# -*- coding:utf-8 -*-

#
# ------------------------------------------------------------------------------
#  @author:            csplink coder
#  @file:              iwdt.py
#  @version:           0.0.6
#  @time:              2025-11-14 15:38:42
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

_iwdt_prescaler_t_return_type = Literal[
    "/128",
    "/16",
    "/256",
    "/32",
    "/4",
    "/64",
    "/8",
]


def iwdt_prescaler_t(
    project: Project,
    instance: str = "IWDT",
    default: _iwdt_prescaler_t_return_type = "/4",
) -> _iwdt_prescaler_t_return_type:
    return project.configs.get(f"{instance}.iwdt_prescaler_t", default)


def iwdt_reload_t(
    project: Project,
    instance: str = "IWDT",
    default: int = 4095,
) -> int:
    return project.configs.get(f"{instance}.iwdt_reload_t", default)


def iwdt_ctrl_state_t(
    project: Project,
    instance: str = "IWDT",
    default: bool = False,
) -> bool:
    return project.configs.get(f"{instance}.iwdt_ctrl_state_t", default)


# fmt: on
# endregion
# ------------------------------------------------------------------------------

# --< user code begin code, do not change this comment!
def iwdt_prescaler(project: Project) -> str:
    m = {
        "/4": "IWDT_DIVIDER_4",
        "/8": "IWDT_DIVIDER_8",
        "/16": "IWDT_DIVIDER_16",
        "/32": "IWDT_DIVIDER_32",
        "/64": "IWDT_DIVIDER_64",
        "/128": "IWDT_DIVIDER_128",
        "/256": "IWDT_DIVIDER_256",
    }

    prescaler = iwdt_prescaler_t(project)
    return m[prescaler]
# --> user code end code, do not change this comment!
