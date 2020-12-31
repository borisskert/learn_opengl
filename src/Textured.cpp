#include "gl_lib/Textured.h"

namespace gl_lib {

    Textured::Textured(gl_lib::Drawable *drawable) : decorated(drawable) {}


    void Textured::addTexture(gl_lib::Texture *texture) {
        this->textures.push_back(texture);
    }


    void Textured::prepare(Context *context) {
        this->decorated->prepare(context);
    }


    void Textured::initialize(Context *context) {
        this->decorated->initialize(context);

        for(Texture* texture : textures) {
            texture->initialize();
        }

        Shader *shader = context->shader;
        shader->use();

        if (!this->textures.empty()) {
            shader->setInt("texture1", 0);
        }

        if (this->textures.size() > 1) {
            shader->setInt("texture2", 1);
        }
    }

    void Textured::update(Context *context) {
        this->decorated->update(context);
    }

    void Textured::draw(Context *context) {
        for (int index = 0; index < this->textures.size(); index++) {
            Texture *texture = this->textures[index];

            glActiveTexture(GL_TEXTURE0 + index);
            texture->bind();
        }

        this->decorated->draw(context);
    }
}
