#ifndef MYFIRSTOPENGL_ELEMENTBUFFEROBJECT_H
#define MYFIRSTOPENGL_ELEMENTBUFFEROBJECT_H


class ElementBufferObject {
private:
    int maxIndex = -1;
    std::vector<float> vertices;
    std::vector<unsigned int> indices;

public:
    ElementBufferObject() = default;

    void addVertex(float vertex) {
        this->vertices.push_back(vertex);
    }

    void addIndex(unsigned int index) {
        if ((int) index > this->maxIndex) {
            maxIndex = (int) index;
        }

        this->indices.push_back(index);
    }

    unsigned int verticesCount() const {
        return this->vertices.size();
    }

    unsigned int indicesCount() const {
        return this->indices.size();
    }

    float *getVertices() const {
        auto *verticesArray = new float[this->vertices.size()];

        for (int index = 0; index < this->vertices.size(); index++) {
            verticesArray[index] = this->vertices[index];
        }

        return verticesArray;
    }

    unsigned int *getIndices() const {
        auto *indicesArray = new unsigned int[this->indices.size()];

        for (int index = 0; index < this->indices.size(); index++) {
            indicesArray[index] = this->indices[index];
        }

        return indicesArray;
    }

    ElementBufferObject operator+(const ElementBufferObject &other) {
        ElementBufferObject result;

        for (float vertex : this->vertices) {
            result.vertices.push_back(vertex);
        }

        for (float vertex : other.vertices) {
            result.vertices.push_back(vertex);
        }

        for (unsigned int index : this->indices) {
            result.addIndex(index);
        }

        unsigned int indicesOffset = result.maxIndex + 1;

        for (unsigned int index : other.indices) {
            result.addIndex(index + indicesOffset);
        }

        return result;
    }

    ElementBufferObject &operator+=(const ElementBufferObject &other) {
        ElementBufferObject result = *this + other;

        this->maxIndex = result.maxIndex;
        this->indices = result.indices;
        this->vertices = result.vertices;

        return *this;
    }
};


#endif //MYFIRSTOPENGL_ELEMENTBUFFEROBJECT_H
