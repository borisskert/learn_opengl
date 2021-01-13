#include "gl_lib/DiffuseTextured.h"


namespace gl_lib {
    DiffuseTextured::DiffuseTextured(gl_lib::Drawable *drawable, FileTexture *texture)
            : DrawableDecorator(drawable),
              texture(texture) {}


    void DiffuseTextured::prepare(Context *context) {
        this->decorated->prepare(context);

        context->shader->attachFragmentShader("assets/shader/fragment.mono-texture.shader");
    }


    void DiffuseTextured::initialize(Context *context) {
        this->decorated->initialize(context);
        this->texture->initialize();

        Shader *shader = context->shader;
        shader->use();
    }

    void DiffuseTextured::update(Context *context) {
        this->decorated->update(context);
    }

    void DiffuseTextured::draw(Context *context) {
        context->shader->setInt("material.diffuse", 0);
        context->shader->setVec3("material.specular", glm::vec3(0.5f));
        context->shader->setFloat("material.shininess", 32.0f);

        glActiveTexture(GL_TEXTURE0);
        texture->bind();

        this->decorated->draw(context);
    }
}