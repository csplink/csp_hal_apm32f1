set_xmakever("2.7.2")

rule("csp_rule_build")
do
    before_build("scripts/binary_before_build")
    after_build("scripts/binary_after_build")
end
rule_end()
