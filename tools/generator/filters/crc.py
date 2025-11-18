#!/usr/bin/env python3
# -*- coding:utf-8 -*-

#
# ------------------------------------------------------------------------------
#  @author:            csplink coder
#  @file:              crc.py
#  @version:           0.0.6
#  @time:              2025-11-14 15:39:27
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

def crc_ctrl_state_t(
    project: Project,
    instance: str = "CRC",
    default: bool = False,
) -> bool:
    return project.configs.get(f"{instance}.crc_ctrl_state_t", default)


# fmt: on
# endregion
# ------------------------------------------------------------------------------

# --< user code begin code, do not change this comment!

# --> user code end code, do not change this comment!
