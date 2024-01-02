--
-- Licensed under the GNU General Public License v. 3 (the "License")
-- You may not use this file except in compliance with the License.
-- You may obtain a copy of the License at
--
--     https://www.gnu.org/licenses/gpl-3.0.html
--
-- Unless required by applicable law or agreed to in writing, software
-- distributed under the License is distributed on an "AS IS" BASIS,
-- WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
-- See the License for the specific language governing permissions and
-- limitations under the License.
--
-- Copyright (C) 2023-2023 xqyjlj<xqyjlj@126.com>
--
-- @author      xqyjlj
-- @file        xmake.lua
--
-- Change Logs:
-- Date           Author       Notes
-- ------------   ----------   -----------------------------------------------
-- 2023-12-19     xqyjlj       initial version
--
local _version = "v0.0.1"

function version()
    return _version
end

function _assert(gpiox, index, x, y)
    assert(x == y, "P%s%s std.gpio_mode_t: %s is invalid, should be %s!", gpiox, index, x, y)
end

function __generate_gpio(gpiox, pins)
    gpiox = string.upper(gpiox)
    local code_table = {}
    local defines_table = {}
    table.insert(code_table, string.format("    /* enable the GPIO%s ports clock */", gpiox))
    table.insert(code_table, string.format("    RCM_EnableAPB2PeriphClock(RCM_APB2_PERIPH_GPIO%s);", gpiox))
    table.insert(code_table, "")
    for _, func in ipairs(table.orderkeys(pins)) do
        for _, index in ipairs(table.orderkeys(pins[func])) do
            local property = pins[func][index]["config"]["function_property"]["gpio"]
            local comment = pins[func][index]["config"]["comment"]
            local port
            local pin
            if comment and string.len(comment) > 0 then
                port = comment .. "_PORT"
                pin = comment .. "_PIN"
                table.insert(code_table, string.format("    /* configure the %s(GPIO%s), %s(GPIO_PIN_%s) */", port,
                                                       gpiox, pin, index))
                table.insert(defines_table, {key = port, value = "GPIO" .. gpiox})
                table.insert(defines_table, {key = pin, value = "GPIO_PIN_" .. index})
            else
                port = "GPIO" .. gpiox
                pin = "GPIO_PIN_" .. index
                table.insert(code_table, string.format("    /* configure the GPIO%s, GPIO_PIN_%s */", gpiox, index))
            end
            if func == "gpio-output" then -- first should add pin level
                -- level
                local pin_level
                if property["std.gpio_level_t"] == "std.gpio_level_low" then
                    pin_level = "BIT_RESET"
                elseif property["std.gpio_level_t"] == "std.gpio_level_high" then
                    pin_level = "BIT_SET"
                else
                    assert(0, "P%s%s std.gpio_output_type_t: %s is invalid!", gpiox, index,
                           property["std.gpio_output_type_t"])
                end
                table.insert(code_table, string.format("    GPIO_WriteBitValue(%s, %s, %s);", port, pin, pin_level))
                table.insert(code_table, "")
            end
            table.insert(code_table, string.format("    config.pin = %s;", pin))
            if func == "gpio-analog" then -- analog
                _assert(gpiox, index, property["std.gpio_mode_t"], "std.gpio_mode_analog")
                table.insert(code_table, "    config.mode = GPIO_MODE_ANALOG;")
            elseif func == "gpio-input" then -- input
                _assert(gpiox, index, property["std.gpio_mode_t"], "std.gpio_mode_input")
                -- pull
                if property["std.gpio_pull_t"] == "std.gpio_pull_up" then
                    table.insert(code_table, "    config.mode = GPIO_MODE_IN_PU;")
                elseif property["std.gpio_pull_t"] == "std.gpio_pull_down" then
                    table.insert(code_table, "    config.mode = GPIO_MODE_IN_PD;")
                elseif property["std.gpio_pull_t"] == "std.gpio_pull_no" then
                    table.insert(code_table, "    config.mode = GPIO_MODE_IN_FLOATING;")
                else
                    assert(0, "P%s%s std.gpio_pull_t: %s is invalid!", gpiox, index, property["std.gpio_pull_t"])
                end
            elseif func == "gpio-output" then -- output
                _assert(gpiox, index, property["std.gpio_mode_t"], "std.gpio_mode_output")
                -- output_type
                if property["std.gpio_output_type_t"] == "std.gpio_output_pp" then
                    table.insert(code_table, "    config.mode = GPIO_MODE_OUT_PP;")
                elseif property["std.gpio_output_type_t"] == "std.gpio_output_od" then
                    table.insert(code_table, "    config.mode = GPIO_MODE_OUT_OD;")
                else
                    assert(0, "P%s%s std.gpio_output_type_t: %s is invalid!", gpiox, index,
                           property["std.gpio_output_type_t"])
                end
                -- speed
                if property["std.gpio_speed_t"] == "std.gpio_speed_low" then
                    table.insert(code_table, "    config.speed = GPIO_SPEED_10MHz;")
                elseif property["std.gpio_speed_t"] == "std.gpio_speed_medium" then
                    table.insert(code_table, "    config.speed = GPIO_SPEED_2MHz;") -- why 2MHz?
                elseif property["std.gpio_speed_t"] == "std.gpio_speed_high" then
                    table.insert(code_table, "    config.speed = GPIO_SPEED_50MHz;")
                else
                    assert(0, "P%s%s std.gpio_speed_t: %s is invalid!", gpiox, index, property["std.gpio_speed_t"])
                end
            else
                assert(0, "P%s%s function: %s is invalid!", gpiox, index, func)
            end
            table.insert(code_table, string.format("    GPIO_Config(%s, &config);", port))
            table.insert(code_table, "")
        end
    end
    return {code = table.concat(code_table, "\n"), defines = defines_table}
