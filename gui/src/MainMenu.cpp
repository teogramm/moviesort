#include "ui_mainmenu.h"
#include "MainMenu.h"
#include <QPushButton>

MSGui::MainMenu::MainMenu(QWidget *parent)
    : QWidget(parent), ui(new Ui::MainMenu) {
    ui->setupUi(this);
    populateMenu();
}

MSGui::MainMenu::~MainMenu() {
    delete ui;
}

void MSGui::MainMenu::populateMenu() {
    auto addMovieButton = new QPushButton("Add Movie");
    QPushButton::connect(addMovieButton, &QPushButton::clicked,
                         this, &MSGui::MainMenu::optionAddMoviePressed);
    ui->mainMenu->insertWidget(0,addMovieButton);
}
