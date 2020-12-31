#ifndef LEARN_OPENGL_DRAWABLE_H
#define LEARN_OPENGL_DRAWABLE_H


#include "Shader.h"
#include "Context.h"


namespace gl_lib {

    class Drawable {
    public:
        virtual void prepare(Context *) = 0;

        virtual void initialize(Context *) = 0;

        virtual void update(Context *) = 0;

        virtual void draw(Context *) = 0;
    };
}


#endif //LEARN_OPENGL_DRAWABLE_H
