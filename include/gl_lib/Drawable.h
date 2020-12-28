#ifndef LEARN_OPENGL_DRAWABLE_H
#define LEARN_OPENGL_DRAWABLE_H


#include "Shader.h"

namespace gl_lib {

    class Drawable {
    public:
        virtual void initialize(Shader*) = 0;

        virtual void update(Shader*) = 0;

        virtual void draw() = 0;
    };
}


#endif //LEARN_OPENGL_DRAWABLE_H
