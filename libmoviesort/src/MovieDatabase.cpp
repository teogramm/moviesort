#include "MovieDatabase.h"

/**
 * Creates the movies table.
 * It contains the name of each movie and its elo.
 * @param db pointer to sqlite3 database
 */
void create_movies_table(sqlite3* db){
    auto sql_stmt = std::string(
            "CREATE TABLE IF NOT EXISTS movies ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "name TEXT UNIQUE NOT NULL,"
            "elo INT DEFAULT 1000 NOT NULL"
            ");"
    );
    sqlite3_stmt* prepared;
    sqlite3_prepare_v2(db, sql_stmt.c_str(), -1, &prepared, nullptr);
    sqlite3_step(prepared);
    auto result = sqlite3_finalize(prepared);
    if(result != SQLITE_OK){
        auto err_str = sqlite3_errmsg(db);
        throw std::runtime_error(std::string("Error initializing database: ").append(err_str));
    }
}

/**
 * Creates all the necessary tables in the database, if they do not exist.
 * @param db pointer to sqlite3 database
 */
void initialize_database(sqlite3* db){
    create_movies_table(db);
}

/**
 * Opens a movie database in the given database file
 * @param databaseFile fstream containing the database
 */
MovieDatabase::MovieDatabase(const std::string& databaseFile) {
    // DB is opened rw or is created if it does not exist
    auto err = sqlite3_open(databaseFile.c_str(), &db);
    if(err != SQLITE_OK){
        auto err_str = sqlite3_errmsg(db);
        throw std::runtime_error(std::string("Error initializing database: ").append(err_str));
    }
    initialize_database(db);
}

MovieDatabase::~MovieDatabase() {
    sqlite3_close_v2(db);
}

