cmake_minimum_required(VERSION 3.12)

# make ExternalProject_Add enabled
include(ExternalProject)

# Google Test
if(BUILD_TEST)
    set(BUILD_GMOCK OFF CACHE INTERNAL "" FORCE)
    set(INSTALL_GTEST OFF CACHE INTERNAL "" FORCE)
    if(MSVC)
        set(gtest_force_shared_crt ON CACHE INTERNAL "" FORCE)
    endif()
    add_subdirectory(googletest EXCLUDE_FROM_ALL)
endif()

# zlib
ExternalProject_Add(
    EP_zlib
    GIT_REPOSITORY  https://github.com/altseed/zlib
    GIT_TAG         v1.2.11
    SOURCE_DIR      ${CMAKE_CURRENT_BINARY_DIR}/zlib-src
    BINARY_DIR      ${CMAKE_CURRENT_BINARY_DIR}/zlib-build
    PREFIX          ${CMAKE_CURRENT_BINARY_DIR}/Build/zlib
    INSTALL_DIR     ${CMAKE_CURRENT_BINARY_DIR}/Install/zlib
    CMAKE_ARGS      -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/Install/zlib
                    -DCMAKE_USER_MAKE_RULES_OVERRIDE=${CMAKE_CURRENT_SOURCE_DIR}/CFlagOverrides.cmake
                    -DUSE_MSVC_RUNTIME_LIBRARY_DLL=${USE_MSVC_RUNTIME_LIBRARY_DLL}
                    -DMSVC_SANITIZE_ENABLED=${MSVC_SANITIZE_ENABLED}
                    -DASM686=off
                    -DAMD64=off
)
list(APPEND THIRDPARTY_INCLUDES ${CMAKE_CURRENT_BINARY_DIR}/Install/zlib/include)
list(APPEND THIRDPARTY_LIBRARY_DIRECTORIES ${CMAKE_CURRENT_BINARY_DIR}/Install/zlib/lib)

# libpng
ExternalProject_Add(
    EP_libpng
    DEPENDS         EP_zlib
    SOURCE_DIR      ${CMAKE_CURRENT_SOURCE_DIR}/libpng
    PREFIX          ${CMAKE_CURRENT_BINARY_DIR}/Build/libpng
    INSTALL_DIR     ${CMAKE_CURRENT_BINARY_DIR}/Install/libpng
    CMAKE_ARGS      -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/Install/libpng
                    -DCMAKE_USER_MAKE_RULES_OVERRIDE=${CMAKE_CURRENT_SOURCE_DIR}/CFlagOverrides.cmake
                    -DUSE_MSVC_RUNTIME_LIBRARY_DLL=${USE_MSVC_RUNTIME_LIBRARY_DLL}
                    -DMSVC_SANITIZE_ENABLED=${MSVC_SANITIZE_ENABLED}
                    -DZLIB_INCLUDE_DIR=${CMAKE_CURRENT_BINARY_DIR}/Install/zlib/include
                    -DPNG_BUILD_ZLIB=ON
                    -DPNG_SHARED=OFF
                    -DPNG_TESTS=OFF
                    -DCMAKE_POSITION_INDEPENDENT_CODE=ON
)
list(APPEND THIRDPARTY_INCLUDES ${CMAKE_CURRENT_BINARY_DIR}/Install/libpng/include)
list(APPEND THIRDPARTY_LIBRARY_DIRECTORIES ${CMAKE_CURRENT_BINARY_DIR}/Install/libpng/lib)

if(MSVC)
    set(LIBPNG_LIB_DEBUG "libpng16_staticd" PARENT_SCOPE)
    set(LIBPNG_LIB_RELEASE "libpng16_static" PARENT_SCOPE)
elseif(BUILD_WITH_POSTFIX)
    set(LIBPNG_LIB_DEBUG "png16d" PARENT_SCOPE)
    set(LIBPNG_LIB_RELEASE "png16" PARENT_SCOPE)
else()
    set(LIBPNG_LIB_DEBUG "png16" PARENT_SCOPE)
    set(LIBPNG_LIB_RELEASE "png16" PARENT_SCOPE)
endif()

