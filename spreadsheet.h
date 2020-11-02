#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <QTableWidget>

QT_BEGIN_NAMESPACE
class Cell;
QT_END_NAMESPACE

class Spreadsheet : public QTableWidget
{
    Q_OBJECT

public:
    Spreadsheet(QWidget *parent = 0);
    void columnHeaders();
    void rowHeaders();


public slots:

    void selectCurrentRow();
    void selectCurrentColumn();
    void del();

};

#endif // SPREADSHEET_H
