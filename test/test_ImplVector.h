#include <gtest/gtest.h>
#include "ImplVector.h"
#include <iostream>

struct VectorFixture : public testing::Test {
    const size_t count = 10;
    size_t val = 20;
    size_t size = 11;
    ImplVector <size_t> Vec;
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}

    void SetUp() override {
        for (size_t i = 0; i < count; ++i) {
            Vec.push_back(i);
        }
    }
    void TearDown() override {}
};

TEST(Vector, InitializationContainer) {
    // Arrange
    ImplVector <int> Vec;
    // Assert
    std::cout << "Checking the size of an empty container" << std::endl;
    ASSERT_EQ(Vec.size(), 0);
}

TEST_F(VectorFixture, PushBack) {
    // Act
    Vec.push_back(VectorFixture::val);
    // Assert
    std::cout << "Checking the element inserted at the end" << std::endl;
    EXPECT_EQ(Vec[10], VectorFixture::val);
    ASSERT_EQ(Vec.size(), VectorFixture::size);
}

TEST_F(VectorFixture, InsertFront) {
    // Act
    Vec.insert(1, VectorFixture::val);
    // Assert
    std::cout << "Checking the element inserted at the beginning" << std::endl;
    ASSERT_EQ(Vec[0], VectorFixture::val);
}

TEST_F(VectorFixture, InsertInMiddle) {
    // Act
    Vec.insert(6, VectorFixture::val);
    // Assert
    std::cout << "Checking the element inserted at the middle" << std::endl;
    ASSERT_EQ(Vec[5], VectorFixture::val);
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

TEST_F(VectorFixture, GetSize) {
    // Arrange
    size = 10;
    // Assert
    std::cout << "Checking the size of the container" << std::endl;
    ASSERT_EQ(Vec.size(), size);
}

TEST(Vector, CopyVector) {
    // Arrange
    size_t count = 10;
    ImplVector <size_t> vec1;
    ImplVector <size_t> vec2;
    for (size_t i = 0; i < count; ++i) {
        vec1.push_back(i);
        vec2.push_back(i*2);
    }
    vec1.push_back(10);
    //Act
    vec1 = vec2;
    // Assert
    std::cout << "Checking the copy of the container" << std::endl;
    ASSERT_EQ(vec1, vec2);
}

TEST(Vector, MoveCopyVector) {
    // Arrange
    size_t count = 10;

    ImplVector <size_t> vec1;
    ImplVector <size_t> vec2;
    ImplVector <size_t> vec3;
    for (size_t i = 0; i < count; ++i) {
        vec1.push_back(i);
        vec2.push_back(i * 2);
    }
    vec1.push_back(10);
    //Act
    vec3 = vec2;
    vec1 = std::move(vec2);
    // Assert
    std::cout << "Checking the move copy of the container" << std::endl;
    ASSERT_EQ(vec1,vec3);
}
