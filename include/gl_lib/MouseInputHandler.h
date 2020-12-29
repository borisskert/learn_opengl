#ifndef LEARN_OPENGL_MOUSEINPUTHANDLER_H
#define LEARN_OPENGL_MOUSEINPUTHANDLER_H


namespace gl_lib {

    class MouseInputHandler {
    public:
        virtual void onMouseInput(GLFWwindow* window, double x, double y) = 0;
    };
}



#endif //LEARN_OPENGL_MOUSEINPUTHANDLER_H
