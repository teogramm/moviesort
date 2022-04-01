#ifndef MOVIESORT_MOVIEDATABASE_H
#define MOVIESORT_MOVIEDATABASE_H
#include <fstream>
#include <memory>
#include <sqlite3.h>
#include <SQLiteCpp/Database.h>

class MovieDatabase {
public:
    explicit MovieDatabase(const std::string& databaseFile);
private:
    SQLite::Database db;
};


#endif //MOVIESORT_MOVIEDATABASE_H
