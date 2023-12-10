
Solution.AddProject("GLFW", 	"Dependencies/GLFW")
Solution.AddProject("Glad", 	"Dependencies/Glad")
Solution.AddProject("ImGui", 	"Dependencies/ImGui")

group "Dependencies"
	include (Solution.Projects["GLFW"].Path)
	include (Solution.Projects["Glad"].Path)
	include (Solution.Projects["ImGui"].Path)
group ""

Solution.Projects["Blackbird"].PlatformDefineName = "BLACKBIRD"
Solution.Projects["Blackbird"].Type = "StaticLib"
Solution.Projects["Blackbird"].IncludeDirs = {
	"%{Solution.Projects.Blackbird.Path}/",
	"%{Solution.Projects.Blackbird.Path}/src/",
	"%{Solution.Projects.Blackbird.Path}/Dependencies",
	"%{Solution.Projects.Blackbird.Path}/Dependencies/ImGui",
}
Solution.Projects["Blackbird"].Defines = {
	"GLFW_INCLUDE_NONE"
}
Solution.Projects["Blackbird"].ProjectDependencies = {
	"ProjectCore",
	"LittleECS",
	"GLFW",
	"Glad",
	"ImGui"
}

project "Blackbird"
	kind 		(Solution.Projects["Blackbird"].Type)
	language "C++"
	cppdialect "C++20"

	targetdir 	(Solution.Path.ProjectTargetDirectory)
    objdir 		(Solution.Path.ProjectObjectDirectory)

	includedirs {
		"%{Solution.Projects.Blackbird.Path}/Dependencies/GLFW/include",
		"%{Solution.Projects.Blackbird.Path}/Dependencies/Glad/include"
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
		"opengl32.lib"
	}

	Solution.Project("Blackbird")

	filter "system:windows"
		defines "_CRT_SECURE_NO_WARNINGS"