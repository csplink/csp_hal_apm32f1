--
-- Licensed under the Apache License, Version 2.0 (the "License");
-- You may not use this file except in compliance with the License.
-- You may obtain a copy of the License at
--
--     http://www.apache.org/licenses/LICENSE-2.0
--
-- Unless required by applicable law or agreed to in writing, software
-- distributed under the License is distributed on an "AS IS" BASIS,
-- WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
-- See the License for the specific language governing permissions and
-- limitations under the License.
--
-- Copyright (C) 2022-2023 xqyjlj<xqyjlj@126.com>
--
-- @author      xqyjlj
-- @file        xmake.lua
--
-- Change Logs:
-- Date           Author       Notes
-- ------------   ----------   -----------------------------------------------
-- 2023-08-03     xqyjlj       initial version
--
add_rules("mode.debug", "mode.release")

set_project("blink") -- set project name
set_version("0.0.0") -- set version
set_xmakever("2.7.9")

add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})

includes("../../xmake.lua")

add_requires("arm-none-eabi")
set_toolchains("@arm-none-eabi")

add_ldflags("-T../../libraries/cmsis/Source/gcc/gcc_APM32F10xxE.ld", {force = true})

target("blink")
do
    set_kind("binary")
    set_warnings("allextra", "error")

    set_languages("c99")
    set_extension(".elf")
    add_deps("csp_hal_apm32f1")

    add_rules("csp.bin")
    add_rules("csp.map")
    add_rules("csp.cpu")

    add_files("main.c")
end
target_end()
