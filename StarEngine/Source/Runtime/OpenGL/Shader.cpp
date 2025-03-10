#include"starpch.h"

#include "Shader.h"
#include "Runtime/Core/File/File.h"
#include"glad/glad.h"

namespace Star
{
void Shader::Init(String vsPath, String fsPath)
{
    // 顶点着色器对象句柄
    Handle vertexShader;

    // 片段着色器对象句柄
    Handle fragmentShader;

    // 顶点着色器代码
    String vertexShaderSource;
    // 片段着色器代码
    String fragmentShaderSource;

    File file;
    ByteArray buffer;

    if (!file.Open(vsPath, OpenMode::ReadOnly))
    {
        // @log
    }
    file.ReadAll(buffer);
    file.Close();
    vertexShaderSource = buffer;

    if (!file.Open(fsPath, OpenMode::ReadOnly))
    {
        // @log
    }
    file.ReadAll(buffer);
    file.Close();
    fragmentShaderSource = buffer;

    const char* vsCode = vertexShaderSource.ToCString();
    const char* fsCode = fragmentShaderSource.ToCString();

    // 创建顶点着色器
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    // 创建片段着色器
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    // 加载着色器程序到着色器对象中
    glShaderSource(vertexShader, 1, &vsCode, NULL);
    glShaderSource(fragmentShader, 1, &fsCode, NULL);
    
    int  success;
    char infoLog[512];


    // 编译顶点着色器程序
    // 检查顶点着色器程序是否编译成功
    // 若顶点着色器程序编译失败，进行输出打印
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // 编译片段着色器程序
    // 检查片段着色器程序是否编译成功
    // 若片段着色器程序编译失败，进行输出打印
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // 创建一个着色器程序对象
    m_shaderProgram = glCreateProgram();

    // 将之前编译的着色器附加到程序对象上
    glAttachShader(m_shaderProgram, vertexShader);
    glAttachShader(m_shaderProgram, fragmentShader);

    // 链接
    glLinkProgram(m_shaderProgram);

    // 检查着色器程序是否链接成功
    glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &success);

    // 着色器程序链接失败，进行输出打印
    if (!success) {
        glGetProgramInfoLog(m_shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    // 着色器对象链接到程序对象以后，删除着色器对象
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

}

void Shader::Tick()
{

}

void Shader::Exit()
{
    glDeleteProgram(m_shaderProgram);
}

void Shader::Bind()
{
    glUseProgram(m_shaderProgram);
}

void Shader::Unbind()
{
    glUseProgram(0);
}
}// namespace Star 