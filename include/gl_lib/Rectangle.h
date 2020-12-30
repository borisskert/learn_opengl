#ifndef LEARN_OPENGL_RECTANGLE_H
#define LEARN_OPENGL_RECTANGLE_H

#include <glm/glm.hpp>
#include "Model.h"


namespace gl_lib {

    class Rectangle : public Model {
    private:
        glm::vec3 a = glm::vec3(-0.5, -0.5, 0.0);
        glm::vec3 b = glm::vec3(0.5, -0.5, 0.0);
        glm::vec3 c = glm::vec3(0.5, 0.5, 0.0);
        glm::vec3 d = glm::vec3(-0.5, 0.5, 0.0);

        glm::vec3 colorA = glm::vec3(1.0f);
        glm::vec3 colorB = glm::vec3(1.0f);
        glm::vec3 colorC = glm::vec3(1.0f);
        glm::vec3 colorD = glm::vec3(1.0f);

    public:
        Rectangle();

        Rectangle(const Rectangle &);


        Vertices toVertices() override;


        class Builder;

        static Rectangle::Builder *builder();
    };


    class Rectangle::Builder {
    private:
        Rectangle rectangle;

    public:
        Builder();

        Rectangle::Builder *positionA(glm::vec3);

        Rectangle::Builder *positionB(glm::vec3);

        Rectangle::Builder *positionC(glm::vec3);

        Rectangle::Builder *positionD(glm::vec3);

        Rectangle::Builder *colorA(glm::vec3);

        Rectangle::Builder *colorB(glm::vec3);

        Rectangle::Builder *colorC(glm::vec3);

        Rectangle::Builder *colorD(glm::vec3);

        Rectangle::Builder *color(glm::vec3);

        Rectangle build();
    };
}


#endif //LEARN_OPENGL_RECTANGLE_H
