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
-- Copyright (C) 2023-2023 xqyjlj<xqyjlj@126.com>
--
-- @author      xqyjlj
-- @file        xmake.lua
--
-- Change Logs:
-- Date           Author       Notes
-- ------------   ----------   -----------------------------------------------
-- 2023-07-12     xqyjlj       initial version
--
set_xmakever("2.8.6")
set_version("0.0.2")
set_project("csp_hal_apm32f1") -- set project name

add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})

set_config("arch", "arm")
set_config("cpu", "cortex-m3")

target("csp_hal_apm32f1")
do
    set_kind("object")
    set_warnings("allextra", "error")
    set_languages("c99", "cxx11")
    set_installdir("$(buildir)/install")

    add_rules("asm")

    add_includedirs("libraries/cmsis/inc", {public = true})
    add_includedirs("libraries/cmsis_core/inc", {public = true})
    add_includedirs("libraries/drivers/inc", {public = true})

    add_files("libraries/drivers/src/*.c")

    add_installfiles("libraries/cmsis/inc/*.h", {prefixdir = "include"})
    add_installfiles("libraries/cmsis_core/inc/*.h", {prefixdir = "include"})
    add_installfiles("libraries/drivers/inc/*.h", {prefixdir = "include"})
end
target_end()
