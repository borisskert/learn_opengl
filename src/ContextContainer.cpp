#include "gl_lib/ContextContainer.h"

namespace gl_lib {

    ContextContainer::ContextContainer() = default;


    void ContextContainer::store(Drawable *drawable, Context modelContext) {
        contexts[drawable] = modelContext;
        drawables.push_back(drawable);
    }


    Context ContextContainer::getFor(Drawable *drawable) {
        return contexts[drawable];
    }


    std::vector<Drawable *> ContextContainer::getDrawables() {
        return drawables;
    }
}
