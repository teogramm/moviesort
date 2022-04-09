#ifndef MOVIESORT_MAINAPP_H
#define MOVIESORT_MAINAPP_H
#include <QDialog>
#include <MovieSort/Backend.h>
#include "MainMenu.h"
#include "AddMoviePanel.h"
#include "interfaces/BackendAdapter.h"

// TODO: Add statistics about file imports (total, successful, failed, already in)
namespace Ui{
    class MainApp;
}

namespace MSGui{
    /**
     * Responsible for switching between the different panels of the app.
     */
    class MainApp: public QDialog{
        Q_OBJECT
    public:
        MainApp();
        ~MainApp() override;
    private slots:
        /**
         * Opens the Add Movie panel and switches to it.
         */
        void openAddMoviePanel();
        /**
         * Opens the Add Movie panel and switches to it.
         */
        void openMovieMatchPanel();
        /**
         * Opens the Add Movie panel and switches to it.
         */
        void openMovieListPanel();
        /**
         * Closes the currently open panel
         */
        void closePanel();
    private:
        Ui::MainApp* ui;
        MainMenu* mainMenu;
        MSGui::BackendAdapter* backend;
        /**
         * Connect the signals emitted from the main menu to the slots that open
         * the respective panes in MainApp.
         */
        void connectMainMenu();
    };
}

#endif //MOVIESORT_MAINAPP_H
