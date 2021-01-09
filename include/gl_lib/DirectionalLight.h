#ifndef LEARN_OPENGL_DIRECTIONALLIGHT_H
#define LEARN_OPENGL_DIRECTIONALLIGHT_H

#include <glm/vec3.hpp>
#include "LightSource.h"


namespace gl_lib {
    class DirectionalLight : public LightSource {
    private:
        glm::vec3 direction;
        glm::vec3 ambient;
        glm::vec3 diffuse;
        glm::vec3 specular;

    public:
        DirectionalLight();

        DirectionalLight(
                glm::vec3 direction,
                glm::vec3 ambient,
                glm::vec3 diffuse,
                glm::vec3 specular
        );

        void prepare(Context *) override;

        void initialize(Context *) override;

        void update(Context *) override;

        void draw(Context *) override;

        void prepareLight(Context *) override;

        void renderLight(Context *) override;

        glm::vec3 getBackgroundColor() const override;

        glm::vec3 getModelPosition() override;

        glm::mat4 getModelMatrix() override;

        glm::mat4 getTransformMatrix() override;
    };
}


#endif //LEARN_OPENGL_DIRECTIONALLIGHT_H
