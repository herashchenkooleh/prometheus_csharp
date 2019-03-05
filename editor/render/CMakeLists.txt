project(D3DContent)

file(GLOB SRC_FILES ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)
file(GLOB INC_FILES ${CMAKE_CURRENT_LIST_DIR}/inc/*.hpp)
set(DEF_FILE ${CMAKE_CURRENT_LIST_DIR}/D3DContent.def)

add_library(D3DContent SHARED ${SRC_FILES} ${INC_FILES} ${DEF_FILE})

target_include_directories (
    D3DContent
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}/inc ${DirectX_INCLUDE_DIR}
)

target_link_libraries(D3DContent ${DirectX_LIBRARY} ${DirectX_D3DX9_LIBRARY})

set_property(TARGET D3DContent PROPERTY LINK_FLAGS
    /DEF:"${ModuleDefinition_SOURCE_DIR}/example_dll_2.def")

set_target_properties (D3DContent PROPERTIES FOLDER editor)