#ifndef MOVIESORT_EXCEPTIONS_H
#define MOVIESORT_EXCEPTIONS_H
#include <exception>
#include <string>
#include <utility>
#include <stdexcept>

namespace MovieSort{
    class DatabaseError: public std::runtime_error{
    public:
        explicit DatabaseError(const std::string &info) : runtime_error(info) {};
    };

    class MovieAlreadyExists: public DatabaseError{
        constexpr static auto message = " already exists in the database.";
    public:
        explicit MovieAlreadyExists(const std::string &movieName): DatabaseError(movieName + message) {
        }
    };

    class MovieNotFound: public DatabaseError{
        constexpr static auto message = " not found in database.";
    public:
        explicit MovieNotFound(const std::string &movieName): DatabaseError(movieName + message){};
    };
}

#endif //MOVIESORT_EXCEPTIONS_H
