#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BrowseButton_clicked()
{
    ui->lineEdit->setText(
                QFileDialog::getExistingDirectory(this,
                                                  QString(),
                                                  QDir::homePath()));
}

void MainWindow::on_showInExplorerButton_clicked()
{
    const QString s {ui->lineEdit->text().replace('/','\\')},
    arg {QString("%1,%2").arg("/root",s)};
    explorer.start("C:/Windows/explorer",
                {"/e",arg});
}
