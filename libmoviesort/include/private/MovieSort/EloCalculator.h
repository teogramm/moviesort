#ifndef MOVIESORT_ELOCALCULATOR_H
#define MOVIESORT_ELOCALCULATOR_H

#include <MovieSort/Movie.h>
#include <utility>

namespace MovieSort{
    class EloCalculator {

        static constexpr unsigned D = 400;
        static constexpr unsigned K = 32;
        static std::pair<double, double> getExpected(unsigned score1, unsigned score2);
    public:
        /**
         * Get the scores of two movies based on the outcome of a match.
         * @param score1 Score of opponent A
         * @param score2 Score of opponent B
         * @param result Outcome of the match. Acceptable outcomes are described in MatchResult.h
         */
        static std::pair<unsigned, unsigned> getNewScores(unsigned score1, unsigned score2, int result);
    };
}

#endif //MOVIESORT_ELOCALCULATOR_H
