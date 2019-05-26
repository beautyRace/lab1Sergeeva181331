#include "autorization.h"
#include "ui_autorization.h"
#include "myfunctions.h"
#include "user.h"
#include <QList>
#include <QMessageBox>
#include "workerform.h"

autorization::autorization(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::autorization)
{
    ui->setupUi(this);
}

void autorization::on_enterButton_clicked(){
    string login = ui->loginText->text().toStdString(); //считали с поля ввода
    string password = ui->passwordText->text().toStdString();
    int flag = 0;
    string current;
    QList<user> users = myFunctions::getUser();
    for (int i=0; i<users.size(); i++){
        if(users[i].getLogin()==login && users[i].getPassword()==password){
            if(users[i].getRights()=="admin"){
                flag=1;
                current=users[i].getFullName();
            }else{
                flag=2;
                current=users[i].getFullName();
            }
        }
    }
    if (flag==1){
        af = new adminForm();
        this->close();
        af->setWindowTitle(QString::fromStdString(current));
        af->show();
    }else{
        if (flag == 2){
            wf = new workerform();
            this->close();
            wf->setWindowTitle(QString::fromStdString(current));
            wf->show();
        }else{
            QMessageBox::about(this, "Ошибка", "Неверный логин или пароль");
            ui->passwordText->clear();
        }
    }
}

autorization::~autorization()
{
    delete ui;
}
