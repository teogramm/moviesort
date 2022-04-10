cmake_minimum_required(VERSION 3.14)
project(libmoviesort VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
include(GNUInstallDirs)

set(LIBMOVIESORT_INC
        ${PROJECT_SOURCE_DIR}/include/public/MovieSort/Backend.h
        ${PROJECT_SOURCE_DIR}/include/public/MovieSort/Exceptions.h
        ${PROJECT_SOURCE_DIR}/include/public/MovieSort/MatchResult.h
        ${PROJECT_SOURCE_DIR}/include/public/MovieSort/Movie.h
        ${PROJECT_SOURCE_DIR}/include/private/EloCalculator.h
        ${PROJECT_SOURCE_DIR}/include/private/Match.h
        ${PROJECT_SOURCE_DIR}/include/private/MovieDatabase.h)

set(LIBMOVIESORT_SRC src/MovieDatabase.cpp src/EloCalculator.cpp src/Backend.cpp src/Match.cpp)

add_library(libmoviesort ${LIBMOVIESORT_INC} ${LIBMOVIESORT_SRC})
add_library(MovieSort::libmoviesort ALIAS libmoviesort)

find_package(SQLite3)
if (SQLite3_FOUND)
    set(SQLITECPP_INTERNAL_SQLITE OFF CACHE BOOL "" FORCE)
else(SQLite3_FOUND)
    set(SQLITECPP_INTERNAL_SQLITE OFF CACHE BOOL "" FORCE)
endif(SQLite3_FOUND)
add_subdirectory(vendor/SQLiteCpp EXCLUDE_FROM_ALL)
target_link_libraries(libmoviesort PRIVATE SQLiteCpp)
target_include_directories(libmoviesort PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/public>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        PRIVATE ${PROJECT_SOURCE_DIR}/include/private)

# --------- GoogleTest --------------
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF)
set(INSTALL_GMOCK OFF)
FetchContent_MakeAvailable(googletest)
# ----------------------------------

# Install the library
# https://jeremimucha.com/2021/03/cmake-fundamentals-part7/
include(CMakePackageConfigHelpers)
install(TARGETS libmoviesort
        EXPORT MovieSortTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/public/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT MovieSortTargets DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MovieSort
        NAMESPACE MovieSort::)
