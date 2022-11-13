import("core.project.config")
import("core.project.project")

local artifact_dir = config.buildir() .. "/artifact/" .. config.mode() .. "/"

function main(target)
    target:add("ldflags", "-Wl,--print-memory-usage,-Map=" .. artifact_dir ..
                   project.name() .. ".map")
end
