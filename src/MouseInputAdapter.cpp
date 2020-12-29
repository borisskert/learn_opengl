#include "gl_lib/MouseInputAdapter.h"

namespace gl_lib {

    gl_lib::MouseInputHandler *MouseInputAdapter::staticInstance;

    MouseInputAdapter::MouseInputAdapter(GLFWwindow *window)
            : window(window) {
    }

    void MouseInputAdapter::registerCallback(gl_lib::MouseInputHandler *handler) {
        staticInstance = handler;

        glfwSetCursorPosCallback(window, mouseMovementCallbackFunction);
        glfwSetScrollCallback(window, mouseScrollCallbackFunction);
    }

    void MouseInputAdapter::mouseMovementCallbackFunction(GLFWwindow *window, double x, double y) {
        staticInstance->onMouseMove(window, x, y);
    }

    void MouseInputAdapter::mouseScrollCallbackFunction(GLFWwindow *window, double x, double y) {
        staticInstance->onMouseScroll(window, x, y);
    }
}
