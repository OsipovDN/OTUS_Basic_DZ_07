#include <gtest/gtest.h>
#include "ImplList.h"
#include <iostream>

size_t counter;
    struct Type {
        ~Type() { counter++; }
    };

struct ListFixture : public testing::Test {
    const int count = 10;
    size_t val = 20;
    size_t size = 11;
    ImplList <size_t> lst;

    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}

    void SetUp() override {
        for (size_t i = 0; i < count; ++i) {
            lst.push_back(i);
        }
    }
    void TearDown() override {}

};

TEST(List, InitializationContainer) {
	// Arrange
    ImplList <size_t> lst;
    size_t size = 0;
	// Assert
	std::cout << "Checking the size of an empty container" << std::endl;
    EXPECT_EQ(lst.get_size(), size);
}

TEST_F(ListFixture, PushBack) {
    
    lst.push_back(val);
    // Assert
    std::cout << "Checking the element inserted at the end" << std::endl;
    EXPECT_EQ(lst.get_size(), ListFixture::size);
    ASSERT_FALSE(lst.is_empty());
}

TEST_F(ListFixture, InsertFront) {
    // Arrange
    ImplList <size_t> Reslst;
    Reslst.push_back(ListFixture::val);
    for (size_t i = 0; i < ListFixture::count; ++i) {
        Reslst.push_back(i);
    }
    // Act
    lst.insert(1, ListFixture::val);
    // Assert
    std::cout << "Checking the element inserted at the beginning" << std::endl;
    EXPECT_EQ(lst.get_size(), ListFixture::size);
    ASSERT_TRUE(Reslst == lst);
}

TEST_F(ListFixture, InsertInMiddle) {
    // Arrange

    ImplList <size_t> Reslst;
    for (size_t i = 0; i < ListFixture::count; ++i) {
        if (i == 5)
            Reslst.push_back(ListFixture::val);
        Reslst.push_back(i); 
    }
    // Act    
    lst.insert(6, ListFixture::val);
    // Assert
    std::cout << "Checking the element inserted at the middle" << std::endl;
    EXPECT_EQ(lst.get_size(), ListFixture::size);
    EXPECT_FALSE(lst.is_empty());
    ASSERT_TRUE(Reslst == lst);
}

TEST(List, EraseEnd) {
    // Arrange
    const size_t count = 10;
    ImplList <size_t> lst;
    ImplList <size_t> lstRes;
    for (size_t i = 0; i < count; ++i) {
        lst.push_back(i);
        if (i != (count - 1))
            lstRes.push_back(i);
    }
    // Act
    lst.erase(10);
    // Assert
    std::cout << "Checking the size after deleting the last element" << std::endl;
    EXPECT_EQ(lst.get_size(), lstRes.get_size());
    ASSERT_TRUE(lst == lstRes);
}

TEST(List, EraseFront) {
    // Arrange
    const size_t count = 10;
    ImplList <size_t> lst;
    ImplList <size_t> lstRes;
    for (size_t i = 0; i < count; ++i) {
        if (i != 0)
            lstRes.push_back(i);
        lst.push_back(i);   
    }
    // Act
    lst.erase(1);
    // Assert
    std::cout << "Checking the size after deleting the last element" << std::endl;
    EXPECT_EQ(lst.get_size(), lstRes.get_size());
    ASSERT_TRUE(lst == lstRes);
}

TEST(List, EraseMidlle) {
    // Arrange
    const size_t count = 11;
    ImplList <size_t> lst;
    ImplList <size_t> lstRes;
    for (size_t i = 0; i < count; ++i) {
        if (i != 5)
            lstRes.push_back(i);
        lst.push_back(i);
    }
    // Act
    lst.erase(6);
    // Assert
    std::cout << "Checking the size after deleting the last element" << std::endl;
    EXPECT_EQ(lst.get_size(), lstRes.get_size());
    ASSERT_TRUE(lst == lstRes);
}

TEST(List, GetSize) {
    // Arrange
    const size_t count = 10;
    const size_t size = 10;
    ImplList <size_t> lst;
    for (size_t i = 0; i < count; ++i) {
        lst.push_back(i);
    }
    // Assert
    std::cout << "Checking the size of the container" << std::endl;
    ASSERT_EQ(lst.get_size(), size);
}

TEST(List, CallDestructor) {
    // Arrange
    const size_t count = 10;
    const size_t val = 10;
    ImplList <Type> lst;
    counter = 0;
    for (size_t i = 0; i < count; ++i) {
        lst.push_back(Type());
        std::cout << "тут" << std::endl;
    }
    // Act
    for (size_t i = (count - 1); i >= 0; ++i) {
        std::cout << "тут1" << std::endl;
        lst.erase(i);
    }
    ASSERT_EQ(counter, val);

}