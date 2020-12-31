#include <gl_lib/Image.h>
#include <gl_lib/RuntimeException.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"

namespace gl_lib {

    Image loadImage(const char *filePath) {
        int width, height, channels;

        stbi_set_flip_vertically_on_load(true);
        unsigned char *data = stbi_load(filePath, &width, &height, &channels, 0);

        if (data) {
            Image image;
            image.data = data;
            image.width = width;
            image.height = height;
            image.channels = channels;

            return image;
        } else {
            throw RuntimeException("Failed to load texture");
        }
    }
}
