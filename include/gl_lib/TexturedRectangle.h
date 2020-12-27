#ifndef OPENGL_GAME_OF_LIFE_TEXTUREDRECTANGLE_H
#define OPENGL_GAME_OF_LIFE_TEXTUREDRECTANGLE_H


#include <glm/vec3.hpp>
#include "Drawable.h"
#include "OpenGlBuffer.h"
#include "Texture.h"

namespace gl_lib {

    class TexturedRectangle : public Drawable {
        OpenGlBuffer buffer;

        const glm::vec3 a;
        const glm::vec3 b;
        const glm::vec3 c;
        const glm::vec3 d;

        const glm::vec3 colorA;
        const glm::vec3 colorB;
        const glm::vec3 colorC;
        const glm::vec3 colorD;

        Texture texture;

    protected:
        void configureVertexArray();

        void configureElementBuffer();

    public:
        TexturedRectangle(
                const glm::vec3 a, const glm::vec3 b, const glm::vec3 c, const glm::vec3 d,
                const glm::vec3 colorA, const glm::vec3 colorB, const glm::vec3 colorC, const glm::vec3 colorD,
                Texture texture
        );

        void initialize() override;

        void draw() override;
    };
}


#endif //OPENGL_GAME_OF_LIFE_TEXTUREDRECTANGLE_H
