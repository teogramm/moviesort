#include <gtest/gtest.h>
#include <MovieSort/EloCalculator.h>
#include <MovieSort/MatchResult.h>

using namespace MovieSort;
TEST(EloCalculator,TestWin1){
    auto results = EloCalculator::getNewScores(1200, 1000, RESULT_FIRST_MOVIE_WIN);
    EXPECT_EQ(results.first, 1208);
    EXPECT_EQ(results.second, 992);
}

TEST(EloCalculator, TestWin2){
    auto results = EloCalculator::getNewScores(1200,  1000, RESULT_SECOND_MOVIE_WIN);
    EXPECT_EQ(results.first, 1176);
    EXPECT_EQ(results.second, 1024);
}