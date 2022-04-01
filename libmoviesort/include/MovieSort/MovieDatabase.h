#ifndef MOVIESORT_MOVIEDATABASE_H
#define MOVIESORT_MOVIEDATABASE_H
#include <fstream>
#include <memory>
#include <sqlite3.h>
#include "SQLiteCpp/Database.h"

namespace MovieSort {
    class MovieDatabase {
    public:
        explicit MovieDatabase(const std::string &databaseFile);
        void addMovie(const std::string &movieName);
    private:
        SQLite::Database db;
    };
}


#endif //MOVIESORT_MOVIEDATABASE_H
