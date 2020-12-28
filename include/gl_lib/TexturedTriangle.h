#ifndef LEARN_OPENGL_TEXTUREDTRIANGLE_H
#define LEARN_OPENGL_TEXTUREDTRIANGLE_H

#include "Drawable.h"
#include <gl_lib/gl_lib.h>
#include "TextureUnit.h"
#include "glm/glm.hpp"
#include "OpenGlBuffer.h"


namespace gl_lib {

    class TexturedTriangle : public Drawable {
    private:
        OpenGlBuffer buffer;

        const glm::vec3 positionA;
        const glm::vec3 positionB;
        const glm::vec3 positionC;
        const glm::vec3 colorA;
        const glm::vec3 colorB;
        const glm::vec3 colorC;

        TextureUnit texture;

    protected:
        void configureVertexArray();

        void configureElementBuffer();

        unsigned int getIndicesCount();

    public:
        TexturedTriangle(
                glm::vec3 positionA, glm::vec3 positionB, glm::vec3 positionC,
                glm::vec3 colorA, glm::vec3 colorB, glm::vec3 colorC, TextureUnit texture
        );

        void initialize(Shader *) override;

        void update(Shader *) override;

        void draw() override;
    };
}


#endif //LEARN_OPENGL_TEXTUREDTRIANGLE_H
