#include "ui_mainapp.h"
#include "MainApp.h"

MSGui::MainApp::MainApp(): QDialog(), ui(new Ui::MainApp) {
    ui->setupUi(this);
}

MSGui::MainApp::~MainApp() {
    delete ui;
}