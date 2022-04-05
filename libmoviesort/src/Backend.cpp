#include "MovieSort/Backend.h"
#include "MovieDatabase.h"
#include "EloCalculator.h"

class MovieSort::Backend::impl{
public:
    explicit impl(const std::string& fileName): db(MovieDatabase(fileName)){};
    MovieDatabase& getDB(){
        return db;
    }
private:
    MovieDatabase db;
};

MovieSort::Backend::~Backend() = default;

MovieSort::Backend::Backend(const std::string &fileName): pimpl(std::make_unique<impl>(fileName)){}

void MovieSort::Backend::addMovie(const std::string &movieName) {
    pimpl->getDB().addMovie(movieName);
}

void MovieSort::Backend::writeMatchResult(Match &match) {
    pimpl->getDB().writeMatchResult(match);
}

std::vector<MovieSort::Movie> MovieSort::Backend::getAllMovies() {
    return pimpl->getDB().getAllMovies();
}

std::vector<MovieSort::Movie> MovieSort::Backend::getTopKMovies(unsigned int k) {
    return pimpl->getDB().getTopKMovies(k);
};

