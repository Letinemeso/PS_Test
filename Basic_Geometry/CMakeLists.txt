cmake_minimum_required(VERSION 3.10)

project(Basic_Geometry)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(Basic_Geometry STATIC
    Basic_Geometry.cpp
    Basic_Shapes.cpp
)

target_include_directories(Basic_Geometry PUBLIC 
                            "${PROJECT_BINARY_DIR}" 
                            "${PROJECT_SOURCE_DIR}"
                            "${PROJECT_SOURCE_DIR}/../Utility/include"
                            "${PROJECT_SOURCE_DIR}/../L_Variable/include"
                            )
