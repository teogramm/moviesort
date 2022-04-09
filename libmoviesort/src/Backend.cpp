#include <random>

#include "MovieSort/Backend.h"
#include "MovieSort/Exceptions.h"
#include "MovieDatabase.h"
#include "EloCalculator.h"
#include "MovieSort/MatchResult.h"

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

std::vector<MovieSort::Movie> MovieSort::Backend::getAllMovies() {
    return pimpl->getDB().getAllMovies();
}

std::vector<MovieSort::Movie> MovieSort::Backend::getTopKMovies(unsigned int k) {
    return pimpl->getDB().getTopKMovies(k);
}

std::pair<MovieSort::Movie, MovieSort::Movie> MovieSort::Backend::generateMatch() {
    if(pimpl->getDB().getMovieCount() < 2){
        throw std::runtime_error("Not enough movies in the database.");
    }
    // Generate a random ID
    auto distribution = std::uniform_int_distribution<unsigned>(1,pimpl->getDB().getMaxId());
    std::random_device rd;
    // Seed with pseudorandom value
    std::default_random_engine generator(rd());

    auto id1 = distribution(generator);
    Movie m1("",0);
    // Keep generating random IDs until we find one that belongs to a movie
    while(true){
        try{
            m1 = pimpl->getDB().getMovieById(id1);
            break;
        }catch(MovieSort::MovieNotFound& e){
            id1 = distribution(generator);
        }
    }

    auto id2 = distribution(generator);
    Movie m2("",0);
    // Keep generating random IDs until we find one that belongs to a movie
    // and the id is different from the first movie's id
    while(true){
        if(id1 == id2){
            distribution(generator);
        }
        try{
            m2 = pimpl->getDB().getMovieById(id2);
            break;
        }catch(MovieSort::MovieNotFound& e){
            id2 = distribution(generator);
        }
    }
    return {m1,m2};
}

void
MovieSort::Backend::writeMatchResult(const std::string &movie1Name, const std::string &movie2Name, int matchResult) {
    auto movie1 = Movie(movie1Name, pimpl->getDB().getMovieElo(movie1Name));
    auto movie2 = Movie(movie2Name, pimpl->getDB().getMovieElo(movie2Name));
    auto match = Match(movie1, movie2, matchResult);
    // Check if match result is valid
    if(!MovieSort::is_valid_result(matchResult)){
        throw std::invalid_argument("Invalid match result code");
    }
    pimpl->getDB().writeMatchResult(match);
}

unsigned MovieSort::Backend::getMovieCount() {
    return pimpl->getDB().getMovieCount();
};