# libzip
ExternalProject_Add(
    EP_libzip
    DEPENDS         EP_zlib
    SOURCE_DIR      ${CMAKE_CURRENT_SOURCE_DIR}/libzip
    PREFIX          ${CMAKE_CURRENT_BINARY_DIR}/Build/libzip
    INSTALL_DIR     ${CMAKE_CURRENT_BINARY_DIR}/Install/libzip
    CMAKE_ARGS      -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/Install/libzip
                    -DCMAKE_USER_MAKE_RULES_OVERRIDE=${CMAKE_CURRENT_SOURCE_DIR}/CFlagOverrides.cmake
                    -DUSE_MSVC_RUNTIME_LIBRARY_DLL=${USE_MSVC_RUNTIME_LIBRARY_DLL}
                    -DMSVC_SANITIZE_ENABLED=${MSVC_SANITIZE_ENABLED}
                    -DZLIB_INCLUDE_DIR=${CMAKE_CURRENT_BINARY_DIR}/Install/zlib/include
                    -DZLIB_LIBRARY=${CMAKE_CURRENT_BINARY_DIR}/Install/zlib/lib
                    -DBUILD_SHARED_LIBS=OFF
                    -DBUILD_TOOLS=OFF
                    -DBUILD_REGRESS=OFF
                    -DBUILD_EXAMPLES=OFF
                    -DBUILD_DOC=OFF
                    -DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=true
                    -DENABLE_BZIP2=OFF
)

list(APPEND THIRDPARTY_INCLUDES ${CMAKE_CURRENT_BINARY_DIR}/Install/libzip/include)
list(APPEND THIRDPARTY_LIBRARY_DIRECTORIES ${CMAKE_CURRENT_BINARY_DIR}/Install/libzip/lib)

# glfw
ExternalProject_Add(
    EP_glfw
    SOURCE_DIR      ${CMAKE_CURRENT_SOURCE_DIR}/glfw
    PREFIX          ${CMAKE_CURRENT_BINARY_DIR}/Build/glfw
    INSTALL_DIR     ${CMAKE_CURRENT_BINARY_DIR}/Install/glfw
    CMAKE_ARGS      -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/Install/glfw
                    -DCMAKE_DEBUG_POSTFIX=d
                    -DCMAKE_USER_MAKE_RULES_OVERRIDE=${CMAKE_CURRENT_SOURCE_DIR}/CFlagOverrides.cmake
                    -DUSE_MSVC_RUNTIME_LIBRARY_DLL=${USE_MSVC_RUNTIME_LIBRARY_DLL}
                    -DMSVC_SANITIZE_ENABLED=${MSVC_SANITIZE_ENABLED}
                    -DGLFW_BUILD_EXAMPLES=OFF
                    -DGLFW_BUILD_TESTS=OFF
                    -DGLFW_BUILD_DOCS=OFF
                    -DGLFW_INSTALL=ON
)
list(APPEND THIRDPARTY_INCLUDES ${CMAKE_CURRENT_BINARY_DIR}/Install/glfw/include)
list(APPEND THIRDPARTY_LIBRARY_DIRECTORIES ${CMAKE_CURRENT_BINARY_DIR}/Install/glfw/lib)

if(BUILD_WITH_POSTFIX)
    set(GLFW3_LIB_DEBUG "glfw3d" PARENT_SCOPE)
    set(GLFW3_LIB_RELEASE "glfw3" PARENT_SCOPE)
else()
    set(GLFW3_LIB_DEBUG "glfw3" PARENT_SCOPE)
    set(GLFW3_LIB_RELEASE "glfw3" PARENT_SCOPE)
endif()

# freetype
ExternalProject_Add(
    EP_freetype
    SOURCE_DIR      ${CMAKE_CURRENT_SOURCE_DIR}/freetype2
    PREFIX          ${CMAKE_CURRENT_BINARY_DIR}/Build/freetype2
    INSTALL_DIR     ${CMAKE_CURRENT_BINARY_DIR}/Install/freetype2
    CMAKE_ARGS      -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/Install/freetype2
                    -DCMAKE_USER_MAKE_RULES_OVERRIDE=${CMAKE_CURRENT_SOURCE_DIR}/CFlagOverrides.cmake
                    -DUSE_MSVC_RUNTIME_LIBRARY_DLL=${USE_MSVC_RUNTIME_LIBRARY_DLL}
                    -DMSVC_SANITIZE_ENABLED=${MSVC_SANITIZE_ENABLED}
                    -DCMAKE_DEBUG_POSTFIX=d
                    -DBUILD_SHARED_LIBS=OFF
                    -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
                    -DCMAKE_POSITION_INDEPENDENT_CODE=ON
)

list(APPEND THIRDPARTY_INCLUDES ${CMAKE_CURRENT_BINARY_DIR}/Install/freetype2/include)
list(APPEND THIRDPARTY_LIBRARY_DIRECTORIES ${CMAKE_CURRENT_BINARY_DIR}/Install/freetype2/lib)

