#include <glm/ext.hpp>
#include "gl_lib/Rotating.h"

namespace gl_lib {

    Rotating::Rotating(
            gl_lib::Drawable *drawable,
            float startingAngle,
            float speed,
            glm::vec3 rotationAxis
    )
            : DrawableDecorator(drawable),
              startingAngle(startingAngle),
              speed(speed),
              rotationAxis(rotationAxis) {}


    glm::mat4 Rotating::getModelMatrix() {
        return decorated->getModelMatrix();
    }


    glm::mat4 Rotating::getTransformMatrix() {
        glm::mat4 modelMatrix = decorated->getTransformMatrix();

        modelMatrix = glm::rotate(modelMatrix, glm::radians(startingAngle), rotationAxis);

        double time = glfwGetTime();

        return glm::rotate(
                modelMatrix,
                glm::radians(startingAngle) + (float) time * speed,
                rotationAxis
        );;
    }


    void Rotating::prepare(Context *context) {
        this->decorated->prepare(context);
        context->shader->setMat4("model", this->getModelMatrix());
        context->shader->setMat4("transform", this->getTransformMatrix());
    }


    void Rotating::initialize(Context *context) {
        this->decorated->initialize(context);
        context->shader->setMat4("model", this->getModelMatrix());
        context->shader->setMat4("transform", this->getTransformMatrix());
    }


    void Rotating::update(Context *context) {
        this->decorated->update(context);
        context->shader->setMat4("model", this->getModelMatrix());
        context->shader->setMat4("transform", this->getTransformMatrix());
    }
}
