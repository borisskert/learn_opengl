#ifndef MYFIRSTOPENGL_VERTEXMODEL_H
#define MYFIRSTOPENGL_VERTEXMODEL_H


#include "ElementBufferObject.h"


class VertexModel {
public:
    virtual ElementBufferObject toElementBufferObject() const = 0;
};


#endif //MYFIRSTOPENGL_VERTEXMODEL_H
