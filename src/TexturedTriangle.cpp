#include "gl_lib/TexturedTriangle.h"

namespace gl_lib {

    void TexturedTriangle::configureVertexArray() {
        float vertices[] = {
                positionA.x, positionA.y, positionA.z,
                colorA.x, colorA.y, colorA.z,
                1.0f, 1.0f,
                positionB.x, positionB.y, positionB.z,
                colorB.x, colorB.y, colorB.z,
                1.0f, 0.0f,
                positionC.x, positionC.y, positionC.z,
                colorC.x, colorC.y, colorC.z,
                0.0f, 1.0f
        };

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) 0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (6 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (6 * sizeof(float)));
        glEnableVertexAttribArray(2);
    }


    void TexturedTriangle::configureElementBuffer() {
        unsigned int indices[] = {
                0, 1, 2
        };

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    }


    unsigned int TexturedTriangle::getIndicesCount() {
        return 3;
    }


    TexturedTriangle::TexturedTriangle(
            glm::vec3 positionA, glm::vec3 positionB, glm::vec3 positionC,
            glm::vec3 colorA, glm::vec3 colorB, glm::vec3 colorC, TextureUnit texture
    )
            : positionA(positionA), positionB(positionB), positionC(positionC),
              colorA(colorA), colorB(colorB), colorC(colorC), texture(texture) {}


    void TexturedTriangle::initialize(Shader*) {
        buffer.initialize();

        this->buffer.bindVertexArray();
        this->configureVertexArray();

        this->buffer.bindElementBuffer();
        this->configureElementBuffer();

        this->texture.initialize();
    }


    void TexturedTriangle::update(Shader*) {

    }


    void TexturedTriangle::draw() {
        this->texture.bindTextures();
        this->buffer.bindVertexArray();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    }
}
