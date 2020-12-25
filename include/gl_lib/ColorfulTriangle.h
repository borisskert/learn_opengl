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
        void configureVertexArray() override;

        void configureElementBuffer() override;

        unsigned int getIndicesCount() override;

    public:
        ColorfulTriangle(
                glm::vec3 positionA, glm::vec3 positionB, glm::vec3 positionC,
                glm::vec3 colorA, glm::vec3 colorB, glm::vec3 colorC);
    };
}


#endif //MYFIRSTOPENGL_COLORFULTRIANGLE_H
