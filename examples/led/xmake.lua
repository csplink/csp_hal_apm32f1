----< add user code begin header
--
-- ----------------------------------------------------------------------------
--  @author      csplink (v0.0.0.1)
--  @file        xmake.lua
--  @brief       file automatically-generated by tool: [csp] version: [v0.0.0.1]
--                  date: Mon Jan  1 14:08:28 2024
--  @note        See more information at https://xmake.io
--
-- ----------------------------------------------------------------------------
--  @attention
--
--  Copyright (C) 2024 csplink software.
--  All rights reserved.
--
-- ----------------------------------------------------------------------------
--
----> add user code end header

-------------------------------- project rules --------------------------------
add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})
----< add user code begin project rules

----> add user code end project rules

-------------------------------- project config -------------------------------
----< add user code begin project config
set_project("led") -- Set project name
set_version("0.0.0") -- Set version
set_xmakever("2.8.3") -- Set minimal xmake version
----> add user code end project config

---------------------------------- includes -----------------------------------
----< add user code begin includes
includes("../../xmake.lua")
----> add user code end includes

---------------------------------- toolchains ---------------------------------
-- Set toolchains, which will be automatically downloaded and installed by xmake
add_requires("arm-none-eabi")
set_toolchains("@arm-none-eabi")

------------------------------------ flags ------------------------------------
----< add user code begin flags
add_ldflags("-mcpu=cortex-m3", "-mthumb", "-mthumb-interwork", "-Wl,--gc-sections", "-TAPM32F103ZET6.lds",
            {force = true})
add_cxflags("-mcpu=cortex-m3", "-mthumb", "-mthumb-interwork", "-ffunction-sections", "-fdata-sections", "-fno-common",
            "-fmessage-length=0", {force = true})
add_asflags("-mcpu=cortex-m3", "-mthumb", "-mthumb-interwork", "-ffunction-sections", "-fdata-sections", "-fno-common",
            "-fmessage-length=0", {force = true})
add_defines("APM32F10X_HD", {force = true})
----> add user code end flags

target("untitled")
do
    set_kind("binary")
    ----------------------------- target configs ------------------------------
    set_warnings("allextra")
    set_warnings("error")
    set_languages("c99")
    set_languages("cxx11")
    add_deps("csp_hal_apm32f1")
    add_rules("asm")
    add_rules("csp.bin")
    add_rules("csp.map")
    ----< add user code begin target configs

    ----> add user code end target configs

    ------------------------------ target files -------------------------------
    add_files("core/src/*.c")
    add_files("startup_apm32f10x_hd.s")
    add_includedirs("core/inc", {public = true})
    ----< add user code begin target files

    ----> add user code end target files
end
target_end()