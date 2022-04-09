#include <QMessageBox>
#include "utils.h"

void MSGui::showError(const QString& errorMsg){
    auto msgBox = QMessageBox();
    msgBox.setText(errorMsg);
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setModal(true);
    msgBox.exec();
}