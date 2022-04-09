#ifndef MOVIESORT_BACKEND_H
#define MOVIESORT_BACKEND_H
#include <string>
#include <vector>
#include <memory>
#include "MovieSort/Movie.h"
#include "MovieSort/IMatch.h"
#include "MovieSort/IMovieInfo.h"

namespace MovieSort {
    class Backend: public IMatch, public IMovieInfo{
    public:
        explicit Backend(const std::string &fileName);
        // Define destructor here and implement it in the cpp file
        ~Backend();
        void addMovie(const std::string &movieName);
        void writeMatchResult(const std::string& movie1Name, const std::string& movie2Name, int matchResult) override;
        [[nodiscard]] std::vector<Movie> getAllMovies() override;
        unsigned getMovieCount() override;
        std::vector<Movie> getTopKMovies(unsigned k) override;
        std::pair<Movie, Movie> generateMatch() override;
    private:
        class impl;
        std::unique_ptr<impl> pimpl;
    };
}

#endif //MOVIESORT_BACKEND_H
