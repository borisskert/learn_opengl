#ifndef LEARN_OPENGL_DIFFUSETEXTURED_H
#define LEARN_OPENGL_DIFFUSETEXTURED_H


#include "DrawableDecorator.h"
#include "FileTexture.h"

namespace gl_lib {

    class DiffuseTextured : public DrawableDecorator {
    private:
        FileTexture *texture;

    public:
        explicit DiffuseTextured(Drawable *, FileTexture *);

        void prepare(Context *) override;

        void initialize(Context *) override;

        void update(Context *) override;

        void draw(Context *) override;
    };
}


#endif //LEARN_OPENGL_DIFFUSETEXTURED_H
