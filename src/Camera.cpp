#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "gl_lib/Camera.h"

namespace gl_lib {

    Camera::Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up)
            : position(position), target(target),
              direction(glm::normalize(position - target)),
              right(glm::normalize(glm::cross(up, direction))),
              up(up) {}


    void Camera::updatePosition(glm::vec3 newPosition) {
        this->position = newPosition;
        this->direction = glm::normalize(position - target);
        this->right = glm::normalize(glm::cross(up, direction));
        this->up = glm::cross(direction, right);
    }


    glm::mat4 Camera::getView() {
        return glm::lookAt(position, target, up);
    }


    void Camera::forward(float speed) {
        target -= speed * direction;
        updatePosition(position - speed * direction);
    }

    void Camera::backward(float speed) {
        target += speed * direction;
        updatePosition(position + speed * direction);
    }

    void Camera::strafeLeft(float speed) {
        target += glm::normalize(glm::cross(direction, up)) * speed;
        updatePosition(position + glm::normalize(glm::cross(direction, up)) * speed);
    }

    void Camera::strafeRight(float speed) {
        target -= glm::normalize(glm::cross(direction, up)) * speed;
        updatePosition(position - glm::normalize(glm::cross(direction, up)) * speed);
    }


    Camera Camera::create() {
        return Camera(
                glm::vec3(0.0f, 0.0f, 3.0f),
                glm::vec3(0.0f, 0.0f, 0.0f),
                glm::vec3(0.0f, 1.0f, 0.0f)
        );
    }
}
