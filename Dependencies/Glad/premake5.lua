

project "Glad"
    kind "StaticLib"
    language "C"
    staticruntime "on"
    
    targetdir   (project_targetdir .. "/%{prj.name}")
    objdir      (project_objdir .. "/%{prj.name}")

    files {
        "include/glad/glad.h",
        "include/KHR/khrplatform.h",
        "src/glad.c"
    }

    includedirs {
        "include"
    }
