#ifndef OPENGL_GAME_OF_LIFE_OPENGLBUFFER_H
#define OPENGL_GAME_OF_LIFE_OPENGLBUFFER_H


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


#endif //OPENGL_GAME_OF_LIFE_OPENGLBUFFER_H
