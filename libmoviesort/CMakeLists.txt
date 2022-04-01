project(libmoviesort)

set(CMAKE_CXX_STANDARD 17)
add_library(${PROJECT_NAME} src/test.cpp src/MovieDatabase.cpp include/MovieSort/MovieDatabase.h include/MovieSort/Exceptions.h)

find_package(SQLite3 REQUIRED)

# Link to system sqlite
set(SQLITECPP_INTERNAL_SQLITE OFF CACHE BOOL "" FORCE)
add_subdirectory(vendor/SQLiteCpp)

target_link_libraries(${PROJECT_NAME} PRIVATE SQLiteCpp SQLite::SQLite3)
target_include_directories(${PROJECT_NAME}
        PUBLIC include
        PRIVATE ${SQLITE_INCLUDE_DIRS}
)