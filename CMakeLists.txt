cmake_minimum_required (VERSION 3.8)

project (ImplemContainers)
find_package(GTest)

add_executable (
    ImplemContainers
    ImplContainers.cpp
)

add_executable (
    test_Containers
    test/test_ImplVector.cpp
    test/test_ImplList.cpp
    )

target_include_directories(
    ImplemContainers
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
    )
target_include_directories(
    ImplemContainers PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/Conteiners
    )

target_include_directories(
    test_Containers PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Conteiners
)
target_include_directories(
    test_Containers PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/test
)

target_include_directories(
    test_Containers PRIVATE
    ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(
    test_Containers PRIVATE
    ${GTEST_BOTH_LIBRARIES}
)


set_target_properties(ImplemContainers PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(ImplemContainers PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
    target_compile_options(test_Containers PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(ImplemContainers PRIVATE
        /EHsc
        /W4
        /WX
    )
    target_compile_options(test_Containers PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()