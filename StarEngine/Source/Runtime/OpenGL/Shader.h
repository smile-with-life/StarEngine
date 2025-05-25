#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/String/String.h"

namespace Star
{
class Shader
{
public:
    Shader(const String& vsPath, const String fsPath);

    ~Shader() = default;
public:
    void Use() const;

    void SetInt(const String& name, int value) const;
public:
    Handle m_handle;
};
}// namespace Star
