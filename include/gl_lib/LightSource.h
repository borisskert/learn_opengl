#ifndef LEARN_OPENGL_LIGHTSOURCE_H
#define LEARN_OPENGL_LIGHTSOURCE_H


#include "Drawable.h"

namespace gl_lib {

    class LightSource : public Drawable {
    private:
        glm::vec3 position;
        glm::vec3 color;
        glm::vec3 scale;

    public:
        LightSource();

        LightSource(glm::vec3 position, glm::vec3 color, glm::vec3 scale);

        void initialize(Context *) override;

        void update(Context *) override;

        void draw(Context *) override;

        void renderLight(Context *);

        void configureVertexArray() const;
    };
}



#endif //LEARN_OPENGL_LIGHTSOURCE_H
