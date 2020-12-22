#ifndef MYFIRSTOPENGL_TRIANGLE_H
#define MYFIRSTOPENGL_TRIANGLE_H

#include "Point.h"
#include "VertexModel.h"

class Triangle : public VertexModel {
private:
    const Point a;
    const Point b;
    const Point c;

public:
    Triangle(Point a, Point b, Point c)
            : a(a), b(b), c(c) {}

    Point getA() const {
        return a;
    }

    Point getB() const {
        return b;
    }

    Point getC() const {
        return c;
    }

    ElementBufferObject toElementBufferObject() const override {
        ElementBufferObject ebo;

        ebo.addVertex(a.getX());
        ebo.addVertex(a.getY());
        ebo.addVertex(a.getZ());

        ebo.addVertex(b.getX());
        ebo.addVertex(b.getY());
        ebo.addVertex(b.getZ());

        ebo.addVertex(c.getX());
        ebo.addVertex(c.getY());
        ebo.addVertex(c.getZ());

        ebo.addIndex(0);
        ebo.addIndex(1);
        ebo.addIndex(2);

        return ebo;
    }
};


#endif //MYFIRSTOPENGL_TRIANGLE_H
