#include "workerform.h"
#include "ui_workerform.h"
#include "myfunctions.h"
#include <string>
#include <QStringList>
#include "QStandardItemModel"
#include "QStandardItem"
#include "myfunctions.h"

using namespace std;

workerform::workerform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::workerform)
{
    ui->setupUi(this);

    as=myFunctions::getAssets();

    model = new QStandardItemModel;

    horizontalHeader.append("Name");
    horizontalHeader.append("Category");
    horizontalHeader.append("Income");
    horizontalHeader.append("Consumption");
    horizontalHeader.append("Profit");
    model->setHorizontalHeaderLabels(horizontalHeader);

    for (int i=0; i<as.size(); i++){
        item = new QStandardItem(QString::fromStdString(as[i].getName()));
        model->setItem(i, 0, item);
        item = new QStandardItem(QString::fromStdString(as[i].getCategory()));
        model->setItem(i, 1, item);
        item = new QStandardItem(QString::number(as[i].getIncome()));
        model->setItem(i, 2, item);
        item = new QStandardItem(QString::number(as[i].getConsumption()));
        model->setItem(i, 3, item);
        item = new QStandardItem(QString::number(as[i].getProfit()));
        model->setItem(i, 4, item);
    }
    ui->tableView->setModel(model);

    ui->tableView->resizeRowsToContents();

}

void workerform::on_sortName_clicked(){
    ui->tableView->sortByColumn(0, Qt::SortOrder::AscendingOrder);
}
void workerform::on_sortCategory_clicked(){
    ui->tableView->sortByColumn(1, Qt::SortOrder::AscendingOrder);
}
void workerform::on_find_clicked(){
    model->clear();
    model->setHorizontalHeaderLabels(horizontalHeader);
    int k=0;
    if(ui->lineEdit->text()== NULL){
        for (int i=0; i<as.size(); i++){
            item = new QStandardItem(QString::fromStdString(as[i].getName()));
            model->setItem(i, 0, item);
            item = new QStandardItem(QString::fromStdString(as[i].getCategory()));
            model->setItem(i, 1, item);
            item = new QStandardItem(QString::number(as[i].getIncome()));
            model->setItem(i, 2, item);
            item = new QStandardItem(QString::number(as[i].getConsumption()));
            model->setItem(i, 3, item);
            item = new QStandardItem(QString::number(as[i].getProfit()));
            model->setItem(i, 4, item);
        }
        ui->tableView->setModel(model);

        ui->tableView->resizeRowsToContents();
    }
    if(ui->lineEdit->text()== "realty"){
        for (int i=0; i<as.size(); i++){
            if (QString::fromStdString(as[i].getCategory())=="realty"){
                item = new QStandardItem(QString::fromStdString(as[i].getName()));
                model->setItem(k, 0, item);
                item = new QStandardItem(QString::fromStdString(as[i].getCategory()));
                model->setItem(k, 1, item);
                item = new QStandardItem(QString::number(as[i].getIncome()));
                model->setItem(k, 2, item);
                item = new QStandardItem(QString::number(as[i].getConsumption()));
                model->setItem(k, 3, item);
                item = new QStandardItem(QString::number(as[i].getProfit()));
                model->setItem(k, 4, item);
                k++;
            }
        }
        ui->tableView->setModel(model);

        ui->tableView->resizeRowsToContents();
    }
    if(ui->lineEdit->text()== "transport"){
        for (int i=0; i<as.size(); i++){
            if (QString::fromStdString(as[i].getCategory())=="transport"){
                item = new QStandardItem(QString::fromStdString(as[i].getName()));
                model->setItem(k, 0, item);
                item = new QStandardItem(QString::fromStdString(as[i].getCategory()));
                model->setItem(k, 1, item);
                item = new QStandardItem(QString::number(as[i].getIncome()));
                model->setItem(k, 2, item);
                item = new QStandardItem(QString::number(as[i].getConsumption()));
                model->setItem(k, 3, item);
                item = new QStandardItem(QString::number(as[i].getProfit()));
                model->setItem(k, 4, item);
                k++;
            }
        }
        ui->tableView->setModel(model);

        ui->tableView->resizeRowsToContents();
    }
    if(ui->lineEdit->text()== "finance"){
        for (int i=0; i<as.size(); i++){
            if (QString::fromStdString(as[i].getCategory())=="finance"){
                item = new QStandardItem(QString::fromStdString(as[i].getName()));
                model->setItem(k, 0, item);
                item = new QStandardItem(QString::fromStdString(as[i].getCategory()));
                model->setItem(k, 1, item);
                item = new QStandardItem(QString::number(as[i].getIncome()));
                model->setItem(k, 2, item);
                item = new QStandardItem(QString::number(as[i].getConsumption()));
                model->setItem(k, 3, item);
                item = new QStandardItem(QString::number(as[i].getProfit()));
                model->setItem(k, 4, item);
                k++;
            }
        }
        ui->tableView->setModel(model);

        ui->tableView->resizeRowsToContents();
    }
}

workerform::~workerform()
{
    delete ui;
}
