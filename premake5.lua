workspace "Proteus"
	architecture "x64"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
		"%{prj.name}/vendor/spdlog/include"
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
