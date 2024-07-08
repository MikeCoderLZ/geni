cmake_minimum_required(VERSION 3.27.6)

project(Geni)

cmake_path( APPEND PROJECT_SOURCE_DIR "cmake" OUTPUT_VARIABLE Geni_LOCAL_MODULE_PATH )
cmake_path( APPEND PROJECT_SOURCE_DIR "depend" OUTPUT_VARIABLE Geni_LOCAL_DEPEND_PATH )
cmake_path( APPEND PROJECT_SOURCE_DIR "cmake" OUTPUT_VARIABLE Geni_LOCAL_CONFIG_PATH )

message( STATUS "local module path: ${Geni_LOCAL_MODULE_PATH}" )
message( STATUS "local depend path: ${Geni_LOCAL_DEPEND_PATH}" )
message( STATUS "local config path: ${Geni_LOCAL_CONFIG_PATH}" )

list( APPEND CMAKE_MODULE_PATH ${Geni_LOCAL_MODULE_PATH} )

include( Subproject )
Subprojects(
    PREFIX ${Geni_LOCAL_DEPEND_PATH}
    CONFIG_DIRECTORY ${Geni_LOCAL_CONFIG_PATH}
    cpputest
)

add_executable( test-compile test/main.cpp )
target_include_directories( test-compile PRIVATE source )
target_link_libraries( test-compile cpputest-static )
