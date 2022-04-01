#ifndef MOVIESORT_MOVIEDATABASE_H
#define MOVIESORT_MOVIEDATABASE_H
#include <fstream>
#include <memory>
#include <sqlite3.h>

class MovieDatabase {
public:
    explicit MovieDatabase(const std::string& databaseFile);
    ~MovieDatabase();
private:
    sqlite3* db = nullptr;
};


#endif //MOVIESORT_MOVIEDATABASE_H
