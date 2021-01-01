#include <glm/ext.hpp>
#include "gl_lib/MovingInOrbit.h"


namespace gl_lib {

    gl_lib::MovingInOrbit::MovingInOrbit(
            gl_lib::Drawable *decorated,
            float speed,
            glm::vec2 radius,
            glm::vec3 centre,
            float angle
    ) : DrawableDecorator(decorated),
        speed(speed),
        radius(radius),
        centre(centre),
        angle(angle) {}


    glm::vec3 calculateRotatedRight(glm::vec3 v, float angleInRadians) {
        glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec3 right = glm::normalize(glm::cross(v, worldUp));
        glm::mat4 translate = glm::rotate(glm::mat4(1.0f), -angleInRadians, v);

        right = translate * glm::vec4(right, 1.0f);

        return glm::vec3(right.x, right.y, right.z) * glm::length(v);
    }

    float angleBetween(
            glm::vec3 a,
            glm::vec3 b,
            glm::vec3 origin
    ) {
        glm::vec3 da = glm::normalize(a - origin);
        glm::vec3 db = glm::normalize(b - origin);
        return glm::acos(glm::dot(da, db));
    }

    glm::mat4 rotateToRadius(glm::vec3 radius3) {
        const glm::vec3 &xAxis = glm::vec3(1, 0, 0);

        glm::mat4 translation = glm::mat4(1.0f);

        float angle2 = angleBetween(glm::normalize(radius3), xAxis, glm::vec3(0));
        if (angle2 != 0) {
            glm::vec3 up = glm::cross(radius3, xAxis);
            translation = glm::rotate(translation, angle2, up);
        }

        return translation;
    }

    glm::mat4 MovingInOrbit::rotateOrbit(const glm::mat4 &model) const {
        glm::vec3 radius3 = glm::vec3(radius.x, 0.0f, radius.y);
        glm::vec3 rotationPosition = getRotation(radius3);

        glm::mat4 model2 = model * rotateToRadius(radius3);
        model2 = glm::translate(model2, rotationPosition);

        return model2;
    }

    glm::vec3 MovingInOrbit::getRotation(glm::vec3 &radius3) const {
        double time = glfwGetTime();


        glm::vec3 right = glm::vec3(glm::length(radius3), 0, 0);
        glm::vec3 front = calculateRotatedRight(right, glm::radians(angle));

        glm::vec3 rotationPosition = glm::vec3(
                (front.x + right.x) * cos(time * speed),
                (front.y + right.y) * sin(time * speed),
                (front.z + right.z) * sin(time * speed));

        return rotationPosition;
    }


    glm::mat4 MovingInOrbit::getTransformMatrix() {
        return rotateOrbit(decorated->getTransformMatrix());
    }


    void MovingInOrbit::prepare(Context *context) {
        this->decorated->prepare(context);
        context->shader->setMat4("model", this->getModelMatrix());
        context->shader->setMat4("transform", this->getTransformMatrix());
    }


    void MovingInOrbit::initialize(Context *context) {
        this->decorated->initialize(context);
        context->shader->setMat4("model", this->getModelMatrix());
        context->shader->setMat4("transform", this->getTransformMatrix());
    }


    void MovingInOrbit::update(Context *context) {
        this->decorated->update(context);
        context->shader->setMat4("model", this->getModelMatrix());
        context->shader->setMat4("transform", this->getTransformMatrix());
    }
}
