#ifndef LEARN_OPENGL_COLORFULTRIANGLE_H
#define LEARN_OPENGL_COLORFULTRIANGLE_H

#include "glm/glm.hpp"
#include "Drawable.h"
#include "OpenGlBuffer.h"

namespace gl_lib {

    class ColorfulTriangle : public Drawable {
    private:
        OpenGlBuffer buffer;

        const glm::vec3 positionA;
        const glm::vec3 positionB;
        const glm::vec3 positionC;
        const glm::vec3 colorA;
        const glm::vec3 colorB;
        const glm::vec3 colorC;

    protected:
        void configureVertexArray();

        void configureElementBuffer();

        unsigned int getIndicesCount();

    public:
        ColorfulTriangle(
                glm::vec3 positionA, glm::vec3 positionB, glm::vec3 positionC,
                glm::vec3 colorA, glm::vec3 colorB, glm::vec3 colorC);

        void initialize(Context *) override;

        void update(Context *) override;

        void draw(Context *) override;
    };
}


#endif //LEARN_OPENGL_COLORFULTRIANGLE_H
