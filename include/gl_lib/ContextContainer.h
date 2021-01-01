#ifndef LEARN_OPENGL_CONTEXTCONTAINER_H
#define LEARN_OPENGL_CONTEXTCONTAINER_H


#include <map>
#include <vector>
#include "Context.h"
#include "Drawable.h"

namespace gl_lib {

    class ContextContainer {
    private:
        std::map<Drawable *, Context> contexts;
        std::vector<Drawable *> drawables;

    public:
        ContextContainer();

        Context getFor(Drawable *drawable);

        void store(Drawable *drawable, Context modelContext);

        std::vector<Drawable *> getDrawables();
    };
}


#endif //LEARN_OPENGL_CONTEXTCONTAINER_H
