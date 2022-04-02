#include "MovieSort/MovieDatabase.h"
#include "MovieSort/Exceptions.h"

///**
// * Create a full text search index for the movies table
// * @param db
// */
//void create_movies_fts(SQLite::Database &db){
//    auto sql_query = std::string(
//            "CREATE VIRTUAL TABLE IF NOT EXISTS movies_fts USING fts5("
//            "name,"
//            "content=movies,"
//            "prefix='3 4'"
//            ")"
//    );
//    auto stmt = SQLite::Statement(db, sql_query);
//    stmt.executeStep();
//    auto sql_triggers = std::string(
//            "CREATE TRIGGER movies_fts_insert AFTER INSERT ON movies"
//            "BEGIN"
//            "INSERT INTO moviess_fts (rowid, name) VALUES (new.rowid, new.names);"
//            "END;"
//    );
//}

/**
 * Creates the movies table.
 * It contains the name of each movie and its elo.
 * @param db SQLiteCpp database object
 */
void create_movies_table(SQLite::Database &db){
    auto sql_query = std::string(
            "CREATE TABLE IF NOT EXISTS movies ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "name TEXT UNIQUE NOT NULL,"
            "elo INT DEFAULT 1000 NOT NULL"
            ");"
    );
    auto stmt = SQLite::Statement(db, sql_query);
    stmt.executeStep();
    // Create Full text search for the table
//    create_movies_fts(db);
}

/**
 * Create table containing matches between movies.
 * @param db SQLiteCpp database object
 */
void create_matches_table(SQLite::Database &db){
    auto sql_query = std::string(
            "CREATE TABLE IF NOT EXISTS matches ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "timestamp TEXT NOT NULL,"
            "movie1 INTEGER NOT NULL,"
            "movie2 INTEGER NOT NULL,"
            "result INTEGER NOT NULL,"
            "FOREIGN KEY (id) REFERENCES movies(id)"
            ");"
    );
    auto stmt = SQLite::Statement(db, sql_query);
    stmt.executeStep();
}

/**
 * Creates all the necessary tables in the database, if they do not exist.
 * @param db pointer to sqlite3 database
 */
void initialize_database(SQLite::Database &db){
    create_movies_table(db);
    create_matches_table(db);
}

using namespace MovieSort;
/**
 * Opens a movie database in the given database file
 * @param databaseFile path to the database file
 */
MovieDatabase::MovieDatabase(const std::string& databaseFile): db(SQLite::Database(databaseFile, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE))
{
    try {
        initialize_database(db);
    }catch (SQLite::Exception &e){
        // Rethrow exception as database error
        throw DatabaseError(e.what());
    }
}

void MovieDatabase::addMovie(const std::string &movieName) {
    auto query = std::string("INSERT INTO movies(name) VALUES (?);");
    auto stmt = SQLite::Statement(db, query);
    stmt.bind(1, movieName);
    try {
        stmt.executeStep();
    } catch (SQLite::Exception &e) {
        auto what_string = std::string(e.what());
        if (what_string.find("UNIQUE") != std::string::npos){
            throw MovieAlreadyExists(movieName);
        }else{
            throw DatabaseError(what_string);
        }
    }
}

