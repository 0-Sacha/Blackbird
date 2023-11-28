
project "Glad"
    kind "StaticLib"
    language "C"
    
    targetdir 	(Solution.Path.ProjectTargetDirectory)
    objdir 		(Solution.Path.ProjectObjectDirectory)

    files {
        "include/glad/glad.h",
        "include/KHR/khrplatform.h",
        "src/glad.c"
    }

    includedirs {
        "include"
    }
