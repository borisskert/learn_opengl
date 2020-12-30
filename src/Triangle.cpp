#include "glm/glm.hpp"
#include <gl_lib/gl_lib.h>
#include <gl_lib/Triangle.h>


namespace gl_lib {

    Triangle::Triangle() = default;

    Triangle::Triangle(const Triangle &other) {
        this->a = other.a;
        this->b = other.b;
        this->c = other.c;

        this->colorA = other.colorA;
        this->colorB = other.colorB;
        this->colorC = other.colorC;
    }


    glm::vec3 Triangle::getA() {
        return a;
    }

    glm::vec3 Triangle::getB() {
        return b;
    }

    glm::vec3 Triangle::getC() {
        return c;
    }

    glm::vec3 Triangle::getColorA() {
        return colorA;
    }

    glm::vec3 Triangle::getColorB() {
        return colorB;
    }

    glm::vec3 Triangle::getColorC() {
        return colorC;
    }

    glm::vec3 Triangle::normal() {
        glm::vec3 ab = b - a;
        glm::vec3 ca = a - c;

        glm::vec3 cross = glm::cross(ab, ca);

        return glm::normalize(cross);
    }


    Vertices Triangle::toVertices() {
        glm::vec3 normal = this->normal();

        float vertices[] = {
                a.x, a.y, a.z, colorA.x, colorA.y, colorA.z, 0.0f, 0.0f, normal.x, normal.y, normal.z,
                b.x, b.y, b.z, colorB.x, colorB.y, colorB.z, 1.0f, 0.0f, normal.x, normal.y, normal.z,
                c.x, c.y, c.z, colorC.x, colorC.y, colorC.z, 1.0f, 1.0f, normal.x, normal.y, normal.z
        };

        return Vertices(11 * 3, vertices);
    };


    Triangle::Builder *Triangle::builder() {
        return new Builder();
    }

    Triangle::Builder::Builder() = default;

    Triangle::Builder *Triangle::Builder::positionA(glm::vec3 value) {
        this->triangle.a = value;
        return this;
    }

    Triangle::Builder *Triangle::Builder::positionB(glm::vec3 value) {
        this->triangle.b = value;
        return this;
    }

    Triangle::Builder *Triangle::Builder::positionC(glm::vec3 value) {
        this->triangle.c = value;
        return this;
    }

    Triangle::Builder *Triangle::Builder::colorA(glm::vec3 value) {
        this->triangle.colorA = value;
        return this;
    }

    Triangle::Builder *Triangle::Builder::colorB(glm::vec3 value) {
        this->triangle.colorB = value;
        return this;
    }

    Triangle::Builder *Triangle::Builder::colorC(glm::vec3 value) {
        this->triangle.colorC = value;
        return this;
    }

    Triangle::Builder *Triangle::Builder::color(glm::vec3 value) {
        this->triangle.colorA = value;
        this->triangle.colorB = value;
        this->triangle.colorC = value;

        return this;
    }

    Triangle Triangle::Builder::build() {
        return triangle;
    }
}
