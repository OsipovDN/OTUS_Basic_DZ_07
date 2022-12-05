#include <gtest/gtest.h>
#include "ImplVector.h"
#include <iostream>

TEST(Vector, Size) {
    // Arrange
    ImplVector <int> Vec;
    // Assert
    std::cout << "Checking the size of an empty container" << std::endl;
    ASSERT_EQ(Vec.size(), 0);

}

TEST(Vector, PushBack) {
    // Arrange
    const size_t count = 10;
    size_t val= 20;
    ImplVector <size_t> Vec;

    // Act
    for (size_t i = 0; i < count; ++i) {
        Vec.push_back(i);
    }
    Vec.push_back(val);

    // Assert
    std::cout << "Checking the size of container" << std::endl;
    EXPECT_EQ(Vec.size(), (count+1));
    std::cout << "Checking the element inserted at the end" << std::endl;
    ASSERT_EQ(Vec[10], val);
}

TEST(Vector, InsertFront) {
    // Arrange
    const size_t count = 10;
    size_t val = 20;
    ImplVector <size_t> Vec;

    // Act
    for (size_t i = 0; i < count; ++i) {
        Vec.push_back(i);
    }
    Vec.insert(1,val);

    // Assert
    std::cout << "Checking the size of container" << std::endl;
    EXPECT_EQ(Vec.size(), (count + 1));
    std::cout << "Checking the element inserted at the beginning" << std::endl;
    ASSERT_EQ(Vec[0], val);
}

TEST(Vector, InsertInMiddle) {
    // Arrange
    const size_t count = 10;
    size_t val = 30;
    ImplVector <size_t> Vec;

    // Act
    for (size_t i = 0; i < count; ++i) {
        Vec.push_back(i);
    }
    Vec.insert(6, val);
    
    // Assert
    std::cout << "Checking the size of container" << std::endl;
    EXPECT_EQ(Vec.size(), (count + 1));
    std::cout << "Checking the element inserted at the middle" << std::endl;
    ASSERT_EQ(Vec[5], val);
}
TEST(Vector, EraseEnd) {
    // Arrange
    const size_t count = 10;
    size_t size = 9;
    ImplVector <size_t> Vec;
    ImplVector <size_t> VecRes;

    // Act
    for (size_t i = 0; i < count; ++i) {
        Vec.push_back(i);
    }
    Vec.erase(10);

    // Assert
    std::cout << "Checking the size after deleting the last element" << std::endl;
    EXPECT_EQ(Vec.size(), size);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}