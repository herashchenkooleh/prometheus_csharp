add_library(math INTERFACE)

file(GLOB INL_FILES ${CMAKE_CURRENT_LIST_DIR}/inl/*.inl)
file(GLOB INC_FILES ${CMAKE_CURRENT_LIST_DIR}/inc/*.hpp)

target_sources (
    math
    INTERFACE ${INL_FILES} ${INC_FILES}
)

target_include_directories (
    math
    INTERFACE ${CMAKE_CURRENT_LIST_DIR}/inc ${CMAKE_CURRENT_LIST_DIR}/inl
)

target_compile_options(math INTERFACE "/std:c++latest")