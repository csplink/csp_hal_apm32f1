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
# @file        gen_mdk_arm.py
#
# Change Logs:
# Date           Author       Notes
# ------------   ----------   -----------------------------------------------
# 2024-06-03     xqyjlj       initial version
#

import os, sys
import xml.etree.ElementTree as etree

script_dir = os.path.dirname(__file__)
root_dir = os.path.join(script_dir, "..", "..")

sys.path.append(script_dir)
import filters.make as make


def main(project: dict, min_version: str, keil_tree: etree.ElementTree, keil_utils) -> str:
    """
    Generate MDK project files for ARM.

    Args:
        project (dict): Project information.
        output_dir (str): Output directory.
    """

    # version = project["TargetProjectMinVersion"]
    chip = project["TargetChip"][:11]
    chip_type = chip[:9]

    template_file = f"{script_dir}/templates/MDK-Arm/{chip_type}/{chip}.uvprojx"
    assert os.path.isfile(template_file), f"Template file {template_file} not found."

    if keil_tree is None:
        tree = etree.parse(template_file)
    else:
        tree = keil_tree
    target_name = project['Name']

    root = tree.getroot()
    out = []
    out.append('<?xml version="1.0" encoding="UTF-8" standalone="no" ?>\n')

    tree.find('Targets/Target/TargetName').text = target_name
    tree.find('Targets/Target/TargetOption/TargetCommonOption/OutputName').text = target_name
    tree.find('Targets/Target/TargetOption/TargetCommonOption/AfterMake/RunUserProg1').text = "1"
    tree.find('Targets/Target/TargetOption/TargetCommonOption/AfterMake/UserProg1Name'
              ).text = f"fromelf --bin !L --output {target_name}.bin"
    tree.find('Targets/Target/TargetOption/TargetArmAds/Cads/VariousControls/Define').text = ', '.join(
        make.make_marco(project))

    incs = []
    for inc in make.make_inc_dirs(project):
        incs.append(f'../{inc}'.replace('/', '\\'))
    existing_incs = tree.find('Targets/Target/TargetOption/TargetArmAds/Cads/VariousControls/IncludePath').text.split(
        ";")

    for inc in existing_incs:
        if not inc in incs:
            incs.append(inc)

    tree.find('Targets/Target/TargetOption/TargetArmAds/Cads/VariousControls/IncludePath').text = ';'.join(incs)

    groups = tree.find('Targets/Target/Groups')
    if groups is None:
        groups = etree.SubElement(tree.find('Targets/Target'), 'Groups')

    startup_file = make.make_startup_file(project)
    keil_utils.add_group(groups, "application/mdk", [startup_file], "")

    for key, value in make.make_src_files_group(project).items():
        keil_utils.add_group(groups, key, value, "../")

    keil_utils.xml_indent(root)
    out.append(etree.tostring(root, encoding='utf-8', short_empty_elements=False).decode())

    return "\n".join(out)
