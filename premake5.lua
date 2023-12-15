workspace "SedenGL"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "SedenGL"
	location "SedenGL"
	kind "Sharedlib"
	language "C++"

	targetdir ("build/bin/"..outputdir.."/%{prj.name}")
	objdir ("build/bin-int/"..outputdir.."/%{prj.name}")

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp"
	}

	includedirs
	{
		
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"
		
		defines
		{
			"SEDEN_PLATFORM_WINDOWS",
			"SEDEN_BUILD"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../build/bin/"..outputdir.."/Sandbox")

		}

workspace "SedenGL"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("build/bin/"..outputdir.."/%{prj.name}")
	objdir ("build/bin-int/"..outputdir.."/%{prj.name}")

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp"
	}

	includedirs
	{
		"SedenGL"
	}

	links
	{
		"SedenGL"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"
		
		defines
		{
			"SEDEN_PLATFORM_WINDOWS"
		}

