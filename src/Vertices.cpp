#include <algorithm>
#include "gl_lib/Vertices.h"

namespace gl_lib {

    Vertices::Vertices(unsigned int size)
            : size(size),
              vertices(new float[size]) {}

    Vertices::Vertices(unsigned int size, float *vertices)
            : size(size),
              vertices(new float[size]) {
        std::copy(vertices, vertices + size, this->vertices);
    }


    float *Vertices::toArray() const {
        return vertices;
    }

    unsigned int Vertices::getSize() const {
        return size;
    }

    Vertices::~Vertices() {
        delete[] vertices;
    }

    Vertices Vertices::operator+(const Vertices &other) const {
        Vertices sum = Vertices(this->size + other.size);

        std::copy(this->vertices, this->vertices + this->size, sum.vertices);
        std::copy(other.vertices, other.vertices + other.size, sum.vertices + this->size);

        return sum;
    }
}
