#include "starpch.h"
#include "Shader.h"
#include "OpenGLCommon.h"
#include "Runtime/Core/File/File.h"

namespace Star
{
Shader::Shader(const String& vsPath, const String fsPath)
{
    File file;
    ByteArray buffer;
    String vsSource;
    String fsSource;
    int  success;
    char infoLog[512];

    if (!file.Open(vsPath, OpenMode::ReadOnly))
    {
        std::cout << "顶点着色器文件打开失败！" << std::endl;
    }
    file.ReadAll(buffer);
    file.Close();
    vsSource = buffer;

    if (!file.Open(fsPath, OpenMode::ReadOnly))
    {
        std::cout << "片段着色器文件打开失败！" << std::endl;
    }
    file.ReadAll(buffer);
    file.Close();
    fsSource = buffer;

    const char* vsCode = vsSource.ToCString();
    const char* fsCode = fsSource.ToCString();

    // 创建顶点着色器
    Handle vsHandle = glCreateShader(GL_VERTEX_SHADER);

    // 创建片段着色器
    Handle fsHandle = glCreateShader(GL_FRAGMENT_SHADER);

    // 加载着色器程序到着色器对象中
    glShaderSource(vsHandle, 1, &vsCode, NULL);
    glShaderSource(fsHandle, 1, &fsCode, NULL);

    // 编译顶点着色器程序  
    glCompileShader(vsHandle);
    // 检查顶点着色器程序是否编译成功
    glGetShaderiv(vsHandle, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vsHandle, 512, NULL, infoLog);
        std::cout << "顶点着色器编译失败:\n" << infoLog << std::endl;
        Assert(false);
    }

    // 编译片段着色器程序 
    glCompileShader(fsHandle);
    // 检查片段着色器程序是否编译成功
    glGetShaderiv(fsHandle, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fsHandle, 512, NULL, infoLog);
        std::cout << "片段着色器编译失败:\n" << infoLog << std::endl;
        Assert(false);
    }

    // 创建一个着色器程序对象
    m_handle = glCreateProgram();

    // 将之前编译的着色器附加到程序对象上
    glAttachShader(m_handle, vsHandle);
    glAttachShader(m_handle, fsHandle);

    // 链接着色器程序
    glLinkProgram(m_handle);
    // 检查着色器程序是否链接成功
    glGetProgramiv(m_handle, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(m_handle, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        Assert(false);
    }

    // 着色器对象链接到程序对象以后，删除着色器对象
    glDeleteShader(vsHandle);
    glDeleteShader(fsHandle);
}

void Shader::Use() const
{
    glUseProgram(m_handle);
}
void Shader::SetInt(const String& name, int value) const
{
    glUseProgram(m_handle);
    GLCall(glUniform1i(glGetUniformLocation(m_handle, name), value));
}
}// namespace Star


