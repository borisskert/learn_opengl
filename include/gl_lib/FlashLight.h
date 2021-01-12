#ifndef LEARN_OPENGL_FLASHLIGHT_H
#define LEARN_OPENGL_FLASHLIGHT_H


#include "LightSource.h"
#include "Camera.h"

namespace gl_lib {
    class FlashLight : public LightSource {
    private:
        glm::vec3 ambient = glm::vec3(0.1f);
        glm::vec3 diffuse = glm::vec3(0.8f);
        glm::vec3 specular = glm::vec3(1.0f);

        Camera *camera;

    public:
        explicit FlashLight(
                Camera *camera
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


#endif //LEARN_OPENGL_FLASHLIGHT_H
