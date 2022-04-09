#ifndef MOVIESORT_IMATCH_H
#define MOVIESORT_IMATCH_H
#include <MovieSort/Movie.h>
#include <vector>

namespace MSGui {
/**
 * An Interface used to request matches and submit results
 */
    class IMatch {
    public:
        virtual std::pair<MovieSort::Movie, MovieSort::Movie> generateMatch() = 0;
        virtual void
        writeMatchResult(const QString &movie1Name, const QString &movie2Name, int matchResult) = 0;
        virtual std::vector<MovieSort::Movie> getTopKMovies(unsigned) = 0;
    };
}

#endif //MOVIESORT_IMATCH_H
