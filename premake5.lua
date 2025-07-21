workspace "StarEngine" --工作区
    system "Windows"
	architecture "x86_64" --架构
    characterset "Unicode" --字符集
    startproject "TestGame" --[[启动项目]]

	configurations --配置项
    {    
        "Test",                        
        "Debug",
        "Release",
        "Dist"
    }

    flags  --设置编译器选项
	{
		"MultiProcessorCompile" --多处理器并行编译
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" --输出目录

IncludeDir={}

IncludeDir["GLFW"] = "StarEngine/Dependencies/GLFW/include"
IncludeDir["Glad"] = "StarEngine/Dependencies/GLAD/include"
IncludeDir["ICU4C"] = "StarEngine/Dependencies/ICU4C/include"
IncludeDir["Stb"] = "StarEngine/Dependencies/Stb/include"
IncludeDir["NlohmannJson"] = "StarEngine/Dependencies/NlohmannJson/include"
IncludeDir["Sciter"] = "StarEngine/Dependencies/Sciter/include"
IncludeDir["Ultralight"] = "StarEngine/Dependencies/Ultralight/include"

include "StarEngine/Dependencies/GLFW"
include "StarEngine/Dependencies/Glad"
include "StarEngine/Dependencies/Stb"
include "StarEngine/Dependencies/NlohmannJson"

project "StarEngine" --项目
    location "StarEngine" --项目文件的目录
    kind "SharedLib" --生成类型
    language "C++" --语言
    cppdialect "C++20" --C++标准
    staticruntime "on" --是否将运行时库静态链接运行时库（dll属性的文件需要关闭）

    targetdir ("Bin/" .. outputdir .. "/%{prj.name}") --输出目录
    objdir ("Bin-Int/" .. outputdir .. "/%{prj.name}") --中间目录

    pchheader "starpch.h" --预编译头文件
    pchsource "StarEngine/Source/starpch.cpp" --VS下的预编译文件-

    files
    {
        "%{prj.name}/Source/starpch.h",
        "%{prj.name}/Source/starpch.cpp",
        "%{prj.name}/Source/Starengine.h"
    }

    includedirs --包含目录
    {
        "%{prj.name}/Source",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ICU4C}",
        "%{IncludeDir.Stb}",
        "%{IncludeDir.NlohmannJson}",
        "%{IncludeDir.Ultralight}",
    }

    libdirs 
    {
        "%{prj.name}/Dependencies/ICU4C/lib64",
        "%{prj.name}/Dependencies/Ultralight/lib"
    }

    links --链接库
    {
        "GLFW",
        "Glad",
        "opengl32.lib",
        "icuuc",
        "Stb",
        "Ultralight",
        "UltralightCore",
        "WebCore",
        "AppCore"
    }

    filter "configurations:Test" --Test模式
	    defines "STAR_TEST"
		buildoptions "/MDd"
		symbols "On"

    filter "configurations:Debug" --Debug模式
	    defines "STAR_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release" --Release模式
	    defines "STAR_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist" --Dist模式
	    defines "STAR_DIST"
		buildoptions "/MD"
		optimize "On"

    filter "system:Windows" --当系统是Windows时
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines --预定义宏
		{
			"PLATFORM_WINDOWS",
			"BUILD_EXPORT_DLL"
		}

		postbuildcommands --编译完成后执行
		{
			("{MKDIR} %[bin/" .. outputdir .. "/TestGame]"),
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/TestGame")
		}
    
    -- 模块构建
    include "StarEngine/Source/Core/CoreMake.lua" --核心模块
    include "StarEngine/Source/Launch/LaunchMake.lua" --启动模块
    include "StarEngine/Source/Platform/PlatformMake.lua" --平台模块   
    include "StarEngine/Source/Manager/ManagerMake.lua" --管理器模块
    include "StarEngine/Source/UI/UIMake.lua" --管理器模块
project "TestGame"
    location "TestGame"
    kind "windowedapp"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    debugdir "." -- 工作目录
    
    files
    {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp"
    }
    
    includedirs
    {
        "StarEngine/Source",
        "."
    }

    libdirs 
    {
        "%{prj.name}/Dependencies/ICU4C/lib64"
    }
    
    links
    {
        "StarEngine",
        "icuuc"
    }

    filter "configurations:Test" --Test模式
	    defines "STAR_Test"
		buildoptions "/MDd"
		symbols "On"

    filter "configurations:Debug" --Debug模式
	    defines "STAR_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release" --Release模式
	    defines "STAR_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist" --Dist模式
	    defines "STAR_DIST"
		buildoptions "/MD"
		optimize "On"
    
    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"
            
        defines
        {
            "PLATFORM_WINDOWS"
        }
    
    