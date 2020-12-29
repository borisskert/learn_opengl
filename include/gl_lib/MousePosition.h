#ifndef LEARN_OPENGL_MOUSEPOSITION_H
#define LEARN_OPENGL_MOUSEPOSITION_H

#include <glm/vec2.hpp>

namespace gl_lib {

    class MousePosition {
    private:
        glm::vec2 last;
        glm::vec2 offset;
        bool hasBeenUpdated = false;

    public:
        MousePosition(int screenWidth, int screenHeight);

        void update(glm::vec2);

        glm::vec2 getOffset();
    };
}


#endif //LEARN_OPENGL_MOUSEPOSITION_H
