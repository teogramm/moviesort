#include "MovieDatabase.h"
#include "MovieSort/Exceptions.h"
#include <SQLiteCpp/Transaction.h>
#include <SQLiteCpp/Database.h>

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
    auto indexStmt = SQLite::Statement(db,
"CREATE INDEX IF NOT EXISTS movie_name_index ON movies(name);");
    indexStmt.executeStep();
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

class MovieDatabase::impl{
    SQLite::Database db;
public:
    explicit impl(const std::string& databaseFile):
        db(SQLite::Database(databaseFile, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE)) {};
    SQLite::Database& getDB(){
        return db;
    }
};
MovieDatabase::~MovieDatabase() = default;

/**
 * Opens a movie database in the given database file
 * @param databaseFile path to the database file
 */
MovieDatabase::MovieDatabase(const std::string& databaseFile):
    pimpl(std::make_unique<impl>(databaseFile))
{
    try {
        initialize_database(pimpl->getDB());
    }catch (SQLite::Exception &e){
        // Rethrow exception as database error
        throw DatabaseError(e.what());
    }
}

void MovieDatabase::addMovie(const std::string &movieName) {
    auto query = std::string("INSERT INTO movies(name) VALUES (?);");
    auto stmt = SQLite::Statement(pimpl->getDB(), query);
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

unsigned MovieDatabase::getMovieElo(const std::string &movieName) {
    auto query = std::string("SELECT elo FROM movies WHERE name = ?;");
    auto stmt = SQLite::Statement(pimpl->getDB(), query);
    stmt.bind(1, movieName);
    stmt.executeStep();
    if(stmt.hasRow()) {
        unsigned elo = stmt.getColumn(0);
        return elo;
    }else{
        throw MovieNotFound(movieName);
    }
}


void MovieDatabase::writeMatchResult(Match &match) {
    auto transaction = SQLite::Transaction(pimpl->getDB());
    // First insert an entry on the matches table
    auto insert_query = std::string(
            "INSERT INTO matches(timestamp, movie1, movie2, result) "
            "VALUES (?,"
            "(SELECT id FROM movies WHERE name = ?),"
            "(SELECT id FROM movies WHERE name = ?),"
            "?);"
    );
    auto insert_stmt = SQLite::Statement(pimpl->getDB(), insert_query);
    insert_stmt.bind(1, match.getTimestamp());
    insert_stmt.bind(2, match.getFirstMovie().getName());
    insert_stmt.bind(3, match.getSecondMovie().getName());
    insert_stmt.bind(4, match.getResult());
    insert_stmt.executeStep();
    // Update the Elo of the movies
    auto update_query = std::string(
        "UPDATE movies SET elo = ? WHERE name = ?;"
    );
    auto update_stmt = SQLite::Statement(pimpl->getDB(), update_query);
    update_stmt.bind(1, match.getNewScores().first);
    update_stmt.bind(2, match.getFirstMovie().getName());
    update_stmt.executeStep();
    update_stmt.reset();
    update_stmt.bind(1, match.getNewScores().second);
    update_stmt.bind(2, match.getSecondMovie().getName());
    update_stmt.executeStep();
    transaction.commit();
}

std::vector<Movie> MovieSort::MovieDatabase::getAllMovies() {
    auto query = std::string(
            "SELECT name,elo FROM movies;"
    );
    auto movies = std::vector<Movie>();
    auto& db = pimpl->getDB();
    auto stmt = SQLite::Statement(db, query);
    while(stmt.executeStep()){
        std::string name = stmt.getColumn(0);
        unsigned elo = stmt.getColumn(1);
        movies.emplace_back(name,elo);
    }
    return movies;
}

std::vector<Movie> MovieSort::MovieDatabase::getTopKMovies(unsigned k){
    auto query = std::string(
            "SELECT name, elo FROM movies ORDER BY elo DESC LIMIT ?;"
    );
    auto stmt = SQLite::Statement(pimpl->getDB(), query);
    stmt.bind(1,k);
    auto movies = std::vector<Movie>();
    while(stmt.executeStep()){
        std::string name = stmt.getColumn(0);
        unsigned elo = stmt.getColumn(1);
        movies.emplace_back(name,elo);
    }
    return movies;
}

