#ifndef MOVIESORT_IMATCH_H
#define MOVIESORT_IMATCH_H
#include "Movie.h"


namespace MovieSort {
/**
 * An Interface used to request matches and submit results
 */
    class IMatch {
    public:
        virtual std::pair<MovieSort::Movie, MovieSort::Movie> generateMatch() = 0;
        virtual void
        writeMatchResult(const std::string &movie1Name, const std::string &movie2Name, int matchResult) = 0;
    };
}
#endif //MOVIESORT_IMATCH_H
