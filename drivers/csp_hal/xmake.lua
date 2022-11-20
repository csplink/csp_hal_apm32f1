set_xmakever("2.7.2")

target("drivers_csp")
	set_kind("static")
	add_files(
        "chal/src/*.c",
        "port/src/*.c"
    )
    add_includedirs(
        "chal/inc",
        "port/inc",
        "$(buildir)",
        {public = true}
    )
