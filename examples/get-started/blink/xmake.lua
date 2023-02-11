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
-- 2023-01-02     xqyjlj       initial version
--
add_rules("mode.debug", "mode.release")

set_project("blink") -- set project name
set_version("0.0.0") -- set version
set_xmakever("2.7.2")

includes("../../../xmake.lua")

add_cflags("-mcpu=cortex-m3", "-mthumb", "-mthumb-interwork", "-ffunction-sections", "-fdata-sections", "-fno-common",
           "-fmessage-length=0", "-Wall", "-Werror", {force = true})

add_asflags("-mcpu=cortex-m3", "-mthumb", "-mthumb-interwork", "-ffunction-sections", "-fdata-sections", "-fno-common",
            "-fmessage-length=0", "-Wall", "-Werror", "-x assembler-with-cpp", {force = true})

add_ldflags("-mcpu=cortex-m3", "-mthumb", "-mthumb-interwork", "-Wl,--gc-sections",
            "-T../../../linkscripts/gcc/APM32F103xE.lds", {force = true})

toolchain("arm-none-eabi") -- add toolchain
do
    set_kind("cross") -- set toolchain kind
    set_description("arm embedded compiler")
    set_toolset("cc", "arm-none-eabi-gcc")
    set_toolset("ld", "arm-none-eabi-gcc")
    set_toolset("ar", "arm-none-eabi-ar")
    set_toolset("as", "arm-none-eabi-gcc")
end
toolchain_end()
set_config("plat", "cross")
set_toolchains("arm-none-eabi") -- set toolchains

target("blink")
do
    set_kind("binary")
    set_languages("c99")
    set_extension(".elf")
    add_deps("csp_hal_apm32f1")
    add_files("main.c")
end
target_end()
