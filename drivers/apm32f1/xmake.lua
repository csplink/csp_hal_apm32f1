set_xmakever("2.7.2")

target("apm32f1")
    set_kind("static")
    add_includedirs(
        "cmsis/Include",
        "hal/Inc",
        "cmsis_core/Include",
        {public = true}
    )
    add_files(
        "cmsis/Source/Templates/system_stm32f1xx.c",
        "hal/Src/*.c"
    )
    remove_files(
        "hal/Src/*_template.c"
    )
    if(is_config("mcu", "apm32f103zet6")) then
        if(is_config("compiler", "gcc")) then
            add_files("cmsis/Source/Templates/gcc/startup_stm32f103xe.s")
        end
        add_defines("STM32F103xE")
    end
