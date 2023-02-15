cmake_minimum_required(VERSION 3.10)

include(FetchContent)

# FetchContent_Declare(
#     "L_Variable"
#     GIT_REPOSITORY "https://github.com/Letinemeso/L_Variable.git"
#     SOURCE_DIR "../L_Variable"
#     GIT_TAG "origin/master"
#   )
# FetchContent_MakeAvailable(L_Variable)
# 
# FetchContent_Declare(
#     "Utility"
#     GIT_REPOSITORY "https://github.com/Letinemeso/Utility.git"
#     SOURCE_DIR "../Utility"
#     GIT_TAG "origin/master"
#   )
# FetchContent_MakeAvailable(Utility)
# 
# FetchContent_Declare(
#     "googletest"
#     GIT_REPOSITORY "https://github.com/google/googletest.git"
#     SOURCE_DIR "../googletest"
#     GIT_TAG "origin/main"
#   )
# FetchContent_MakeAvailable(googletest)

add_subdirectory(googletest)
add_subdirectory(Utility)
add_subdirectory(L_Variable)
add_subdirectory(Basic_Geometry)
add_subdirectory(Tests)
