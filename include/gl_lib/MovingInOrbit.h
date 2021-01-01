#ifndef LEARN_OPENGL_MOVINGINORBIT_H
#define LEARN_OPENGL_MOVINGINORBIT_H


#include "DrawableDecorator.h"

namespace gl_lib {

    class MovingInOrbit : public DrawableDecorator {
    private:
        float speed;
        glm::vec2 radius;
        glm::vec3 centre;
        float angle;

        glm::mat4 rotateOrbit(const glm::mat4 &model) const;

    public:
        explicit MovingInOrbit(Drawable *, float speed, glm::vec2 radius, glm::vec3 centre, float angle);

        glm::mat4 getTransformMatrix() override;

        void prepare(Context *) override;

        void initialize(Context *) override;

        void update(Context *) override;

        glm::vec3 getRotation(glm::vec3 &radius3) const;
    };
}


#endif //LEARN_OPENGL_MOVINGINORBIT_H
