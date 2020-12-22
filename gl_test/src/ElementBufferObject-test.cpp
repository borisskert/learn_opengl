#include "gtest/gtest.h"
#include "../../gl_lib/src/Rectangle.h"


TEST(ElementBufferObjectTests, shouldAddTriangleIndicesByPlusOperator) {
    ElementBufferObject eboOne = ElementBufferObject();
    eboOne.addIndex(0);
    eboOne.addIndex(1);
    eboOne.addIndex(2);

    ElementBufferObject eboTwo = ElementBufferObject();
    eboTwo.addIndex(0);
    eboTwo.addIndex(1);
    eboTwo.addIndex(2);

    ElementBufferObject result = eboOne + eboTwo;

    ASSERT_EQ(result.indicesCount(), 6);

    unsigned int *indices = result.getIndices();
    ASSERT_EQ(indices[0], 0);
    ASSERT_EQ(indices[1], 1);
    ASSERT_EQ(indices[2], 2);
    ASSERT_EQ(indices[3], 3);
    ASSERT_EQ(indices[4], 4);
    ASSERT_EQ(indices[5], 5);
}


TEST(ElementBufferObjectTests, shouldAddRectangleIndicesByPlusOperator) {
    ElementBufferObject eboOne = ElementBufferObject();
    eboOne.addIndex(0);
    eboOne.addIndex(1);
    eboOne.addIndex(3);
    eboOne.addIndex(1);
    eboOne.addIndex(2);
    eboOne.addIndex(3);

    ElementBufferObject eboTwo = ElementBufferObject();
    eboTwo.addIndex(0);
    eboTwo.addIndex(1);
    eboTwo.addIndex(3);
    eboTwo.addIndex(1);
    eboTwo.addIndex(2);
    eboTwo.addIndex(3);

    ElementBufferObject result = eboOne + eboTwo;

    ASSERT_EQ(result.indicesCount(), 12);

    unsigned int *indices = result.getIndices();
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


TEST(ElementBufferObjectTests, shouldAddTriangleAndRectangleIndicesByPlusOperator) {
    ElementBufferObject eboOne = ElementBufferObject();
    eboOne.addIndex(0);
    eboOne.addIndex(1);
    eboOne.addIndex(2);

    ElementBufferObject eboTwo = ElementBufferObject();
    eboTwo.addIndex(0);
    eboTwo.addIndex(1);
    eboTwo.addIndex(3);
    eboTwo.addIndex(1);
    eboTwo.addIndex(2);
    eboTwo.addIndex(3);

    ElementBufferObject result = eboOne + eboTwo;

    ASSERT_EQ(result.indicesCount(), 9);

    unsigned int *indices = result.getIndices();
    ASSERT_EQ(indices[0], 0);
    ASSERT_EQ(indices[1], 1);
    ASSERT_EQ(indices[2], 2);
    ASSERT_EQ(indices[3], 3);
    ASSERT_EQ(indices[4], 4);
    ASSERT_EQ(indices[5], 6);
    ASSERT_EQ(indices[6], 4);
    ASSERT_EQ(indices[7], 5);
    ASSERT_EQ(indices[8], 6);
}


TEST(ElementBufferObjectTests, shouldAddTriangleIndicesByPlusEqualOperator) {
    ElementBufferObject eboOne = ElementBufferObject();
    eboOne.addIndex(0);
    eboOne.addIndex(1);
    eboOne.addIndex(2);

    ElementBufferObject eboTwo = ElementBufferObject();
    eboTwo.addIndex(0);
    eboTwo.addIndex(1);
    eboTwo.addIndex(2);

    eboOne += eboTwo;

    ASSERT_EQ(eboOne.indicesCount(), 6);

    unsigned int *indices = eboOne.getIndices();
    ASSERT_EQ(indices[0], 0);
    ASSERT_EQ(indices[1], 1);
    ASSERT_EQ(indices[2], 2);
    ASSERT_EQ(indices[3], 3);
    ASSERT_EQ(indices[4], 4);
    ASSERT_EQ(indices[5], 5);
}


TEST(ElementBufferObjectTests, shouldAddRectangleIndicesByPlusEqualOperator) {
    ElementBufferObject eboOne = ElementBufferObject();
    eboOne.addIndex(0);
    eboOne.addIndex(1);
    eboOne.addIndex(3);
    eboOne.addIndex(1);
    eboOne.addIndex(2);
    eboOne.addIndex(3);

    ElementBufferObject eboTwo = ElementBufferObject();
    eboTwo.addIndex(0);
    eboTwo.addIndex(1);
    eboTwo.addIndex(3);
    eboTwo.addIndex(1);
    eboTwo.addIndex(2);
    eboTwo.addIndex(3);

    eboOne += eboTwo;

    ASSERT_EQ(eboOne.indicesCount(), 12);

    unsigned int *indices = eboOne.getIndices();
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


TEST(ElementBufferObjectTests, shouldAddTriangleAndRectangleIndicesByPlusEqualOperator) {
    ElementBufferObject eboOne = ElementBufferObject();
    eboOne.addIndex(0);
    eboOne.addIndex(1);
    eboOne.addIndex(2);

    ElementBufferObject eboTwo = ElementBufferObject();
    eboTwo.addIndex(0);
    eboTwo.addIndex(1);
    eboTwo.addIndex(3);
    eboTwo.addIndex(1);
    eboTwo.addIndex(2);
    eboTwo.addIndex(3);

    eboOne += eboTwo;

    ASSERT_EQ(eboOne.indicesCount(), 9);

    unsigned int *indices = eboOne.getIndices();
    ASSERT_EQ(indices[0], 0);
    ASSERT_EQ(indices[1], 1);
    ASSERT_EQ(indices[2], 2);
    ASSERT_EQ(indices[3], 3);
    ASSERT_EQ(indices[4], 4);
    ASSERT_EQ(indices[5], 6);
    ASSERT_EQ(indices[6], 4);
    ASSERT_EQ(indices[7], 5);
    ASSERT_EQ(indices[8], 6);
}
