--!csp build system based on xmake
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
-- @file        options.lua
--
-- Change Logs:
-- Date           Author       Notes
-- ------------   ----------   -----------------------------------------------
-- 2023-01-02     xqyjlj       initial version
--

option("csp_hal_apm32f1")
do
    set_default(true)
    set_showmenu(false)
    add_deps("CSP_MCU")
    add_deps("CSP_COMPONENTS_RTOS")
    after_check(
        function(option)
            for _, dep_opt in pairs(option:orderdeps()) do
                option:add("defines", dep_opt:get("defines"))
            end
        end
    )
end
option_end()

option("CSP_MCU")
do
    set_default("apm32f103zet6")
    set_showmenu(true)
    set_values("apm32f103c8t6", "apm32f103zet6")
    set_category("configuration")
    set_description("mcu name")
    add_defines("USE_FULL_LL_DRIVER")
    after_check(
        function(option)
            option:add("defines", option:value():upper())
            if string.find(option:value(), "apm32f103ze") then
                option:add("defines", "STM32F103xE")
            end
        end
    )
end
option_end()

option("CSP_COMPONENTS_RTOS")
do
    set_default("null")
    set_showmenu(true)
    set_values("null", "rtthread nano")
    set_category("configuration")
    set_description("rtos")
end
option_end()
