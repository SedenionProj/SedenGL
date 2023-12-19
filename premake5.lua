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
		"%{prj.name}/**.cpp",
		"%{prj.name}/**.c"
	}

	includedirs
	{
		"%{prj.name}/Dependencies/GLFW/include",
		"%{prj.name}/Dependencies/glad/include",
		"%{prj.name}/Dependencies/GLM",
		"%{prj.name}/Dependencies/stb"
	}

	libdirs
	{
		"%{prj.name}/Dependencies/GLFW/lib-vc2022"
	}

	links
	{
		"glfw3_mt.lib",
		"opengl32.lib",
		"User32.lib",
		"Gdi32.lib",
		"Shell32.lib"
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

