#include "MovieMatchPanel.h"
#include "ui_moviematch.h"

using namespace MSGui;
MovieMatchPanel::MovieMatchPanel(IMatch& backend, QWidget* parent) : QWidget(parent), ui(new Ui::MovieMatch),
                                                                                backend(backend) {
    ui->setupUi(this);
    QPushButton::connect(ui->exitButton, &QPushButton::clicked, this, &MovieMatchPanel::closeButtonPressed);
    QPushButton::connect(ui->skipButton, &QPushButton::clicked, this, &MovieMatchPanel::loadMatch);
    QPushButton::connect(ui->movie1Button, &QPushButton::clicked, this, [this](){
        registerResult(MovieSort::RESULT_FIRST_MOVIE_WIN);
    });
    QPushButton::connect(ui->movie2Button, &QPushButton::clicked, this, [this](){
        registerResult(MovieSort::RESULT_SECOND_MOVIE_WIN);
    });
    QPushButton::connect(ui->drawButton, &QPushButton::clicked, this, [this](){
        registerResult(MovieSort::RESULT_DRAW);
    });
    loadMatch();
}

void MovieMatchPanel::loadMatch() {
    auto movies = backend.generateMatch();
    movie1Name = QString::fromStdString(movies.first.getName());
    movie2Name = QString::fromStdString(movies.second.getName());
    ui->movie1Button->setText(movie1Name);
    ui->movie2Button->setText(movie2Name);
}

void MovieMatchPanel::registerResult(int result){
    backend.writeMatchResult(movie1Name, movie2Name, result);
    loadMatch();
}

MovieMatchPanel::~MovieMatchPanel() {
    delete ui;
}
