#include "BrowseMoviesPanel.h"
#include "ui_browsemovies.h"
#include "BrowseMoviesModel.h"

MSGui::BrowseMoviesPanel::BrowseMoviesPanel(MSGui::IMovieInfo &backend, QWidget *parent)
    : ui(new Ui::MovieBrowser), QWidget(parent){
    ui->setupUi(this);

    connect(ui->closeButton, &QPushButton::clicked, this, &BrowseMoviesPanel::closeButtonPressed);

    auto movies = backend.getAllMovies();
    auto model = new BrowseMoviesModel(movies, ui->movieTableView);
    ui->movieTableView->setModel(model);
}

MSGui::BrowseMoviesPanel::~BrowseMoviesPanel() {
    delete ui;
}
