#ifndef LEARN_OPENGL_CONTEXT_H
#define LEARN_OPENGL_CONTEXT_H

#include "OpenGlBuffer.h"
#include "Shader.h"

namespace gl_lib {

    struct Context {
        Shader *shader;
        OpenGlBuffer *buffer;
    };
}


#endif //LEARN_OPENGL_CONTEXT_H
