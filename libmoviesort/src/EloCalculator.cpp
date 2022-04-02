#include <MovieSort/EloCalculator.h>
#include <cmath>
#include <MovieSort/MatchResult.h>
#include <stdexcept>

using namespace MovieSort;
std::pair<double, double> EloCalculator::getExpected(unsigned score1, unsigned score2) {
    // Make type double, so we can avoid casts when calculating
    auto diff = static_cast<double>(score2) - score1;
    auto E_A = 1/(1+std::pow(10,diff/D));
    diff = static_cast<double>(score1) - score2;
    auto E_B = 1/(1+std::pow(10, diff/D));
    return {E_A, E_B};
}

/**
 * Get S_A and S_B for the given result. S is 1 for the winner and 0 for the loser or
 * 0.5 for both in case of draw.
 * @param result Outcome of the match. Acceptable outcomes are described in MatchResult.h
 * @return std::pair containing S_A and S_B
 */
std::pair<double, double> get_S_values(int result){
    double S_A, S_B;
    switch (result) {
        case RESULT_FIRST_MOVIE_WIN:
            S_A = 1;
            S_B = 0;
            break;
        case RESULT_SECOND_MOVIE_WIN:
            S_A = 0;
            S_B = 1;
            break;
        case RESULT_DRAW:
            S_A = 0.5;
            S_B = 0.5;
            break;
        default:
            std::string errorMessage = std::string("Invalid match result: ");
            throw std::invalid_argument(errorMessage + std::to_string(result));
    }
    return {S_A, S_B};
}

std::pair<unsigned, unsigned> EloCalculator::getNewScores(unsigned score1, unsigned score2, int result) {
    auto expected = getExpected(score1,score2);
    auto s_vals = get_S_values(result);
    // K is split between the two players in a draw
    unsigned actual_K = (result==RESULT_DRAW)?K/2:K;
    // Calculate the new scores
    auto R_A = score1 + actual_K*(s_vals.first - expected.first);
    auto R_B = score2 + actual_K*(s_vals.second - expected.second);
    return {std::round(R_A), std::round(R_B)};
}
