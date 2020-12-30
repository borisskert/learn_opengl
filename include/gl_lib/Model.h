#ifndef LEARN_OPENGL_MODEL_H
#define LEARN_OPENGL_MODEL_H


#include "Vertices.h"

namespace gl_lib {

    class Model {
    public:
        virtual Vertices toVertices() = 0;
    };
}


#endif //LEARN_OPENGL_MODEL_H
