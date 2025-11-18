#!/usr/bin/env python3
# -*- coding:utf-8 -*-

# Licensed under the Apache License v. 2 (the "License")
# You may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0.html
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Copyright (C) 2024-2024 xqyjlj<xqyjlj@126.com>
#
# @author      xqyjlj
# @file        chip.py
#
# Change Logs:
# Date           Author       Notes
# ------------   ----------   -----------------------------------------------
# 2024-12-11     xqyjlj       initial version
#


from csp.project import Project


APM32F10xxE = {
    "flash": {
        "addr": 0x08000000,
        "size": 0x0080000,
    },
    "ram": {
        "addr": 0x20000000,
        "size": 0x00020000,
    },
}

infos = {
    "APM32F103ZET6": {
        **APM32F10xxE,
        "class": "APM32F10X_HD",
        "line": "APM32F103ZE",
    }
}


def chip_info(project: Project) -> dict:
    return infos[project.targetChip]
