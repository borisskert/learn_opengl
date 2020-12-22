#ifndef MYFIRSTOPENGL_VERTEXMODELS_H
#define MYFIRSTOPENGL_VERTEXMODELS_H

#include <vector>
#include "VertexModel.h"


class VertexModels : VertexModel {
private:
    std::vector<VertexModel *> vertexModels;

public:
    VertexModels() = default;

    void add(VertexModel *vertexModel) {
        this->vertexModels.push_back(vertexModel);
    }

    ElementBufferObject toElementBufferObject() const override {
        ElementBufferObject ebo;

        for (VertexModel *model : vertexModels) {
            ebo = ebo + model->toElementBufferObject();
        }

        return ebo;
    }
};


#endif //MYFIRSTOPENGL_VERTEXMODELS_H
