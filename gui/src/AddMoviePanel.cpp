#include "AddMoviePanel.h"
#include "ui_addmovie.h"
#include <QFileDialog>
#include <QtConcurrent/QtConcurrent>

MSGui::AddMoviePanel::AddMoviePanel(QWidget *parent): QWidget(parent), ui(new Ui::AddMovie) {
    ui->setupUi(this);
    // Progress bar is invisible until the user loads a file
    // Make it keep its size even if invisible
    QSizePolicy sp_retain = ui->progressBar->sizePolicy();
    sp_retain.setRetainSizeWhenHidden(true);
    ui->progressBar->setSizePolicy(sp_retain);
    ui->progressBar->setVisible(false);

    // Button connections
    QPushButton::connect(ui->cancelButton, &QPushButton::clicked,
                         this, &MSGui::AddMoviePanel::closeButtonPressed);
    QPushButton::connect(ui->browseButton, &QPushButton::clicked, this, &AddMoviePanel::addMoviesFromFile);
    QPushButton::connect(ui->addMovieButton, &QPushButton::clicked,this, [this](){
        auto movieName = ui->moveNameTextBox->text();
        if(!movieName.isEmpty()){
            emit wantToAddMovie(movieName);
        }
    });
}

MSGui::AddMoviePanel::~AddMoviePanel(){
    delete ui;
}

void MSGui::AddMoviePanel::addMoviesFromFile() {
    auto filePickDialog = QFileDialog(this);
    filePickDialog.setWindowTitle("Select a text file");
    filePickDialog.setOption(QFileDialog::ReadOnly);
    filePickDialog.setFileMode(QFileDialog::ExistingFile);
    filePickDialog.exec();
    if(!filePickDialog.selectedFiles().isEmpty()){
        // Disable the browse button while file is being loaded
        ui->browseButton->setEnabled(false);
        // Replace the white space next to the browse button with a progress bar
        ui->progressBar->setVisible(true);
        ui->progressBar->setEnabled(true);
        ui->progressBar->setMaximum(0);
        ui->progressBar->setMinimum(0);
        auto file = QFile(filePickDialog.selectedFiles().last());
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            //TODO: Handle error
            return;
        auto textStream = QTextStream(&file);
        while(!textStream.atEnd()){
            auto line = textStream.readLine();
            line.remove("\n");
            if(!line.isEmpty()) {
                emit wantToAddMovie(line);
            }
        }
        ui->progressBar->setVisible(false);
    }
}

void MSGui::AddMoviePanel::movieAddedResult(const QString&movieName, MSGui::AddMoviePanel::Result result) {
    auto logWidgetItem = new QTableWidgetItem();
    // Make the item not editable
    logWidgetItem->setFlags(logWidgetItem->flags()^Qt::ItemIsEditable);
    switch (result) {
        case Result::Success:
            logWidgetItem->setText(tr("%1 added successfully.").arg(movieName));
            logWidgetItem->setForeground(QBrush(Qt::white));
            logWidgetItem->setBackground(QBrush(Qt::darkGreen));
            break;
        case Result::MovieAlreadyExists:
            logWidgetItem->setText(tr("%1 already exists.").arg(movieName));
            logWidgetItem->setForeground(QBrush(Qt::white));
            logWidgetItem->setBackground(QBrush(Qt::darkYellow));
            break;
        case Result::Error:
            logWidgetItem->setText(tr("Error while adding %1.").arg(movieName));
            logWidgetItem->setForeground(QBrush(Qt::white));
            logWidgetItem->setBackground(QBrush(Qt::darkRed));
            break;
    }
    auto newRowIndex = ui->log->rowCount();
    ui->log->insertRow(newRowIndex);
    ui->log->setItem(newRowIndex, 0, logWidgetItem);
    ui->log->setCurrentCell(newRowIndex, 0);
}
