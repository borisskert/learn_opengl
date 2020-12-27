#ifndef LEARN_OPENGL_TRIANGLE_H
#define LEARN_OPENGL_TRIANGLE_H

#include "glm/glm.hpp"
#include "Drawable.h"
#include "OpenGlBuffer.h"


namespace gl_lib {

    class Triangle : public Drawable {
    private:
        OpenGlBuffer buffer;

        const glm::vec3 a;
        const glm::vec3 b;
        const glm::vec3 c;

    protected:
        void configureVertexArray();

        void configureElementBuffer();

        unsigned int getIndicesCount();

    public:
        Triangle(glm::vec3 a, glm::vec3 b, glm::vec3 c);

        void initialize() override;

        void draw() override;
    };
}


#endif //LEARN_OPENGL_TRIANGLE_H