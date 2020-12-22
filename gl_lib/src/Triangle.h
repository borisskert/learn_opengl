#ifndef MYFIRSTOPENGL_TRIANGLE_H
#define MYFIRSTOPENGL_TRIANGLE_H

#include "glm/glm.hpp"
#include "Drawable.h"

class Triangle : public Drawable {
private:
    const glm::vec3 a;
    const glm::vec3 b;
    const glm::vec3 c;

protected:
    void configureVertexArray() override {
        float vertices[] = {
                a.x, a.y, a.z,
                b.x, b.y, b.z,
                c.x, c.y, c.z,
        };

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
    }

    void configureElementBuffer() override {
        unsigned int indices[] = {
                0, 1, 2
        };

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    }

    unsigned int getIndicesCount() override {
        return 3;
    }

public:
    Triangle(glm::vec3 a, glm::vec3 b, glm::vec3 c)
            : a(a), b(b), c(c) {}
};


#endif //MYFIRSTOPENGL_TRIANGLE_H
