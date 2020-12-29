#include "gl_lib/MousePosition.h"


namespace gl_lib {

    MousePosition::MousePosition(int screenWidth, int screenHeight)
            : last(glm::vec2(screenWidth / 2, screenHeight / 2)) {}


    void MousePosition::update(glm::vec2 newPosition) {
        if (!hasBeenUpdated) {
            last = newPosition;
            offset = glm::vec2(0.0f);
            hasBeenUpdated = true;
        } else {
            offset = newPosition - last;
            last = newPosition;
        }
    }

    glm::vec2 MousePosition::getOffset() {
        return offset;
    }
}
