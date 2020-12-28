#ifndef LEARN_OPENGL_TEXTUREDRECTANGLE_H
#define LEARN_OPENGL_TEXTUREDRECTANGLE_H


#include <glm/vec3.hpp>
#include "Drawable.h"
#include "OpenGlBuffer.h"
#include "TextureUnit.h"

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

        TextureUnit texture;

    protected:
        void configureVertexArray();

        void configureElementBuffer();

    public:
        TexturedRectangle(
                const glm::vec3 a, const glm::vec3 b, const glm::vec3 c, const glm::vec3 d,
                const glm::vec3 colorA, const glm::vec3 colorB, const glm::vec3 colorC, const glm::vec3 colorD,
                TextureUnit texture
        );

        void initialize(Shader *) override;

        void update(Shader *) override;

        void draw() override;
    };
}


#endif //LEARN_OPENGL_TEXTUREDRECTANGLE_H
