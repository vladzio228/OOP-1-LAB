#include <QtWidgets>

#include "spreadsheet.h"
#include "cell.h"

Spreadsheet::Spreadsheet(QWidget *parent)
    : QTableWidget(parent)
{
     setSelectionMode(ContiguousSelection);

  setRowCount(0);
  setColumnCount(0);
  setRowCount(10);
  setColumnCount(10);

  columnHeaders();
  rowHeaders();

  setCurrentCell(0, 0);
}

void Spreadsheet::columnHeaders()
{
    QTableWidgetItem *letter = new QTableWidgetItem(QString(QChar('A')));
    setHorizontalHeaderItem(0,letter);

    for(int i=1;i<columnCount();++i){
        QString temp = horizontalHeaderItem(i-1)->text();
        int amountOfZ=0;
        for(int k=0;k<temp.size();++k){
            if(temp[k]==QChar('Z')){
                amountOfZ+=1;
            }
        }
        for(int j=temp.size()-1;j>=0;--j){

           if(temp[j]!=QChar('Z')){
               temp[j]=QChar(temp[j].unicode()+1);
               QTableWidgetItem *mem = new QTableWidgetItem(temp);
               setHorizontalHeaderItem(i,mem);
               break;
            }
           else if(temp.size()==amountOfZ){
               QString temp2=temp;
               for(int k=0;k<temp2.size();++k){
                   temp2[k]=QChar('A');
               }

               temp=QString(QChar('A'))+temp2;
               QTableWidgetItem *mem = new QTableWidgetItem(temp);
               setHorizontalHeaderItem(i,mem);
               break;
            }
           else{
                temp[j]=QChar('A');
                temp[j-1]=QChar(temp[j-1].unicode()+1);
                QTableWidgetItem *mem = new QTableWidgetItem(temp);
                setHorizontalHeaderItem(i,mem);
                break;
            }
        }
    }
}

void Spreadsheet::rowHeaders()
{
    for(int i=0;i<rowCount();++i){
        QTableWidgetItem *letter =new QTableWidgetItem(QString(QString::number(i+1)));
        setVerticalHeaderItem(i,letter);
    }
}

void Spreadsheet::selectCurrentRow()
{
    selectRow(currentRow());
}

void Spreadsheet::selectCurrentColumn()
{
    selectColumn(currentColumn());
}

void Spreadsheet::del(){
    QList<QTableWidgetItem *> items = selectedItems();
    if (!items.isEmpty()) {
        foreach (QTableWidgetItem *item, items)
            delete item;
    }
}


