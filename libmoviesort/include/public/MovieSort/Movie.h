#ifndef MOVIESORT_MOVIE_H
#define MOVIESORT_MOVIE_H
#include <string>
#include <utility>

namespace MovieSort {
    class Movie {
    public:
        Movie(std::string movieName, unsigned movieElo): name(std::move(movieName)), elo(movieElo){};
        [[nodiscard]] std::string getName() const {
            return name;
        }
        [[nodiscard]] unsigned getElo() const {
            return elo;
        }
    private:
        std::string name;
        unsigned elo;
    };
}

#endif //MOVIESORT_MOVIE_H
