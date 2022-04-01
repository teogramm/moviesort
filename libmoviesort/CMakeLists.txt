project(libmoviesort)

add_library(${PROJECT_NAME} src/test.cpp src/MovieDatabase.cpp include/MovieDatabase.h)

find_package(SQLite3 REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE SQLite::SQLite3)
target_include_directories(${PROJECT_NAME}
        PUBLIC include
        PRIVATE ${SQLITE_INCLUDE_DIRS}
)