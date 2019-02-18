#!lua

newoption {
   trigger     = "doxygen_path",
   value       = "path",
   description = "Doxygen executable path"
}

if _ACTION == "gmake" then
    premake.error("gmake action DOESN't support this script. Please use gmake2")
end

function get_version()
    local version = "Unknown"
    local f = io.open("CHANGELOG.md", "r")
    if f then
        local l = f:read("*line")
        local v = l:match("#+%s+([%d.]+)%s+%([%d+-]+%)")
        if v then version = v end
        f:close()
    end
    return version
end


solution "BearLibTerminal"

    local is_win = os.host() == "windows"
    local opengl = is_win and "opengl32" or "GL"
    local linux_libs = { "X11", "m", "dl" }
    if is_win then linux_libs = {} end

    configurations {
        "sharedrelease", "staticrelease", "shareddebug", "staticdebug"
    }

    filter "configurations:*"
        flags "UndefinedIdentifiers"

    filter "configurations:*debug"
        defines "DEBUG"
        symbols "ON"
        optimize "Off"

    filter "configurations:*release"
        defines "NDEBUG"
        symbols "OFF"
        optimize "Speed"
        omitframepointer "ON"
        flags { "NoBufferSecurityCheck", "NoRuntimeChecks" }

    filter { "action:vs*", "configurations:*release" }
        flags "LinkTimeOptimization"

    filter { "toolset:gcc", "system:windows" }
        makesettings "CC=gcc"

    filter { }

    function examples_common(options)
        local is_hello = options.is_hello and options['is_hello']
        kind "ConsoleApp"
        dependson "BearLibTerminal"
        includedirs "Terminal/Include/C"
        links "BearLibTerminal"
        links { linux_libs }
        filter "toolset:gcc"
            if is_hello then
                buildoptions {
                    "-Wall", "-pedantic",
                    "-Wformat=2", "-Wshadow", "-Wbad-function-cast"
                }
            end
        filter { "configurations:shared*", "system:not windows" }
            buildoptions "-fpie"
        filter "configurations:static*"
            defines "BEARLIBTERMINAL_STATIC_BUILD"
            if _ACTION:sub(0, 5) == "gmake" then
                links "stdc++"
            end
            links { "FreeType2", "PicoPng", opengl }
            if is_win then
                links { "gdi32", "winmm" }
            end
        filter "configurations:shared*"
            if is_win and not is_hello then
                links "winmm"
            end
        filter {}
    end

    project "PicoPng"
        local pico_dir = "Terminal/Dependencies/PicoPNG"
        language "C++"
        kind "StaticLib"
        filter {
            "configurations:static*", "kind:StaticLib",
            "system:windows", "action:gmake*"
        }
            targetprefix "lib"
            targetextension ".a"
        filter {
            "system:not windows", "action:gmake*", "configurations:shared*"
        }
            buildoptions "-fpic"
        filter {}
        includedirs (pico_dir .. "/Include")
        files (pico_dir .. "/Source/PicoPNG.cpp")

    project "FreeType2"
        local ft_dir = "Terminal/Dependencies/FreeType/"
        language "C"
        kind "StaticLib"
        includedirs (ft_dir .. "/Include")
        defines "FT2_BUILD_LIBRARY"
        filter {
            "configurations:static*", "kind:StaticLib",
            "system:windows", "action:gmake*"
        }
            targetprefix "lib"
            targetextension ".a"
        filter "toolset:gcc"
            buildoptions {
                "-Wall", "-Wstrict-prototypes", "-Wshadow", "-Wformat=2"
            }
        filter {
            "system:not windows", "action:gmake*", "configurations:shared*"
        }
            buildoptions "-fpic"
        filter {}
        files {
            ft_dir .. "Source/autofit/autofit.c",
            ft_dir .. "Source/base/ftbase.c",
            ft_dir .. "Source/base/ftbbox.c",
            ft_dir .. "Source/base/ftdebug.c",
            ft_dir .. "Source/base/ftfstype.c",
            ft_dir .. "Source/base/ftgasp.c",
            ft_dir .. "Source/base/ftglyph.c",
            ft_dir .. "Source/base/ftinit.c",
            ft_dir .. "Source/base/ftlcdfil.c",
            ft_dir .. "Source/base/ftmm.c",
            ft_dir .. "Source/base/ftsystem.c",
            ft_dir .. "Source/raster/raster.c",
            ft_dir .. "Source/sfnt/sfnt.c",
            ft_dir .. "Source/smooth/smooth.c",
            ft_dir .. "Source/truetype/truetype.c"
        }

    project "BearLibTerminal"
        local v_str = get_version()
        language "C++"
        cppdialect "C++11"
        print("BearLibTerminal v" .. v_str)
        defines ("TERMINAL_VERSION=\"" .. v_str .. "\"")
        dependson { "PicoPng", "FreeType2" }
        includedirs {
            "Terminal/Include/C",
            "Terminal/Dependencies/FreeType/Include",
            "Terminal/Dependencies/PicoPNG/Include",
            "Terminal/Dependencies/NanoJPEG/Include"
        }
        files "Terminal/Source/*.cpp"
        filter "configurations:static*"
            kind "StaticLib"
            defines "BEARLIBTERMINAL_STATIC_BUILD"
        filter "configurations:shared*"
            kind "SharedLib"
            links { "FreeType2", "PicoPng", opengl }
            if is_win then
                files "Terminal/Resource/Terminal.rc"
                links { "gdi32", "winmm" }
            else
                buildoptions "-fpic"
            end
        filter {
            "configurations:static*", "kind:StaticLib",
            "system:windows", "action:gmake*"
        }
            targetprefix "lib"
            targetextension ".a"
        filter "system:windows"
            defines { "UNICODE" , "_UNICODE" }
        filter { "configurations:shared*", "toolset:gcc" }
            linkoptions "-fvisibility=hidden"
            if is_win then
                linkoptions "-static"
            else
                linkoptions "-static-libgcc"
            end
        filter {}

    project "Hello"
        language "C"
        examples_common { is_hello = true }
        files "Samples/hello.c"

    project "Omni"
        language "C++"
        cppdialect "C++11"
        examples_common { is_hello = false }
        files {
            "Samples/Omni/Source/Main.cpp",
            "Samples/Omni/Source/Common.cpp",
            "Samples/Omni/Source/WindowsGlyphList4.cpp",
            "Samples/Omni/Source/BasicOutput.cpp",
            "Samples/Omni/Source/DefaultFont.cpp",
            "Samples/Omni/Source/Tilesets.cpp",
            "Samples/Omni/Source/Sprites.cpp",
            "Samples/Omni/Source/ManualCellsize.cpp",
            "Samples/Omni/Source/AutoGenerated.cpp",
            "Samples/Omni/Source/MultipleFonts.cpp",
            "Samples/Omni/Source/TextAlignment.cpp",
            "Samples/Omni/Source/FormattedLog.cpp",
            "Samples/Omni/Source/Layers.cpp",
            "Samples/Omni/Source/ExtendedBasics.cpp",
            "Samples/Omni/Source/ExtendedInterlayer.cpp",
            "Samples/Omni/Source/ExtendedSmoothScroll.cpp",
            "Samples/Omni/Source/DynamicSprites.cpp",
            "Samples/Omni/Source/Speed.cpp",
            "Samples/Omni/Source/Keyboard.cpp",
            "Samples/Omni/Source/Mouse.cpp",
            "Samples/Omni/Source/TextInput.cpp",
            "Samples/Omni/Source/InputFiltering.cpp",
            "Samples/Omni/Source/WindowResize.cpp",
            "Samples/Omni/Source/Pick.cpp"
        }

    project "Examples"
        kind "Makefile"
        dependson { "Hello", "Omni" }

    project "Doc"
        local dp = ""
        kind "Makefile"
        if _OPTIONS["doxygen_path"] then
            dp = _OPTIONS["doxygen_path"] .. '/'
        end
        basedir "Doc"
        buildcommands { dp .. "doxygen" }
        cleancommands "{RMDIR} html"
