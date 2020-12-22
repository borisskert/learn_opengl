#ifndef MYFIRSTOPENGL_POINT_H
#define MYFIRSTOPENGL_POINT_H


class Point {
private:
    const float x;
    const float y;
    const float z;

public:
    Point(float x, float y, float z)
            : x(x), y(y), z(z) {}

    float getX() const {
        return x;
    }

    float getY() const {
        return y;
    }

    float getZ() const {
        return z;
    }
};


#endif //MYFIRSTOPENGL_POINT_H
