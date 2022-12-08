#include <gtest/gtest.h>
#include "ImplList.h"
#include <iostream>

TEST(List, InitializationContainer) {
	// Arrange
    ImplList <int> lst;
    size_t size = 0;
	// Assert
	std::cout << "Checking the size of an empty container" << std::endl;
    EXPECT_EQ(lst.get_size(), size);
}

TEST(List, PushBack) {
    // Arrange
    const int count = 10;
    int val = 20;
    size_t size = 11;
    ImplList <int> lst;
    // Act
    for (int i = 0; i < count; ++i) {
        lst.push_back(i);
    }
    lst.push_back(val);
    // Assert
    std::cout << "Checking the element inserted at the end" << std::endl;
    EXPECT_EQ(lst.get_size(), size);
    ASSERT_FALSE(lst.is_empty());
}

TEST(List, InsertFront) {
    // Arrange
    const int count = 10;
    int val = 20;
    int size = 11;
    ImplList <int> lst;
    ImplList <int> Reslst;
    Reslst.push_back(val);
    for (int i = 0; i < count; ++i) {
        lst.push_back(i);
        Reslst.push_back(i);
    }
    // Act
    lst.insert(1, val);
    // Assert
    std::cout << "Checking the element inserted at the beginning" << std::endl;
    EXPECT_EQ(lst.get_size(), size);
    ASSERT_TRUE(Reslst == lst);
}

TEST(List, InsertInMiddle) {
    // Arrange
    const int count = 10;
    int val = 30;
    size_t size = 11;
    ImplList <int> lst;
    ImplList <int> Reslst;
    for (int i = 0; i < count; ++i) {
        if (i == 5)
            Reslst.push_back(val);
        lst.push_back(i);
        Reslst.push_back(i); 
    }
    // Act    
    lst.insert(6, val);
    // Assert
    std::cout << "Checking the element inserted at the middle" << std::endl;
    EXPECT_EQ(lst.get_size(), size);
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