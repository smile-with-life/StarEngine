#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/GraphicAPI/Buffer.h"

namespace Star
{
class OpenGLBuffer : public Buffer
{
public:
    
public:
    virtual bool Upload(const void* data, int32 size, uintptr_t offset);

    virtual MemoryMode Mode();

    virtual int32 Size();

    virtual BufferType Type();
};
}// namespace Star