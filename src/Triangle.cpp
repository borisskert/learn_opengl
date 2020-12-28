#include "glm/glm.hpp"
#include <gl_lib/gl_lib.h>
#include <gl_lib/Triangle.h>


namespace gl_lib {

    void Triangle::configureVertexArray() {
        float vertices[] = {
                a.x, a.y, a.z,
                b.x, b.y, b.z,
                c.x, c.y, c.z,
        };

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
        glEnableVertexAttribArray(0);
    }

    void Triangle::configureElementBuffer() {
        unsigned int indices[] = {
                0, 1, 2
        };

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    }

    unsigned int Triangle::getIndicesCount() {
        return 3;
    }


    Triangle::Triangle(glm::vec3 a, glm::vec3 b, glm::vec3 c)
            : a(a), b(b), c(c) {}


    void Triangle::initialize(Shader*) {
        buffer.initialize();

        this->buffer.bindVertexArray();
        this->configureVertexArray();

        this->buffer.bindElementBuffer();
        this->configureElementBuffer();
    }


    void Triangle::update(Shader*) {

    }


    void Triangle::draw() {
        buffer.bindVertexArray();
        glDrawElements(GL_TRIANGLES, this->getIndicesCount(), GL_UNSIGNED_INT, nullptr);
    }
}