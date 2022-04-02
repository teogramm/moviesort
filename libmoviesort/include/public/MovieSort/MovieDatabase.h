#ifndef MOVIESORT_MOVIEDATABASE_H
#define MOVIESORT_MOVIEDATABASE_H
#include <fstream>
#include <memory>
#include <sqlite3.h>
#include <MovieSort/Match.h>
#include <SQLiteCpp/Database.h>

namespace MovieSort {
    class MovieDatabase {
    public:
        explicit MovieDatabase(const std::string &databaseFile);
        explicit MovieDatabase(SQLite::Database &db): db(std::move(db)){};
        void addMovie(const std::string &movieName);
        /**
         * Get the elo score of the given movie.
         * @param movieName Full name of the movie.
         * @return elo of the movie
         */
        [[nodiscard]] unsigned getMovieElo(const std::string &movieName);
        void writeMatchResult(Match &match);
    private:
        SQLite::Database db;
    };
}


#endif //MOVIESORT_MOVIEDATABASE_H
