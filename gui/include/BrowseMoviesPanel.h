#ifndef MOVIESORT_BROWSEMOVIESPANEL_H
#define MOVIESORT_BROWSEMOVIESPANEL_H
#include <QWidget>
#include <MovieSort/IMovieInfo.h>

namespace Ui{
    class MovieBrowser;
};

namespace MSGui{
    class BrowseMoviesPanel: public QWidget{
        Q_OBJECT
    public:
        explicit BrowseMoviesPanel(MovieSort::IMovieInfo& backend, QWidget* parent = nullptr);
        ~BrowseMoviesPanel() override;
    signals:
        void closeButtonPressed();
    private:
        Ui::MovieBrowser* ui;
    };
}

#endif //MOVIESORT_BROWSEMOVIESPANEL_H
