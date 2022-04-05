#ifndef MOVIESORT_MAINMENU_H
#define MOVIESORT_MAINMENU_H
#include <QWidget>

namespace Ui{
    class MainMenu;
}

namespace MSGui{
    class MainMenu: public QWidget{
        Q_OBJECT
    public:
        explicit MainMenu(QWidget* parent = nullptr);
        ~MainMenu() override;
    signals:
        void optionAddMoviePressed();
        void closeButtonPressed();
    private:
        Ui::MainMenu* ui;
        void populateMenu();
    };
}

#endif //MOVIESORT_MAINMENU_H
