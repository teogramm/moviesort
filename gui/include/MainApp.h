#ifndef MOVIESORT_MAINAPP_H
#define MOVIESORT_MAINAPP_H
#include <QDialog>
#include <MovieSort/Backend.h>

namespace Ui{
    class MainApp;
}

namespace MSGui{
    class MainApp: public QDialog{
        Q_OBJECT
    public:
        MainApp();
        ~MainApp() override;
    private:
        Ui::MainApp* ui;

    };
}

#endif //MOVIESORT_MAINAPP_H
