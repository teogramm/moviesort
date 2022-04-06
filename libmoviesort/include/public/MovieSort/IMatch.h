#ifndef MOVIESORT_IMATCH_H
#define MOVIESORT_IMATCH_H
#include "Movie.h"

/**
 * An Interface used to request matches and submit results
 */
class IMatch{
    virtual std::pair<MovieSort::Movie, MovieSort::Movie> getMatch() = 0;
    virtual void submitMatchResult(const std::string& movie1Name, const std::string& movie2Name, int matchResult) = 0;
};
#endif //MOVIESORT_IMATCH_H
