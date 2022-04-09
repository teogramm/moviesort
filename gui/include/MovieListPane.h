#ifndef MOVIESORT_MOVIELISTPANE_H
#define MOVIESORT_MOVIELISTPANE_H
#include <QWidget>
#include <MovieSort/IMovieInfo.h>

namespace Ui{
    class MovieBrowser;
};

namespace MSGui{
    class MovieBrowser: public QWidget{
        Q_OBJECT
    public:
        explicit MovieBrowser(MovieSort::IMovieInfo& backend, QWidget* parent = nullptr);
        ~MovieBrowser() override;
    signals:
        void closeButtonPressed();
    private:
        Ui::MovieBrowser* ui;
    };
}

#endif //MOVIESORT_MOVIELISTPANE_H
