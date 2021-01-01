#include "gl_lib/DiffuseTextured.h"


namespace gl_lib {
    DiffuseTextured::DiffuseTextured(gl_lib::Drawable *drawable, Texture *texture)
            : DrawableDecorator(drawable),
              texture(texture) {}


    void DiffuseTextured::prepare(Context *context) {
        this->decorated->prepare(context);

        context->shader->attachFragmentShader("assets/shader/diffuse.textured.fragment.shader");
    }


    void DiffuseTextured::initialize(Context *context) {
        this->decorated->initialize(context);
        this->texture->initialize();

        Shader *shader = context->shader;
        shader->use();

        shader->setInt("material.diffuse", 0);
    }

    void DiffuseTextured::update(Context *context) {
        this->decorated->update(context);
    }

    void DiffuseTextured::draw(Context *context) {
        glActiveTexture(GL_TEXTURE0);
        texture->bind();

        this->decorated->draw(context);
    }
}