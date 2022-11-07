set_xmakever("2.7.2")

for _, dir in ipairs(os.dirs(os.scriptdir().."/*")) do
    if os.exists(dir.."/xmake.lua") then
        includes(dir)
    end
end
