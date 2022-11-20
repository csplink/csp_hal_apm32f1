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
