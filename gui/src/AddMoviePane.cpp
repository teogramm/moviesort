#include "AddMoviePane.h"
#include "ui_addmovie.h"

MSGui::AddMovie::AddMovie(QWidget *parent): QWidget(parent), ui(new Ui::AddMovie) {
    ui->setupUi(this);
    QPushButton::connect(ui->cancelButton, &QPushButton::clicked,
                         this, &MSGui::AddMovie::closeButtonPressed);
}

MSGui::AddMovie::~AddMovie(){
    delete ui;
}