#include "gtest/gtest.h"
#include "../../gl_lib/src/Rectangle.h"
#include "TestModels.h"


TEST(RectangleTests, shouldBuildVerticesModel) {
    Rectangle rectangle = buildRectangleOne();
    const ElementBufferObject &ebo = rectangle.toElementBufferObject();

    ASSERT_EQ(ebo.verticesCount(), 12);

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
    ASSERT_EQ(vertices[9], 0.0f);
    ASSERT_EQ(vertices[10], 0.5f);
    ASSERT_EQ(vertices[11], 0.0f);

    ASSERT_EQ(ebo.indicesCount(), 6);

    unsigned int *indices = ebo.getIndices();
    ASSERT_EQ(indices[0], 0);
    ASSERT_EQ(indices[1], 1);
    ASSERT_EQ(indices[2], 3);
    ASSERT_EQ(indices[3], 1);
    ASSERT_EQ(indices[4], 2);
    ASSERT_EQ(indices[5], 3);
}
