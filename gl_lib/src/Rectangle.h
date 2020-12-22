#ifndef MYFIRSTOPENGL_RECTANGLE_H
#define MYFIRSTOPENGL_RECTANGLE_H

#include "VertexModel.h"
#include <glm/glm.hpp>

class Rectangle : public VertexModel {
private:
    const glm::vec3 a;
    const glm::vec3 b;
    const glm::vec3 c;
    const glm::vec3 d;

public:
    Rectangle(const glm::vec3 a, const glm::vec3 b, const glm::vec3 c, const glm::vec3 d)
            : a(a), b(b), c(c), d(d) {}

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

        ebo.addVertex(d.x);
        ebo.addVertex(d.y);
        ebo.addVertex(d.z);

        ebo.addIndex(0);
        ebo.addIndex(1);
        ebo.addIndex(3);

        ebo.addIndex(1);
        ebo.addIndex(2);
        ebo.addIndex(3);

        return ebo;
    }
};


#endif //MYFIRSTOPENGL_RECTANGLE_H
