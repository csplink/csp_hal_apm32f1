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
option("mcu")
do
    set_default("APM32F103ZET6")
    set_showmenu(true)
    set_values("APM32F103C8T6", "APM32F103ZET6")
    set_category("configuration")
    set_description("mcu name")
    set_configvar("MCU", "$(mcu)")
    add_defines("$(mcu)")
    after_check(function(option)
        import("core.project.project")
        if string.find(option:value(), "APM32F103ZE") then
            option:add("defines", "APM32F10X_HD")
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

