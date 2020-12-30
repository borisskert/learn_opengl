#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <gl_lib/Vertices.h>

using namespace gl_lib;

TEST(VerticesTests, shouldAddVerticesByPlusOperator) {
    float verticesA[] = {
            0.44f, 0.33
    };

    Vertices a(2, verticesA);

    float verticesB[] = {
            0.77f, 0.22, 0.11
    };
    Vertices b(3, verticesB);


    Vertices c = a + b;


    ASSERT_EQ(c.getSize(), 5);

    float expectedVertices[] = {
            0.44f, 0.33,
            0.77f, 0.22, 0.11
    };

    float* actualArray = c.toArray();
    EXPECT_THAT(expectedVertices, ::testing::ElementsAreArray(actualArray, c.getSize()));
}

