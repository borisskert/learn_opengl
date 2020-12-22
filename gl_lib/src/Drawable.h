#ifndef MYFIRSTOPENGL_DRAWABLE_H
#define MYFIRSTOPENGL_DRAWABLE_H

#include <GLFW/glfw3.h>
#include "Typedefs.h"


static vertexBuffer createVertexBuffer() {
    unsigned int vertexBufferObject;
    glGenBuffers(1, &vertexBufferObject);

    return vertexBufferObject;
}


static vertexArray createVertexArray() {
    unsigned int vertexArrayObject;
    glGenVertexArrays(1, &vertexArrayObject);

    return vertexArrayObject;
}


static elementBuffer createElementBuffer() {
    unsigned int elementBufferObject;
    glGenBuffers(1, &elementBufferObject);

    return elementBufferObject;
}


class Drawable {
private:
    vertexBuffer vertexBufferObject;
    vertexArray vertexArrayObject;
    elementBuffer elementBufferObject;

    vertexArray initializeVertexArray() {
        vertexArrayObject = createVertexArray();
        glBindVertexArray(vertexArrayObject);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);

        configureVertexArray();

        return vertexArrayObject;
    }

    elementBuffer initializeElementBuffer() {
        elementBuffer elementBufferObject = createElementBuffer();
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);

        configureElementBuffer();

        return elementBufferObject;
    }

protected:
    virtual void configureVertexArray() = 0;

    virtual void configureElementBuffer() = 0;

    virtual unsigned int getIndicesCount() = 0;

public:
    void initialize() {
        this->vertexBufferObject = createVertexBuffer();
        this->vertexArrayObject = initializeVertexArray();
        this->elementBufferObject = initializeElementBuffer();
    }

    void draw() {
        glBindVertexArray(vertexArrayObject);
        glDrawElements(GL_TRIANGLES, getIndicesCount(), GL_UNSIGNED_INT, nullptr);
    }
};


#endif //MYFIRSTOPENGL_DRAWABLE_H
