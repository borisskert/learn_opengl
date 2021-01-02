#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "gl_lib/Camera.h"

namespace gl_lib {

    Camera::Camera(glm::vec3 position, glm::vec3 up)
            : position(position),
              up(up), worldUp(up) {
        update();
    }


    glm::vec3 calculateFront(float yaw, float pitch) {
        glm::vec3 front;
        front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        front.y = sin(glm::radians(pitch));
        front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

        return glm::normalize(front);
    }


    void Camera::update() {
        this->front = calculateFront(this->yaw, this->pitch);
        this->right = glm::normalize(glm::cross(this->front, this->worldUp));
        this->up = glm::normalize(glm::cross(right, front));
    }


    glm::mat4 Camera::getView() {
        return glm::lookAt(position, position + front, up);
    }


    void Camera::forward(float speed) {
        position += speed * front;
    }

    void Camera::backward(float speed) {
        position -= speed * front;
    }

    void Camera::strafeLeft(float speed) {
        position -= glm::normalize(glm::cross(front, up)) * speed;
    }

    void Camera::strafeRight(float speed) {
        position += glm::normalize(glm::cross(front, up)) * speed;
    }

    void Camera::goUp(float speed) {
        position += glm::normalize(worldUp) * speed;
    }

    void Camera::goDown(float speed) {
        position += glm::normalize(-worldUp) * speed;
    }


    void Camera::rotate(glm::vec2 offset) {
        yaw += offset.x;
        pitch += offset.y;

        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;

        update();
    }


    Camera Camera::create() {
        return Camera(
                glm::vec3(0.0f, 0.0f, 3.0f),
                glm::vec3(0.0f, 1.0f, 0.0f)
        );
    }

    glm::vec3 Camera::getPosition() {
        return position;
    }
}
