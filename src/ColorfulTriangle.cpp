#include "glm/glm.hpp"
#include <gl_lib/gl_lib.h>
#include <gl_lib/ColorfulTriangle.h>

namespace gl_lib {

    void ColorfulTriangle::configureVertexArray() {
        float vertices[] = {
                positionA.x, positionA.y, positionA.z,
                colorA.x, colorA.y, colorA.z,
                positionB.x, positionB.y, positionB.z,
                colorB.x, colorB.y, colorB.z,
                positionC.x, positionC.y, positionC.z,
                colorC.x, colorC.y, colorC.z,
        };

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
        glEnableVertexAttribArray(1);
    }

    void ColorfulTriangle::configureElementBuffer() {
        unsigned int indices[] = {
                0, 1, 2
        };

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    }

    unsigned int ColorfulTriangle::getIndicesCount() {
        return 3;
    }

    ColorfulTriangle::ColorfulTriangle(
            glm::vec3 positionA, glm::vec3 positionB, glm::vec3 positionC,
            glm::vec3 colorA, glm::vec3 colorB, glm::vec3 colorC)
            : positionA(positionA), positionB(positionB), positionC(positionC),
              colorA(colorA), colorB(colorB), colorC(colorC) {}


    void ColorfulTriangle::initialize(Shader*) {
        buffer.initialize();

        this->buffer.bindVertexArray();
        this->configureVertexArray();

        this->buffer.bindElementBuffer();
        this->configureElementBuffer();
    }


    void ColorfulTriangle::update(Shader*) {

    }


    void ColorfulTriangle::draw() {
        buffer.bindVertexArray();
        glDrawElements(GL_TRIANGLES, this->getIndicesCount(), GL_UNSIGNED_INT, nullptr);
    }
}
