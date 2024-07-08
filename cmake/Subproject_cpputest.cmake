include(ExternalProject)

function( Subproject_Init_cpputest prefix )
    list(APPEND CMAKE_MESSAGE_INDENT "  ")
    
    message( STATUS "Configuring subproject cpputest" )
    ExternalProject_Add(
        cpputest
        GIT_REPOSITORY      git@github.com:cpputest/cpputest.git
        GIT_TAG             v4.0
        GIT_PROGRESS        TRUE
        CMAKE_ARGS          -DBUILD_SHARED=ON -DBUILD_TESTING=OFF --install-prefix ${CMAKE_SOURCE_DIR}/depend/Install/cpputest
        UPDATE_COMMAND      ""
        # INSTALL_COMMAND     -install ${CMAKE_SOURCE_DIR}/depend/Install/cpputest
        UPDATE_DISCONNECTED ON
    )

    ExternalProject_Get_Property(cpputest INSTALL_DIR)
    find_path( CPPUTEST_INCLUDE_DIR CppUTest/Utest.h HINTS \/include NO_CACHE)
    find_library( CPPUTEST_SHARED_LIB NAMES libCppUTest.so HINTS ${INSTALL_DIR}/lib NO_CACHE)
    find_library( CPPUTEST_EXT_SHARED_LIB NAMES libCppUTestExt.so HINTS ${INSTALL_DIR}/lib NO_CACHE)
    find_library( CPPUTEST_STATIC_LIB NAMES libCppUTest.a HINTS ${INSTALL_DIR}/lib NO_CACHE)
    find_library( CPPUTEST_EXT_STATIC_LIB NAMES libCppUTestExt.a HINTS ${INSTALL_DIR}/lib NO_CACHE)

    if( CPPUTEST_INCLUDE_DIR STREQUAL "CPPUTEST_INCLUDE_DIR-NOTFOUND" )
        message( WARNING "Subproject 'cpputest' has not yet been installed; using expected install directories. You should build a dependent target from the main project." )
        set( CPPUTEST_INCLUDE_DIR "${INSTALL_DIR}/include" )
        set( CPPUTEST_SHARED_LIB "${INSTALL_DIR}/lib/libCppUTest.so" )
        set( CPPUTEST_EXT_SHARED_LIB "${INSTALL_DIR}/lib/libCppUTestExt.so" )
        set( CPPUTEST_STATIC_LIB "${INSTALL_DIR}/lib/libCppUTest.so" )
        set( CPPUTEST_EXT_STATIC_LIB "${INSTALL_DIR}/lib/libCppUTestExt.so" )
    endif()

    add_library( cpputest-shared SHARED IMPORTED )
    set_target_properties( cpputest-shared PROPERTIES IMPORTED_LOCATION ${CPPUTEST_SHARED_LIB} )
    target_include_directories( cpputest-shared INTERFACE ${CPPUTEST_INCLUDE_DIR} )
    add_library( cpputest-ext-shared SHARED IMPORTED )
    set_target_properties( cpputest-ext-shared PROPERTIES IMPORTED_LOCATION ${CPPUTEST_EXT_SHARED_LIB} )
    target_include_directories( cpputest-ext-shared INTERFACE ${CPPUTEST_INCLUDE_DIR} )
    add_library( cpputest-static SHARED IMPORTED )
    set_target_properties( cpputest-static PROPERTIES IMPORTED_LOCATION ${CPPUTEST_STATIC_LIB} )
    target_include_directories( cpputest-static INTERFACE ${CPPUTEST_INCLUDE_DIR} )
    add_library( cpputest-ext-static SHARED IMPORTED )
    set_target_properties( cpputest-ext-static PROPERTIES IMPORTED_LOCATION ${CPPUTEST_EXT_STATIC_LIB} )
    target_include_directories( cpputest-ext-static INTERFACE ${CPPUTEST_INCLUDE_DIR} )

    list(POP_BACK CMAKE_MESSAGE_INDENT)
endfunction()
