#include "gl_lib/Cube.h"
#include <glm/gtc/matrix_transform.hpp>


namespace gl_lib {
    Cube::Cube() {}


    Cube::Cube(Cube const &other) {
        this->a = other.a;
        this->b = other.b;
        this->c = other.c;
        this->d = other.d;
        this->e = other.e;
        this->f = other.f;
        this->g = other.g;
        this->h = other.h;

        this->position = other.position;
        this->angle = other.angle;

        this->colorA = other.colorA;
        this->colorB = other.colorB;
        this->colorC = other.colorC;
        this->colorD = other.colorD;
        this->colorE = other.colorE;
        this->colorF = other.colorF;
        this->colorG = other.colorG;
        this->colorH = other.colorH;
    }


    void Cube::configureVertexArray() {
        float vertices[] = {
                a.x, a.y, a.z, colorA.x, colorA.y, colorA.z, 0.0f, 0.0f,
                b.x, b.y, b.z, colorB.x, colorB.y, colorB.z, 1.0f, 0.0f,
                c.x, c.y, c.z, colorC.x, colorC.y, colorC.z, 1.0f, 1.0f,
                c.x, c.y, c.z, colorC.x, colorC.y, colorC.z, 1.0f, 1.0f,
                d.x, d.y, d.z, colorD.x, colorD.y, colorD.z, 0.0f, 1.0f,
                a.x, a.y, a.z, colorA.x, colorA.y, colorA.z, 0.0f, 0.0f,

                e.x, e.y, e.z, colorE.x, colorE.y, colorE.z, 0.0f, 0.0f,
                f.x, f.y, f.z, colorF.x, colorF.y, colorF.z, 1.0f, 0.0f,
                g.x, g.y, g.z, colorG.x, colorG.y, colorG.z, 1.0f, 1.0f,
                g.x, g.y, g.z, colorG.x, colorG.y, colorG.z, 1.0f, 1.0f,
                h.x, h.y, h.z, colorH.x, colorH.y, colorH.z, 0.0f, 1.0f,
                e.x, e.y, e.z, colorE.x, colorE.y, colorE.z, 0.0f, 0.0f,

                h.x, h.y, h.z, colorH.x, colorH.y, colorH.z, 1.0f, 0.0f,
                d.x, d.y, d.z, colorD.x, colorD.y, colorD.z, 1.0f, 1.0f,
                a.x, a.y, a.z, colorA.x, colorA.y, colorA.z, 0.0f, 1.0f,
                a.x, a.y, a.z, colorA.x, colorA.y, colorA.z, 0.0f, 1.0f,
                e.x, e.y, e.z, colorE.x, colorE.y, colorE.z, 0.0f, 0.0f,
                h.x, h.y, h.z, colorH.x, colorH.y, colorH.z, 1.0f, 0.0f,

                g.x, g.y, g.z, colorG.x, colorG.y, colorG.z, 1.0f, 0.0f,
                c.x, c.y, c.z, colorC.x, colorC.y, colorC.z, 1.0f, 1.0f,
                b.x, b.y, b.z, colorB.x, colorB.y, colorB.z, 0.0f, 1.0f,
                b.x, b.y, b.z, colorB.x, colorB.y, colorB.z, 0.0f, 1.0f,
                f.x, f.y, f.z, colorF.x, colorF.y, colorF.z, 0.0f, 0.0f,
                g.x, g.y, g.z, colorG.x, colorG.y, colorG.z, 1.0f, 0.0f,

                a.x, a.y, a.z, colorA.x, colorA.y, colorA.z, 0.0f, 1.0f,
                b.x, b.y, b.z, colorB.x, colorB.y, colorB.z, 1.0f, 1.0f,
                f.x, f.y, f.z, colorF.x, colorF.y, colorF.z, 1.0f, 0.0f,
                f.x, f.y, f.z, colorF.x, colorF.y, colorF.z, 1.0f, 0.0f,
                e.x, e.y, e.z, colorE.x, colorE.y, colorE.z, 0.0f, 0.0f,
                a.x, a.y, a.z, colorA.x, colorA.y, colorA.z, 0.0f, 1.0f,

                d.x, d.y, d.z, colorD.x, colorD.y, colorD.z, 0.0f, 1.0f,
                c.x, c.y, c.z, colorC.x, colorC.y, colorC.z, 1.0f, 1.0f,
                g.x, g.y, g.z, colorG.x, colorG.y, colorG.z, 1.0f, 0.0f,
                g.x, g.y, g.z, colorG.x, colorG.y, colorG.z, 1.0f, 0.0f,
                h.x, h.y, h.z, colorH.x, colorH.y, colorH.z, 0.0f, 0.0f,
                d.x, d.y, d.z, colorD.x, colorD.y, colorD.z, 0.0f, 1.0f
        };

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) 0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (6 * sizeof(float)));
        glEnableVertexAttribArray(2);
    }


    void Cube::initialize(Context *context) {
        context->buffer->initialize();

        context->buffer->bindVertexArray();
        this->configureVertexArray();

        context->textures->initialize();

        Shader *shader = context->shader;
        shader->setInt("texture1", 0);
        shader->setInt("texture2", 1);
    }


    void Cube::update(Context *context) {
        Shader *shader = context->shader;

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, position);
        model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

        model = glm::rotate(model, (float) glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
        shader->setMat4("model", model);

        glm::mat4 trans = glm::mat4(1.0f);
        double time = glfwGetTime();
        trans = glm::translate(trans, glm::vec3(glm::cos(time), glm::sin(time), 0.0f));
        trans = glm::rotate(trans, (float) time, glm::vec3(0.0f, 0.0f, 1.0f));

        shader->setMat4("transform", trans);
    }


    void Cube::draw(Context *context) {
        context->textures->bindTextures();
        context->buffer->bindVertexArray();
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }


    Cube::Builder* Cube::builder() {
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

    Cube::Builder *Cube::Builder::position(glm::vec3 value) {
        cube.position = value;
        return this;
    }

    Cube::Builder *Cube::Builder::color(glm::vec3 value) {
        cube.colorA = value;
        cube.colorB = value;
        cube.colorC = value;
        cube.colorD = value;
        cube.colorE = value;
        cube.colorF = value;
        cube.colorG = value;
        cube.colorH = value;

        return this;
    }

    Cube::Builder *Cube::Builder::colorA(glm::vec3 value) {
        cube.colorA = value;
        return this;
    }

    Cube::Builder *Cube::Builder::colorB(glm::vec3 value) {
        cube.colorB = value;
        return this;
    }

    Cube::Builder *Cube::Builder::colorC(glm::vec3 value) {
        cube.colorC = value;
        return this;
    }

    Cube::Builder *Cube::Builder::colorD(glm::vec3 value) {
        cube.colorD = value;
        return this;
    }

    Cube::Builder *Cube::Builder::colorE(glm::vec3 value) {
        cube.colorE = value;
        return this;
    }

    Cube::Builder *Cube::Builder::colorF(glm::vec3 value) {
        cube.colorF = value;
        return this;
    }

    Cube::Builder *Cube::Builder::colorG(glm::vec3 value) {
        cube.colorG = value;
        return this;
    }

    Cube::Builder *Cube::Builder::colorH(glm::vec3 value) {
        cube.colorH = value;
        return this;
    }

    Cube::Builder *Cube::Builder::angle(float value) {
        cube.angle = value;
        return this;
    }


    Cube Cube::Builder::build() {
        return cube;
    }
}
