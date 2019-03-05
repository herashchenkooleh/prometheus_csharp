cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(prometheus CXX)

include(GNUInstallDirs)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

add_subdirectory(libraries)
add_subdirectory(editor)

include(cmake/googletest.cmake)
include(cmake/FindPkgMacros.cmake)
include(cmake/FindDirectx9.cmake)

fetch_googletest(${PROJECT_SOURCE_DIR}/cmake ${PROJECT_BINARY_DIR}/googletest)

enable_testing()

add_subdirectory(test)

set_target_properties (gmock PROPERTIES FOLDER googletest)
set_target_properties (gmock_main PROPERTIES FOLDER googletest)
set_target_properties (gtest PROPERTIES FOLDER googletest)
set_target_properties (gtest_main PROPERTIES FOLDER googletest)