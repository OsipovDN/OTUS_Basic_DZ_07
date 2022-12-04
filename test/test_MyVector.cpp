#include <gtest/gtest.h>
#include "myVector.h"

TEST(Vector, Size) {
    MyVector <int> Vec;

    ASSERT_EQ(Vec.size(), 0);

}

TEST(Vector, PushBack) {
    // Arrange
    const size_t count = 10;
    size_t val= 20;
    MyVector <size_t> Vec;

    // Act
    for (size_t i = 0; i < count; ++i) {
        Vec.push_back(i);
    }
    Vec.push_back(val);

    // Assert
    ASSERT_EQ(Vec.size(), count+1);
    ASSERT_EQ(Vec[10], val);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}