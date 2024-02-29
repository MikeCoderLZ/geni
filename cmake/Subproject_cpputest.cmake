include(ExternalProject)

function( Subproject_Init_cpputest )
    list(APPEND CMAKE_MESSAGE_INDENT "  ")
    
    message( STATUS "Configuring subproject cpputest" )
    ExternalProject_Add(
        cpputest
        DOWNLOAD_COMMAND ""
        UPDATE_COMMAND ""
        PATCH_COMMAND ""
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        TEST_COMMAND ""
        INSTALL_COMMAND ""
    )
    message( AUTHOR_WARNING "Configuration of cpputest failed. Configuration implementation has been stubbed out at: /Users/mikeoliver/Development/Projects/geni/cmake/Subproject_cpputest.cmake. You must complete the implementation of this automatically generated configuration file.")
    list(POP_BACK CMAKE_MESSAGE_INDENT)
endfunction()
