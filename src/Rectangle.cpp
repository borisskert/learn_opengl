#include <gl_lib/Rectangle.h>
#include <gl_lib/Triangle.h>


namespace gl_lib {

    Rectangle::Rectangle() = default;

    Rectangle::Rectangle(const Rectangle &other) {
        this->a = other.a;
        this->b = other.b;
        this->c = other.c;
        this->d = other.d;

        this->colorA = other.colorA;
        this->colorB = other.colorB;
        this->colorC = other.colorC;
        this->colorD = other.colorD;
    }


    Vertices Rectangle::toVertices() {
        Triangle abd = Triangle::builder()
                ->positionA(a)
                ->positionB(b)
                ->positionC(d)
                ->build();

        Triangle bcd = Triangle::builder()
                ->positionA(b)
                ->positionB(c)
                ->positionC(d)
                ->build();

        const glm::vec3 &abdNormal = abd.normal();
        const glm::vec3 &bcdNormal = bcd.normal();

        float vertices[] = {
                a.x, a.y, a.z, colorA.x, colorA.y, colorA.z, 0.0f, 0.0f, abdNormal.x, abdNormal.y, abdNormal.z,
                b.x, b.y, b.z, colorB.x, colorB.y, colorB.z, 1.0f, 0.0f, abdNormal.x, abdNormal.y, abdNormal.z,
                c.x, c.y, c.z, colorC.x, colorC.y, colorC.z, 1.0f, 1.0f, abdNormal.x, abdNormal.y, abdNormal.z,
                c.x, c.y, c.z, colorC.x, colorC.y, colorC.z, 1.0f, 1.0f, bcdNormal.x, bcdNormal.y, bcdNormal.z,
                d.x, d.y, d.z, colorD.x, colorD.y, colorD.z, 0.0f, 1.0f, bcdNormal.x, bcdNormal.y, bcdNormal.z,
                a.x, a.y, a.z, colorA.x, colorA.y, colorA.z, 0.0f, 0.0f, bcdNormal.x, bcdNormal.y, bcdNormal.z,
        };

        return Vertices(6 * 11, vertices);
    }


    Rectangle::Builder *Rectangle::builder() {
        return new Builder();
    }


    Rectangle::Builder::Builder() = default;


    Rectangle::Builder *Rectangle::Builder::positionA(glm::vec3 value) {
        rectangle.a = value;
        return this;
    }

    Rectangle::Builder *Rectangle::Builder::positionB(glm::vec3 value) {
        rectangle.b = value;
        return this;
    }

    Rectangle::Builder *Rectangle::Builder::positionC(glm::vec3 value) {
        rectangle.c = value;
        return this;
    }

    Rectangle::Builder *Rectangle::Builder::positionD(glm::vec3 value) {
        rectangle.d = value;
        return this;
    }

    Rectangle::Builder *Rectangle::Builder::colorA(glm::vec3 value) {
        rectangle.colorA = value;
        return this;
    }

    Rectangle::Builder *Rectangle::Builder::colorB(glm::vec3 value) {
        rectangle.colorB = value;
        return this;
    }

    Rectangle::Builder *Rectangle::Builder::colorC(glm::vec3 value) {
        rectangle.colorC = value;
        return this;
    }

    Rectangle::Builder *Rectangle::Builder::colorD(glm::vec3 value) {
        rectangle.colorD = value;
        return this;
    }

    Rectangle::Builder *Rectangle::Builder::color(glm::vec3 value) {
        rectangle.colorA = value;
        rectangle.colorB = value;
        rectangle.colorC = value;
        rectangle.colorD = value;

        return this;
    }


    Rectangle Rectangle::Builder::build() {
        return rectangle;
    }
}
