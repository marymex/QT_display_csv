#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "table_model.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_actionOpen_2_triggered();

    void on_actionSave_2_triggered();

private:
    Ui::MainWindow *ui;
    QString inputFile;
    QList<QList<QString> >  _data;
    QList<QString>   _headers;
    table_model* model;
};
#endif // MAINWINDOW_H
