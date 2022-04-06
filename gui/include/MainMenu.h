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
        /**
         * Emitted when the object wants to reload the top movies list.
         * @param k get the top k movies
         */
         // Currently unused and logic is implemented in MainApp.h
         // Consider if it should be used or removed.
        void wantTopMovies(unsigned k = 10);
        void optionAddMoviePressed();
        void closeButtonPressed();
    private:
        Ui::MainMenu* ui;
        std::vector<MovieSort::Movie> topMovies;
        void populateMenu();
        /**
         * Populate the top movies table with values from the
         */
        void populateTopMoviesTable();
    };
}

#endif //MOVIESORT_MAINMENU_H
