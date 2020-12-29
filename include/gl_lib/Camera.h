#ifndef LEARN_OPENGL_CAMERA_H
#define LEARN_OPENGL_CAMERA_H


#include <glm/vec3.hpp>

namespace gl_lib {

    class Camera {
    private:
        glm::vec3 position;
        glm::vec3 front;
        glm::vec3 up;
        glm::vec3 right;

        float yaw = -90.0f;
        float pitch = 0.0f;

        void update();

    public:
        Camera(glm::vec3 position, glm::vec3 up);

        glm::mat4 getView();

        void forward(float speed);
        void backward(float speed);
        void strafeLeft(float speed);
        void strafeRight(float speed);

        void rotate(glm::vec2 offset);

        static Camera create();
    };
}


#endif //LEARN_OPENGL_CAMERA_H
