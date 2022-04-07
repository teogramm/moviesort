#ifndef MOVIESORT_MOVIEMATCHPANEL_H
#define MOVIESORT_MOVIEMATCHPANEL_H
#include <QWidget>
#include "MovieSort/IMatch.h"

namespace Ui{
    class MovieMatch;
}

namespace MSGui {
    class MovieMatch : public QWidget {
    Q_OBJECT
    public:
        explicit MovieMatch(MovieSort::IMatch &backend, QWidget *parent = nullptr);
        ~MovieMatch() override;

    signals:
        /**
         * Called when the user wants to close this panel
         */
        void closeButtonPressed();
    private:
        Ui::MovieMatch *ui;
        MovieSort::IMatch &backend;
    };
}

#endif //MOVIESORT_MOVIEMATCHPANEL_H
