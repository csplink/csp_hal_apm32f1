set_xmakever("2.7.2")

add_includedirs(
    "../../drivers/csp_hal/port/inc",
    "$(projectdir)"
)

includes(
    "../../components/xmake.lua",
    "../../drivers/xmake.lua",
    "rule.lua"
)

set_config("arch", "cortex-m3")

if is_mode("debug") then 
    -- add_cflags("-g", "-gdwarf-2")
    add_defines("DEBUG")
end
