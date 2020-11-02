#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include "spreadsheet.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_actionRow_triggered();
    void on_actionColumn_triggered();
    void on_actionAll_triggered();
    void on_actionDelete_triggered();

    void on_actionAddColumn_triggered();
    void on_actionRemoveColumn_triggered();
    void on_actionAddRow_triggered();
    void on_actionRemoveRow_triggered();

    void on_actionAbout_triggered();
    void on_actionAboutQt_triggered();

    void on_actionExit_triggered();

    void on_tableWidget_cellClicked(int row, int column);



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
