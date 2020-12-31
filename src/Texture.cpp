#include <gl_lib/Image.h>
#include <utility>
#include "gl_lib/Texture.h"
#include "stb_image.h"


namespace gl_lib {

    Texture::Texture(std::string path) : path(std::move(path)) {}


    void Texture::initialize() {
        Image image = loadImage(this->path.c_str());

        this->id = createTexture();

        glBindTexture(GL_TEXTURE_2D, this->id);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_REPEAT);

        int internalFormat = image.channels > 3 ? GL_RGBA : GL_RGB;

        glTexImage2D(
                GL_TEXTURE_2D, 0, internalFormat,
                image.width, image.height,
                0, internalFormat, GL_UNSIGNED_BYTE,
                image.data
        );
        glGenerateMipmap(GL_TEXTURE_2D);


        stbi_image_free(image.data);
    }


    void Texture::bind() {
        glBindTexture(GL_TEXTURE_2D, this->id);
    }
}
