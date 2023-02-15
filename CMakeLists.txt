cmake_minimum_required(VERSION 3.10)

include(FetchContent)

FetchContent_Declare(
    "L_Variable"
    GIT_REPOSITORY "https://github.com/Letinemeso/L_Variable.git"
    SOURCE_DIR "../L_Variable"
    GIT_TAG "origin/master"
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
  )
FetchContent_MakeAvailable(L_Variable)

FetchContent_Declare(
    "Utility"
    GIT_REPOSITORY "https://github.com/Letinemeso/Utility.git"
    SOURCE_DIR "../Utility"
    GIT_TAG "origin/master"
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
  )
FetchContent_MakeAvailable(Utility)

add_subdirectory(Basic_Geometry)
add_subdirectory(Tests)
