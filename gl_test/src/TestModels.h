#ifndef MYFIRSTOPENGL_TESTMODELS_H
#define MYFIRSTOPENGL_TESTMODELS_H


#include "../../gl_lib/src/Triangle.h"
#include "../../gl_lib/src/Rectangle.h"


static Triangle buildTriangleOne() {
    const Point &a = Point(0.5f, 0.5f, 0.0f);
    const Point &b = Point(0.5f, 0.0f, 0.0f);
    const Point &c = Point(0.0f, 0.0f, 0.0f);

    return {a, b, c};
}


static Triangle buildTriangleTwo() {
    const Point &a = Point(-0.5f, -0.5f, 0.0f);
    const Point &b = Point(-0.5f, 0.0f, 0.0f);
    const Point &c = Point(0.0f, 0.0f, 0.0f);

    return {a, b, c};
}


static Rectangle buildRectangleOne() {
    const Point &a = Point(0.5f, 0.5f, 0.0f);
    const Point &b = Point(0.5f, 0.0f, 0.0f);
    const Point &c = Point(0.0f, 0.0f, 0.0f);
    const Point &d = Point(0.0f, 0.5f, 0.0f);

    return {a, b, c, d};
}


static Rectangle buildRectangleTwo() {
    const Point &a = Point(-0.5f, -0.5f, 0.0f);
    const Point &b = Point(-0.5f, 0.0f, 0.0f);
    const Point &c = Point(0.0f, 0.0f, 0.0f);
    const Point &d = Point(0.0f, -0.5f, 0.0f);

    return {a, b, c, d};
}


#endif //MYFIRSTOPENGL_TESTMODELS_H
