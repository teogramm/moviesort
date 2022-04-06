#include <gtest/gtest.h>
#include <MovieSort/MatchResult.h>
#include "Match.h"
#include "EloCalculator.h"

using namespace MovieSort;
TEST(EloCalculator,TestWin1){
    auto results = EloCalculator::getNewScores(1000,1000, RESULT_FIRST_MOVIE_WIN);
    EXPECT_EQ(results.first, 1016);
    EXPECT_EQ(results.second, 984);
    results = EloCalculator::getNewScores(1200, 1000, RESULT_FIRST_MOVIE_WIN);
    EXPECT_EQ(results.first, 1208);
    EXPECT_EQ(results.second, 992);
}

TEST(EloCalculator, TestWin2){
    auto results = EloCalculator::getNewScores(1000,1000, RESULT_SECOND_MOVIE_WIN);
    EXPECT_EQ(results.first, 984);
    EXPECT_EQ(results.second, 1016);
    results = EloCalculator::getNewScores(1200,  1000, RESULT_SECOND_MOVIE_WIN);
    EXPECT_EQ(results.first, 1176);
    EXPECT_EQ(results.second, 1024);
}

TEST(EloCalculator, Draw){
    // Draw between two equal players should not change anything
    auto results = EloCalculator::getNewScores(1000,1000, RESULT_DRAW);
    EXPECT_EQ(results.first, 1000);
    EXPECT_EQ(results.second, 1000);
}