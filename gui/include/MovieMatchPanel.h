#ifndef MOVIESORT_MOVIEMATCHPANEL_H
#define MOVIESORT_MOVIEMATCHPANEL_H
#include <QWidget>
#include "MovieSort/IMatch.h"
#include "MovieSort/MatchResult.h"

namespace Ui{
    class MovieMatch;
}

namespace MSGui {
    class MovieMatchPanel : public QWidget{
    Q_OBJECT
    public:
        explicit MovieMatchPanel(MovieSort::IMatch &backend, QWidget *parent = nullptr);
        ~MovieMatchPanel() override;

    signals:
        /**
         * Called when the user wants to close this panel
         */
        void closeButtonPressed();
    private:
        Ui::MovieMatch *ui;
        MovieSort::IMatch &backend;
        QString movie1Name, movie2Name;
        void loadMatch();
        /**
         * Register match result between the two movies in movie1Name and movie2Name
         * @param result see MovieSort/MatchResult.h
         */
        void registerResult(int result);
    };
}

#endif //MOVIESORT_MOVIEMATCHPANEL_H
