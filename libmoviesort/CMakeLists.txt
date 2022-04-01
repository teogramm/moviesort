project(libmoviesort)

add_library(${PROJECT_NAME} src/test.cpp src/MovieDatabase.cpp include/MovieDatabase.h)

find_package(SQLite3 REQUIRED)

# Link to system sqlite
set(SQLITECPP_INTERNAL_SQLITE OFF CACHE BOOL "" FORCE)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/vendor/SQLiteCpp)

target_link_libraries(${PROJECT_NAME} PRIVATE SQLite::SQLite3 SQLiteCpp)
target_include_directories(${PROJECT_NAME}
        PUBLIC include
        PRIVATE ${SQLITE_INCLUDE_DIRS}
)