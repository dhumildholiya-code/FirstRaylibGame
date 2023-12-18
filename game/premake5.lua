function link_raylib()
    links {"raylib"}
    includedirs{"../vendor/raylib/include"}
    libdirs{"../vendor/raylib"}

    filter "system:windows"
        defines{"_WIN32"}
        links {"winmm", "kernel32", "opengl32", "gdi32"}
end

project "game"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir("../bin/" .. outputdir .. "/%{prj.name}")
    objdir("..bin-int/" .. outputdir .. "/%{prj.name}")

    files{
        "src/**.cpp",
        "include/**.h"
    }

    includedirs {"include"}
    --linking raylib static lib
    link_raylib()

    filter {"configurations:Debug"}
        defines {"DEBUG"}
        runtime "Debug"
        symbols "on"

    filter {"configurations:Release"}
        kind "WindowedApp"
        entrypoint "mainCRTStartup"
        defines {"NDEBUG"}
        runtime "Release"
        optimize "on"