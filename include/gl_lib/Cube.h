#ifndef LEARN_OPENGL_CUBE_H
#define LEARN_OPENGL_CUBE_H


#include <glm/vec3.hpp>
#include "Drawable.h"
#include "OpenGlBuffer.h"
#include "TextureUnit.h"
#include "Shader.h"

namespace gl_lib {

    class Cube : public Drawable {
    private:
        glm::vec3 a = glm::vec3(-0.5f, -0.5f, 0.5f);
        glm::vec3 b = glm::vec3(0.5f, -0.5f, 0.5f);
        glm::vec3 c = glm::vec3(0.5f, 0.5f, 0.5f);
        glm::vec3 d = glm::vec3(-0.5f, 0.5f, 0.5f);
        glm::vec3 e = glm::vec3(-0.5f, -0.5f, -0.5f);
        glm::vec3 f = glm::vec3(0.5f, -0.5f, -0.5f);
        glm::vec3 g = glm::vec3(0.5f, 0.5f, -0.5f);
        glm::vec3 h = glm::vec3(-0.5f, 0.5f, -0.5f);

        glm::vec3 colorA = glm::vec3(0.0f);
        glm::vec3 colorB = glm::vec3(0.0f);
        glm::vec3 colorC = glm::vec3(0.0f);
        glm::vec3 colorD = glm::vec3(0.0f);
        glm::vec3 colorE = glm::vec3(0.0f);
        glm::vec3 colorF = glm::vec3(0.0f);
        glm::vec3 colorG = glm::vec3(0.0f);
        glm::vec3 colorH = glm::vec3(0.0f);

        glm::vec3 position = glm::vec3(0.0f);
        float angle = 0.0f;

        void configureVertexArray();

    public:
        Cube();

        Cube(Cube const &);

        void initialize(Context *) override;

        void update(Context *) override;

        void draw(Context *) override;

        class Builder;

        static Cube::Builder *builder();
    };


    class Cube::Builder {
    private:
        Cube cube;

    public:
        Builder();

        Builder *positionA(glm::vec3);

        Builder *positionB(glm::vec3);

        Builder *positionC(glm::vec3);

        Builder *positionD(glm::vec3);

        Builder *positionE(glm::vec3);

        Builder *positionF(glm::vec3);

        Builder *positionG(glm::vec3);

        Builder *positionH(glm::vec3);

        Builder *position(glm::vec3);

        Builder *color(glm::vec3);

        Builder *colorA(glm::vec3);

        Builder *colorB(glm::vec3);

        Builder *colorC(glm::vec3);

        Builder *colorD(glm::vec3);

        Builder *colorE(glm::vec3);

        Builder *colorF(glm::vec3);

        Builder *colorG(glm::vec3);

        Builder *colorH(glm::vec3);

        Builder *angle(float);

        Cube build();
    };
}


#endif //LEARN_OPENGL_CUBE_H
