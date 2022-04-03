project(moviesort-gui)

find_package(Curses REQUIRED)

add_executable(moviesort src/test.cpp)
target_include_directories(moviesort PRIVATE include)
target_link_libraries(moviesort libmoviesort ncurses)