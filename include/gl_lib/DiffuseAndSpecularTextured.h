#ifndef LEARN_OPENGL_DIFFUSEANDSPECULARTEXTURED_H
#define LEARN_OPENGL_DIFFUSEANDSPECULARTEXTURED_H


namespace gl_lib {
    class DiffuseAndSpecularTextured : public Drawable {
    private:
        Drawable *decorated;
        Texture *diffuse;
        Texture *specular;

    public:
        explicit DiffuseAndSpecularTextured(Drawable *, Texture *diffuse, Texture *specular);

        void prepare(Context *) override;

        void initialize(Context *) override;

        void update(Context *) override;

        void draw(Context *) override;
    };
}


#endif //LEARN_OPENGL_DIFFUSEANDSPECULARTEXTURED_H
