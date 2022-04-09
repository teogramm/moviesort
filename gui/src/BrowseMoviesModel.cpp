
#include <QModelIndex>
#include "BrowseMoviesModel.h"

using MSGui::BrowseMoviesModel;
int BrowseMoviesModel::rowCount(const QModelIndex &parent) const {
    return movies.size();
}

int BrowseMoviesModel::columnCount(const QModelIndex &parent) const {
    return 2;
}

QVariant BrowseMoviesModel::data(const QModelIndex &index, int role) const {
    if(index.isValid()  && index.row() < movies.size() && index.column() < 2){
        if(role == Qt::DisplayRole){
            if(index.column() == 0){
                return {QString::fromStdString(movies.at(index.row()).getName())};
            }else {
                return {movies.at(index.row()).getElo()};
            }
        }
    }
    return {};
}

QVariant BrowseMoviesModel::headerData(int section, Qt::Orientation orientation, int role) const {
   if(role == Qt::DisplayRole && orientation == Qt::Horizontal && section < 2){
       if(section == 0){
           return {QStringLiteral("Name")};
       }else{
           return {QStringLiteral("Elo")};
       }
   }
   return QVariant();
}
