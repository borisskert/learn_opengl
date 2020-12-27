#ifndef LEARN_OPENGL_TEXTUREUNIT_H
#define LEARN_OPENGL_TEXTUREUNIT_H


#include "gl_lib.h"
#include "Image.h"
#include "Texture.h"
#include <vector>


namespace gl_lib {

    class TextureUnit {
    private:
        std::vector<Texture*> textures;

    public:
        explicit TextureUnit();

        void addTexture(Texture*);

        void initialize();

        void bindTextures();
    };
}


#endif //LEARN_OPENGL_TEXTUREUNIT_H
