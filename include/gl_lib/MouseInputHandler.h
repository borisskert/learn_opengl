#ifndef LEARN_OPENGL_MOUSEINPUTHANDLER_H
#define LEARN_OPENGL_MOUSEINPUTHANDLER_H


namespace gl_lib {

    class MouseInputHandler {
    public:
        virtual void onMouseMove(GLFWwindow *window, double x, double y) {};

        virtual void onMouseScroll(GLFWwindow *window, double x, double y) {};
    };
}


#endif //LEARN_OPENGL_MOUSEINPUTHANDLER_H
