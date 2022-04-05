#ifndef MOVIESORT_MAINAPP_H
#define MOVIESORT_MAINAPP_H
#include <QDialog>
#include <MovieSort/Backend.h>
#include "MainMenu.h"

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
    private:
        Ui::MainApp* ui;
        MainMenu* mainMenu;
    };
}

#endif //MOVIESORT_MAINAPP_H
