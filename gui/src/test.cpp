#include "MainApp.h"
#include <QApplication>
#include <MovieSort/Movie.h>

int main(int argc, char *argv[])
{
    QApplication app{argc, argv};
    auto a = MSGui::MainApp();
    a.show();
    return app.exec();
}