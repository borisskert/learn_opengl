#include <gl_lib/Rectangle.h>
#include "gl_lib/Cube.h"


namespace gl_lib {

    Cube::Cube() = default;


    Cube::Cube(const Cube &other) {
        this->a = other.a;
        this->b = other.b;
        this->c = other.c;
        this->d = other.d;
        this->e = other.e;
        this->f = other.f;
        this->g = other.g;
        this->h = other.h;

        this->colorABD = other.colorABD;
        this->colorADE = other.colorADE;
        this->colorABE = other.colorABE;
        this->colorBAC = other.colorBAC;
        this->colorBAF = other.colorBAF;
        this->colorBCF = other.colorBCF;
        this->colorCDB = other.colorCDB;
        this->colorCBG = other.colorCBG;
        this->colorCGD = other.colorCGD;
        this->colorDCA = other.colorDCA;
        this->colorDAH = other.colorDAH;
        this->colorDHC = other.colorDHC;
        this->colorEFA = other.colorEFA;
        this->colorEAH = other.colorEAH;
        this->colorEHF = other.colorEHF;
        this->colorFBG = other.colorFBG;
        this->colorFGE = other.colorFGE;
        this->colorFBE = other.colorFBE;
        this->colorGFC = other.colorGFC;
        this->colorGFH = other.colorGFH;
        this->colorGCH = other.colorGCH;
        this->colorHDG = other.colorHDG;
        this->colorHGE = other.colorHGE;
        this->colorHED = other.colorHED;
    }


    Vertices Cube::toVertices() {
        Rectangle adcb = Rectangle::builder()
                ->positionA(a)
                ->positionB(d)
                ->positionC(c)
                ->positionD(b)
                ->colorA(colorABD)
                ->colorB(colorBAC)
                ->colorC(colorCDB)
                ->colorD(colorDCA)
                ->build();

        Rectangle fghe = Rectangle::builder()
                ->positionA(f)
                ->positionB(g)
                ->positionC(h)
                ->positionD(e)
                ->colorA(colorFGE)
                ->colorB(colorGFH)
                ->colorC(colorHGE)
                ->colorD(colorEHF)
                ->build();

        Rectangle ehda = Rectangle::builder()
                ->positionA(e)
                ->positionB(h)
                ->positionC(d)
                ->positionD(a)
                ->colorA(colorEAH)
                ->colorB(colorHED)
                ->colorC(colorDAH)
                ->colorD(colorADE)
                ->build();

        Rectangle bcgf = Rectangle::builder()
                ->positionA(b)
                ->positionB(c)
                ->positionC(g)
                ->positionD(f)
                ->colorA(colorBCF)
                ->colorB(colorCBG)
                ->colorC(colorGFC)
                ->colorD(colorFBG)
                ->build();

        Rectangle eabf = Rectangle::builder()
                ->positionA(e)
                ->positionB(a)
                ->positionC(b)
                ->positionD(f)
                ->colorA(colorEFA)
                ->colorB(colorABE)
                ->colorC(colorBAF)
                ->colorD(colorFBE)
                ->build();

        Rectangle dhgc = Rectangle::builder()
                ->positionA(d)
                ->positionB(h)
                ->positionC(g)
                ->positionD(c)
                ->colorA(colorDHC)
                ->colorB(colorHDG)
                ->colorC(colorGCH)
                ->colorD(colorCGD)
                ->build();

        return adcb.toVertices()
               + fghe.toVertices()
               + ehda.toVertices()
               + bcgf.toVertices()
               + eabf.toVertices()
               + dhgc.toVertices();
    }

    Cube::Builder *Cube::builder() {
        return new Builder();
    }


    Cube::Builder::Builder() = default;


    Cube::Builder *Cube::Builder::positionA(glm::vec3 value) {
        cube.a = value;
        return this;
    }

    Cube::Builder *Cube::Builder::positionB(glm::vec3 value) {
        cube.b = value;
        return this;
    }

    Cube::Builder *Cube::Builder::positionC(glm::vec3 value) {
        cube.c = value;
        return this;
    }

    Cube::Builder *Cube::Builder::positionD(glm::vec3 value) {
        cube.d = value;
        return this;
    }

    Cube::Builder *Cube::Builder::positionE(glm::vec3 value) {
        cube.e = value;
        return this;
    }

