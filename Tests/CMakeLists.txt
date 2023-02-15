cmake_minimum_required(VERSION 3.10)

project(Tests)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Tests
    main.cpp
)

target_include_directories(Tests PUBLIC 
                            "${PROJECT_BINARY_DIR}" 
                            "${PROJECT_SOURCE_DIR}"
                            "${PROJECT_SOURCE_DIR}/../Utility/include"
                            "${PROJECT_SOURCE_DIR}/../L_Variable/include"
                            "${PROJECT_SOURCE_DIR}/../Basic_Geometry"
)

target_link_libraries(Tests PUBLIC 
    "${PROJECT_BINARY_DIR}/../Basic_Geometry/libBasic_Geometry.a"
    "${PROJECT_BINARY_DIR}/../_deps/l_variable-build/libL_Variable.a"
    "${PROJECT_BINARY_DIR}/../_deps/utility-build/libUtility.a"
)
