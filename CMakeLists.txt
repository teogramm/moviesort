cmake_minimum_required(VERSION 3.21)
project (moviesort)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(libmoviesort)
add_executable(moviesort main.cpp)
target_link_libraries(moviesort libmoviesort)