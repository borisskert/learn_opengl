#ifndef LEARN_OPENGL_LIGHTSOURCE_H
#define LEARN_OPENGL_LIGHTSOURCE_H


#include "Drawable.h"

namespace gl_lib {

    class LightSource : public Drawable {
    private:
        glm::vec3 position;
        glm::vec3 color;
        float strength;
        glm::vec3 scale;

    public:
        LightSource();

        LightSource(glm::vec3 position, glm::vec3 color, float strength, glm::vec3 scale);

        void prepare(Context *) override;

        void initialize(Context *) override;

        void update(Context *) override;

        void draw(Context *) override;

        void renderLight(Context *);

        void configureVertexArray() const;

        glm::vec3 getColor() const;

        float getStrength() const;

        void setPosition(glm::vec3);

        void setColor(glm::vec3);
    };
}


#endif //LEARN_OPENGL_LIGHTSOURCE_H
