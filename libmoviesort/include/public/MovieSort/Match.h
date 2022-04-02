#ifndef MOVIESORT_MATCH_H
#define MOVIESORT_MATCH_H
#include <MovieSort/Movie.h>

namespace MovieSort{
    /**
     * A match between two movies.
     * Includes a timestamp that is calculated when creating the object.
     */
    class Match {
        unsigned char result;
        /**
         * The movies that took part in the match
         */
        Movie movie1, movie2;
        /**
         * Timestamp of the match. Calculated when the object is created.
         */
        std::string timestamp;
        /**
         * Whether the new scores of the movies have been calculated.
         */
        bool calculated = false;
        std::pair<unsigned, unsigned> newScores;
        void calculateTimestamp();
    public:
        /**
         * Creates a new Match object between two movies. Initializes the timestamp.
         */
        Match(Movie movie1, Movie movie2, unsigned char result);
        /**
         * Calculate and return the new Elo scores of the movies
         * @return pair with the new scores of the first and the second movie
         */
        std::pair<unsigned, unsigned> getNewScores();
        /**
         * Get the first movie in the match.
         * @return Movie object
         */
        [[nodiscard]] const MovieSort::Movie& getFirstMovie() const;
        /**
         * Get the second movie in the match.
         * @return Movie object
         */
        [[nodiscard]] const MovieSort::Movie& getSecondMovie() const;
        [[nodiscard]] unsigned char getResult() const;
        [[nodiscard]] std::string getTimestamp() const;
    };
}

#endif //MOVIESORT_MATCH_H
