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
-- 2023-07-17     xqyjlj       initial version
--
set_xmakever("2.7.9")
set_version("0.0.0")
set_project("clink") -- set project name

includes("xmake/option.lua")

target("clink")
do
    set_kind("static")
    set_warnings("allextra", "error")
    set_languages("c99", "cxx11")
    set_installdir("$(buildir)/install")
    -- print(get_clink_options())
    for _, name in ipairs(get_clink_options()) do
        add_options(name)
    end
    add_configfiles("clink_config.h.in")
    add_rules("asm")

    add_includedirs("$(buildir)", {public = true})
    add_includedirs("inc", {public = true})

    add_files("src/*.c")
    add_files("src/devices/*.c")

    add_installfiles("$(buildir)/clink_config.h", {prefixdir = "include"})
    add_installfiles("inc/(clink/*.h)", {prefixdir = "include"})

    if is_mode("debug") then
        add_defines("CLINK_DEBUG=1")
    end
end
target_end()
