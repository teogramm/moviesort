#ifndef MOVIESORT_IMOVIEINFO_H
#define MOVIESORT_IMOVIEINFO_H

#include <vector>
#include "Movie.h"

namespace MovieSort{
    /**
     * Interface with methods that provide information about the movies stored
     * in the database.
     */
    class IMovieInfo{
    public:
        virtual std::vector<MovieSort::Movie> getAllMovies() = 0;
        virtual unsigned getMovieCount() = 0;
    };
}

#endif //MOVIESORT_IMOVIEINFO_H
