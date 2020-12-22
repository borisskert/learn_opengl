#include "gtest/gtest.h"
#include "../../gl_lib/src/Triangle.h"
#include "TestModels.h"


TEST(TriangleTests, shouldBuildVerticesModel) {
    Triangle triangle = buildTriangleOne();
    const ElementBufferObject &ebo = triangle.toElementBufferObject();


    ASSERT_EQ(ebo.indicesCount(), 3);
    ASSERT_EQ(ebo.verticesCount(), 9);

    float *vertices = ebo.getVertices();
    ASSERT_EQ(vertices[0], 0.5f);
    ASSERT_EQ(vertices[1], 0.5f);
    ASSERT_EQ(vertices[2], 0.0f);
    ASSERT_EQ(vertices[3], 0.5f);
    ASSERT_EQ(vertices[4], 0.0f);
    ASSERT_EQ(vertices[5], 0.0f);
    ASSERT_EQ(vertices[6], 0.0f);
    ASSERT_EQ(vertices[7], 0.0f);
    ASSERT_EQ(vertices[8], 0.0f);

    unsigned int *indices = ebo.getIndices();
    ASSERT_EQ(indices[0], 0);
    ASSERT_EQ(indices[1], 1);
    ASSERT_EQ(indices[2], 2);
}
