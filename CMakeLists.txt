cmake_minimum_required (VERSION 3.8)

project (MyContainers)
find_package(GTest)

add_executable (
    MyContainers 
    myContainers.cpp
)

add_executable (
    test_MyVector
    test/test_MyVector.cpp
)

target_include_directories(
    MyContainers 
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
    )
target_include_directories(
    MyContainers 
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Conteiners
    )


target_include_directories(
    test_MyVector PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(
    test_MyVector PRIVATE
    ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(
    test_MyVector PRIVATE
    ${GTEST_BOTH_LIBRARIES}
)


set_target_properties(MyContainers PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(MyContainers PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(MyContainers PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()