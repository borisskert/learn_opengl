#ifndef MYFIRSTOPENGL_TRIANGLE_H
#define MYFIRSTOPENGL_TRIANGLE_H

#include "glm/glm.hpp"
#include "Drawable.h"


namespace gl_lib {

    class Triangle : public Drawable {
    private:
        const glm::vec3 a;
        const glm::vec3 b;
        const glm::vec3 c;

    protected:
        void configureVertexArray() override;

        void configureElementBuffer() override;

        unsigned int getIndicesCount() override;

    public:
        Triangle(glm::vec3 a, glm::vec3 b, glm::vec3 c);
    };
}


#endif //MYFIRSTOPENGL_TRIANGLE_H
