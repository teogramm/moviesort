#ifndef MOVIESORT_ADDMOVIEPANEL_H
#define MOVIESORT_ADDMOVIEPANEL_H

#include <QWidget>

namespace Ui{
    class AddMovie;
};

namespace MSGui{

    class AddMoviePanel: public QWidget{
        Q_OBJECT
    public:
        explicit AddMoviePanel(QWidget* parent = nullptr);
        ~AddMoviePanel() override;
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

#endif //MOVIESORT_ADDMOVIEPANEL_H
