#include <iostream>
#include <OpenGL/gl3.h>

#ifndef DISABLE_ERROR_CHECKING
#define GL_CALL(x) \
    clearError();  \
    x;             \
    logCall(__FILE__, __LINE__);
#endif

#ifdef DISABLE_ERROR_CHECKING
#define GL_CALL(x) \
    x;
#endif

static void clearError()
{
    while (glGetError() != GL_NO_ERROR);
}

static bool logCall(const char *file, int line)
{
    while (GLenum error = glGetError())
    {
        std::cout << error << " - " << file << " - " << line << std::endl;
        return false;
    }
    return true;
}
