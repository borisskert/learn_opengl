#ifndef LEARN_OPENGL_RECTANGLE_H
#define LEARN_OPENGL_RECTANGLE_H

#include <glm/glm.hpp>
#include "Drawable.h"


namespace gl_lib {

    class Rectangle : public Drawable {
    private:
        const glm::vec3 a;
        const glm::vec3 b;
        const glm::vec3 c;
        const glm::vec3 d;

    protected:
        void configureVertexArray() override;

        void configureElementBuffer() override;

        unsigned int getIndicesCount() override;

    public:
        Rectangle(const glm::vec3 a, const glm::vec3 b, const glm::vec3 c, const glm::vec3 d);
    };
}


#endif //LEARN_OPENGL_RECTANGLE_H
