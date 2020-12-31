#ifndef LEARN_OPENGL_MODELADAPTER_H
#define LEARN_OPENGL_MODELADAPTER_H


#include <glm/vec3.hpp>
#include "Drawable.h"
#include "OpenGlBuffer.h"
#include "Shader.h"
#include "Model.h"

namespace gl_lib {

    class ModelAdapter : public Drawable {
    private:
        gl_lib::Model *model{};
        glm::vec3 position = glm::vec3(0.0f);
        float angle = 0.0f;

        void configureVertexArray();

        ModelAdapter();

    public:
        void prepare(Context *) override;

        void initialize(Context *) override;

        void update(Context *) override;

        void draw(Context *) override;

        class Builder;

        static ModelAdapter::Builder *builder();
    };


    class ModelAdapter::Builder {
    private:
        ModelAdapter cube;

    public:
        Builder();

        Builder *model(Model *);

        Builder *position(glm::vec3);

        Builder *angle(float);

        ModelAdapter build();
    };
}


#endif //LEARN_OPENGL_MODELADAPTER_H
