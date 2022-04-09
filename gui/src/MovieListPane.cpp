#include "MovieListPane.h"
#include "ui_browsemovies.h"
#include "MovieListModel.h"

MSGui::MovieBrowser::MovieBrowser(MovieSort::IMovieInfo &backend, QWidget *parent)
    : ui(new Ui::MovieBrowser), QWidget(parent){
    ui->setupUi(this);

    connect(ui->closeButton, &QPushButton::clicked, this, &MovieBrowser::closeButtonPressed);

    auto movies = backend.getAllMovies();
    auto model = new MovieListModel(movies, ui->movieTableView);
    ui->movieTableView->setModel(model);
}

MSGui::MovieBrowser::~MovieBrowser() {
    delete ui;
}
