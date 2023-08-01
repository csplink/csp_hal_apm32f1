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
set_xmakever("2.7.9")
set_version("0.0.2")
set_project("csp_hal_apm32f1") -- set project name

add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})

includes("xmake/option.lua")
includes("libraries/clink/xmake.lua")

add_requires("arm-none-eabi")
set_toolchains("@arm-none-eabi")

set_config("arch", "arm")
set_config("cpu", "cortex-m3")

target("csp_hal_apm32f1")
do
    set_kind("static")
    set_warnings("allextra", "error")
    set_languages("c99", "cxx11")
    set_installdir("$(buildir)/install")

    add_configfiles("chal_config.h.in")
    add_imports("core.project.project")

    add_rules("asm")
    add_rules("csp.cpu")

    add_options("mcu")
    add_options("use_default_startup")

    add_includedirs("libraries/chal/inc", {public = true})
    add_includedirs("libraries/cmsis/Include", {public = true})
    add_includedirs("libraries/cmsis_core/Include", {public = true})
    add_includedirs("libraries/drivers/inc", {public = true})

    add_files("libraries/chal/src/*.c")
    add_files("libraries/cmsis/Source/*.c")
    add_files("libraries/drivers/src/*.c")

    add_installfiles("$(buildir)/chal_config.h", {prefixdir = "include"})
    add_installfiles("libraries/cmsis/Include/*.h", {prefixdir = "include"})
    add_installfiles("libraries/cmsis_core/Include/*.h", {prefixdir = "include"})
    add_installfiles("libraries/drivers/inc/*.h", {prefixdir = "include"})
    add_installfiles("libraries/chal/inc/(chal/*.h)", {prefixdir = "include"})

    add_deps("clink")

    on_config(function(target)
        if project.option("use_default_startup"):value() then
            local mcu = project.option("mcu"):value()
            if string.find(mcu, "APM32F103ZE") then
                if target:has_tool("cc", "gcc") then
                    target:add("files", "$(scriptdir)/libraries/cmsis/Source/gcc/startup_apm32f10x_hd.S")
                end
            end
        end
    end)
end
target_end()
