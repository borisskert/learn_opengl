#ifndef LEARN_OPENGL_DRAWABLE_H
#define LEARN_OPENGL_DRAWABLE_H


#include "Shader.h"
#include "Context.h"


namespace gl_lib {

    class Drawable {
    public:
        virtual glm::vec3 getModelPosition() = 0;

        virtual glm::mat4 getModelMatrix() = 0;

        virtual glm::mat4 getTransformMatrix() = 0;

        virtual void prepare(Context *) = 0;

        virtual void initialize(Context *) = 0;

        virtual void update(Context *) = 0;

        virtual void draw(Context *) = 0;
    };
}


#endif //LEARN_OPENGL_DRAWABLE_H
