set_xmakever("2.7.2")

rule("build_binary")
    after_build(function(target)
        if is_mode("release") then
            print("release finished")
            os.exec("/opt/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-objcopy -O ihex build/cross/cortex-m3/release/rtt_thread.elf build/rtt_thread.hex")
            os.exec("/opt/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-objcopy -O binary build/cross/cortex-m3/release/rtt_thread.elf build/rtt_thread.bin")
        end

        if is_mode("debug") then
            print("debug finished")
            os.exec("arm-none-eabi-objcopy -O ihex ./build/cross/cortex-m3/debug/rtt_thread.elf ./build/rtt_thread.hex")
            os.exec("arm-none-eabi-objcopy -O binary ./build/cross/cortex-m3/debug/rtt_thread.elf ./build/rtt_thread.bin")
        end

        if is_mode("release") then
            os.exec("/opt/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-size -Ax ./build/cross/cortex-m3/release/rtt_thread.elf")
            os.exec("/opt/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-size -Bx ./build/cross/cortex-m3/release/rtt_thread.elf")
            os.exec("/opt/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-size -Bd ./build/cross/cortex-m3/release/rtt_thread.elf")  
        end

        if is_mode("debug") then
            os.exec("arm-none-eabi-size -Ax ./build/cross/cortex-m3/debug/rtt_thread.elf")
            os.exec("arm-none-eabi-size -Bx ./build/cross/cortex-m3/debug/rtt_thread.elf")
            os.exec("arm-none-eabi-size -Bd ./build/cross/cortex-m3/debug/rtt_thread.elf")
        end
       
        os.execv(
            "/opt/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-objdump",
            {"-D", "./build/cross/cortex-m3/release/rtt_thread.elf"}, 
            {stdout = "./build/rtt_thread.s"}
        )
        
        -- os.execv(
        --     "/opt/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-objdump",
        --     {"-h -S", "./build/cross/cortex-m3/release/rtt_thread.elf"}, 
        --     {stdout = "./build/rtt_thread.s"}
        -- )
        --print("heap-堆, stack-栈, .data-已初始化的变量全局/静态变量, .bss-未初始化的data, .text-代码和常量")
        -- os.run("arm-none-eabi-objdump.exe -D ./build/cross/m3/release/rtt_thread.elf > rtt_thread.s")
        -- os.exec("arm-none-eabi-objdump -h -S ./build/cross/m3/debug/rtt_thread.elf > rtt_thread.list")
    end)   