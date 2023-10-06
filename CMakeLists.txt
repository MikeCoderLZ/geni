cmake_minimum_required(VERSION 3.27.6)

project(Geni)

include_directories(
    depend/cpputest/include
    depend/portable-snippets 
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

add_executable(
    test-memory
    ${GENI_SRC_MEMORY}
    test/memory/main.cpp
)

add_executable(
    test-system
    ${GENI_SRC_SYSTEM}
    test/system/main.cpp
)

add_executable(
    test-utility
    ${GENI_SRC_UTILITY}
    test/utility/main.cpp
)
