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


import os

import yaml

__resourceDir = os.path.join(os.path.dirname(__file__), "..", "resource")


def chip_info(project: dict) -> dict:
    with open(os.path.join(__resourceDir, "chip_info.yaml"), "r") as f:
        infos = yaml.load(f.read(), Loader=yaml.FullLoader)

    return infos[project['targetChip']]
