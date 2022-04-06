#ifndef MOVIESORT_BACKEND_H
#define MOVIESORT_BACKEND_H
#include <string>
#include <vector>
#include <memory>
#include "MovieSort/Movie.h"


namespace MovieSort {
    class Backend {
    public:
        explicit Backend(const std::string &fileName);
        // Define destructor here and implement it in the cpp file
        ~Backend();
        void addMovie(const std::string &movieName);
        void writeMatchResult(const std::string& movie1Name, const std::string& movie2Name, int matchResult);
        [[nodiscard]] std::vector<Movie> getAllMovies();
        std::vector<Movie> getTopKMovies(unsigned k = 10);
        std::pair<Movie, Movie> generateMatch();
    private:
        class impl;
        std::unique_ptr<impl> pimpl;
    };
}

#endif //MOVIESORT_BACKEND_H
