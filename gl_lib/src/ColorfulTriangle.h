#ifndef MYFIRSTOPENGL_COLORFULTRIANGLE_H
#define MYFIRSTOPENGL_COLORFULTRIANGLE_H

#include "glm/glm.hpp"
#include "Drawable.h"

namespace gl_lib {

    class ColorfulTriangle : public Drawable {
    private:
        const glm::vec3 positionA;
        const glm::vec3 positionB;
        const glm::vec3 positionC;
        const glm::vec3 colorA;
        const glm::vec3 colorB;
        const glm::vec3 colorC;

    protected:
        void configureVertexArray() override {
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
        ColorfulTriangle(
                glm::vec3 positionA, glm::vec3 positionB, glm::vec3 positionC,
                glm::vec3 colorA, glm::vec3 colorB, glm::vec3 colorC)
                : positionA(positionA), positionB(positionB), positionC(positionC),
                  colorA(colorA), colorB(colorB), colorC(colorC) {}
    };
}


#endif //MYFIRSTOPENGL_COLORFULTRIANGLE_H
