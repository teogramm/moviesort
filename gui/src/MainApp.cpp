#include "ui_mainapp.h"
#include "MainApp.h"
#include "AddMoviePane.h"

MSGui::MainApp::MainApp(): QDialog(), ui(new Ui::MainApp) {
    ui->setupUi(this);
    auto mm = new MainMenu(ui->stackedWidget);
    mainMenu = mm;
    QObject::connect(mainMenu, &MSGui::MainMenu::optionAddMoviePressed,
                     this, &MSGui::MainApp::openAddMoviePanel);
    ui->stackedWidget->addWidget(mainMenu);
}

MSGui::MainApp::~MainApp() {
    delete ui;
    delete mainMenu;
}

void MSGui::MainApp::openAddMoviePanel() {
    auto addMoviePane = new AddMovie(ui->stackedWidget);
    QObject::connect(addMoviePane, &AddMovie::closeButtonPressed, this, &MainApp::closePanel);
    ui->stackedWidget->addWidget(addMoviePane);
    ui->stackedWidget->setCurrentWidget(addMoviePane);
}

void MSGui::MainApp::closePanel() {
    auto currWidget = ui->stackedWidget->currentWidget();
    delete currWidget;
}
