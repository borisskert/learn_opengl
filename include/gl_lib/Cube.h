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
        glm::vec3 a;
        glm::vec3 b;
        glm::vec3 c;
        glm::vec3 d;
        glm::vec3 e;
        glm::vec3 f;
        glm::vec3 g;
        glm::vec3 h;

        const glm::vec3 colorA;
        const glm::vec3 colorB;
        const glm::vec3 colorC;
        const glm::vec3 colorD;
        const glm::vec3 colorE;
        const glm::vec3 colorF;
        const glm::vec3 colorG;
        const glm::vec3 colorH;

        glm::vec3 position;
        float angle;

        void configureVertexArray();

    public:
        Cube();


        Cube(
                glm::vec3 color
        );


        Cube(
                glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 d,
                glm::vec3 e, glm::vec3 f, glm::vec3 g, glm::vec3 h
        );


        Cube(
                glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 d,
                glm::vec3 e, glm::vec3 f, glm::vec3 g, glm::vec3 h,
                glm::vec3 color
        );


        Cube(
                glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 d,
                glm::vec3 e, glm::vec3 f, glm::vec3 g, glm::vec3 h,
                glm::vec3 color,
                glm::vec3 position,
                float angle
        );


        Cube(
                glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 d,
                glm::vec3 e, glm::vec3 f, glm::vec3 g, glm::vec3 h,
                glm::vec3 colorA, glm::vec3 colorB, glm::vec3 colorC, glm::vec3 colorD,
                glm::vec3 colorE, glm::vec3 colorF, glm::vec3 colorG, glm::vec3 colorH,
                glm::vec3 position,
                float angle
        );

        void initialize(Context *) override;

        void update(Context *) override;

        void draw(Context *) override;
    };
}


#endif //LEARN_OPENGL_CUBE_H
