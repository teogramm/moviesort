#ifndef MOVIESORT_MOVIEDATABASE_H
#define MOVIESORT_MOVIEDATABASE_H
#include <fstream>
#include <memory>
#include "MovieSort/Match.h"

namespace MovieSort {
    class MovieDatabase {
    public:
        explicit MovieDatabase(const std::string &databaseFile);
        // Define the destructor here and implement it in the cpp file
        ~MovieDatabase();
        void addMovie(const std::string &movieName);
        /**
         * Get the elo score of the given movie.
         * @param movieName Full name of the movie.
         * @return elo of the movie
         */
        [[nodiscard]] unsigned getMovieElo(const std::string &movieName);
        void writeMatchResult(Match &match);
    private:
        class impl;
        std::unique_ptr<impl> pimpl;
    };
}


#endif //MOVIESORT_MOVIEDATABASE_H
