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
-- @file        csplink.lua
--
-- Change Logs:
-- Date           Author       Notes
-- ------------   ----------   -----------------------------------------------
-- 2023-01-02     xqyjlj       initial version
--

set_xmakever("2.7.2")

set_config("arch", "cortex-m3")

includes("projects/xmake/rules.lua")
includes("projects/xmake/options.lua")

for _, dir in ipairs(os.dirs(os.scriptdir() .. "/*")) do
    file = dir .. "/csplink.lua"
    if os.exists(file) then
        includes(file)
    end
end

target("csp_hal_apm32f1")
do
    set_kind("static")
    add_deps("drivers") -- drivers library
end
target_end()

rule("csp_hal_apm32f1")
do
    add_deps("csp_rule_build_binary") -- auto generate .hex .bin .map .s .list
end
rule_end()
