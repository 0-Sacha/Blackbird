
Project["GLFW"] 		= "vendor/GLFW"
Project["Glad"] 		= "vendor/Glad"
Project["ImGui"] 		= "vendor/imgui"

-- Dependencies
group "Dependencies"
	include (Project["GLFW"])
	include (Project["Glad"])
	include (Project["ImGui"])
group ""

ProjectPublicIncludes["OpenGLCore"] = {
	"%{Project.OpenGLCore}/src/",
	"%{Project.OpenGLCore}/vendor/",

	"%{Project.OpenGLCore}/vendor/GLFW/include",
	"%{Project.OpenGLCore}/vendor/Glad/include",
	"%{Project.OpenGLCore}/vendor/imgui",
	"%{Project.OpenGLCore}/vendor/glm"
}

ProjectPublicDefines["OpenGLCore"] = {
	"GLFW_INCLUDE_NONE"
}

project "OpenGLCore"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	pchheader "OGLCpch.h"
	pchsource "src/OGLCpch.cpp"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"src/**.h",
		"src/**.cpp",
		"vendor/stb_image/**.h",
		"vendor/stb_image/**.cpp",
		"vendor/glm/glm/**.hpp",
		"vendor/glm/glm/**.inl",
	}

	IncludeAndLinkProject("CPPTools")
	IncludeProject("OpenGLCore")

	includedirs {
		"%{Project.OpenGLCore}/vendor/glm",
		"%{Project.OpenGLCore}/vendor/stb_image"
	}

	links {
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"
		defines "_CRT_SECURE_NO_WARNINGS"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"