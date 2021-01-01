#ifndef LEARN_OPENGL_ROTATING_H
#define LEARN_OPENGL_ROTATING_H


#include "DrawableDecorator.h"

namespace gl_lib {

    class Rotating : public DrawableDecorator {
    private:
        float startingAngle;
        float speed;
        glm::vec3 rotationAxis;

    public:
        explicit Rotating(Drawable *, float startingAngle, float speed, glm::vec3 rotationAxis);

        glm::mat4 getModelMatrix() override;

        glm::mat4 getTransformMatrix() override;

        void prepare(Context *) override;

        void initialize(Context *) override;

        void update(Context *) override;
    };
}


#endif //LEARN_OPENGL_ROTATING_H
