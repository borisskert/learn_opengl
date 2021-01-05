#include "gl_lib/Watch.h"
#include <GLFW/glfw3.h>

namespace gl_lib {

    Watch::Watch() {
        currentFrame = glfwGetTime();
        lastFrame = currentFrame;
    }


    void Watch::startFrame() {
        lastFrame = currentFrame;
        currentFrame = glfwGetTime();
    }


    double Watch::getDelta() const {
        return currentFrame - lastFrame;
    }


    double Watch::getCurrent() const {
        return currentFrame;
    }
}
