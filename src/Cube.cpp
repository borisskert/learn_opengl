#include "gl_lib/Cube.h"
#include <glm/gtc/matrix_transform.hpp>


namespace gl_lib {
    Cube::Cube(
            glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 d,
            glm::vec3 e, glm::vec3 f, glm::vec3 g, glm::vec3 h,
            TextureUnit texture
    )
            : a(a), b(b), c(c), d(d),
              e(e), f(f), g(g), h(h),
              colorA(glm::vec3()), colorB(glm::vec3()), colorC(glm::vec3()), colorD(glm::vec3()),
              colorE(glm::vec3()), colorF(glm::vec3()), colorG(glm::vec3()), colorH(glm::vec3()),
              texture(texture) {}

    Cube::Cube(TextureUnit texture)
            : a(glm::vec3(-0.5f, -0.5f, -0.5f)), b(glm::vec3(0.5f, -0.5f, -0.5f)), c(glm::vec3(0.5f, 0.5f, -0.5f)),
              d(glm::vec3(-0.5f, 0.5f, -0.5f)),
              e(glm::vec3(-0.5f, -0.5f, 0.5f)), f(glm::vec3(0.5f, -0.5f, 0.5f)), g(glm::vec3(0.5f, 0.5f, 0.5f)),
              h(glm::vec3(-0.5f, 0.5f, 0.5f)),
              colorA(glm::vec3(1.0f)), colorB(glm::vec3(1.0f)), colorC(glm::vec3(1.0f)), colorD(glm::vec3(1.0f)),
              colorE(glm::vec3(1.0f)), colorF(glm::vec3(1.0f)), colorG(glm::vec3(1.0f)), colorH(glm::vec3(1.0f)),
              texture(texture) {}


    Cube::Cube(glm::vec3 color, TextureUnit texture)
            : a(glm::vec3(-0.5f, -0.5f, -0.5f)), b(glm::vec3(0.5f, -0.5f, -0.5f)), c(glm::vec3(0.5f, 0.5f, -0.5f)),
              d(glm::vec3(-0.5f, 0.5f, -0.5f)),
              e(glm::vec3(-0.5f, -0.5f, 0.5f)), f(glm::vec3(0.5f, -0.5f, 0.5f)), g(glm::vec3(0.5f, 0.5f, 0.5f)),
              h(glm::vec3(-0.5f, 0.5f, 0.5f)),
              colorA(color), colorB(color), colorC(color), colorD(color),
              colorE(color), colorF(color), colorG(color), colorH(color),
              texture(texture) {}


    Cube::Cube(
            glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 d,
            glm::vec3 e, glm::vec3 f, glm::vec3 g, glm::vec3 h,
            glm::vec3 color,
            TextureUnit texture
    )
            : a(a), b(b), c(c), d(d),
              e(e), f(f), g(g), h(h),
              colorA(color), colorB(color), colorC(color), colorD(color),
              colorE(color), colorF(color), colorG(color), colorH(color),
              texture(texture) {}


    Cube::Cube(
            glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 d,
            glm::vec3 e, glm::vec3 f, glm::vec3 g, glm::vec3 h,
            glm::vec3 colorA, glm::vec3 colorB, glm::vec3 colorC, glm::vec3 colorD,
            glm::vec3 colorE, glm::vec3 colorF, glm::vec3 colorG, glm::vec3 colorH,
            glm::vec3 position,
            float angle,
            TextureUnit texture
    )
            : a(a), b(b), c(c), d(d),
              e(e), f(f), g(g), h(h),
              colorA(colorA), colorB(colorB), colorC(colorC), colorD(colorD),
              colorE(colorE), colorF(colorF), colorG(colorG), colorH(colorH),
              position(position),
              angle(angle),
              texture(texture) {}


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


    void Cube::initialize(Shader * shader) {
        buffer.initialize();

        this->buffer.bindVertexArray();
        this->configureVertexArray();

        this->texture.initialize();


        shader->setInt("texture1", 0);
        shader->setInt("texture2", 1);
    }


    void Cube::update(Shader* shader) {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, position);
        model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

        model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
        shader->setMat4("model", model);

        glm::mat4 trans = glm::mat4(1.0f);
        double time = glfwGetTime();
        trans = glm::translate(trans, glm::vec3(glm::cos(time), glm::sin(time), 0.0f));
        trans = glm::rotate(trans, (float) time, glm::vec3(0.0f, 0.0f, 1.0f));

        shader->setMat4("transform", trans);
    }


    void Cube::draw() {
        this->texture.bindTextures();
        buffer.bindVertexArray();
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
}
