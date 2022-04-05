#include "ui_mainmenu.h"
#include "MainMenu.h"

MSGui::MainMenu::MainMenu(QWidget *parent)
    : QWidget(parent), ui(new Ui::MainMenu) {
    ui->setupUi(this);
}

MSGui::MainMenu::~MainMenu() {
    delete ui;
}
