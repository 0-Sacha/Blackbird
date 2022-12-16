
Solution.Projects["GLFW"] 		= "Dependencies/GLFW"
Solution.Projects["Glad"] 		= "Dependencies/Glad"
Solution.Projects["ImGui"] 		= "Dependencies/imgui"

-- Dependencies
group "Dependencies"
	include (Solution.Projects["GLFW"])
	include (Solution.Projects["Glad"])
	include (Solution.Projects["ImGui"])
group ""

Solution.ProjectInfo.Includes["Blackbird"] = {
	"%{Solution.Projects.Blackbird}/src/",

	"%{Solution.Projects.Blackbird}/Dependencies/",
	"%{Solution.Projects.Blackbird}/Dependencies/GLFW/include",
	"%{Solution.Projects.Blackbird}/Dependencies/Glad/include",
	"%{Solution.Projects.Blackbird}/Dependencies/ImGui",
	"%{Solution.Projects.Blackbird}/Dependencies/glm",
	"%{Solution.Projects.Blackbird}/Dependencies/stb_image"
}

Solution.ProjectInfo.Defines["Blackbird"] = {
	"GLFW_INCLUDE_NONE"
}

project "Blackbird"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	pchheader "Blackbirdpch.h"
	pchsource "src/Blackbirdpch.cpp"

	targetdir 	(Solution.Path.ProjectTargetDirectory)
    objdir 		(Solution.Path.ProjectObjectDirectory)

	files {
		"src/**.h",
		"src/**.cpp",
		"vendor/stb_image/**.h",
		"vendor/stb_image/**.cpp",
		"vendor/glm/glm/**.hpp",
		"vendor/glm/glm/**.inl",
	}

	Solution.IncludeAndLinkProject("EngineCore")
	Solution.IncludeProject("Blackbird")

	links {
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		defines "_CRT_SECURE_NO_WARNINGS"