workspace "Proteus"
	architecture "x64"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
IncludeDir = {}
IncludeDir["GLFW"] = "Proteus/vendor/GLFW/include"

project "GLFW"
    kind "StaticLib"
    language "C"
    
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
        "Proteus/vendor/GLFW/include/GLFW/glfw3.h",
        "Proteus/vendor/GLFW/include/GLFW/glfw3native.h",
        "Proteus/vendor/GLFW/src/glfw_config.h",
        "Proteus/vendor/GLFW/src/context.c",
        "Proteus/vendor/GLFW/src/init.c",
        "Proteus/vendor/GLFW/src/input.c",
        "Proteus/vendor/GLFW/src/monitor.c",
        "Proteus/vendor/GLFW/src/vulkan.c",
        "Proteus/vendor/GLFW/src/window.c"
    }
    
	filter "system:windows"
        buildoptions { "-std=c11", "-lgdi32" }
        systemversion "latest"
        staticruntime "On"
        
        files
        {
            "Proteus/vendor/GLFW/src/win32_init.c",
            "Proteus/vendor/GLFW/src/win32_joystick.c",
            "Proteus/vendor/GLFW/src/win32_monitor.c",
            "Proteus/vendor/GLFW/src/win32_time.c",
            "Proteus/vendor/GLFW/src/win32_thread.c",
            "Proteus/vendor/GLFW/src/win32_window.c",
            "Proteus/vendor/GLFW/src/wgl_context.c",
            "Proteus/vendor/GLFW/src/egl_context.c",
            "Proteus/vendor/GLFW/src/osmesa_context.c"
        }

		defines 
		{ 
            "_GLFW_WIN32",
            "_CRT_SECURE_NO_WARNINGS"
		}
    filter { "system:windows", "configurations:Release" }
        buildoptions "/MT"

project "Proteus"
	location "Proteus"
	kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "Proteus_pch.h"
	pchsource "Proteus/src/Proteus_pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/GLFW/include"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
	cppdialect "C++17"
	staticruntime "On"
	systemversion "latest"

	defines
	{
		"PROTEUS_DEBUG",
		"PROTEUS_BUILD_DLL",
		"PROTEUS_PLATFORM_WIN"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
	}

	filter "configurations:Debug"
		defines "PROTEUS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PROTEUS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PROTEUS_DIST"
		optimize "On"


project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Proteus/vendor/spdlog/include",
		"Proteus/src"
	}

	links
	{
		"Proteus"
	}

	filter "system:windows"
	cppdialect "C++17"
	staticruntime "On"
	systemversion "latest"

	defines
	{
		"PROTEUS_DEBUG",
		"PROTEUS_PLATFORM_WIN"
	}


	filter "configurations:Debug"
		defines "PROTEUS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PROTEUS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PROTEUS_DIST"
		optimize "On"
