cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_CXX_STANDARD 17)

project(Geni)

# set(CMAKE_MODULE_PATH "depend")
# set(CppUTest_DIR "depend/CppUTest")

include(FetchContent)

FetchContent_Declare(
    CppUTest
    GIT_REPOSITORY  https://github.com/CppUTest/CppUTest.git
    GIT_TAG         v4.0
)

set(TESTS OFF CACHE BOOL "Switch off CppUTest Test build")

# FetchContent_GetProperties(CppUTest)
# if(NOT CppUTest_POPULATED)
#   message(STATUS "CppUTest not populated.")
#   FetchContent_Populate(CppUTest)
#   message(STATUS "CppUTest source dir: ${CppUTest_SOURCE_DIR}")
#   message(STATUS "CppUTest binary dir: ${CppUTest_BINARY_DIR}")
#   add_subdirectory(${CppUTest_SOURCE_DIR} ${CppUTest_BINARY_DIR})
# else()
#   message(STATUS "CppUTest populated.")
# endif()

FetchContent_MakeAvailable(CppUTest)

find_package(CppUTest)

include_directories(
    src
)

# src/control
set(
    GENI_SRC_CONTROL
)

# src/memory
set(
    GENI_SRC_MEMORY
)

# src/system
set(
    GENI_SRC_SYSTEM
)

# src/utility
set(
    GENI_SRC_UTILITY
)

add_executable(
    test-control
    ${GENI_SRC_CONTROL}
    test/control/main.cpp
)

target_link_libraries(
    test-control
    PRIVATE
    CppUTest::CppUTest
    CppUTest::CppUTestExt
)

# add_executable(
#     test-memory
#     ${GENI_SRC_MEMORY}
#     test/memory/main.cpp
# )

# target_link_libraries(
#     test-memory
#     PRIVATE
#     CppUTest::CppUTest
#     CppUTest::CppUTestExt
# )

# add_executable(
#     test-system
#     ${GENI_SRC_SYSTEM}
#     test/system/main.cpp
# )

# add_executable(
#     test-utility
#     ${GENI_SRC_UTILITY}
#     test/utility/main.cpp
# )
