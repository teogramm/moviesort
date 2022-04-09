#ifndef MOVIESORT_ADDMOVIEPANEL_H
#define MOVIESORT_ADDMOVIEPANEL_H
#include <QWidget>
#include "interfaces/IMovieMgmt.h"

namespace Ui{
    class AddMovie;
};

namespace MSGui{

    class AddMoviePanel: public QWidget{
        Q_OBJECT
    public:
        explicit AddMoviePanel(IMovieMgmt& backend, QWidget* parent = nullptr);
        ~AddMoviePanel() override;
    signals:
        void closeButtonPressed();
    private slots:
        void addMoviesFromFile();
    private:
        bool fileLoadingInProgress = false;
        Ui::AddMovie* ui;
        IMovieMgmt& backend;
        /**
         * Writes the result of an addMovie operation to the log widget.
         * @param movieName Name of the movie that was added
         * @param result Result of the addMovieOperation
         */
        void writeAddMovieResult(const QString&movieName, MSGui::IMovieMgmt::AddResult result);
    };
}

#endif //MOVIESORT_ADDMOVIEPANEL_H
