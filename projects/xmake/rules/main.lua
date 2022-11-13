set_xmakever("2.7.2")

includes("../../../tools/xmake/rules/main.lua", "mcu.lua", "binary.lua")

rule("csp_rule_build")
do
    -- add other rule deps
    add_deps("csp_rule_sys", "csp_rule_mcu", "csp_rule_build_binary")
end
rule_end()
