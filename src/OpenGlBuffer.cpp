#include "gl_lib/OpenGlBuffer.h"

namespace gl_lib {

    OpenGlBuffer::OpenGlBuffer() = default;


    void OpenGlBuffer::initialize() {
        this->vertexBufferObject = gl_lib::createVertexBuffer();
        this->vertexArrayObject = gl_lib::createVertexArray();

        glBindVertexArray(vertexArrayObject);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);

        this->elementBufferObject = gl_lib::createElementBuffer();
    }


    void OpenGlBuffer::bindVertexArray() {
        glBindVertexArray(vertexArrayObject);
    }


    void OpenGlBuffer::bindElementBuffer() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
    }
}