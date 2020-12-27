#ifndef LEARN_OPENGL_IMAGE_H
#define LEARN_OPENGL_IMAGE_H

namespace gl_lib {

    struct Image {
        unsigned char *data;
        int width;
        int height;
        int channels;
    };


    Image loadImage(const char *filePath);
}

#endif //LEARN_OPENGL_IMAGE_H