# msdfgen
ExternalProject_Add(
    EP_msdfgen
    DEPENDS         EP_freetype
    SOURCE_DIR      ${CMAKE_CURRENT_SOURCE_DIR}/msdfgen
    PREFIX          ${CMAKE_CURRENT_BINARY_DIR}/Build/msdfgen
    INSTALL_DIR     ${CMAKE_CURRENT_BINARY_DIR}/Install/msdfgen
    CMAKE_ARGS      -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/Install/msdfgen
                    -DCMAKE_USER_MAKE_RULES_OVERRIDE=${CMAKE_CURRENT_SOURCE_DIR}/CFlagOverrides.cmake
                    -DUSE_MSVC_RUNTIME_LIBRARY_DLL=${USE_MSVC_RUNTIME_LIBRARY_DLL}
                    -DMSVC_SANITIZE_ENABLED=${MSVC_SANITIZE_ENABLED}
                    -DFREETYPE_INCLUDE_DIRS=${CMAKE_CURRENT_BINARY_DIR}/Install/freetype2/include/freetype2
                    -DFREETYPE_LIBRARY=${CMAKE_CURRENT_BINARY_DIR}/Install/freetype2
                    -DMSDFGEN_BUILD_MSDFGEN_STANDALONE=OFF
                    -DCMAKE_DEBUG_POSTFIX=d
                    -DBUILD_SHARED_LIBS=OFF
                    -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
                    -DCMAKE_POSITION_INDEPENDENT_CODE=ON
)

list(APPEND THIRDPARTY_INCLUDES ${CMAKE_CURRENT_BINARY_DIR}/Install/msdfgen/include)
list(APPEND THIRDPARTY_LIBRARY_DIRECTORIES ${CMAKE_CURRENT_BINARY_DIR}/Install/msdfgen/lib)

# box2d
set(BOX2D_BUILD_UNIT_TESTS OFF CACHE BOOL "disable box2d unit test" FORCE)
set(BOX2D_BUILD_TESTBED OFF CACHE BOOL "disable box2d testbed" FORCE)
add_subdirectory(box2d)
set_property(TARGET box2d PROPERTY POSITION_INDEPENDENT_CODE ON)
list(APPEND THIRDPARTY_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/box2d/include)

# hidapi
add_subdirectory(hidapi EXCLUDE_FROM_ALL)

# spdlog
add_subdirectory(spdlog EXCLUDE_FROM_ALL)
set_target_properties(spdlog PROPERTIES POSITION_INDEPENDENT_CODE ON)

# For address sanitizer on Windows (Caching causes an odr error)
target_compile_options(spdlog PUBLIC -DSPDLOG_NO_TLS)

# imgui
add_subdirectory(imgui EXCLUDE_FROM_ALL)
list(APPEND THIRDPARTY_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/imgui)

# nativefiledialog
set(NFD_BUILD_UNIT_TESTS OFF CACHE BOOL "disable NFD unit test" FORCE)
add_subdirectory(nativefiledialog)
set_property(TARGET nativefiledialog PROPERTY POSITION_INDEPENDENT_CODE ON)
list(APPEND THIRDPARTY_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/nativefiledialog/src/include)

# LLGI
set(BUILD_TEST_TEMP ${BUILD_TEST})
set(BUILD_TEST OFF)
set(BUILD_TOOL ON CACHE BOOL "For LLGI")
add_subdirectory(LLGI)
set(BUILD_TEST ${BUILD_TEST_TEMP})
list(APPEND THIRDPARTY_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/LLGI/src)
list(APPEND THIRDPARTY_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/LLGI/tools/ShaderTranspilerCore)
set_target_properties(ShaderTranspilerCore PROPERTIES POSITION_INDEPENDENT_CODE ON)

# OSM
set(BUILD_TEST_TEMP ${BUILD_TEST})
set(BUILD_TEST OFF)
add_subdirectory(OpenSoundMixer)
set(BUILD_TEST ${BUILD_TEST_TEMP})
list(APPEND THIRDPARTY_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/OpenSoundMixer/src)

# stb
list(APPEND THIRDPARTY_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/stb)

# assign valiables into the parent scope
set(THIRDPARTY_INCLUDES ${THIRDPARTY_INCLUDES} PARENT_SCOPE)
set(THIRDPARTY_LIBRARY_DIRECTORIES ${THIRDPARTY_LIBRARY_DIRECTORIES} PARENT_SCOPE)
