#ifndef MYFIRSTOPENGL_RECTANGLE_H
#define MYFIRSTOPENGL_RECTANGLE_H

#include "Point.h"
#include "VertexModel.h"

class Rectangle : public VertexModel {
private:
    const Point a;
    const Point b;
    const Point c;
    const Point d;

public:
    Rectangle(Point a, Point b, Point c, Point d)
            : a(a), b(b), c(c), d(d) {}

    Point getA() const {
        return a;
    }

    Point getB() const {
        return b;
    }

    Point getC() const {
        return c;
    }

    Point getD() const {
        return d;
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

        ebo.addVertex(d.getX());
        ebo.addVertex(d.getY());
        ebo.addVertex(d.getZ());

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
