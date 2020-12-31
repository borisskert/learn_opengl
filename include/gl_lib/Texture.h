#ifndef LEARN_OPENGL_TEXTURE_H
#define LEARN_OPENGL_TEXTURE_H

#include <gl_lib/gl_lib.h>


namespace gl_lib {

    class Texture {
    private:
        textureId id;
        const std::string path;

    public:
        explicit Texture(std::string path);

        void initialize();

        void bind();
    };

}


#endif //LEARN_OPENGL_TEXTURE_H
