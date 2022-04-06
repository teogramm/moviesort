#include "ui_mainmenu.h"
#include "MainMenu.h"
#include <QPushButton>

MSGui::MainMenu::MainMenu(QWidget *parent)
    : QWidget(parent), ui(new Ui::MainMenu) {
    ui->setupUi(this);
    populateMenu();

    // Stretch first column
    // Resize second column to contents
    auto headerView = ui->leaderboard->horizontalHeader();
    headerView->setSectionResizeMode(0, QHeaderView::Stretch);
    headerView->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->leaderboard->setSelectionBehavior(QAbstractItemView::SelectRows);

    emit wantTopMovies();
}

MSGui::MainMenu::~MainMenu() {
    delete ui;
}

void MSGui::MainMenu::populateMenu() {
    auto addMovieButton = new QPushButton("Add Movie", this);
    QPushButton::connect(addMovieButton, &QPushButton::clicked,
                         this, &MSGui::MainMenu::optionAddMoviePressed);
    ui->mainMenu->insertWidget(0,addMovieButton);

    auto quitButton = new QPushButton("Quit", this);
    QPushButton::connect(quitButton, &QPushButton::clicked, [](){
        QApplication::quit();
    });
    ui->mainMenu->insertWidget(1, quitButton);
}

void MSGui::MainMenu::setTopMovies(const std::vector<MovieSort::Movie> &newTopMovies) {
    this->topMovies = newTopMovies;
    populateTopMoviesTable();
}

void MSGui::MainMenu::populateTopMoviesTable() {
    // Delete everything
    ui->leaderboard->setRowCount(0);
    for(MovieSort::Movie& m: topMovies){
        auto movieLabel = new QTableWidgetItem(QString::fromStdString(m.getName()));
        movieLabel->setFlags(movieLabel->flags()^Qt::ItemIsEditable);
        auto movieElo = new QTableWidgetItem(QString::number(m.getElo()));
        movieElo->setFlags(movieElo->flags()^Qt::ItemIsEditable);
        auto newRowIndex = ui->leaderboard->rowCount();
        ui->leaderboard->insertRow(newRowIndex);
        ui->leaderboard->setItem(newRowIndex, 0, movieLabel);
        ui->leaderboard->setItem(newRowIndex, 1, movieElo);
    }
}
