#include "gtest/gtest.h"
#include "../../gl_lib/src/VertexModels.h"
#include "TestModels.h"


TEST(VertexModelsTests, shouldBuildEmptyInstance) {
    //arrange
    VertexModels models;

    const ElementBufferObject &config = models.toElementBufferObject();

    //assert
    ASSERT_EQ(config.indicesCount(), 0);
    ASSERT_EQ(config.verticesCount(), 0);
}


TEST(VertexModelsTests, shouldBuildForOneTriangle) {
    //arrange
    VertexModels models;

    Triangle triangle = buildTriangleOne();
    models.add(&triangle);

    const ElementBufferObject &ebo = models.toElementBufferObject();

    //assert
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

    ASSERT_EQ(ebo.indicesCount(), 3);

    unsigned int *indices = ebo.getIndices();
    ASSERT_EQ(indices[0], 0);
    ASSERT_EQ(indices[1], 1);
    ASSERT_EQ(indices[2], 2);
}


TEST(VertexModelsTests, shouldBuildForTwoTriangles) {
    //arrange
    VertexModels models;

    Triangle triangleOne = buildTriangleOne();
    models.add(&triangleOne);

    Triangle triangleTwo = buildTriangleTwo();
    models.add(&triangleTwo);

    const ElementBufferObject &ebo = models.toElementBufferObject();

    //assert
    ASSERT_EQ(ebo.verticesCount(), 18);

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
    ASSERT_EQ(vertices[9], -0.5f);
    ASSERT_EQ(vertices[10], -0.5f);
    ASSERT_EQ(vertices[11], 0.0f);
    ASSERT_EQ(vertices[12], -0.5f);
    ASSERT_EQ(vertices[13], 0.0f);
    ASSERT_EQ(vertices[14], 0.0f);
    ASSERT_EQ(vertices[15], 0.0f);
    ASSERT_EQ(vertices[16], 0.0f);
    ASSERT_EQ(vertices[17], 0.0f);

    ASSERT_EQ(ebo.indicesCount(), 6);

    unsigned int *indices = ebo.getIndices();
    ASSERT_EQ(indices[0], 0);
    ASSERT_EQ(indices[1], 1);
    ASSERT_EQ(indices[2], 2);
    ASSERT_EQ(indices[3], 3);
    ASSERT_EQ(indices[4], 4);
    ASSERT_EQ(indices[5], 5);
}


TEST(VertexModelsTests, shouldBuildForOneRectangle) {
    //arrange
    VertexModels models;

    Rectangle rectangle = buildRectangleOne();
    models.add(&rectangle);

    const ElementBufferObject &config = models.toElementBufferObject();

    //assert
    ASSERT_EQ(config.verticesCount(), 12);

    float *vertices = config.getVertices();
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

    ASSERT_EQ(config.indicesCount(), 6);

    unsigned int *indices = config.getIndices();
    ASSERT_EQ(indices[0], 0);
    ASSERT_EQ(indices[1], 1);
    ASSERT_EQ(indices[2], 3);
    ASSERT_EQ(indices[3], 1);
    ASSERT_EQ(indices[4], 2);
    ASSERT_EQ(indices[5], 3);
}


