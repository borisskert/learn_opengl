#ifndef LEARN_OPENGL_FILETEXTURE_H
#define LEARN_OPENGL_FILETEXTURE_H

#include <gl_lib/gl_lib.h>


namespace gl_lib {

    class FileTexture {
    private:
        textureId id;
        const std::string path;

    public:
        explicit FileTexture(std::string path);

        void initialize();

        void bind();
    };

}


#endif //LEARN_OPENGL_FILETEXTURE_H
