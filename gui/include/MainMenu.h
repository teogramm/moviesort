#ifndef MOVIESORT_MAINMENU_H
#define MOVIESORT_MAINMENU_H
#include <QWidget>
#include <vector>
#include <MovieSort/Movie.h>

namespace Ui{
    class MainMenu;
}

namespace MSGui{
    // TODO: Improve leaderboard appearance
    // TODO: Add text label when leaderboard is empty
    class MainMenu: public QWidget{
        Q_OBJECT
    public:
        explicit MainMenu(QWidget* parent = nullptr);
        ~MainMenu() override;

    public slots:
        void setTopMovies(const std::vector<MovieSort::Movie> &newTopMovies);
    signals:
        void optionAddMoviePressed();
        void optionStartMatchPressed();
        void optionSeeMoviesPressed();
    private:
        Ui::MainMenu* ui;
        std::vector<MovieSort::Movie> topMovies;
        void populateMenu();
        /**
         * Populate the top movies table with values from the
         */
        void populateTopMoviesTable();
        /**
         * Configure the leaderboard widget.
         */
        void setUpLeaderboard();
    };
}

#endif //MOVIESORT_MAINMENU_H
