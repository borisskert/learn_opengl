#ifndef LEARN_OPENGL_CUBE_H
#define LEARN_OPENGL_CUBE_H


#include <glm/vec3.hpp>
#include "Model.h"

namespace gl_lib {

    class Cube : public Model {
    private:
        glm::vec3 a = glm::vec3(-0.5f, -0.5f, 0.5f);
        glm::vec3 b = glm::vec3(0.5f, -0.5f, 0.5f);
        glm::vec3 c = glm::vec3(0.5f, 0.5f, 0.5f);
        glm::vec3 d = glm::vec3(-0.5f, 0.5f, 0.5f);
        glm::vec3 e = glm::vec3(-0.5f, -0.5f, -0.5f);
        glm::vec3 f = glm::vec3(0.5f, -0.5f, -0.5f);
        glm::vec3 g = glm::vec3(0.5f, 0.5f, -0.5f);
        glm::vec3 h = glm::vec3(-0.5f, 0.5f, -0.5f);

        glm::vec3 colorABD = glm::vec3(0.0f);
        glm::vec3 colorADE = glm::vec3(0.0f);
        glm::vec3 colorABE = glm::vec3(0.0f);
        glm::vec3 colorBAC = glm::vec3(0.0f);
        glm::vec3 colorBAF = glm::vec3(0.0f);
        glm::vec3 colorBCF = glm::vec3(0.0f);
        glm::vec3 colorCDB = glm::vec3(0.0f);
        glm::vec3 colorCBG = glm::vec3(0.0f);
        glm::vec3 colorCGD = glm::vec3(0.0f);
        glm::vec3 colorDCA = glm::vec3(0.0f);
        glm::vec3 colorDAH = glm::vec3(0.0f);
        glm::vec3 colorDHC = glm::vec3(0.0f);
        glm::vec3 colorEFA = glm::vec3(0.0f);
        glm::vec3 colorEAH = glm::vec3(0.0f);
        glm::vec3 colorEHF = glm::vec3(0.0f);
        glm::vec3 colorFBG = glm::vec3(0.0f);
        glm::vec3 colorFGE = glm::vec3(0.0f);
        glm::vec3 colorFBE = glm::vec3(0.0f);
        glm::vec3 colorGFC = glm::vec3(0.0f);
        glm::vec3 colorGFH = glm::vec3(0.0f);
        glm::vec3 colorGCH = glm::vec3(0.0f);
        glm::vec3 colorHDG = glm::vec3(0.0f);
        glm::vec3 colorHGE = glm::vec3(0.0f);
        glm::vec3 colorHED = glm::vec3(0.0f);

    public:
        Cube();

        Cube(const Cube &);


        Vertices toVertices() override;


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

        Builder *color(glm::vec3);

        Builder *colorA(glm::vec3);

        Builder *colorB(glm::vec3);

        Builder *colorC(glm::vec3);

        Builder *colorD(glm::vec3);

        Builder *colorE(glm::vec3);

        Builder *colorF(glm::vec3);

        Builder *colorG(glm::vec3);

        Builder *colorH(glm::vec3);

        Builder *colorABCD(glm::vec3);

        Builder *colorEADH(glm::vec3);

        Builder *colorFEHG(glm::vec3);

        Builder *colorBFGC(glm::vec3);

        Builder *colorBAEF(glm::vec3);

        Builder *colorCGHD(glm::vec3);

        Cube build();
    };
}


#endif //LEARN_OPENGL_CUBE_H
