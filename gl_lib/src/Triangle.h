#ifndef MYFIRSTOPENGL_TRIANGLE_H
#define MYFIRSTOPENGL_TRIANGLE_H

#include "glm/glm.hpp"
#include "VertexModel.h"

class Triangle : public VertexModel {
private:
    const glm::vec3 a;
    const glm::vec3 b;
    const glm::vec3 c;

public:
    Triangle(glm::vec3 a, glm::vec3 b, glm::vec3 c)
            : a(a), b(b), c(c) {}

    ElementBufferObject toElementBufferObject() const override {
        ElementBufferObject ebo;

        ebo.addVertex(a.x);
        ebo.addVertex(a.y);
        ebo.addVertex(a.z);

        ebo.addVertex(b.x);
        ebo.addVertex(b.y);
        ebo.addVertex(b.z);

        ebo.addVertex(c.x);
        ebo.addVertex(c.y);
        ebo.addVertex(c.z);

        ebo.addIndex(0);
        ebo.addIndex(1);
        ebo.addIndex(2);

        return ebo;
    }
};


#endif //MYFIRSTOPENGL_TRIANGLE_H
