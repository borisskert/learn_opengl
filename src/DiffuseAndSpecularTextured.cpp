#include <gl_lib/Drawable.h>
#include <gl_lib/Texture.h>
#include "gl_lib/DiffuseAndSpecularTextured.h"


namespace gl_lib {
    DiffuseAndSpecularTextured::DiffuseAndSpecularTextured(
            gl_lib::Drawable *drawable,
            Texture *diffuse,
            Texture *specular
    )
            : decorated(drawable),
              diffuse(diffuse),
              specular(specular) {}


    void DiffuseAndSpecularTextured::prepare(Context *context) {
        this->decorated->prepare(context);

        context->shader->attachFragmentShader("assets/shader/diffuse-and-specular.textured.fragment.shader");
    }


    void DiffuseAndSpecularTextured::initialize(Context *context) {
        this->decorated->initialize(context);
        this->diffuse->initialize();
        this->specular->initialize();

        Shader *shader = context->shader;
        shader->use();

        shader->setInt("material.diffuse", 0);
        shader->setInt("material.specular", 1);
    }

    void DiffuseAndSpecularTextured::update(Context *context) {
        this->decorated->update(context);
    }

    void DiffuseAndSpecularTextured::draw(Context *context) {
        glActiveTexture(GL_TEXTURE0);
        diffuse->bind();

        glActiveTexture(GL_TEXTURE1);
        specular->bind();

        this->decorated->draw(context);
    }
}
