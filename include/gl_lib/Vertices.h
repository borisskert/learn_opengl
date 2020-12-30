#ifndef LEARN_OPENGL_VERTICES_H
#define LEARN_OPENGL_VERTICES_H


namespace gl_lib {

    class Vertices {
    private:
        float *vertices;
        unsigned int size;

        explicit Vertices(unsigned int size);

    public:
        explicit Vertices(unsigned int size, float *vertices);

        ~Vertices();

        [[nodiscard]] float *toArray() const;

        [[nodiscard]] unsigned int getSize() const;

        Vertices operator+(const Vertices &other) const;
    };
}


#endif //LEARN_OPENGL_VERTICES_H
