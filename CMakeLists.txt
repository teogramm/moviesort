cmake_minimum_required(VERSION 3.21)
project (moviesort)

include(CMakePrintHelpers)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(libmoviesort)
add_subdirectory(gui)