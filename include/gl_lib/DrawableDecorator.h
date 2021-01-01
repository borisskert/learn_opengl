#ifndef LEARN_OPENGL_DRAWABLEDECORATOR_H
#define LEARN_OPENGL_DRAWABLEDECORATOR_H


#include "Drawable.h"

namespace gl_lib {
    class DrawableDecorator : public Drawable {
    protected:
        Drawable *decorated;

    public:
        DrawableDecorator(Drawable *decorated) : decorated(decorated) {};


        virtual glm::vec3 getModelPosition() override {
            return decorated->getModelPosition();
        };

        virtual glm::mat4 getModelMatrix() override {
            return decorated->getModelMatrix();
        };

        virtual glm::mat4 getTransformMatrix() override {
            return decorated->getTransformMatrix();
        };


        virtual void prepare(Context *context) override {
            this->decorated->prepare(context);
        }

        virtual void initialize(Context *context) override {
            this->decorated->initialize(context);
        };

        virtual void update(Context *context) override {
            this->decorated->update(context);
        };

        virtual void draw(Context *context) override {
            this->decorated->draw(context);
        };
    };
}


#endif //LEARN_OPENGL_DRAWABLEDECORATOR_H
