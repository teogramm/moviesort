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
        enum class Result{
            Success,
            MovieAlreadyExists,
            Error
        };
    signals:
        void wantToAddMovie(const QString& movieName);
        void closeButtonPressed();
    private slots:
        void addMoviesFromFile();
    public slots:
        void movieAddedResult(const QString& movieName, Result result);
    private:
        bool fileLoadingInProgress = false;
        Ui::AddMovie* ui;
    };
}

#endif //MOVIESORT_ADDMOVIEPANE_H
