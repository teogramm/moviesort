#ifndef MOVIESORT_EXCEPTIONS_H
#define MOVIESORT_EXCEPTIONS_H
#include <exception>
#include <string>
#include <utility>
#include <stdexcept>

namespace MovieSort{
    /**
     * A general error in the database.
     */
    class DatabaseError: public std::runtime_error{
    public:
        explicit DatabaseError(const std::string &info) : runtime_error(info) {};
    };

    /**
     * Indicates that a movie with the same name exists in the database.
     */
    class MovieAlreadyExists: public DatabaseError{
        constexpr static auto message = " already exists in the database.";
    public:
        explicit MovieAlreadyExists(const std::string &movieName): DatabaseError(movieName + message) {
        }
    };

    /**
     * Indicates that a movie was not found in the database.
     */
    class MovieNotFound: public DatabaseError{
        constexpr static auto message = " not found in database.";
    public:
        explicit MovieNotFound(const std::string &movieName): DatabaseError(movieName + message){};
    };
}

#endif //MOVIESORT_EXCEPTIONS_H
