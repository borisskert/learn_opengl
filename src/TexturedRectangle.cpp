#include "gl_lib/TexturedRectangle.h"

namespace gl_lib {

    TexturedRectangle::TexturedRectangle(
            const glm::vec3 a, const glm::vec3 b, const glm::vec3 c, const glm::vec3 d,
            const glm::vec3 colorA, const glm::vec3 colorB, const glm::vec3 colorC, const glm::vec3 colorD,
            Texture texture
    ) : a(a), b(b), c(c), d(d),
        colorA(colorA), colorB(colorB), colorC(colorC), colorD(colorD),
        texture(texture) {}


    void TexturedRectangle::configureVertexArray() {
        float vertices[] = {
                a.x, a.y, a.z,
                colorA.x, colorA.y, colorA.z,
                1.0f, 1.0f,
                b.x, b.y, b.z,
                colorB.x, colorB.y, colorB.z,
                1.0f, 0.0f,
                c.x, c.y, c.z,
                colorC.x, colorC.y, colorC.z,
                0.0f, 0.0f,
                d.x, d.y, d.z,
                colorD.x, colorD.y, colorD.z,
                0.0f, 1.0f
        };

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) 0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (6 * sizeof(float)));
        glEnableVertexAttribArray(2);
    }


    void TexturedRectangle::configureElementBuffer() {
        unsigned int indices[] = {
                0, 1, 3,
                1, 2, 3,
        };

        glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                     sizeof(indices), indices, GL_STATIC_DRAW);
    }


    void TexturedRectangle::initialize() {
        buffer.initialize();

        this->buffer.bindVertexArray();
        this->configureVertexArray();

        this->buffer.bindElementBuffer();
        this->configureElementBuffer();

        this->texture.initialize();
    }


    void TexturedRectangle::draw() {
        glBindTexture(GL_TEXTURE_2D, texture.getId());
        this->buffer.bindVertexArray();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    }
}
