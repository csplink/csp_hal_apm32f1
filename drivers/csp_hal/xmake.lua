set_xmakever("2.7.2")

target("csp_hal")
	set_kind("static")
	add_files(
        "src/*.c"
    )
    add_includedirs(
        "inc",
        ".",
        "$(projectdir)",
        {public = true}
    )
