#ifndef MOVIESORT_MOVIEDATABASE_H
#define MOVIESORT_MOVIEDATABASE_H
#include <memory>
#include <vector>
#include "Match.h"

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
        [[nodiscard]] std::vector<Movie> getAllMovies();
        [[nodiscard]] std::vector<Movie> getTopKMovies(unsigned k = 10);
        [[nodiscard]] unsigned getMovieCount();
        /**
         *
         * @param id
         * @return
         * @throw MovieSort::MovieNotFound when a movie with the given ID does not exist.
         */
        [[nodiscard]] Movie getMovieById(unsigned id);
        // Useful when we want to generate random movie IDs
        unsigned getMaxId();
    private:
        class impl;
        std::unique_ptr<impl> pimpl;

    };
}


#endif //MOVIESORT_MOVIEDATABASE_H
