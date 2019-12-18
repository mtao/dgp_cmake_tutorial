cmake_minimum_required(VERSION 3.11.1)

project(DGPCMakeTutorial VERSION 0.1
    DESCRIPTION "A tutorial for the DGP on CMake"
    LANGUAGES CXX)


# https://cmake.org/cmake/help/v3.15/module/FindBoost.html

find_package(Boost COMPONENTS filesystem)




add_library(localization src/hello_map.cpp src/get_hello.cpp)
target_include_directories(localization PUBLIC include PRIVATE include_private)

set_target_properties(localization PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    )

add_executable(hello_world src/hello_world.cpp)
target_link_libraries(hello_world Boost::filesystem localization)


# ========================================
# https://cliutils.gitlab.io/modern-cmake/chapters/projects/fetch.html

# get hte fetchcontent module
include(FetchContent REQUIRED)
# declare where to fetch libigl from
FetchContent_Declare(
    libigl
    GIT_REPOSITORY https://github.com/libigl/libigl.git
    #GIT_TAG f6b406427400ed7ddb56cfc2577b6af571827c8c
    GIT_TAG v2.1.0
    )

#for igl we have to set a variable to activate the viewer
set(LIBIGL_USE_STATIC_LIBRARY OFF)
set(LIBIGL_WITH_OPENGL ON)
set(LIBIGL_WITH_OPENGL_GLFW ON)
set(LIBIGL_WITH_PNG OFF)
set(LIBIGL_WITH_TETGEN OFF)
set(LIBIGL_WITH_TRIANGLE OFF)
set(LIBIGL_WITH_PREDICATES OFF)
set(LIBIGL_WITH_XML OFF)
set(LIBIGL_WITH_EMBREE OFF)
set(LIBIGL_WITH_COMISO OFF)

# new cmake can update in one shot, but the older one requires one extra command
if(${CMAKE_VERSION} VERSION_LESS 3.14)
    FetchContent_Populate(libigl)
    add_subdirectory(${libigl_SOURCE_DIR} ${libigl_BINARY_DIR})
else()
    FetchContent_MakeAvailable(libigl)
endif()


add_library(harmonic_oscillator src/harmonic_oscillator.cpp include/harmonic_oscillator.hpp)
target_include_directories(harmonic_oscillator PUBLIC include)
target_link_libraries(harmonic_oscillator Boost::boost)

add_executable(oscillating_cube src/oscillating_cube.cpp)
target_link_libraries(oscillating_cube igl::opengl_glfw harmonic_oscillator)




# ========================================




set(DGtal_DIR ${CMAKE_CURRENT_LIST_DIR}/extern/DGtal/build)
find_package(DGtal CONFIG)

if(DGtal_FOUND)
else(DGtal_FOUND)
    message(FATAL_ERROR "Please run the get_deps.sh script!")
endif(DGtal_FOUND)

add_executable(dgtal_logo ${DGtal_DIR}/../examples/io/boards/logoDGtal.cpp)
target_include_directories(dgtal_logo PRIVATE ${DGTAL_INCLUDE_DIRS})
target_link_directories(dgtal_logo PRIVATE ${DGTAL_LIBRARY_DIRS})
target_link_libraries(dgtal_logo ${DGTAL_LIBRARIES})

add_subdirectory(tests EXCLUDE_FROM_ALL)