    Cube::Builder *Cube::Builder::positionF(glm::vec3 value) {
        cube.f = value;
        return this;
    }

    Cube::Builder *Cube::Builder::positionG(glm::vec3 value) {
        cube.g = value;
        return this;
    }

    Cube::Builder *Cube::Builder::positionH(glm::vec3 value) {
        cube.h = value;
        return this;
    }

    Cube::Builder *Cube::Builder::color(glm::vec3 value) {
        cube.colorABD = value;
        cube.colorADE = value;
        cube.colorABE = value;
        cube.colorBAC = value;
        cube.colorBAF = value;
        cube.colorBCF = value;
        cube.colorCDB = value;
        cube.colorCBG = value;
        cube.colorCGD = value;
        cube.colorDCA = value;
        cube.colorDAH = value;
        cube.colorDHC = value;
        cube.colorEFA = value;
        cube.colorEAH = value;
        cube.colorEHF = value;
        cube.colorFBG = value;
        cube.colorFGE = value;
        cube.colorFBE = value;
        cube.colorGFC = value;
        cube.colorGFH = value;
        cube.colorGCH = value;
        cube.colorHDG = value;
        cube.colorHGE = value;
        cube.colorHED = value;

        return this;
    }

    Cube::Builder *Cube::Builder::colorA(glm::vec3 value) {
        cube.colorABD = value;
        cube.colorADE = value;
        cube.colorABE = value;

        return this;
    }

    Cube::Builder *Cube::Builder::colorB(glm::vec3 value) {
        cube.colorBAC = value;
        cube.colorBAF = value;
        cube.colorBCF = value;

        return this;
    }

    Cube::Builder *Cube::Builder::colorC(glm::vec3 value) {
        cube.colorCDB = value;
        cube.colorCBG = value;
        cube.colorCGD = value;

        return this;
    }

    Cube::Builder *Cube::Builder::colorD(glm::vec3 value) {
        cube.colorDCA = value;
        cube.colorDAH = value;
        cube.colorDHC = value;

        return this;
    }

    Cube::Builder *Cube::Builder::colorE(glm::vec3 value) {
        cube.colorEFA = value;
        cube.colorEAH = value;
        cube.colorEHF = value;

        return this;
    }

    Cube::Builder *Cube::Builder::colorF(glm::vec3 value) {
        cube.colorFBG = value;
        cube.colorFGE = value;
        cube.colorFBE = value;

        return this;
    }

    Cube::Builder *Cube::Builder::colorG(glm::vec3 value) {
        cube.colorGFC = value;
        cube.colorGFH = value;
        cube.colorGCH = value;

        return this;
    }

    Cube::Builder *Cube::Builder::colorH(glm::vec3 value) {
        cube.colorHDG = value;
        cube.colorHGE = value;
        cube.colorHED = value;

        return this;
    }


    Cube Cube::Builder::build() {
        return cube;
    }

    Cube::Builder *Cube::Builder::colorABCD(glm::vec3 value) {
        cube.colorABD = value;
        cube.colorBAC = value;
        cube.colorCDB = value;
        cube.colorDCA = value;

        return this;
    }

    Cube::Builder *Cube::Builder::colorEADH(glm::vec3 value) {
        cube.colorEAH = value;
        cube.colorADE = value;
        cube.colorDAH = value;
        cube.colorHED = value;

        return this;
    }

    Cube::Builder *Cube::Builder::colorFEHG(glm::vec3 value) {
        cube.colorFGE = value;
        cube.colorEHF = value;
        cube.colorHGE = value;
        cube.colorGFH = value;

        return this;
    }

    Cube::Builder *Cube::Builder::colorBFGC(glm::vec3 value) {
        cube.colorBCF = value;
        cube.colorFBG = value;
        cube.colorGFC = value;
        cube.colorCBG = value;

        return this;
    }

    Cube::Builder *Cube::Builder::colorBAEF(glm::vec3 value) {
        cube.colorBAF = value;
        cube.colorABE = value;
        cube.colorEFA = value;
        cube.colorFBE = value;

        return this;
    }

    Cube::Builder *Cube::Builder::colorCGHD(glm::vec3 value) {
        cube.colorCGD = value;
        cube.colorGCH = value;
        cube.colorHDG = value;
        cube.colorDHC = value;

        return this;
    }
}
