#ifndef LEARN_OPENGL_MOUSEINPUTADAPTER_H
#define LEARN_OPENGL_MOUSEINPUTADAPTER_H

#include <GLFW/glfw3.h>
#include "MouseInputHandler.h"


using namespace gl_lib;

namespace gl_lib {

    class MouseInputAdapter {
    private:
        GLFWwindow* window;
        static gl_lib::MouseInputHandler *staticInstance;

        static void callbackFunction(GLFWwindow *, double, double);

    public:

        explicit MouseInputAdapter(GLFWwindow *);

        void registerCallback(gl_lib::MouseInputHandler*);
    };
}


#endif //LEARN_OPENGL_MOUSEINPUTADAPTER_H
