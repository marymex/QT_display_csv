#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "readwrite.h"
#include <QMessageBox>

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




void MainWindow::on_actionOpen_2_triggered()
{
    inputFile = QFileDialog::getOpenFileName(this, "Choose file format .csv", QDir::currentPath());
    ui->lineEdit->setText("input file loaded");
    QApplication::processEvents();

    try
    {
     loadCSV(inputFile, _data, _headers);
    }
    catch (const std::runtime_error& e)
    {
       QMessageBox::warning(this, "Error", "Could not open file");
    }

    ui->lineEdit->setText("data read");
    QApplication::processEvents();
    //ui->textEdit->setText(QString::fromStdString(std::to_string(_data.size())));
    model = new table_model(_data, _headers, nullptr);
    ui->tableView->setModel(model);
    ui->lineEdit->setText("data displayed");
    QApplication::processEvents();
}



void MainWindow::on_actionSave_2_triggered()
{
    QString outputFile = QFileDialog::getSaveFileName(this, "Choose file format .csv", QDir::currentPath());
    ui->lineEdit->setText("output file loaded");
    QApplication::processEvents();

    try
    {
        saveTableToFile(outputFile, _data, _headers);
    }
    catch (const std::runtime_error& e)
    {
        QMessageBox::warning(this, "Error", "Could not save file");
    }

    ui->lineEdit->setText("data saved");
    QApplication::processEvents();
}

