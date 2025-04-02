files  --要编译的源文件
{
    "OpenGL.h",
    "OpenGL.cpp",

    "IndexBuffer.h",
    "IndexBuffer.cpp",

    "VertexBuffer.h",
    "VertexBuffer.cpp",

    "Texture.h",
    "Texture.cpp",

    "Shader.h",
    "Shader.cpp",
}

filter "system:Windows"
    files  --要编译的源文件
    {
        "Windows/WindowsOpenGL.h",
        "Windows/WindowsOpenGL.cpp"
    }