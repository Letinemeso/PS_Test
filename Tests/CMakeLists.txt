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
                            "${PROJECT_SOURCE_DIR}/../googletest/googletest/include"
)

target_link_libraries(Tests PUBLIC 
    -pthread
)

target_link_libraries(Tests PUBLIC 
    "${PROJECT_BINARY_DIR}/../Basic_Geometry/libBasic_Geometry.a"
    "${PROJECT_BINARY_DIR}/../L_Variable/libL_Variable.a"
    "${PROJECT_BINARY_DIR}/../Utility/libUtility.a"
    "${PROJECT_BINARY_DIR}/../lib/libgtest.a"
)



