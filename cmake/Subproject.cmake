cmake_minimum_required(VERSION 3.27.6)

include_guard(GLOBAL)

set(
SubprojectConfigTemplate
"include(ExternalProject)\n\
\n\
function( Subproject_Init_@SUBPROJECT_NAME@ prefix )\n\
    list(APPEND CMAKE_MESSAGE_INDENT \"  \")\n\    
    message( STATUS \"Configuring subproject @SUBPROJECT_NAME@\" )\n\
    ExternalProject_Add(\n\
        @SUBPROJECT_NAME@\n\
        DOWNLOAD_COMMAND \"\"\n\
        UPDATE_COMMAND \"\"\n\
        PATCH_COMMAND \"\"\n\
        CONFIGURE_COMMAND \"\"\n\
        BUILD_COMMAND \"\"\n\
        TEST_COMMAND \"\"\n\
        INSTALL_COMMAND \"\"\n\
    )\n\
    ExternalProject_Get_Property(@SUBPROJECT_NAME@ INSTALL_DIR)\n\
    find_path( CPPUTEST_INCLUDE_DIR CppUTest/Utest.h HINTS \\\${INSTALL_DIR}/include NO_CACHE)\n\
    message( STATUS \"install directory: ${INSTALL_DIR}\")\n\
    message( STATUS \"Test val: ${CPPUTEST_INCLUDE_DIR}\")\n\
    message( AUTHOR_WARNING \"Configuration of @SUBPROJECT_NAME@ failed. Configuration implementation has been stubbed out at: @SUBPROJECT_CONFIG_PATH@. You must complete the implementation of this automatically generated configuration file.\")
    list(POP_BACK CMAKE_MESSAGE_INDENT)\n\
endfunction()"
)

set( SubprojectGitignoreTemplate "*\n!.gitignore\n" )

function( Subprojects )
    set( prefix ${PROJECT_SOURCE_DIRECTORY} )
    set( configDir ${PROJECT_SOURCE_DIRECTORY} )
    set( projects "" )

    set( mode "SUBPROJECT" )

    foreach( arg IN LISTS ARGV )
        if( arg STREQUAL "PREFIX" )
            set( mode "PREFIX" )
            continue()
        elseif( arg STREQUAL "CONFIG_DIRECTORY" )
            set( mode "CONFIG_DIRECTORY" )
            continue()
        endif()

        if( mode STREQUAL "PREFIX" )
            set( mode "SUBPROJECT" )
            set( prefix ${arg} )
            if( NOT EXISTS ${prefix} )
                message( FATAL_ERROR "Given subproject subproject directory \"${prefix}\" does not exist" )
            endif()
        elseif( mode STREQUAL "CONFIG_DIRECTORY" )
            set( mode "SUBPROJECT" )
            cmake_path( APPEND configDir ${arg} )
            if( NOT EXISTS ${configDir} )
                message( FATAL_ERROR "Given subproject config directory \"${configDir}\" does not exist" )
            endif()
        else()
            string( TOLOWER ${arg} lcproject )
            list( APPEND projects ${lcproject} )
        endif()
    endforeach()

    message( VERBOSE "Subproject directory: ${prefix}")
    message( VERBOSE "Subproject config directory: ${prefix}")

    message( VERBOSE "Subprojects:" )
    list(APPEND CMAKE_MESSAGE_INDENT "  ")

    foreach(project IN LISTS projects)
    message(VERBOSE ${project})
    endforeach()

    list(POP_BACK CMAKE_MESSAGE_INDENT)

    message( VERBOSE "" )

    set( projectConfigTmp "Subproject_config.cmake.tmp" )
    set( projectConfigTmpPath ${configDir} )
    cmake_path( APPEND projectConfigTmpPath ${projectConfigTmp} )
    file( TOUCH ${projectConfigTmpPath} )
    file( WRITE ${projectConfigTmpPath} ${SubprojectConfigTemplate} )

    set_property( DIRECTORY PROPERTY EP_BASE ${prefix} )
    cmake_path( APPEND prefix "Download" OUTPUT_VARIABLE Subproject_DOWNLOAD_DIRECTORY )
    cmake_path( APPEND prefix "Source" OUTPUT_VARIABLE Subproject_SOURCE_DIRECTORY )
    cmake_path( APPEND prefix "Build" OUTPUT_VARIABLE Subproject_BUILD_DIRECTORY )
    cmake_path( APPEND prefix "Install" OUTPUT_VARIABLE Subproject_INSTALL_DIRECTORY )
    cmake_path( APPEND prefix "Stamp" OUTPUT_VARIABLE Subproject_STAMP_DIRECTORY )
    cmake_path( APPEND prefix "tmp" OUTPUT_VARIABLE Subproject_TMP_DIRECTORY )
    
    file( MAKE_DIRECTORY ${Subproject_DOWNLOAD_DIRECTORY} )
    file( MAKE_DIRECTORY ${Subproject_SOURCE_DIRECTORY} )
    file( MAKE_DIRECTORY ${Subproject_BUILD_DIRECTORY} )
    file( MAKE_DIRECTORY ${Subproject_INSTALL_DIRECTORY} )
    file( MAKE_DIRECTORY ${Subproject_STAMP_DIRECTORY} )
    file( MAKE_DIRECTORY ${Subproject_TMP_DIRECTORY} )

    cmake_path( APPEND prefix ".gitignore" OUTPUT_VARIABLE Subproject_GITIGNORE )
    
    if( NOT EXISTS ${Subproject_GITIGNORE} )
        file( TOUCH ${Subproject_GITIGNORE} )
        file( WRITE ${Subproject_GITIGNORE} ${SubprojectGitignoreTemplate} )
    endif()

    foreach( project IN LISTS projects )
        set( projectFile "Subproject_${project}.cmake" )
        set( foundProject FALSE )
        foreach( path ${CMAKE_MODULE_PATH} )
            cmake_path( APPEND path ${projectFile} )
            if( EXISTS ${path} )
                message( STATUS "Project config found." )
                set( foundProject TRUE )
                include( ${path} )
                cmake_language( CALL "Subproject_Init_${project}" prefix )
                break()
            endif()
        endforeach()

        if( NOT foundProject )
        message( STATUS "Project config not found." )
            set( projectConfig "Subproject_${project}.cmake" )
            set( projectConfigPath ${configDir} )
            cmake_path( APPEND projectConfigPath ${projectConfig} )
            file( TOUCH ${projectConfigPath} )
            set( SUBPROJECT_NAME ${project} )
            set( SUBPROJECT_CONFIG_PATH ${projectConfigPath} )
            configure_file( ${projectConfigTmpPath} ${projectConfigPath} )
            file( REMOVE ${projectConfigTmpPath} )
            include( ${projectConfigPath} )
            cmake_language( CALL "Subproject_Init_${project}" prefix )
        endif()
    endforeach()

    
    file( REMOVE projectConfigTmpPath )

endfunction()
