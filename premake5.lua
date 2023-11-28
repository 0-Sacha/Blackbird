
Solution.Projects["GLFW"] 		= "Dependencies/GLFW"
Solution.Projects["Glad"] 		= "Dependencies/Glad"
Solution.Projects["ImGui"] 		= "Dependencies/imgui"

group "Dependencies"
	include (Solution.Projects["GLFW"])
	include (Solution.Projects["Glad"])
	include (Solution.Projects["ImGui"])
group ""

Solution.ProjectsInfo.PlatformDefineName["Blackbird"] = "BLACKBIRD"

Solution.ProjectsInfo.IncludeDirs["Blackbird"] = {
	"%{Solution.Projects.Blackbird}/",
	"%{Solution.Projects.Blackbird}/src/",

	"%{Solution.Projects.Blackbird}/Dependencies",
	"%{Solution.Projects.Blackbird}/Dependencies/ImGui",
}

Solution.ProjectsInfo.Defines["Blackbird"] = {
	"GLFW_INCLUDE_NONE"
}

Solution.ProjectsInfo.ProjectDependencies["Blackbird"] = {
	"ProjectCore",
	"LittleECS"
}

project "Blackbird"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	targetdir 	(Solution.Path.ProjectTargetDirectory)
    objdir 		(Solution.Path.ProjectObjectDirectory)

	includedirs {
		"%{Solution.Projects.Blackbird}/Dependencies/GLFW/include",
		"%{Solution.Projects.Blackbird}/Dependencies/Glad/include"
	}

	files {
		"src/**.h",
		"src/**.cpp",
		"Dependencies/stb_image/**.h",
		"Dependencies/stb_image/**.cpp",
		"Dependencies/glm/glm/**.hpp",
		"Dependencies/glm/glm/**.inl",

		"Dependencies/Glad/include/glad.h",
		"Dependencies/Glad/src/glad.c",
	}

	links {
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	Solution.Project("Blackbird")

	filter "system:windows"
		defines "_CRT_SECURE_NO_WARNINGS"