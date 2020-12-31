#include <glm/ext.hpp>
#include "gl_lib/LightSource.h"

namespace gl_lib {

    LightSource::LightSource()
            : position(glm::vec3(0.0f, 0.0f, 0.0f)),
              color(glm::vec3(1.0f)),
              strength(1.0f),
              scale(glm::vec3(1.0f)) {}


    LightSource::LightSource(
            glm::vec3 position,
            glm::vec3 color,
            float strength,
            glm::vec3 scale
    )
            : position(position),
              color(color),
              strength(strength),
              scale(scale) {}


    void LightSource::configureVertexArray() const {
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


    void LightSource::prepare(Context *context) {
        context->shader->attachVertexShader("assets/shader/lightVertex.shader");
        context->shader->attachFragmentShader("assets/shader/lightFragment.shader");
    }


    void LightSource::initialize(Context *context) {
        context->shader->initialize();
        context->buffer->initialize();

        context->buffer->bindVertexArray();
        this->configureVertexArray();
    }


    void LightSource::update(Context *context) {
        context->shader->use();
    };

    void LightSource::draw(Context *context) {
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

    void LightSource::renderLight(Context *context) {
        context->shader->setVec3("lightPos", position);

        glm::vec3 ambient = glm::vec3(0.2f) * color;
        glm::vec3 diffuse = glm::vec3(0.5f) * color;
        glm::vec3 specular = glm::vec3(1.0f);

        context->shader->setVec3("light.ambient",  ambient);
        context->shader->setVec3("light.diffuse",  diffuse);
        context->shader->setVec3("light.specular", specular);
    }

    glm::vec3 LightSource::getColor() const {
        return color;
    }

    float LightSource::getStrength() const {
        return strength;
    }

    void LightSource::setPosition(glm::vec3 value) {
        this->position = value;
    }

    void LightSource::setColor(glm::vec3 value) {
        this->color = value;
    }
}
