cmake_minimum_required(VERSION 3.11.1)

project(DGPCMakeTutorial VERSION 0.1
    DESCRIPTION "A tutorial for the DGP on CMake"
    LANGUAGES CXX)


# https://cmake.org/cmake/help/v3.15/module/FindBoost.html

find_package(Boost COMPONENTS filesystem)


add_executable(hello_world src/hello_world.cpp)
target_link_libraries(hello_world Boost::filesystem)


