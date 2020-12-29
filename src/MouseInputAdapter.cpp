#include "gl_lib/MouseInputAdapter.h"

namespace gl_lib {

    gl_lib::MouseInputHandler *MouseInputAdapter::staticInstance;

    MouseInputAdapter::MouseInputAdapter(GLFWwindow *window)
            : window(window) {
    }

    void MouseInputAdapter::registerCallback(gl_lib::MouseInputHandler *handler) {
        staticInstance = handler;
        glfwSetCursorPosCallback(window, callbackFunction);
    }

    void MouseInputAdapter::callbackFunction(GLFWwindow *window, double x, double y) {
        staticInstance->onMouseInput(window, x, y);
    }
}
