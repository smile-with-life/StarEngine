#include "starpch.h"
#include "OpenGLBuffer.h"

namespace Star
{
    bool OpenGLBuffer::Upload(const void* data, int32 size, uintptr_t offset)
    {
        return false;
    }
    MemoryMode OpenGLBuffer::Mode()
    {
        return MemoryMode();
    }
    int32 OpenGLBuffer::Size()
    {
        return int32();
    }
    BufferType OpenGLBuffer::Type()
    {
        return BufferType();
    }
}// namespace Star