add_executable (
    unit_tests
    vector.cpp
    matrix.cpp
)

target_link_libraries (
    unit_tests
    gtest_main
    math
)

add_test (
  NAME unit
  COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
)

set_target_properties (unit_tests PROPERTIES FOLDER unit_tests)

set (
    CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
)

foreach(CompilerFlag ${CompilerFlags})
  string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
endforeach()