#ifndef MOVIESORT_BROWSEMOVIESPANEL_H
#define MOVIESORT_BROWSEMOVIESPANEL_H
#include <QWidget>
#include "interfaces/IMovieInfo.h"

namespace Ui{
    class MovieBrowser;
};

namespace MSGui{
    class BrowseMoviesPanel: public QWidget{
        Q_OBJECT
    public:
        explicit BrowseMoviesPanel(MSGui::IMovieInfo& backend, QWidget* parent = nullptr);
        ~BrowseMoviesPanel() override;
    signals:
        void closeButtonPressed();
    private:
        Ui::MovieBrowser* ui;
    };
}

#endif //MOVIESORT_BROWSEMOVIESPANEL_H
