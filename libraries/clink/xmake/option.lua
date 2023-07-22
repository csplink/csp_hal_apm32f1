--
-- Licensed under the Apache License, Version 2.0 (the "License");
-- You may not use this file except in compliance with the License.
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
-- Copyright (C) 2023-2023 xqyjlj<xqyjlj@126.com>
--
-- @author      xqyjlj
-- @file        xmake.lua
--
-- Change Logs:
-- Date           Author       Notes
-- ------------   ----------   -----------------------------------------------
-- 2023-07-20     xqyjlj       initial version
--
category = "components/clink"

config = {
    CLINK_NAME_MAX = {default = "8", description = "The maximal size of object name", category = category},
    CLINK_USING_RTTHREAD = {default = false, description = "Enable RT-Thread RTOS", category = category},
    CLINK_USING_STDLIB = {default = false, description = "Enable use standard C library", category = category},
    CLINK_USING_TINY_SIZE = {default = false, description = "Enable use tiny size", category = category}
}

function get_clink_options()
    return table.orderkeys(config)
end

for _, name in ipairs(table.orderkeys(config)) do
    local cfg = config[name]
    option(name)
    do
        set_default(cfg.default)
        set_showmenu(true)
        set_category(cfg.category)
        set_description(cfg.description)
        set_configvar(name, get_config(name))
        if cfg.values then
            set_values(cfg.values)
        end
    end
end
