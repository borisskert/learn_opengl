#ifndef LEARN_OPENGL_CAMERA_H
#define LEARN_OPENGL_CAMERA_H


#include <glm/vec3.hpp>

namespace gl_lib {

    class Camera {
    private:
        glm::vec3 position;
        glm::vec3 target;
        glm::vec3 direction;
        glm::vec3 up;
        glm::vec3 right;

    public:
        Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up);

        void updatePosition(glm::vec3 newPosition);

        glm::mat4 getView();

        void forward(float speed);
        void backward(float speed);
        void strafeLeft(float speed);
        void strafeRight(float speed);

        static Camera create();
    };
}


#endif //LEARN_OPENGL_CAMERA_H
