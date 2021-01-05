#ifndef LEARN_OPENGL_GAME_H
#define LEARN_OPENGL_GAME_H

#include <vector>
#include <gl_lib/Drawable.h>
#include <gl_lib/LightSource.h>
#include <gl_lib/Watch.h>


namespace gl_lib {
    class Game {
    public:
        virtual std::vector<Drawable *> getObjects() = 0;

        virtual std::vector<gl_lib::LightSource *> getLights() = 0;

        virtual void update(const Watch *) = 0;
    };
}


#endif //LEARN_OPENGL_GAME_H
