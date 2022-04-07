project(moviesort-gui)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS forms)
find_package(Qt6Widgets COMPONENTS Core Widgets REQUIRED)

set(MOVIESORT_H
        include/MainApp.h
        include/MainMenu.h include/AddMoviePane.h include/MovieMatchPanel.h include/utils.h)
source_group(headers ${MOVIESORT_H})

set(MOVIESORT_SRC
        src/MainApp.cpp
        src/MainMenu.cpp
        src/utils.cpp src/AddMoviePane.cpp
        src/MovieMatchPanel.cpp
        src/utils.cpp)
source_group(sources ${MOVIESORT_SRC})

set(MOVIESORT_FORMS
        forms/addmovie.ui
        forms/mainapp.ui
        forms/mainmenu.ui
        forms/moviematch.ui
        forms/browsemovies.ui)
source_group(forms ${MOVIESORT_FORMS})

add_executable(moviesort src/test.cpp ${MOVIESORT_SRC} ${MOVIESORT_H} ${MOVIESORT_FORMS})
target_include_directories(moviesort PRIVATE include)
target_link_libraries(moviesort libmoviesort Qt6::Core Qt6::Widgets)
