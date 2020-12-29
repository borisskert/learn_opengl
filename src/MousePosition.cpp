#include "gl_lib/MousePosition.h"


namespace gl_lib {

    MousePosition::MousePosition(int screenWidth, int screenHeight)
            : lastCursorPosition(glm::vec2(screenWidth / 2, screenHeight / 2)) {}


    void MousePosition::update(glm::vec2 newPosition) {
        if (!hasCursorBeenUpdated) {
            lastCursorPosition = newPosition;
            cursorPositionOffset = glm::vec2(0.0f);
            hasCursorBeenUpdated = true;
        } else {
            cursorPositionOffset = newPosition - lastCursorPosition;
            lastCursorPosition = newPosition;
        }
    }

    glm::vec2 MousePosition::getOffset() {
        return cursorPositionOffset;
    }
}
