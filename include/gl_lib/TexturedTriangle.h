#ifndef OPENGL_GAME_OF_LIFE_TEXTUREDTRIANGLE_H
#define OPENGL_GAME_OF_LIFE_TEXTUREDTRIANGLE_H

#include "Drawable.h"
#include <gl_lib/gl_lib.h>
#include "Texture.h"
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

        Texture texture;

    protected:
        void configureVertexArray();

        void configureElementBuffer();

        unsigned int getIndicesCount();

    public:
        TexturedTriangle(
                glm::vec3 positionA, glm::vec3 positionB, glm::vec3 positionC,
                glm::vec3 colorA, glm::vec3 colorB, glm::vec3 colorC, Texture texture
        );

        void initialize() override;

        void draw() override;
    };
}


#endif //OPENGL_GAME_OF_LIFE_TEXTUREDTRIANGLE_H
