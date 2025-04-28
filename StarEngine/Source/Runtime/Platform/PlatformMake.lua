files  --要编译的源文件
{
    "Application.h",
    "Application.cpp",
    "Window.h",
    "Window.cpp",
    "Console.h",
    "Console.cpp",
    "Platform.h",
    "Platform.cpp"
}
filter "system:Windows"
    files  --要编译的源文件
    {
        "Windows/WindowsApplication.h",
        "Windows/WindowsApplication.cpp",
        "Windows/WindowsWindow.h",
        "Windows/WindowsWindow.cpp",
        "Windows/WindowsConsole.h",
        "Windows/WindowsConsole.cpp",
        "Windows/WindowsPlatform.h",
        "Windows/WindowsPlatform.cpp",
    }