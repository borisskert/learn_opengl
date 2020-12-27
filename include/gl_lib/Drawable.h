#ifndef LEARN_OPENGL_DRAWABLE_H
#define LEARN_OPENGL_DRAWABLE_H


namespace gl_lib {

    class Drawable {
    public:
        virtual void initialize() = 0;

        virtual void draw() = 0;
    };
}


#endif //LEARN_OPENGL_DRAWABLE_H
