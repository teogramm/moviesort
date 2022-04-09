#ifndef MOVIESORT_MOVIELISTMODEL_H
#define MOVIESORT_MOVIELISTMODEL_H
#include <QAbstractTableModel>
#include <utility>
#include <MovieSort/Movie.h>

namespace MSGui {
    class MovieListModel : public QAbstractTableModel {
    Q_OBJECT
    public:
        explicit MovieListModel(std::vector<MovieSort::Movie> movies, QObject *parent = nullptr)
                : movies(std::move(movies)), QAbstractTableModel(parent) {}

        int rowCount(const QModelIndex &parent) const override;

        int columnCount(const QModelIndex &parent) const override;

        QVariant data(const QModelIndex &index, int role) const override;

        QVariant headerData(int section, Qt::Orientation orientation, int role) const override;;

    private:
        std::vector<MovieSort::Movie> movies;
    };
}
#endif //MOVIESORT_MOVIELISTMODEL_H
