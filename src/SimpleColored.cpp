#include "gl_lib/SimpleColored.h"

namespace gl_lib {
    SimpleColored::SimpleColored(gl_lib::Drawable *decorated)
            : DrawableDecorator(decorated) {}


    void SimpleColored::prepare(Context *context) {
        DrawableDecorator::prepare(context);

        context->shader->attachFragmentShader("assets/shader/fragment.simple-color.shader");
    }


    void SimpleColored::initialize(Context *context) {
        DrawableDecorator::initialize(context);
    }


    void SimpleColored::update(Context *context) {
        DrawableDecorator::update(context);
    }


    void SimpleColored::draw(Context *context) {


        context->shader->setVec3("material.ambient", glm::vec3(1.0f));
        context->shader->setVec3("material.diffuse", glm::vec3(1.0f));
        context->shader->setVec3("material.specular", glm::vec3(0.5f));
        context->shader->setFloat("material.shininess", 32.0f);

        DrawableDecorator::draw(context);
    }
}
