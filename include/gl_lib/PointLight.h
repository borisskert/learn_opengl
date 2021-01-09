#ifndef LEARN_OPENGL_LIGHTSOURCE_H
#define LEARN_OPENGL_LIGHTSOURCE_H

#include "LightSource.h"


namespace gl_lib {

    class PointLight : public LightSource {
    private:
        glm::vec3 position;
        glm::vec3 color;
        float strength;
        glm::vec3 scale;

        const int id;

    protected:
        glm::vec3 getModelPosition() override;

        glm::mat4 getModelMatrix() override;

        glm::mat4 getTransformMatrix() override;

    public:
        PointLight();

        PointLight(glm::vec3 position, glm::vec3 color, float strength, glm::vec3 scale);

        void prepare(Context *) override;

        void initialize(Context *) override;

        void update(Context *) override;

        void draw(Context *) override;

        void prepareLight(Context *) override;

        void renderLight(Context *) override;

        void configureVertexArray() const;

        glm::vec3 getColor() const;

        float getStrength() const;

        void setPosition(glm::vec3);

        void setColor(glm::vec3);

        glm::vec3 getBackgroundColor() const override;
    };
}


#endif //LEARN_OPENGL_LIGHTSOURCE_H
