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
-- @file        binary_before_build.lua
--
-- Change Logs:
-- Date           Author       Notes
-- ------------   ----------   -----------------------------------------------
-- 2023-01-02     xqyjlj       initial version
--

import("core.project.config")
import("core.project.project")

local artifact_dir = path.absolute(os.projectdir()) .. "/build/artifact/" .. config.mode() .. "/"

function main(target)
    if not os.exists(artifact_dir) then
        os.mkdir(artifact_dir)
    end

    target:add("ldflags", "-Wl,--print-memory-usage,-Map=" .. artifact_dir .. target:name() .. ".map")
end
