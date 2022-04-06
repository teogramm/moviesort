#include "Match.h"
#include "EloCalculator.h"
#include <ctime>
#include <utility>

void MovieSort::Match::calculateTimestamp() {
    // https://stackoverflow.com/a/9528166/15303489
    time_t now;
    time(&now);
    char buf[sizeof "2011-10-08T07:07:09Z"];
    strftime(buf, sizeof buf, "%FT%TZ", gmtime(&now));
    timestamp = std::string(buf);
}

MovieSort::Match::Match(MovieSort::Movie movie1, MovieSort::Movie movie2, unsigned char result)
                    :movie1(std::move(movie1)), movie2(std::move(movie2)), result(result){
    calculateTimestamp();
}

std::pair<unsigned, unsigned> MovieSort::Match::getNewScores(){
    // Don't calculate scores until they are requested.
    if(!calculated){
        newScores = EloCalculator::getNewScores(movie1.getElo(), movie2.getElo(), result);
        calculated = true;
    }
    return newScores;
}

const MovieSort::Movie& MovieSort::Match::getFirstMovie() const {
    return movie1;
}

const MovieSort::Movie& MovieSort::Match::getSecondMovie() const {
    return movie2;
}

unsigned char MovieSort::Match::getResult() const {
    return result;
}

std::string MovieSort::Match::getTimestamp() const {
    return timestamp;
}
