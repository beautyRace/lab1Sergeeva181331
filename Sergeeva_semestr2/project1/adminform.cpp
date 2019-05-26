#include "adminform.h"
#include "ui_adminform.h"
#include "myfunctions.h"
#include <QList>
#include <QMessageBox>

adminForm::adminForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminForm)
{
    ui->setupUi(this);
    us=myFunctions::getUser();

    model = new QStandardItemModel;

    horizontalHeader.append("Login");
    horizontalHeader.append("Password");
    horizontalHeader.append("Full name");
    horizontalHeader.append("Year of birth");
    horizontalHeader.append("Rights");
    model->setHorizontalHeaderLabels(horizontalHeader);

    for (int i=0; i<us.size(); i++){
        item = new QStandardItem(QString::fromStdString(us[i].getLogin()));
        model->setItem(i, 0, item);
        item = new QStandardItem(QString::fromStdString(us[i].getPassword()));
        model->setItem(i, 1, item);
        item = new QStandardItem(QString::fromStdString(us[i].getFullName()));
        model->setItem(i, 2, item);
        item = new QStandardItem(QString::number(us[i].getYearOfBirth()));
        model->setItem(i, 3, item);
        item = new QStandardItem(QString::fromStdString(us[i].getRights()));
        model->setItem(i, 4, item);
    }
    ui->tableWorkers->setModel(model);

    ui->tableWorkers->resizeRowsToContents();


    as=myFunctions::getAssets();

    model2 = new QStandardItemModel;

    horizontalHeader2.append("Name");
    horizontalHeader2.append("Category");
    horizontalHeader2.append("Income");
    horizontalHeader2.append("Consumption");
    horizontalHeader2.append("Profit");
    model2->setHorizontalHeaderLabels(horizontalHeader2);

    for (int i=0; i<as.size(); i++){
        item = new QStandardItem(QString::fromStdString(as[i].getName()));
        model2->setItem(i, 0, item);
        item = new QStandardItem(QString::fromStdString(as[i].getCategory()));
        model2->setItem(i, 1, item);
        item = new QStandardItem(QString::number(as[i].getIncome()));
        model2->setItem(i, 2, item);
        item = new QStandardItem(QString::number(as[i].getConsumption()));
        model2->setItem(i, 3, item);
        item = new QStandardItem(QString::number(as[i].getProfit()));
        model2->setItem(i, 4, item);
    }
    ui->tableAssets->setModel(model2);

    ui->tableAssets->resizeRowsToContents();
}

void adminForm::on_add_clicked(){
    model->insertRow(model->rowCount());
}

void adminForm::on_safe_clicked(){
    QList <user> newUs;
    string login;
    string password;
    string fullName;
    string rights;
    int yearOfBirth;
    int count = model->rowCount();
    for (int i=0; i<count; i++){
        login = model->item(i,0)->text().toUtf8().constData();
        password = model->item(i,1)->text().toUtf8().constData();
        fullName = model->item(i,2)->text().toUtf8().constData();
        yearOfBirth = model->item(i,3)->text().toInt();
        rights = model->item(i,4)->text().toUtf8().constData();
        newUs.push_back(user(login,password,fullName,yearOfBirth,rights));
    }
    myFunctions::setUser(newUs);
    QMessageBox::about(this, "Ура!", "Изменения успешно сохранены!");
}
void adminForm::on_check_clicked(){
    double sum=0;
    for (int i=0; i<as.size(); i++){
        sum+=as[i].getProfit();
    }
    QMessageBox::about(this, "Прибыль", "Общая прибыль = "+QString::number(sum)+" руб.");
}

adminForm::~adminForm()
{
    delete ui;
}
