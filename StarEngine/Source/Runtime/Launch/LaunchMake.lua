files  --要编译的源文件
{
    "EngineLoop.h",
    "EngineLoop.cpp"
}
filter "system:Windows"
    files  --要编译的源文件
    {      
        "Windows/WindowsLaunch.cpp",
        "Windows/WindowsExport.def"
    }