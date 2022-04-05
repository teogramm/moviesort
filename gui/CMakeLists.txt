project(moviesort-gui)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS forms)
find_package(Qt6Widgets COMPONENTS Core Widgets REQUIRED)

add_executable(moviesort src/test.cpp forms/mainapp.ui forms/mainmenu.ui include/mainapp.h src/mainapp.cpp include/mainmenu.h src/mainmenu.cpp include/addmovie.h src/addmovie.cpp include/utils.h src/utils.cpp)
target_include_directories(moviesort PRIVATE include)
target_link_libraries(moviesort libmoviesort Qt6::Core Qt6::Widgets)
