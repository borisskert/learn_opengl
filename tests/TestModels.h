#ifndef MYFIRSTOPENGL_TESTMODELS_H
#define MYFIRSTOPENGL_TESTMODELS_H


#include "../include/gl_lib/Triangle.h"
#include "../include/gl_lib/Rectangle.h"


static Triangle buildTriangleOne() {
    const glm::vec3 &a = glm::vec3(0.5f, 0.5f, 0.0f);
    const glm::vec3 &b = glm::vec3(0.5f, 0.0f, 0.0f);
    const glm::vec3 &c = glm::vec3(0.0f, 0.0f, 0.0f);

    return {a, b, c};
}


static Triangle buildTriangleTwo() {
    const glm::vec3 &a = glm::vec3(-0.5f, -0.5f, 0.0f);
    const glm::vec3 &b = glm::vec3(-0.5f, 0.0f, 0.0f);
    const glm::vec3 &c = glm::vec3(0.0f, 0.0f, 0.0f);

    return {a, b, c};
}


static Rectangle buildRectangleOne() {
    const glm::vec3 &a = glm::vec3(0.5f, 0.5f, 0.0f);
    const glm::vec3 &b = glm::vec3(0.5f, 0.0f, 0.0f);
    const glm::vec3 &c = glm::vec3(0.0f, 0.0f, 0.0f);
    const glm::vec3 &d = glm::vec3(0.0f, 0.5f, 0.0f);

    return {a, b, c, d};
}


static Rectangle buildRectangleTwo() {
    const glm::vec3 &a = glm::vec3(-0.5f, -0.5f, 0.0f);
    const glm::vec3 &b = glm::vec3(-0.5f, 0.0f, 0.0f);
    const glm::vec3 &c = glm::vec3(0.0f, 0.0f, 0.0f);
    const glm::vec3 &d = glm::vec3(0.0f, -0.5f, 0.0f);

    return {a, b, c, d};
}


#endif //MYFIRSTOPENGL_TESTMODELS_H
