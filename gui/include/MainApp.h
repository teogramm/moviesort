#ifndef MOVIESORT_MAINAPP_H
#define MOVIESORT_MAINAPP_H
#include <QDialog>
#include <MovieSort/Backend.h>
#include "MainMenu.h"
#include "AddMoviePane.h"

// TODO: Add statistics about file imports (total, successful, failed, already in)
namespace Ui{
    class MainApp;
}

namespace MSGui{
    class MainApp: public QDialog{
        Q_OBJECT
    public:
        MainApp();
        ~MainApp() override;
    private slots:
        void openAddMoviePanel();
        void closePanel();
        void addMovie(const QString& movieName);

    signals:
        void movieAdded(const QString& movieName,AddMovie::Result result);
    private:
        Ui::MainApp* ui;
        MainMenu* mainMenu;
        MovieSort::Backend* backend;
    };
}

#endif //MOVIESORT_MAINAPP_H