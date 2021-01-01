#ifndef LEARN_OPENGL_TEXTURED_H
#define LEARN_OPENGL_TEXTURED_H


#include "Texture.h"
#include "DrawableDecorator.h"
#include <vector>


namespace gl_lib {

    /**
     * Decorator to add textures
     */
    class Textured : public DrawableDecorator {
    private:
        std::vector<Texture *> textures;

    public:
        explicit Textured(Drawable *);

        void addTexture(Texture *);

        void prepare(Context *) override;

        void initialize(Context *) override;

        void update(Context *) override;

        void draw(Context *) override;
    };
}


#endif //LEARN_OPENGL_TEXTURED_H
