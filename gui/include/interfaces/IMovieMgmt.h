#ifndef MOVIESORT_IMOVIEMGMT_H
#define MOVIESORT_IMOVIEMGMT_H
#include <QString>


namespace MSGui{
    /**
     * Interface for managing movies in the database.
     */
    class IMovieMgmt{
    public:
        /**
         * Contains the possible results when adding a movie to the backend.
         */
        enum class AddResult{
            Success,
            MovieAlreadyExists,
            Error
        };
        virtual AddResult addMovie(const QString& movieName) = 0;
    };
}

#endif //MOVIESORT_IMOVIEMGMT_H
