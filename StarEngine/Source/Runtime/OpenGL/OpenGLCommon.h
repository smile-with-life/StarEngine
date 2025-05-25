#pragma once
#include "Runtime/Core/Core.h"
#include "glad/glad.h"
#include <iostream>

#define GLCall(x) GLClearError(); \
                   x; \
                   Assert(GLLogError(#x, __FILE__, __LINE__))

inline void GLClearError() {
    while (glGetError() != GL_NO_ERROR);
}

inline bool GLLogError(const char* function, const char* file, int line) {
    while (GLenum error = glGetError()) {
        std::cout << "[OpenGL Error] (" << error << ") "
            << function << " "
            << file << ":" << line << std::endl;
        return false;
    }
    return true;
}
