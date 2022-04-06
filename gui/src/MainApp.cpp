#include "ui_mainapp.h"
#include "MainApp.h"
#include "AddMoviePane.h"
#include "MovieSort/Exceptions.h"

MSGui::MainApp::MainApp(): QDialog(), ui(new Ui::MainApp), backend(new MovieSort::Backend("movies.db")){
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
    delete backend;
}

void MSGui::MainApp::openAddMoviePanel() {
    auto addMoviePane = new AddMovie(ui->stackedWidget);
    QObject::connect(addMoviePane, &AddMovie::closeButtonPressed, this, &MainApp::closePanel);
    QObject::connect(addMoviePane, &AddMovie::wantToAddMovie, this, &MainApp::addMovie);
    QObject::connect(this, &MainApp::movieAdded, addMoviePane, &AddMovie::movieAddedResult);
    ui->stackedWidget->addWidget(addMoviePane);
    ui->stackedWidget->setCurrentWidget(addMoviePane);
}

void MSGui::MainApp::closePanel() {
    auto currWidget = ui->stackedWidget->currentWidget();
    delete currWidget;
}

void MSGui::MainApp::addMovie(const QString &movieName) {
    try{
        backend->addMovie(movieName.toStdString());
        emit movieAdded(movieName, AddMovie::Result::Success);
    } catch (MovieSort::MovieAlreadyExists& e) {
        emit movieAdded(movieName, AddMovie::Result::MovieAlreadyExists);
    } catch (std::exception &e){
        emit movieAdded(movieName, AddMovie::Result::Error);
    }
}
