#include "MovieSort/Backend.h"

MovieSort::Backend::Backend(const std::string &fileName):
    db(new MovieSort::MovieDatabase(fileName)){}

void MovieSort::Backend::addMovie(const std::string &movieName) {
    db->addMovie(movieName);
}

void MovieSort::Backend::writeMatchResult(Match &match) {
    db->writeMatchResult(match);
}

std::vector<MovieSort::Movie> MovieSort::Backend::getAllMovies() {
    return db->getAllMovies();
}

std::vector<MovieSort::Movie> MovieSort::Backend::getTopKMovies(unsigned int k) {
    return db->getTopKMovies(k);
};

