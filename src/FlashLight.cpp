#include "gl_lib/FlashLight.h"

using namespace gl_lib;

namespace gl_lib {

    FlashLight::FlashLight(Camera *camera)
            : camera(camera) {}


    void FlashLight::prepare(Context *context) {

    }


    void FlashLight::initialize(Context *context) {

    }


    void FlashLight::update(Context *context) {

    };

    void FlashLight::draw(Context *context) {

    };

    void FlashLight::prepareLight(Context *context) {
        context->shader->attachFragmentShader("assets/shader/fragment.simple-light.shader");
    }

    void FlashLight::renderLight(Context *context) {
        context->shader->setVec3("flashlight.ambient", ambient);
        context->shader->setVec3("flashlight.diffuse", diffuse);
        context->shader->setVec3("flashlight.specular", specular);

        context->shader->setVec3("flashlight.position", camera->getPosition());
        context->shader->setVec3("flashlight.direction", camera->getFront());
        context->shader->setFloat("flashlight.cutOff", glm::cos(glm::radians(12.5f)));
        context->shader->setFloat("flashlight.outerCutOff", glm::cos(glm::radians(17.5f)));

        context->shader->setFloat("flashlight.constant", 1.0f);
        context->shader->setFloat("flashlight.linear", 0.09f);
        context->shader->setFloat("flashlight.quadratic", 0.032f);
    }

    glm::vec3 FlashLight::getBackgroundColor() const {
        return glm::vec3(0.0f);
    }

    glm::vec3 FlashLight::getModelPosition() {
        return glm::vec3();
    }

    glm::mat4 FlashLight::getModelMatrix() {
        return glm::mat4();
    }

    glm::mat4 FlashLight::getTransformMatrix() {
        return glm::mat4();
    }
}
