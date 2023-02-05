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

includes("../apm32f1/csplink.lua")
includes("../../projects/xmake/options.lua")

target("drivers_csp_hal")
do
    set_kind("object")
    set_values("targetdir", os.scriptdir())
    add_deps("drivers_apm32f1") -- apm32f1xx hal library
    add_files("chal/src/*.c")
    add_includedirs("chal/inc", "$(buildir)", {public = true})
    add_options("csp_hal_apm32f1")
end
target_end()
