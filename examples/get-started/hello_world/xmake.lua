set_project("blink") -- set project name
set_version("0.0.0")  -- set version       
set_xmakever("2.7.2")

add_rules("mode.debug", "mode.release")

includes("../../../tools/xmake/toolchains/cortex-m3.gcc.lua")
includes("../../../project/xmake/project.lua")

set_config("mcu", "apm32f103zet6")

local default_path = "/opt/gcc-arm-none-eabi-10-2020-q4-major"
local target_name = "rtt_thread"
use_toolchain(default_path)

add_defines(
    "APM32F103ZET6"
)

add_cflags(
    "-Og",
    "-mcpu=cortex-m3",
    "-mthumb",
    "-Wall",
    "-fdata-sections",
    "-ffunction-sections",
    "-g3 -gdwarf-2",
    "--specs=nano.specs", 
    {force = true}
)

add_asflags(
    "-Og",
    "-mcpu=cortex-m3",
    "-mthumb",
    "-x assembler-with-cpp",
    "-Wall",
    "-fdata-sections", 
    "-ffunction-sections",
    "-g3 -gdwarf-2",
    {force = true}
)

add_ldflags(
    "-Og",
    "-mcpu=cortex-m3",
    "-T../../../linkscripts/APM32F103xE.lds",  -- 不同芯片需要修改链接脚本 STM32F103XE_FLASH.ld STM32F103C8Tx_FLASH.ld
    "-Wl,--gc-sections",
    "-Wl,--print-memory-usage,-Map=".."$(buildir)/"..target_name..".map",
    {force = true}
)

target(target_name)
    set_kind("binary")
    set_languages("c99")
    set_extension(".elf")
    add_deps(
        "apm32f1"
    )
    add_rules("build_binary")

    add_files(
        "main.c"
    )
    add_includedirs(
        "."
    )
