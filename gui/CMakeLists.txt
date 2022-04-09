project(moviesort-gui)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS forms)
find_package(Qt6Widgets COMPONENTS Core Widgets REQUIRED)

set(MOVIESORT_H
        include/MainApp.h
        include/MainMenu.h include/AddMoviePanel.h
        include/MovieMatchPanel.h
        include/utils.h
        include/BrowseMoviesModel.h
        include/BrowseMoviesPanel.h
        include/interfaces/IMatch.h
        include/interfaces/IMovieMgmt.h
        include/interfaces/IMovieInfo.h
        include/interfaces/BackendAdapter.h)
source_group(headers ${MOVIESORT_H})

set(MOVIESORT_SRC
        src/MainApp.cpp
        src/MainMenu.cpp
        src/utils.cpp src/AddMoviePanel.cpp
        src/MovieMatchPanel.cpp
        src/utils.cpp src/BrowseMoviesModel.cpp src/BrowseMoviesPanel.cpp)
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
