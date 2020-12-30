#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <gl_lib/Triangle.h>

using namespace gl_lib;


TEST(TriangleTests, shouldCreateNormalVector) {
    Triangle triangle = Triangle::builder()
            ->positionA(glm::vec3(-0.5f, -0.5f, 0.0f))
            ->positionB(glm::vec3(0.5f, -0.5f, 0.0f))
            ->positionC(glm::vec3(0.5f, 0.5f, 0.0f))
            ->build();

    glm::vec3 normal = triangle.normal();

    ASSERT_EQ(normal, glm::vec3(0.0f, 0.0f, -1.0f));
}


TEST(TriangleTests, shouldCreateVertices) {
    Triangle triangle = Triangle::builder()
            ->positionA(glm::vec3(-0.5f, -0.5f, 0.0f))
            ->positionB(glm::vec3(0.5f, -0.5f, 0.0f))
            ->positionC(glm::vec3(0.5f, 0.5f, 0.0f))
            ->colorA(glm::vec3(0.9f, 0.8f, 0.7f))
            ->colorB(glm::vec3(0.6f, 0.5f, 0.4f))
            ->colorC(glm::vec3(0.3f, 0.2f, 0.1f))
            ->build();

    const Vertices &vertices = triangle.toVertices();

    ASSERT_EQ(vertices.getSize(), 33);

    float expectedVertices[] = {
            -0.5f, -0.5f, 0.0f, 0.9f, 0.8f, 0.7f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,
            0.5f, -0.5f, 0.0f, 0.6f, 0.5f, 0.4f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f,
            0.5f, 0.5f, 0.0f, 0.3f, 0.2f, 0.1f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
    };

    float* actualArray = vertices.toArray();
    EXPECT_THAT(expectedVertices, ::testing::ElementsAreArray(actualArray, vertices.getSize()));
}
