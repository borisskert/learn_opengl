#include <glm/ext.hpp>
#include <iostream>
#include "gl_lib/PointLight.h"

namespace gl_lib {

    PointLight::PointLight()
            : position(glm::vec3(0.0f, 0.0f, 0.0f)),
              color(glm::vec3(1.0f)),
              strength(1.0f),
              scale(glm::vec3(1.0f)),
              id(LightSourceId::getInstance()->createNew()) {}


    PointLight::PointLight(
            glm::vec3 position, glm::vec3 color, float strength, glm::vec3 scale)
            : position(position),
              color(color),
              strength(strength),
              scale(scale),
              id(LightSourceId::getInstance()->createNew()) {};


    void PointLight::configureVertexArray() const {
        float vertices[] = {
                -0.5f, -0.5f, -0.5f,
                0.5f, -0.5f, -0.5f,
                0.5f, 0.5f, -0.5f,
                0.5f, 0.5f, -0.5f,
                -0.5f, 0.5f, -0.5f,
                -0.5f, -0.5f, -0.5f,

                -0.5f, -0.5f, 0.5f,
                0.5f, -0.5f, 0.5f,
                0.5f, 0.5f, 0.5f,
                0.5f, 0.5f, 0.5f,
                -0.5f, 0.5f, 0.5f,
                -0.5f, -0.5f, 0.5f,

                -0.5f, 0.5f, 0.5f,
                -0.5f, 0.5f, -0.5f,
                -0.5f, -0.5f, -0.5f,
                -0.5f, -0.5f, -0.5f,
                -0.5f, -0.5f, 0.5f,
                -0.5f, 0.5f, 0.5f,

                0.5f, 0.5f, 0.5f,
                0.5f, 0.5f, -0.5f,
                0.5f, -0.5f, -0.5f,
                0.5f, -0.5f, -0.5f,
                0.5f, -0.5f, 0.5f,
                0.5f, 0.5f, 0.5f,

                -0.5f, -0.5f, -0.5f,
                0.5f, -0.5f, -0.5f,
                0.5f, -0.5f, 0.5f,
                0.5f, -0.5f, 0.5f,
                -0.5f, -0.5f, 0.5f,
                -0.5f, -0.5f, -0.5f,

                -0.5f, 0.5f, -0.5f,
                0.5f, 0.5f, -0.5f,
                0.5f, 0.5f, 0.5f,
                0.5f, 0.5f, 0.5f,
                -0.5f, 0.5f, 0.5f,
                -0.5f, 0.5f, -0.5f
        };

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
        glEnableVertexAttribArray(0);
    };


    void PointLight::prepare(Context *context) {
        context->shader->attachVertexShader("assets/shader/lightVertex.shader");
        context->shader->attachFragmentShader("assets/shader/lightFragment.shader");
    }


    void PointLight::initialize(Context *context) {
        context->shader->initialize();
        context->buffer->initialize();

        context->buffer->bindVertexArray();
        this->configureVertexArray();
    }


    void PointLight::update(Context *context) {
        context->shader->use();
    };

    void PointLight::draw(Context *context) {
        context->shader->use();

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, position);
        model = glm::scale(model, scale);
        context->shader->setMat4("model", model);

        context->shader->setVec3("lightColor", color);
        context->shader->setFloat("lightStrength", strength);

        context->buffer->bindVertexArray();
        glDrawArrays(GL_TRIANGLES, 0, 36);
    };

    void PointLight::prepareLight(Context *context) {
        context->shader->attachFragmentShader("assets/shader/fragment.simple-light.shader");
    }

    void PointLight::renderLight(Context *context) {
        std::string idAsText = std::to_string(id);

        context->shader->setInt("countLights", LightSourceId::getInstance()->getCount());
        context->shader->setVec3("pointLights[" + idAsText + "].position", position);

        glm::vec3 ambient = glm::vec3(0.2f) * color;
        glm::vec3 diffuse = glm::vec3(0.75f) * color;
        glm::vec3 specular = glm::vec3(1.0f);

        context->shader->setVec3("pointLights[" + idAsText + "].ambient", ambient);
        context->shader->setVec3("pointLights[" + idAsText + "].diffuse", diffuse);
        context->shader->setVec3("pointLights[" + idAsText + "].specular", specular);

        context->shader->setFloat("pointLights[" + idAsText + "].constant", 1.0f);
        context->shader->setFloat("pointLights[" + idAsText + "].linear", 0.09f);
        context->shader->setFloat("pointLights[" + idAsText + "].quadratic", 0.032f);
    }

    glm::vec3 PointLight::getColor() const {
        return color;
    }

    float PointLight::getStrength() const {
        return strength;
    }

    void PointLight::setPosition(glm::vec3 value) {
        this->position = value;
    }

    void PointLight::setColor(glm::vec3 value) {
        this->color = value;
    }

    glm::vec3 PointLight::getModelPosition() {
        return position;
    }

    glm::mat4 PointLight::getModelMatrix() {
        return glm::mat4(1.0f);
    }

    glm::mat4 PointLight::getTransformMatrix() {
        return glm::mat4(1.0f);
    }

    glm::vec3 PointLight::getBackgroundColor() const {
        return this->getStrength() * 0.05f * this->getColor();
    }
}
