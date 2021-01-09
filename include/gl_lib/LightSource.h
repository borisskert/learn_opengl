#ifndef LEARN_OPENGL_POINTLIGHT_H
#define LEARN_OPENGL_POINTLIGHT_H

#include "Drawable.h"
#include "LightSourceId.h"


namespace gl_lib {

    class LightSource : public Drawable {
    public:
        virtual void prepareLight(Context *) = 0;

        virtual void renderLight(Context *) = 0;

        virtual glm::vec3 getBackgroundColor() const = 0;
    };
}


#endif //LEARN_OPENGL_POINTLIGHT_H
