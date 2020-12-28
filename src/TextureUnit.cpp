#include <gl_lib/TextureUnit.h>
#include <gl_lib/gl_lib.h>

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"


namespace gl_lib {

    TextureUnit::TextureUnit() = default;


    void TextureUnit::addTexture(Texture *texture) {
        this->textures.push_back(texture);
    }


    void TextureUnit::initialize() {
        for (Texture *texture : textures) {
            texture->initialize();
        }
    }


    void TextureUnit::bindTextures() {
        for (int index = 0; index < this->textures.size(); index++) {
            Texture *texture = this->textures[index];

            glActiveTexture(GL_TEXTURE0 + index);
            texture->bind();
        }
    }
}
