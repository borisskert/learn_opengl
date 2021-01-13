#ifndef LEARN_OPENGL_DIFFUSEANDSPECULARTEXTURED_H
#define LEARN_OPENGL_DIFFUSEANDSPECULARTEXTURED_H

#include "DrawableDecorator.h"


namespace gl_lib {
    class DiffuseAndSpecularTextured : public DrawableDecorator {
    private:
        FileTexture *diffuse;
        FileTexture *specular;

    public:
        explicit DiffuseAndSpecularTextured(Drawable *, FileTexture *diffuse, FileTexture *specular);

        void prepare(Context *) override;

        void initialize(Context *) override;

        void update(Context *) override;

        void draw(Context *) override;
    };
}


#endif //LEARN_OPENGL_DIFFUSEANDSPECULARTEXTURED_H
