cmake_minimum_required(VERSION 3.14)
project(libmoviesort)

set(CMAKE_CXX_STANDARD 17)
add_library(${PROJECT_NAME} src/MovieDatabase.cpp src/EloCalculator.cpp src/Backend.cpp)

find_package(SQLite3 REQUIRED)

# Link to system sqlite
set(SQLITECPP_INTERNAL_SQLITE OFF CACHE BOOL "" FORCE)
add_subdirectory(vendor/SQLiteCpp)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(libmoviesort_test tests/TestEloCalculator.cpp)
target_link_libraries(libmoviesort_test gtest_main ${PROJECT_NAME})
include(GoogleTest)
gtest_discover_tests(libmoviesort_test)


target_link_libraries(${PROJECT_NAME} PRIVATE SQLite::SQLite3 PUBLIC SQLiteCpp)
target_include_directories(${PROJECT_NAME}
        PUBLIC include/public
        PRIVATE ${SQLITE_INCLUDE_DIRS}
        PUBLIC include/private
)