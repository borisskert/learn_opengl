#ifndef OPENGL_GAME_OF_LIFE_TEXTURE_H
#define OPENGL_GAME_OF_LIFE_TEXTURE_H


#include "gl_lib.h"

namespace gl_lib {

    struct Image {
        unsigned char *data;
        int width;
        int height;
    };

    class Texture {
    private:
        textureId id;
        const char *texturePath;

        void initializeTexture(Image image) const;

    public:
        explicit Texture(const char *texturePath);

        void initialize();

        textureId getId() const;
    };
}


#endif //OPENGL_GAME_OF_LIFE_TEXTURE_H
