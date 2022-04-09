/**
 * @file
 * Possible outcomes for a match between two movies
 */
#ifndef MOVIESORT_MATCHRESULT_H
#define MOVIESORT_MATCHRESULT_H

namespace MovieSort{
    static constexpr int RESULT_FIRST_MOVIE_WIN = 1;
    static constexpr int RESULT_SECOND_MOVIE_WIN = 2;
    static constexpr int RESULT_DRAW = 0;

    /**
     * Check if the given match result is valid.
     * @param result Result code to be checked.
     * @return true if the given code is an acceptable result code.
     */
    inline bool is_valid_result(int result){
        return result >= 0 && result <= 2;
    }
}


#endif //MOVIESORT_MATCHRESULT_H
