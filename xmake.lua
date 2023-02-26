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
-- 2023-02-12     xqyjlj       add __csplink_debug__
-- 2023-02-09     xqyjlj       adapt to xamke repository
-- 2023-01-02     xqyjlj       initial version
--
set_xmakever("2.7.2")
set_version("0.0.2")
set_project("csp_hal_apm32f1") -- set project name

option("mcu")
do
    set_default("APM32F103ZET6")
    set_showmenu(true)
    set_values("APM32F103C8T6", "APM32F103ZET6")
    set_category("configuration")
    set_description("mcu name")
    add_imports("core.project.config")
    set_configvar("MCU", "$(mcu)")
    add_defines("USE_FULL_LL_DRIVER")
    add_defines("$(mcu)")
    after_check(function(option)
        if string.find(option:value(), "APM32F103ZE") then
            option:add("defines", "STM32F103xE")
            option:set("configvar", "STM32_MCU", "STM32F103xE")
        end
    end)
end
option_end()

option("use_default_startup")
do
    set_default(true)
    set_showmenu(true)
    set_category("configuration/build")
    set_description("use default startup asm file")
    set_configvar("USE_DEFAULT_STARTUP", 1)
end
option_end()

target("csp_hal_apm32f1")
do
    set_kind("static")
    set_configdir("$(buildir)/$(plat)/$(arch)/$(mode)")
    set_installdir("$(buildir)/install")
    set_warnings("all", "error")
    set_languages("c99", "cxx11")

    add_configfiles("csp_hal_apm32f1_config.h.in")
    add_imports("core.project.project")
    add_rules("asm")
    add_options("mcu")
    add_options("use_default_startup")

    add_includedirs("$(buildir)/$(plat)/$(arch)/$(mode)", {public = true})
    add_includedirs("drivers/apm32f1/cmsis/Include", "drivers/apm32f1/hal/Inc", "drivers/apm32f1/cmsis_core/Include",
                    {public = true})
    add_includedirs("drivers/csp_hal/chal/inc", {public = true})

    add_files("drivers/apm32f1/cmsis/Source/Templates/system_stm32f1xx.c", "drivers/apm32f1/hal/Src/stm32f1xx_ll_*.c")
    add_files("drivers/csp_hal/chal/src/*.c")

    remove_files("drivers/apm32f1/hal/Src/*_template.c")
    remove_files("drivers/apm32f1/hal/Src/stm32f1xx_ll_usb.c")
    remove_files("drivers/apm32f1/hal/Src/stm32f1xx_ll_sdmmc.c")
    remove_files("drivers/apm32f1/hal/Src/stm32f1xx_ll_fsmc.c")

    add_installfiles("$(buildir)/$(plat)/$(arch)/$(mode)/csp_hal_apm32f1_config.h",
                     {prefixdir = "include/csp_hal_apm32f1"})
    add_installfiles("drivers/apm32f1/cmsis/Include/*.h", "drivers/apm32f1/hal/Inc/*.h",
                     "drivers/apm32f1/cmsis_core/Include/*.h", {prefixdir = "include/csp_hal_apm32f1"})
    add_installfiles("drivers/csp_hal/chal/inc/(chal/*.h)", {prefixdir = "include/csp_hal_apm32f1"})

    if is_mode("debug") then
        add_defines("__csplink_debug__")
    end

    on_config(function(target)
        if project.option("use_default_startup"):value() then
            local mcu = project.option("mcu"):value()
            if string.find(mcu, "APM32F103ZE") then
                if target:has_tool("cc", "gcc") then
                    target:add("files", "$(scriptdir)/drivers/apm32f1/cmsis/Source/Templates/gcc/startup_stm32f103xe.s")
                end
            end
        end
    end)
end
target_end()
