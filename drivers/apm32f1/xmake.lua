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
-- Copyright (C) 2022-present xqyjlj<xqyjlj@126.com>, csplink.github.io
--
-- @author      xqyjlj
-- @file        xmake.lua
--

set_xmakever("2.7.2")

includes("../../projects/xmake/options.lua")

target("drivers_apm32f1")
do
    set_kind("static")
    add_includedirs("cmsis/Include", "hal/Inc", "cmsis_core/Include", "$(buildir)", {public = true})
    add_files("cmsis/Source/Templates/system_stm32f1xx.c", "hal/Src/stm32f1xx_ll_*.c")
    remove_files("hal/Src/*_template.c")
    remove_files("hal/Src/stm32f1xx_ll_usb.c")
    remove_files("hal/Src/stm32f1xx_ll_sdmmc.c")
    remove_files("hal/Src/stm32f1xx_ll_fsmc.c")
    if (is_config("CSP_MCU", "apm32f103zet6")) then
        if (is_config("compiler", "gcc")) then
            add_files("cmsis/Source/Templates/gcc/startup_stm32f103xe.s")
        end
    end
    add_options("csp_hal_apm32f1")
end
target_end()
