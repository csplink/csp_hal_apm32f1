--!csp build system based on xmake
--
-- Licensed under the Apache License, Version 2.0 (the "License");
-- you may not use this file except in compliance with the License.
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
-- Copyright (C) 2022-present xqyjlj<xqyjlj@126.com>
--
-- @author      xqyjlj
-- @file        binary_after_build.lua
--

import("core.project.config")
import("core.project.project")
import("core.tool.toolchain")

local sdkdir = get_config("sdk")
local binutil = sdkdir .. "/bin/" .. get_config("prefix")

local cc = binutil .. "gcc"
local ld = binutil .. "gcc"
local ar = binutil .. "ar"
local as = binutil .. "gcc"
local objcopy = binutil .. "objcopy"
local size = binutil .. "size"
local objdump = binutil .. "objdump"

local artifact_dir = path.absolute(os.projectdir()) .. "/build/artifact/" .. config.mode() .. "/"

function generate_hex(target)
    local file = artifact_dir .. target:name() .. ".hex"
    os.execv(
        objcopy,
        {
            "-O",
            "ihex",
            target:targetfile(),
            file
        }
    )
    print("generate %s", file)
end

function generate_bin(target)
    local file = artifact_dir .. target:name() .. ".bin"
    os.execv(
        objcopy,
        {
            "-O",
            "binary",
            target:targetfile(),
            file
        }
    )
    print("generate %s", file)
end

function show_size(target)
    -- os.execv(size, {"-Ax", target:targetfile()})
    os.execv(size, {"-Bx", target:targetfile()})
    os.execv(size, {"-Bd", target:targetfile()})
end

function disassembly(target)
    local file = artifact_dir .. target:name() .. ".s"
    os.execv(objdump, {"-S", target:targetfile()}, {stdout = artifact_dir .. target:name() .. ".s"})
    print("generate %s", file)

    local file = artifact_dir .. target:name() .. ".list"
    os.execv(objdump, {"-h", target:targetfile()}, {stdout = artifact_dir .. target:name() .. ".list"})
    print("generate %s", file)
end

function main(target)
    if not os.isdir(artifact_dir) then
        os.mkdir(artifact_dir)
    end
    generate_hex(target)
    generate_bin(target)
    show_size(target)
    disassembly(target)
end
