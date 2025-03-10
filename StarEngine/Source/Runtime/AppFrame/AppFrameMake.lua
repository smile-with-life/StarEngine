files  --要编译的源文件
{
    "Application/Application.h",
    "Application/Application.cpp",
    "Window/Window.h",
    "Window/Window.cpp",
    "Console/Console.h",
    "Console/Console.cpp"
}
filter "system:Windows"
    files  --要编译的源文件
    {
        "Application/Windows/WindowsApplication.h",
        "Application/Windows/WindowsApplication.cpp",
        "Window/Windows/WindowsWindow.h",
        "Window/Windows/WindowsWindow.cpp",
        "Console/Windows/WindowsConsole.h",
        "Console/Windows/WindowsConsole.cpp"
    }