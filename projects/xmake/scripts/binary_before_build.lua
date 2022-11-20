import("core.project.config")
import("core.project.project")

local artifact_dir = path.absolute(os.projectdir()) .. "/build/artifact/" .. config.mode() .. "/"

function main(target)
    if not os.exists(artifact_dir) then
        os.mkdir(artifact_dir)
    end

    target:add("ldflags", "-Wl,--print-memory-usage,-Map=" .. artifact_dir .. target:name() .. ".map")
end
