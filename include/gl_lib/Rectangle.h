#ifndef LEARN_OPENGL_RECTANGLE_H
#define LEARN_OPENGL_RECTANGLE_H

#include <glm/glm.hpp>
#include "Drawable.h"
#include "OpenGlBuffer.h"


namespace gl_lib {

    class Rectangle : public Drawable {
    private:
        OpenGlBuffer buffer;

        const glm::vec3 a;
        const glm::vec3 b;
        const glm::vec3 c;
        const glm::vec3 d;

    protected:
        void configureVertexArray();

        void configureElementBuffer();

        unsigned int getIndicesCount();

    public:
        Rectangle(const glm::vec3 a, const glm::vec3 b, const glm::vec3 c, const glm::vec3 d);

        void initialize() override;

        void draw() override;
    };
}


#endif //LEARN_OPENGL_RECTANGLE_H
