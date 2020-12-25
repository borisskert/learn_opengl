#include <gl_lib/Drawable.h>
#include <gl_lib/gl_lib.h>

namespace gl_lib {

    elementBuffer Drawable::initializeElementBuffer() {
        elementBufferObject = createElementBuffer();
        bindElementBuffer(elementBufferObject);

        this->configureElementBuffer();

        return elementBufferObject;
    }

    void Drawable::initialize() {
        this->vertexBufferObject = gl_lib::createVertexBuffer();
        this->vertexArrayObject = gl_lib::createVertexArray();

        glBindVertexArray(vertexArrayObject);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);

        this->configureVertexArray();

        this->elementBufferObject = initializeElementBuffer();
    }

    void Drawable::draw() {
        drawElements(vertexArrayObject, getIndicesCount());
    }
}
