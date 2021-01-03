#ifndef LEARN_OPENGL_SIMPLECOLORED_H
#define LEARN_OPENGL_SIMPLECOLORED_H


#include "DrawableDecorator.h"

namespace gl_lib {

    class SimpleColored : public DrawableDecorator  {
    public:
        explicit SimpleColored(Drawable *);

        void prepare(Context *) override;

        void initialize(Context *) override;

        void update(Context *) override;

        void draw(Context *) override;
    };
}


#endif //LEARN_OPENGL_SIMPLECOLORED_H
