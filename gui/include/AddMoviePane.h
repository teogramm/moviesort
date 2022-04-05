#ifndef MOVIESORT_ADDMOVIEPANE_H
#define MOVIESORT_ADDMOVIEPANE_H

#include <QWidget>

namespace Ui{
    class AddMovie;
};

namespace MSGui{
    class AddMovie: public QWidget{
        Q_OBJECT
    public:
        explicit AddMovie(QWidget* parent = nullptr);
        ~AddMovie() override;
    signals:
        void closeButtonPressed();
    private:
        Ui::AddMovie* ui;
    };
}

#endif //MOVIESORT_ADDMOVIEPANE_H
