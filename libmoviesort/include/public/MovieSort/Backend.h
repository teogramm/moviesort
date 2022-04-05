#ifndef MOVIESORT_BACKEND_H
#define MOVIESORT_BACKEND_H
#include <string>
#include <vector>
#include <memory>
#include "EloCalculator.h"
#include "MovieSort/Match.h"
#include "MovieSort/Movie.h"
#include "MovieDatabase.h"

namespace MovieSort {
    class Backend {
    public:
        explicit Backend(const std::string &fileName);
        void addMovie(const std::string &movieName);
        void writeMatchResult(Match &match);
        [[nodiscard]] std::vector<Movie> getAllMovies();
        std::vector<Movie> getTopKMovies(unsigned k = 10);
    private:
        std::unique_ptr<MovieDatabase> db;
    };
}

#endif //MOVIESORT_BACKEND_H
