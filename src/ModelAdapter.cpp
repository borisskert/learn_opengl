#include "gl_lib/ModelAdapter.h"
#include <glm/gtc/matrix_transform.hpp>


namespace gl_lib {

    ModelAdapter::ModelAdapter() = default;


    void ModelAdapter::configureVertexArray() {
        Vertices vertices = model->toVertices();

        glBufferData(GL_ARRAY_BUFFER, vertices.getSize() * sizeof(float), vertices.toArray(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void *) 0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void *) (3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void *) (6 * sizeof(float)));
        glEnableVertexAttribArray(2);

        glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void *) (8 * sizeof(float)));
        glEnableVertexAttribArray(3);
    }


    void ModelAdapter::prepare(Context *context) {
        context->shader->attachVertexShader("assets/shader/vertex.shader");
        context->shader->attachFragmentShader("assets/shader/fragment.main.shader");
    }


    void ModelAdapter::initialize(Context *context) {
        context->buffer->initialize();

        context->buffer->bindVertexArray();
        this->configureVertexArray();

        context->shader->initialize();
    }


    void ModelAdapter::update(Context *context) {
        context->shader->setMat4("model", this->getModelMatrix());
        context->shader->setMat4("transform", this->getTransformMatrix());
    }


    void ModelAdapter::draw(Context *context) {
        context->buffer->bindVertexArray();
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }


    ModelAdapter::Builder *ModelAdapter::builder() {
        return new Builder();
    }

    glm::vec3 ModelAdapter::getModelPosition() {
        return position;
    }

    glm::mat4 ModelAdapter::getModelMatrix() {
        return glm::translate(glm::mat4(1.0f), position);
    }

    glm::mat4 ModelAdapter::getTransformMatrix() {
        return glm::mat4(1.0f);
    }


    ModelAdapter::Builder::Builder() = default;


    ModelAdapter::Builder *ModelAdapter::Builder::model(Model *model) {
        this->cube.model = model;
        return this;
    }

    ModelAdapter::Builder *ModelAdapter::Builder::position(glm::vec3 value) {
        cube.position = value;
        return this;
    }


    ModelAdapter::Builder *ModelAdapter::Builder::angle(float value) {
        cube.angle = value;
        return this;
    }


    ModelAdapter ModelAdapter::Builder::build() {
        return cube;
    }
}
