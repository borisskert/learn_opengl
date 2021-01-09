#include "gl_lib/DirectionalLight.h"

using namespace gl_lib;

namespace gl_lib {

    DirectionalLight::DirectionalLight()
            : direction(glm::vec3(0.0f)),
              ambient(glm::vec3(0.0f)),
              diffuse(glm::vec3(0.0f)),
              specular(glm::vec3(0.0f)) {}


    DirectionalLight::DirectionalLight(
            glm::vec3 direction,
            glm::vec3 ambient,
            glm::vec3 diffuse,
            glm::vec3 specular
    ) : direction(direction),
        ambient(ambient),
        diffuse(diffuse),
        specular(specular) {}


    void DirectionalLight::prepare(Context *context) {

    }


    void DirectionalLight::initialize(Context *context) {

    }


    void DirectionalLight::update(Context *context) {

    };

    void DirectionalLight::draw(Context *context) {

    };

    void DirectionalLight::prepareLight(Context *context) {
        context->shader->attachFragmentShader("assets/shader/fragment.simple-light.shader");
    }

    void DirectionalLight::renderLight(Context *context) {
        context->shader->setVec3("dirLight.direction", direction);
        context->shader->setVec3("dirLight.ambient", ambient);
        context->shader->setVec3("dirLight.diffuse", diffuse);
        context->shader->setVec3("dirLight.specular", specular);
    }

    glm::vec3 DirectionalLight::getBackgroundColor() const {
        return glm::vec3(0.0f);
    }

    glm::vec3 DirectionalLight::getModelPosition() {
        return glm::vec3();
    }

    glm::mat4 DirectionalLight::getModelMatrix() {
        return glm::mat4();
    }

    glm::mat4 DirectionalLight::getTransformMatrix() {
        return glm::mat4();
    }
}
