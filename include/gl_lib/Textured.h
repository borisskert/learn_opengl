#ifndef LEARN_OPENGL_TEXTURED_H
#define LEARN_OPENGL_TEXTURED_H


#include "Drawable.h"
#include "Texture.h"

namespace gl_lib {

    /**
     * Decorator to add textures
     */
    class Textured : public Drawable {
    private:
        Drawable *decorated;
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
