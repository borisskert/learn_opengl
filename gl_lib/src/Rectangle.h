#ifndef MYFIRSTOPENGL_RECTANGLE_H
#define MYFIRSTOPENGL_RECTANGLE_H

#include <glm/glm.hpp>
#include "Drawable.h"


namespace gl_lib {

    class Rectangle : public Drawable {
    private:
        const glm::vec3 a;
        const glm::vec3 b;
        const glm::vec3 c;
        const glm::vec3 d;

    protected:
        void configureVertexArray() override {
            float vertices[] = {
                    a.x, a.y, a.z,
                    b.x, b.y, b.z,
                    c.x, c.y, c.z,
                    d.x, d.y, d.z,
            };

            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
            glEnableVertexAttribArray(0);
        }

        void configureElementBuffer() override {
            unsigned int indices[] = {
                    0, 1, 3,
                    1, 2, 3,
            };

            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        }

        unsigned int getIndicesCount() override {
            return 6;
        }

    public:
        Rectangle(const glm::vec3 a, const glm::vec3 b, const glm::vec3 c, const glm::vec3 d)
                : a(a), b(b), c(c), d(d) {}
    };
}


#endif //MYFIRSTOPENGL_RECTANGLE_H