TEST(VertexModelsTests, shouldBuildForTwoRectangles) {
    //arrange
    VertexModels models;

    Rectangle rectangleOne = buildRectangleOne();
    models.add(&rectangleOne);

    Rectangle rectangleTwo = buildRectangleTwo();
    models.add(&rectangleTwo);

    const ElementBufferObject &ebo = models.toElementBufferObject();

    //assert
    ASSERT_EQ(ebo.verticesCount(), 24);

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

    ASSERT_EQ(vertices[12], -0.5f);
    ASSERT_EQ(vertices[13], -0.5f);
    ASSERT_EQ(vertices[14], 0.0f);
    ASSERT_EQ(vertices[15], -0.5f);
    ASSERT_EQ(vertices[16], 0.0f);
    ASSERT_EQ(vertices[17], 0.0f);
    ASSERT_EQ(vertices[18], 0.0f);
    ASSERT_EQ(vertices[19], 0.0f);
    ASSERT_EQ(vertices[20], 0.0f);
    ASSERT_EQ(vertices[21], 0.0f);
    ASSERT_EQ(vertices[22], -0.5f);
    ASSERT_EQ(vertices[23], 0.0f);

    ASSERT_EQ(ebo.indicesCount(), 12);

    unsigned int *indices = ebo.getIndices();
    ASSERT_EQ(indices[0], 0);
    ASSERT_EQ(indices[1], 1);
    ASSERT_EQ(indices[2], 3);
    ASSERT_EQ(indices[3], 1);
    ASSERT_EQ(indices[4], 2);
    ASSERT_EQ(indices[5], 3);

    ASSERT_EQ(indices[6], 4);
    ASSERT_EQ(indices[7], 5);
    ASSERT_EQ(indices[8], 7);
    ASSERT_EQ(indices[9], 5);
    ASSERT_EQ(indices[10], 6);
    ASSERT_EQ(indices[11], 7);
}


TEST(VertexModelsTests, shouldBuildForTwoRectanglesAndOneTriangle) {
    //arrange
    VertexModels models;

    Rectangle rectangleOne = buildRectangleOne();
    models.add(&rectangleOne);

    Rectangle rectangleTwo = buildRectangleTwo();
    models.add(&rectangleTwo);

    Triangle triangleOne = buildTriangleOne();
    models.add(&triangleOne);

    const ElementBufferObject &config = models.toElementBufferObject();

    //assert
    ASSERT_EQ(config.verticesCount(), 33);

    float *vertices = config.getVertices();
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

    ASSERT_EQ(vertices[12], -0.5f);
    ASSERT_EQ(vertices[13], -0.5f);
    ASSERT_EQ(vertices[14], 0.0f);
    ASSERT_EQ(vertices[15], -0.5f);
    ASSERT_EQ(vertices[16], 0.0f);
    ASSERT_EQ(vertices[17], 0.0f);
    ASSERT_EQ(vertices[18], 0.0f);
    ASSERT_EQ(vertices[19], 0.0f);
    ASSERT_EQ(vertices[20], 0.0f);
    ASSERT_EQ(vertices[21], 0.0f);
    ASSERT_EQ(vertices[22], -0.5f);
    ASSERT_EQ(vertices[23], 0.0f);

    ASSERT_EQ(vertices[24], 0.5f);
    ASSERT_EQ(vertices[25], 0.5f);
    ASSERT_EQ(vertices[26], 0.0f);
    ASSERT_EQ(vertices[27], 0.5f);
    ASSERT_EQ(vertices[28], 0.0f);
    ASSERT_EQ(vertices[29], 0.0f);
    ASSERT_EQ(vertices[30], 0.0f);
    ASSERT_EQ(vertices[31], 0.0f);
    ASSERT_EQ(vertices[32], 0.0f);

    ASSERT_EQ(config.indicesCount(), 15);

    unsigned int *indices = config.getIndices();
    ASSERT_EQ(indices[0], 0);
    ASSERT_EQ(indices[1], 1);
    ASSERT_EQ(indices[2], 3);
    ASSERT_EQ(indices[3], 1);
    ASSERT_EQ(indices[4], 2);
    ASSERT_EQ(indices[5], 3);

    ASSERT_EQ(indices[6], 4);
    ASSERT_EQ(indices[7], 5);
    ASSERT_EQ(indices[8], 7);
    ASSERT_EQ(indices[9], 5);
    ASSERT_EQ(indices[10], 6);
    ASSERT_EQ(indices[11], 7);

    ASSERT_EQ(indices[12], 8);
    ASSERT_EQ(indices[13], 9);
    ASSERT_EQ(indices[14], 10);
}
