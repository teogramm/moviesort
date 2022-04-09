#ifndef MOVIESORT_BACKENDADAPTER_H
#define MOVIESORT_BACKENDADAPTER_H

#include <QString>
#include <MovieSort/Backend.h>
#include "IMovieInfo.h"
#include "IMatch.h"
#include "IMovieMgmt.h"
#include "IMovieMgmt.h"
#include <MovieSort/Exceptions.h>


namespace MSGui{
    /**
     * Adapter for a MovieSort backend. Implements the GUI interfaces. Converts between
     * standard library classes used by libmoviesort and Qt classes used by the GUI.
     */
    class BackendAdapter: public IMovieInfo, public IMatch, public IMovieMgmt{
    public:
        /**
         * Create a new BackendAdapter. Gets ownership of a MovieSort::Backend object
         * @param backend unique_ptr to a MovieSort::Backend object. Ownership is transferred to this object.
         */
        explicit BackendAdapter(std::unique_ptr<MovieSort::Backend>& backend): backend(std::move(backend)){}

        std::vector<MovieSort::Movie> getAllMovies() override {
            return backend->getAllMovies();
        }

        unsigned int getMovieCount() override {
            return backend->getMovieCount();
        }

        std::pair<MovieSort::Movie, MovieSort::Movie> generateMatch() override {
            return backend->generateMatch();
        }

        void writeMatchResult(const QString &movie1Name, const QString &movie2Name, int matchResult) override {
            backend->writeMatchResult(movie1Name.toStdString(), movie2Name.toStdString(), matchResult);
        }

        std::vector<MovieSort::Movie> getTopKMovies(unsigned int k) override {
            return backend->getTopKMovies(k);
        }

        AddResult addMovie(const QString &movieName) override {
            try{
                backend->addMovie(movieName.toStdString());
                return AddResult::Success;
            } catch (MovieSort::MovieAlreadyExists& e) {
                return AddResult::MovieAlreadyExists;
            } catch (std::runtime_error& e){
                return AddResult::Error;
            }
        };

    private:
        std::unique_ptr<MovieSort::Backend> backend;
    };
}

#endif //MOVIESORT_BACKENDADAPTER_H
