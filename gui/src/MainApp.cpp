#include "ui_mainapp.h"
#include "MainApp.h"
#include "AddMoviePanel.h"
#include "MovieMatchPanel.h"
#include "MovieSort/Exceptions.h"
#include "BrowseMoviesPanel.h"
#include "utils.h"

MSGui::MainApp::MainApp(): QDialog(), ui(new Ui::MainApp){
    // Initialize backend
    // TODO: Database location on ~/.config or as a parameter.
    auto backendPtr = std::make_unique<MovieSort::Backend>("movies.db");
    backend = new BackendAdapter(backendPtr);
    ui->setupUi(this);
    auto mm = new MainMenu(ui->stackedWidget);
    mainMenu = mm;
    mainMenu->setTopMovies(backend->getTopKMovies(10));
    connectMainMenu();
    ui->stackedWidget->addWidget(mainMenu);
}

void MSGui::MainApp::connectMainMenu(){
    QObject::connect(mainMenu, &MSGui::MainMenu::optionAddMoviePressed,
                     this, &MSGui::MainApp::openAddMoviePanel);
    QObject::connect(mainMenu, &MainMenu::optionStartMatchPressed, this, &MainApp::openMovieMatchPanel);
    QObject::connect(mainMenu, &MainMenu::optionSeeMoviesPressed, this, &MainApp::openMovieListPanel);
}

MSGui::MainApp::~MainApp() {
    delete ui;
    delete mainMenu;
    delete backend;
}

void MSGui::MainApp::openAddMoviePanel() {
    auto addMoviePane = new AddMoviePanel(*backend, ui->stackedWidget);
    QObject::connect(addMoviePane, &AddMoviePanel::closeButtonPressed, this, &MainApp::closePanel);
    ui->stackedWidget->addWidget(addMoviePane);
    ui->stackedWidget->setCurrentWidget(addMoviePane);
}

void MSGui::MainApp::openMovieMatchPanel() {
    if(backend->getMovieCount() > 2) {
        auto movieMatchPanel = new MovieMatchPanel(*backend, ui->stackedWidget);
        QObject::connect(movieMatchPanel, &MovieMatchPanel::closeButtonPressed, this, &MainApp::closePanel);
        ui->stackedWidget->addWidget(movieMatchPanel);
        ui->stackedWidget->setCurrentWidget(movieMatchPanel);
    }else{
        MSGui::showError("To start a match add at least 2 movies to the database.");
    }
}

void MSGui::MainApp::openMovieListPanel() {
    auto movieListPanel = new BrowseMoviesPanel(*backend, ui->stackedWidget);
    connect(movieListPanel, &BrowseMoviesPanel::closeButtonPressed, this, &MainApp::closePanel);
    ui->stackedWidget->addWidget(movieListPanel);
    ui->stackedWidget->setCurrentWidget(movieListPanel);
}

void MSGui::MainApp::closePanel() {
    auto currWidget = ui->stackedWidget->currentWidget();
    mainMenu->setTopMovies(backend->getTopKMovies(10));
    delete currWidget;
}