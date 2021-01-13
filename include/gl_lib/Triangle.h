#ifndef LEARN_OPENGL_TRIANGLE_H
#define LEARN_OPENGL_TRIANGLE_H

#include <vector>
#include "glm/glm.hpp"
#include "Model.h"
#include "FileTexture.h"


namespace gl_lib {

    class Triangle : public Model {
    private:
        glm::vec3 a = glm::vec3(-0.5, -0.5, 0.0f);
        glm::vec3 b = glm::vec3(0.5, -0.5, 0.0f);
        glm::vec3 c = glm::vec3(0.0, 0.5, 0.0f);

        glm::vec3 colorA = glm::vec3(1.0f);
        glm::vec3 colorB = glm::vec3(1.0f);
        glm::vec3 colorC = glm::vec3(1.0f);

    public:
        Triangle();

        Triangle(const Triangle &);

        glm::vec3 getA();

        glm::vec3 getB();

        glm::vec3 getC();

        glm::vec3 getColorA();

        glm::vec3 getColorB();

        glm::vec3 getColorC();

        glm::vec3 normal();

        Vertices toVertices() override;

        class Builder;

        static Triangle::Builder *builder();
    };

    class Triangle::Builder {
    private:
        Triangle triangle;

    public:
        Builder();

        Triangle::Builder *positionA(glm::vec3);

        Triangle::Builder *positionB(glm::vec3);

        Triangle::Builder *positionC(glm::vec3);

        Triangle::Builder *colorA(glm::vec3);

        Triangle::Builder *colorB(glm::vec3);

        Triangle::Builder *colorC(glm::vec3);

        Triangle::Builder *color(glm::vec3);

        Triangle::Builder *addTexture(FileTexture *texture);

        Triangle build();
    };
}


#endif //LEARN_OPENGL_TRIANGLE_H
