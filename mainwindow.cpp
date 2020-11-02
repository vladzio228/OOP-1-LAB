#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "spreadsheet.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowState(Qt::WindowMaximized);
    setWindowIcon(QIcon(":/icons/icon/mainIcon.ico"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAboutQt_triggered()
{
   QApplication::aboutQt();
}

void MainWindow::on_actionExit_triggered()
{
   QApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("Про Excel_PoweredByMemes"),
            tr("<h2>Версія 1.0</h2>"
               "<p>Лабораторна робота №1 Петріва Владислава з групи К-24, "
               "реалізована в Qt Framework. "
               "<p>Варіант 19, реалізовано операцї: "
               "<p>3)унарні операції (+,-);"
               "<p>4)піднесення у степінь (^);"
               "<p>6)max(x,y), mіn(x,y);;"
               "<p>7)mmax(x1,x2,...,xN), mmіn(x1,x2,...,xN):(N>=1);"
               ""));
}

void MainWindow::on_actionAddRow_triggered()
{
     ui->tableWidget->insertRow(ui->tableWidget->rowCount());
     ui->tableWidget->rowHeaders();
}

void MainWindow::on_actionAddColumn_triggered()
{
     ui->tableWidget->insertColumn(ui->tableWidget->columnCount());
     ui->tableWidget->columnHeaders();
}

void MainWindow::on_actionRemoveRow_triggered()
{
     ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1);
     ui->tableWidget->rowHeaders();
}

void MainWindow::on_actionRemoveColumn_triggered()
{
     ui->tableWidget->removeColumn(ui->tableWidget->columnCount()-1);
     ui->tableWidget->columnHeaders();
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    ui->lineEdit->setText(QString(QString(ui->tableWidget->horizontalHeaderItem(column)->text())+QString::number(row+1)));
}

void MainWindow::on_actionDelete_triggered()
{
    ui->tableWidget->del();
}

void MainWindow::on_actionRow_triggered()
{
    ui->tableWidget->selectCurrentRow();
}

void MainWindow::on_actionColumn_triggered()
{
    ui->tableWidget->selectCurrentColumn();
}

void MainWindow::on_actionAll_triggered()
{
    ui->tableWidget->selectAll();
}

