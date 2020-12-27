#ifndef LEARN_OPENGL_OPENGLBUFFER_H
#define LEARN_OPENGL_OPENGLBUFFER_H


#include <gl_lib/gl_lib.h>


namespace gl_lib {

    class OpenGlBuffer {
    private:
        vertexBuffer vertexBufferObject;
        vertexArray vertexArrayObject;
        elementBuffer elementBufferObject;

    public:
        OpenGlBuffer();

        void initialize();

        void bindVertexArray();

        void bindElementBuffer();
    };
}


#endif //LEARN_OPENGL_OPENGLBUFFER_H
