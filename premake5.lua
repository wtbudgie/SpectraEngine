workspace "SpectraX"
    architecture "x64"
    startproject "Sandbox"
    configurations { "Debug", "Release" }

outputdir = ("%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}")

project "SpectraEngine"
    location "SpectraEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("".. outputdir .. "/%{prj.name}")
    objdir ("" .. outputdir .. "/obj/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/include"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines { 
            "SA_PLATFORM_WINDOWS", 
            "SA_BUILD_DLL"
        }

        postbuildcommands {
            "{MKDIR} ../" .. outputdir .. "/Sandbox",
            "{COPY} %{cfg.buildtarget.relpath} ../" .. outputdir .. "/Sandbox"
        }

    filter "configurations:Debug"
        defines "SA_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SA_RELEASE"
        optimize "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("".. outputdir .. "/%{prj.name}")
    objdir ("" .. outputdir .. "/obj/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "SpectraEngine/src",
        "SpectraEngine/include"
    }

    links {
        "SpectraEngine"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines { 
            "SA_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "SA_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SA_RELEASE"
        optimize "On"