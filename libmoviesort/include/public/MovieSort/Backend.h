#ifndef MOVIESORT_BACKEND_H
#define MOVIESORT_BACKEND_H
#include <string>
#include <vector>
#include <memory>
#include "MovieSort/Movie.h"

namespace MovieSort {
    class Backend{
    public:
        /**
         * @param fileName File name for the database file.
         */
        explicit Backend(const std::string &fileName);
        // Delete copy constructor. Can't copy SQLite DB.
        Backend(const Backend&) = delete;
        // Define destructor here and implement it in the cpp file
        ~Backend();
        /**
         * Add a new movie to the database.
         * @param movieName Name of the movie to be added.
         * @throws MovieSort::MovieAlreadyExists If a movie with the same name exists in the database
         * @throws MovieSort::DatabaseError If a database error occurs while adding the movie. For details see the
         * error message.
         */
        void addMovie(const std::string &movieName);
        /**
         * Write a match between two movies to the database. The movies must already exist in the database.
         * @param movie1Name Name of the first movie.
         * @param movie2Name Name of the second movie.
         * @param matchResult Outcome of the match. See MatchResult.h for acceptable values.
         * @throws std::invalid_argument If matchResult is an invalid value.
         */
        void writeMatchResult(const std::string& movie1Name, const std::string& movie2Name, int matchResult);
        /**
         * Get all the movies in the database.
         * @return Vector with all the movies in the database, without a particular order.
         */
        [[nodiscard]] std::vector<Movie> getAllMovies();
        /**
         * @return Total number of movies in the database.
         */
        unsigned getMovieCount();
        /**
         * Get the top movies in the database by their Elo score. If the database contains fewer than k movies, they
         * will all be returned.
         * @param k Maximum number of movies to get.
         * @return Vector of k Movie objects, ordered from highest to lowest Elo
         */
        std::vector<Movie> getTopKMovies(unsigned k);
        /**
         * Generate a match between two movies.
         * @return Pair of Movie objects.
         */
        std::pair<Movie, Movie> generateMatch();
    private:
        class impl;
        std::unique_ptr<impl> pimpl;
    };
}

#endif //MOVIESORT_BACKEND_H
