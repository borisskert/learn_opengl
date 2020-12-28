#include <glm/glm.hpp>
#include <gl_lib/gl_lib.h>
#include <gl_lib/Rectangle.h>


namespace gl_lib {


    void Rectangle::configureVertexArray() {
        float vertices[] = {
                a.x, a.y, a.z,
                b.x, b.y, b.z,
                c.x, c.y, c.z,
                d.x, d.y, d.z,
        };

        glBufferData(GL_ARRAY_BUFFER,
                     sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
        glEnableVertexAttribArray(0);
    }


    void Rectangle::configureElementBuffer() {
        unsigned int indices[] = {
                0, 1, 3,
                1, 2, 3,
        };

        glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                     sizeof(indices), indices, GL_STATIC_DRAW);
    }


    unsigned int Rectangle::getIndicesCount() {
        return 6;
    }


    Rectangle::Rectangle(const glm::vec3 a, const glm::vec3 b, const glm::vec3 c, const glm::vec3 d)
            : a(a), b(b), c(c), d(d) {}


    void Rectangle::initialize(Shader*) {
        buffer.initialize();

        this->buffer.bindVertexArray();
        this->configureVertexArray();

        this->buffer.bindElementBuffer();
        this->configureElementBuffer();
    }


    void Rectangle::update(Shader*) {

    }


    void Rectangle::draw() {
        buffer.bindVertexArray();
        glDrawElements(GL_TRIANGLES, this->getIndicesCount(), GL_UNSIGNED_INT, nullptr);
    }
}
