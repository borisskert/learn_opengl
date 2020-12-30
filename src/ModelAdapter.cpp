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


    void ModelAdapter::initialize(Context *context) {
        context->buffer->initialize();

        context->buffer->bindVertexArray();
        this->configureVertexArray();

        context->textures->initialize();

        Shader *shader = context->shader;
        shader->setInt("texture1", 0);
        shader->setInt("texture2", 1);
    }


    void ModelAdapter::update(Context *context) {
        Shader *shader = context->shader;

        glm::mat4 modelMatrix = glm::mat4(1.0f);
        modelMatrix = glm::translate(modelMatrix, position);
        modelMatrix = glm::rotate(modelMatrix, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

        double time = glfwGetTime();

        modelMatrix = glm::rotate(modelMatrix, (float) time / 20 * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
        shader->setMat4("model", modelMatrix);

        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(glm::cos(time / 100), glm::sin(time / 100), 0.0f));
        trans = glm::rotate(trans, (float) time / 50, glm::vec3(0.0f, 0.0f, 1.0f));

        shader->setMat4("transform", trans);
    }


    void ModelAdapter::draw(Context *context) {
        context->textures->bindTextures();
        context->buffer->bindVertexArray();
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }


    ModelAdapter::Builder *ModelAdapter::builder() {
        return new Builder();
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
