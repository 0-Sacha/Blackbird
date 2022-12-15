
Project["GLFW"] 		= "vendor/GLFW"
Project["Glad"] 		= "vendor/Glad"
Project["ImGui"] 		= "vendor/imgui"

-- Dependencies
group "Dependencies"
	include (Project["GLFW"])
	include (Project["Glad"])
	include (Project["ImGui"])
group ""

ProjectPublicIncludes["Spitfire"] = {
	"%{Project.Spitfire}/src/",
	"%{Project.Spitfire}/vendor/",

	"%{Project.Spitfire}/vendor/GLFW/include",
	"%{Project.Spitfire}/vendor/Glad/include",
	"%{Project.Spitfire}/vendor/imgui",
	"%{Project.Spitfire}/vendor/glm"
}

ProjectPublicDefines["Spitfire"] = {
	"GLFW_INCLUDE_NONE"
}

project "Spitfire"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	pchheader "Spitfirepch.h"
	pchsource "src/Spitfirepch.cpp"

	targetdir 	(project_targetdir .. "/%{prj.name}")
	objdir 		(project_objdir .. "/%{prj.name}")

	files {
		"src/**.h",
		"src/**.cpp",
		"vendor/stb_image/**.h",
		"vendor/stb_image/**.cpp",
		"vendor/glm/glm/**.hpp",
		"vendor/glm/glm/**.inl",
	}

	IncludeAndLinkProject("EngineCore")
	IncludeProject("Spitfire")

	includedirs {
		"%{Project.Spitfire}/vendor/glm",
		"%{Project.Spitfire}/vendor/stb_image"
	}

	links {
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		defines "_CRT_SECURE_NO_WARNINGS"