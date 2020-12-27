#include <gl_lib/Texture.h>
#include <gl_lib/gl_lib.h>
#include <gl_lib/RuntimeException.h>

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"

namespace gl_lib {

    Image loadImage(const char *texturePath) {
        int width, height, nrChannels;
        unsigned char *data = stbi_load(texturePath, &width, &height, &nrChannels, 0);

        if (data) {
            Image image;
            image.data = data;
            image.width = width;
            image.height = height;

            return image;
        } else {
            throw RuntimeException("Failed to load texture");
        }
    }

    Texture::Texture(const char *texturePath) : texturePath(texturePath) {}


    void Texture::initialize() {
        Image image = loadImage(this->texturePath);

        id = createTexture();

        initializeTexture(image);

        stbi_image_free(image.data);
    }


    void Texture::initializeTexture(Image image) const {
        glBindTexture(GL_TEXTURE_2D, id);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.width, image.height, 0, GL_RGB, GL_UNSIGNED_BYTE, image.data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    textureId Texture::getId() const {
        return id;
    }
}