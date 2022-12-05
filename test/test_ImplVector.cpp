#include <gtest/gtest.h>
#include "ImplVector.h"
#include <iostream>

TEST(Vector, InitializationContainer) {
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
    for (size_t i = 0; i < count; ++i) {
        Vec.push_back(i);
    }

    // Act
    Vec.push_back(val);

    // Assert
    std::cout << "Checking the element inserted at the end" << std::endl;
    ASSERT_EQ(Vec[10], val);
}

TEST(Vector, InsertFront) {
    // Arrange
    const size_t count = 10;
    size_t val = 20;
    ImplVector <size_t> Vec;
    for (size_t i = 0; i < count; ++i) {
        Vec.push_back(i);
    }
    // Act
    Vec.insert(1,val);

    // Assert
    std::cout << "Checking the element inserted at the beginning" << std::endl;
    ASSERT_EQ(Vec[0], val);
}

TEST(Vector, InsertInMiddle) {
    // Arrange
    const size_t count = 10;
    size_t val = 30;
    ImplVector <size_t> Vec;
    for (size_t i = 0; i < count; ++i) {
        Vec.push_back(i);
    }

    // Act
    Vec.insert(6, val);
    
    // Assert
    std::cout << "Checking the element inserted at the middle" << std::endl;
    ASSERT_EQ(Vec[5], val);
}
TEST(Vector, EraseEnd) {
    // Arrange
    const size_t count = 10;
    ImplVector <size_t> Vec;
    ImplVector <size_t> VecRes;
    for (size_t i = 0; i < count; ++i) {
        Vec.push_back(i);
        if (i != (count - 1))
            VecRes.push_back(i);
    }

    // Act
    Vec.erase(10);

    // Assert
    std::cout << "Checking the size after deleting the last element" << std::endl;
    ASSERT_TRUE(Vec==VecRes);
}

TEST(Vector, EraseFront) {
    // Arrange
    const size_t count = 10;
    ImplVector <size_t> Vec;
    ImplVector <size_t> VecRes;
    for (size_t i = 0; i < count; ++i) {
        Vec.push_back(i);
        if (i != 0)
            VecRes.push_back(i);
    }

    // Act
    Vec.erase(1);

    // Assert
    std::cout << "Checking the size after deleting the first element" << std::endl;
    ASSERT_TRUE(Vec == VecRes);
}

TEST(Vector, EraseMidlle) {
    // Arrange
    const size_t count = 11;
    ImplVector <size_t> Vec;
    ImplVector <size_t> VecRes;
    for (size_t i = 0; i < count; ++i) {
        Vec.push_back(i);
        if (i != 5)
            VecRes.push_back(i);
    }

    // Act
    Vec.erase(6);

    // Assert
    std::cout << "Checking the removal of an element from the middle" << std::endl;
    ASSERT_TRUE(Vec == VecRes);
}

TEST(Vector, OperatorGetElement) {
    // Arrange
    const size_t count = 10;
    size_t val = 0;
    ImplVector <size_t> Vec;
    for (size_t i = 0; i < count; ++i) {
        Vec.push_back(i);
    }

    // Act
    for (size_t i = 0; i < count; ++i) {
        if (Vec[i] != i) 
            break;
        val++;
    }

    // Assert
    std::cout << "Checking the size of the container" << std::endl;
    ASSERT_EQ(Vec.size(),val);
}

TEST(Vector, GetSize) {
    // Arrange
    const size_t count = 10;
    const size_t size = 10;
    ImplVector <size_t> Vec;
    for (size_t i = 0; i < count; ++i) {
        Vec.push_back(i);
    }

    // Act

    // Assert
    std::cout << "Checking the size of the container" << std::endl;
    ASSERT_EQ(Vec.size(), size);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}