#include "MovieMatchPanel.h"
#include "ui_moviematch.h"

using namespace MSGui;
MovieMatch::MovieMatch(MovieSort::IMatch& backend, QWidget* parent) : QWidget(parent), ui(new Ui::MovieMatch),
                        backend(backend) {
    ui->setupUi(this);
    QPushButton::connect(ui->exitButton, &QPushButton::clicked, this, &MovieMatch::closeButtonPressed);
}

MovieMatch::~MovieMatch() {
    delete ui;
}
