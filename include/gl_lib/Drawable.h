#ifndef LEARN_OPENGL_DRAWABLE_H
#define LEARN_OPENGL_DRAWABLE_H

#include <gl_lib/Typedefs.h>


namespace gl_lib {

    class Drawable {
    private:
        vertexBuffer vertexBufferObject;
        vertexArray vertexArrayObject;
        elementBuffer elementBufferObject;

        elementBuffer initializeElementBuffer();

    protected:
        virtual void configureVertexArray() = 0;

        virtual void configureElementBuffer() = 0;

        virtual unsigned int getIndicesCount() = 0;

    public:
        void initialize();

        void draw();
    };
}


#endif //LEARN_OPENGL_DRAWABLE_H
