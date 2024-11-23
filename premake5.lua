workspace "StarEngine" --工作区
	architecture "x86_64" --架构
    startproject "SandBox" --[[启动项目]]

	configurations --配置项
    {                               
        "Debug",
        "Release",
        "Dist"
    }

    flags  --设置编译器选项
	{
		"MultiProcessorCompile" --多处理器并行编译
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" --输出目录

project "StarEngine" --项目
    location "StarEngine" --项目文件的目录
    kind "SharedLib" --生成类型
    language "C++" --语言
    cppdialect "C++20" --C++标准
    staticruntime "on" --是否将运行时库静态链接运行时库（dll属性的文件需要关闭）

    targetdir ("bin/" .. outputdir .. "/%{prj.name}") --输出目录
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}") --中间目录

    pchheader "starpch.h" --预编译头文件
    pchsource "StarEngine/src/starpch.cpp" --VS下的预编译文件-
    files  --要编译的源文件
    {
       "%{prj.name}/src/**.h",
       "%{prj.name}/src/**.cpp",

    }

    includedirs --包含目录
    {
        "%{prj.name}/src",
        "%{prj.name}/src/StarEngine/Interface"
    }

    links --链接库
    {

    }

    filter "system:windows" --当系统是Windows时
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines --预定义宏
		{
			"STAR_PLATFORM_WINDOWS",
			"STAR_BUILD_DLL"
		}

		postbuildcommands --编译完成后执行
		{
			("{MKDIR} %[bin/" .. outputdir .. "/Sandbox]"),
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

    filter "configurations:Debug"
	    defines "STAR_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
	    defines "STAR_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
	    defines "STAR_DIST"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
    location "Sandbox"
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
        "StarEngine/src"
    }
    
    links
    {
        "StarEngine"
    }
    
    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"
            
        defines
        {
            "STAR_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "STAR_DEBUG"
        buildoptions "/MDd"
        symbols "On"
    
    filter "configurations:Release"
        defines "STAR_RELEASE"
        buildoptions "/MD"
        optimize "On"
    
    filter "configurations:Dist"
        defines "STAR_DIST"
        buildoptions "/MD"
        optimize "On"