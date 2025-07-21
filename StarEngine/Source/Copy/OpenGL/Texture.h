#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/String/String.h"

namespace Star
{
class Texture
{
public:
    Texture(const String& path, uint32 index);
    ~Texture();
public:
    void Use() const;
private:
    String m_name;

    Handle m_handle = 0;

    uint32 m_index = 0;
};
}// namespace Star
