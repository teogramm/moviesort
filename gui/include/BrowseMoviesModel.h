#ifndef MOVIESORT_BROWSEMOVIESMODEL_H
#define MOVIESORT_BROWSEMOVIESMODEL_H
#include <QAbstractTableModel>
#include <utility>
#include <MovieSort/Movie.h>

namespace MSGui {
    class BrowseMoviesModel : public QAbstractTableModel {
    Q_OBJECT
    public:
        explicit BrowseMoviesModel(std::vector<MovieSort::Movie> movies, QObject *parent = nullptr)
                : movies(std::move(movies)), QAbstractTableModel(parent) {}

        int rowCount(const QModelIndex &parent) const override;

        int columnCount(const QModelIndex &parent) const override;

        QVariant data(const QModelIndex &index, int role) const override;

        QVariant headerData(int section, Qt::Orientation orientation, int role) const override;;

    private:
        std::vector<MovieSort::Movie> movies;
    };
}
#endif //MOVIESORT_BROWSEMOVIESMODEL_H
