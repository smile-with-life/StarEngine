#pragma once

#include "Runtime/Core/Core.h"

#include "Runtime/AppFrame/Window/Window.h"

#include "Runtime/Core/String/String.h"

namespace Star
{
class Shader
{
public:
    virtual void Init(String vsPath, String fsPath);

    virtual void Tick();

    virtual void Exit();

    virtual void Bind();

    virtual void Unbind();
private:
    // 着色器程序句柄
    Handle m_shaderProgram;

    // 着色器名称
    String m_name;
};
}// namespace Star