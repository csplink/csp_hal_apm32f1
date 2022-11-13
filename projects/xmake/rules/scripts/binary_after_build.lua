import("core.project.config")
import("core.project.project")
import("core.tool.toolchain")

local project_name = project.name()
local sdkdir = get_config("sdk")
local binutil = sdkdir .. "/bin/" .. get_config("prefix")

local cc = binutil .. "gcc"
local ld = binutil .. "gcc"
local ar = binutil .. "ar"
local as = binutil .. "gcc"
local objcopy = binutil .. "objcopy"
local size = binutil .. "size"
local objdump = binutil .. "objdump"

local artifact_dir = config.buildir() .. "/artifact/" .. config.mode() .. "/"

function generate_hex(target)
    os.execv(objcopy, {
        "-O", "ihex", target:targetfile(),
        artifact_dir .. project.name() .. ".hex"
    })
end

function generate_bin(target)
    os.execv(objcopy, {
        "-O", "binary", target:targetfile(),
        artifact_dir .. project.name() .. ".bin"
    })
end

function show_size(target)
    -- os.execv(size, {"-Ax", target:targetfile()})
    os.execv(size, {"-Bx", target:targetfile()})
    os.execv(size, {"-Bd", target:targetfile()})
end

function disassembly(target)
    os.execv(objdump, {"-S", target:targetfile()},
             {stdout = artifact_dir .. project.name() .. ".s"})
    os.execv(objdump, {"-h", target:targetfile()},
             {stdout = artifact_dir .. project.name() .. ".list"})
end

function main(target)
    if not os.isdir(artifact_dir) then
        os.mkdir(artifact_dir) -- create $(buildir)/artifact/config.mode/
    end
    generate_hex(target)
    generate_bin(target)
    show_size(target)
    disassembly(target)
end
