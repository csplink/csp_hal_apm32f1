set_xmakever("2.7.2")

rule("csp_rule_mcu")
do
    option("CSP_MCU")
    do
        set_default("apm32f103zet6")
        set_showmenu(true)
        set_values("apm32f103zet6", "apm32f103c8t6")
        set_category("csp configuration")
        set_description("mcu name")
        after_check(function(option)
            import("core.project.config")
            config.set("mcu", option:value())
        end)
    end
    option_end()
end
rule_end()

if has_config("mcu") then
    add_defines(get_config("mcu"):upper()) --and "mcu" to defines
end
