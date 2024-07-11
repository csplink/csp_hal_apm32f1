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
# @file        deploy.py
#
# Change Logs:
# Date           Author       Notes
# ------------   ----------   -----------------------------------------------
# 2024-06-03     xqyjlj       initial version
#

import os, sys
import glob
import shutil

script_dir = os.path.dirname(__file__)
root_dir = os.path.join(script_dir, "..", "..")

sys.path.append(script_dir)
import filters.make as make

link_script_map = {"tools/coder/res/gcc/APM32F10xxE.lds": ["APM32F103ZET6"]}


def parse_startup_file(project: dict) -> dict:
    name = make.make_startup_file(project)

    if project["TargetProject"] == "MDK-Arm":
        startup = f"{root_dir}/tools/coder/res/mdk/{name}"
    elif project["TargetProject"] == "XMake" or project["TargetProject"] == "CMake":
        startup = f"{root_dir}/tools/coder/res/gcc/{name}"
    else:
        startup = f"{root_dir}/tools/coder/res/gcc/{name}"
    return startup


def main(project: dict, output_dir: str):
    file_list = [
        "libraries/cmsis/inc/*.h",  #
        "libraries/cmsis_core/inc/*.h",
        "libraries/cmsis_core/LICENSE.txt",
        "libraries/drivers/inc/*.h",
        "libraries/drivers/src/*.c",
        ".clang-format",
        ".gitattributes",
        ".gitignore",
        "LICENSE",
        "README*.md"
    ]

    # libraries
    for match in file_list:
        for source in glob.glob(f"{root_dir}/{match}"):
            dest = f"{output_dir}/hal/{os.path.relpath(source, root_dir)}"
            if not os.path.exists(dest):
                if not os.path.isdir(os.path.dirname(dest)):
                    os.makedirs(os.path.dirname(dest))
                shutil.copy(source, dest)

    # startup file
    startup_file_path = parse_startup_file(project)
    startup_file_name = os.path.basename(startup_file_path)
    if project["TargetProject"] == "MDK-Arm":
        dest = f"{output_dir}/mdk-arm/{startup_file_name}"
    else:
        dest = f"{output_dir}/{startup_file_name}"
    if not os.path.exists(dest):
        shutil.copy(startup_file_path, dest)

    # link script
    if project["TargetProject"] == "XMake" or project["TargetProject"] == "CMake":
        dest = f"{output_dir}/{project['TargetChip']}.lds"
        if not os.path.exists(dest):
            for key, value in link_script_map.items():
                if project['TargetChip'] in value:
                    link_script = f"{root_dir}/{key}"
                    break
            assert link_script, f"The project['TargetChip'] link script not found"
            shutil.copy(link_script, dest)

    # system_apm32f10x.c
    dest = f"{output_dir}/core/src/system_apm32f10x.c"
    if not os.path.exists(dest):
        shutil.copy(f"{root_dir}/tools/coder/res/system_apm32f10x.c", dest)