end

function _generate_gpio(project)
    local group = {}
    for name, pin in pairs(project.pin_configs) do
        name = string.lower(name)
        func = string.lower(pin["function"])
        if pin.locked and string.startswith(func, "gpio-") then
            if string.match(name, "^p%l%d+$") then
                local gpiox, index = string.match(name, "^p(%l)(%d+)$")
                if gpiox and index then
                    if not group[gpiox] then
                        group[gpiox] = {}
                    end
                    if not group[gpiox][func] then
                        group[gpiox][func] = {}
                    end
                    group[gpiox][func][index] = {name = name, gpiox = gpiox, index = index, config = pin}
                end
            end
        end
    end

    local code_table = {}
    local defines_table = {}
    table.insert(code_table, "    GPIO_Config_T config = {0};")
    table.insert(code_table, "")
    for _, gpiox in ipairs(table.orderkeys(group)) do
        local data = __generate_gpio(gpiox, group[gpiox])
        if #data.defines > 0 then
            table.join2(defines_table, data.defines)
        end
        table.insert(code_table, data.code)
    end

    return {code = table.concat(code_table, "\n"), defines = defines_table}
end

function generate(project, kind)
    local t = nil
    if string.lower(kind) == "gpio" then
        local data = _generate_gpio(project)
        t = {code = data.code, defines = data.defines, modules = nil}
    elseif string.lower(kind) == "main" then
        t = {}
    end

    return t
end

function get_header(kind)
    local t = nil
    local kind = string.lower(kind)
    if kind == "base" then
        t = {"apm32f10x.h"}
    elseif kind == "gpio" then
        t = {"apm32f10x_gpio.h", "apm32f10x_eint.h", "apm32f10x_misc.h", "apm32f10x_rcm.h"}
    elseif kind == "main" then
        t = {}
    else
        assert(0, "unsupport kind \"%s\"", kind)
    end

    return t
end

local linkscripts = {apm32f103zet6 = "res/%s/APM32F10xxE.lds"}
local startupfiles = {apm32f103zet6 = "res/%s/startup_apm32f10x_hd.s"}

function get_files_and_includes(project)
    local name = string.lower(project["core"]["target"])
    local files = {}
    local includes = {}

    assert(startupfiles[name], "unsupport chip %s", name)

    table.insert(files, path.filename(startupfiles[name]))

    return {files = files, includes = includes}
end

function get_flags(project)
    local name = string.upper(project["core"]["target"])
    local ldflags = {"-mcpu=cortex-m3", "-mthumb", "-mthumb-interwork", "-Wl,--gc-sections"}
    local cflags = {}
    local cxxflags = {}
    local cxflags = {
        "-mcpu=cortex-m3", "-mthumb", "-mthumb-interwork", "-ffunction-sections", "-fdata-sections", "-fno-common",
        "-fmessage-length=0"
    }
    local asflags = {}
    local defines = {}

    assert(startupfiles[string.lower(name)], "unsupport chip %s", name)
    table.insert(ldflags, string.format("-T%s.lds", name))
    table.join2(asflags, cxflags)

    local basename = path.basename(startupfiles[string.lower(name)])
    if basename == "startup_apm32f10x_cl" then
        table.insert(defines, "APM32F10X_CL")
    elseif basename == "startup_apm32f10x_md" then
        table.insert(defines, "APM32F10X_MD")
    elseif basename == "startup_apm32f10x_hd" then
        table.insert(defines, "APM32F10X_HD")
    end

    return {
        ldflags = ldflags,
        cflags = cflags,
        cxxflags = cxxflags,
        cxflags = cxflags,
        asflags = asflags,
        defines = defines
    }
end

function _deploy_files(project, outputdir)
    local rootdir = path.join(os.scriptdir(), "..", "..")
    -- LuaFormatter off
    local filelist =
    {
        "libraries/**/*.h",
        "libraries/**/*.c",
        "libraries/**/*.txt",
        ".clang-format",
        "LICENSE",
        "README*.md",
        "xmake.lua",
    }
    -- LuaFormatter on
    for _, match in ipairs(filelist) do
        for _, file in ipairs(os.files(path.join(rootdir, match))) do
            local dest = path.join(outputdir, "hal", path.relative(file, rootdir))
            if not os.exists(dest) then
                os.vcp(file, dest)
            end
        end
    end
end

function deploy(project, outputdir)
    local name = string.lower(project["core"]["target"])
    local toolchains = project["core"]["toolchains"]
    local target = project["target"]
    local kind;

    assert(startupfiles[name], "unsupport chip %s", name)

    if string.startswith(string.lower(toolchains), "arm-none-eabi") then
        kind = "gcc"
    elseif "mdk" == string.lower(target) then
        kind = "mdk"
    else
        kind = "gcc"
    end

    -- startup file
    local source = path.join(os.scriptdir(), string.format(startupfiles[name], kind))
    local dest = path.join(outputdir, path.filename(source))
    if not os.exists(dest) then
        os.vcp(source, dest)
    end

    -- link script
    if linkscripts[name] then
        local source = path.join(os.scriptdir(), string.format(linkscripts[name], kind))
        local dest = path.join(outputdir, string.upper(name) .. ".lds")
        if not os.exists(dest) then
            os.vcp(source, dest)
        end
    end

    -- system_apm32f10x.c
    local source = path.join(os.scriptdir(), "res", "system_apm32f10x.c")
    local dest = path.join(outputdir, "core", "src", "system_apm32f10x.c")
    if not os.exists(dest) then
        os.vcp(source, dest)
    end

    _deploy_files(project, outputdir)
end
