#include "registration.h"
#include "ui_registration.h"
#include "QMessageBox"
#include "information.h"

registration::registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
}

registration::~registration()
{
    delete ui;
}

void registration::on_registration_2_clicked()
{
    QString jsonArray;

    QString login = ui->login->text();
    QString password = ui->password->text();
    QString password_two = ui->password_two->text();
    QString statuslog;
    if (ui->admin->isChecked()) statuslog = "admin";
    if (ui->user->isChecked()) statuslog = "user";
    if (password == password_two){
        jsonArray = "{\"status\":\"registration\",\"username\":\""+login+"\",\"password\":\""+password+"\",\"login\":\""+statuslog+"\"}";
        classSocket.sendToClient(socket, jsonArray);
        //QMessageBox::information(this, "Регистрация", "Регистрация прошла успешно");
    }
    else QMessageBox::warning(this, "Регистрация", "Вы неправильно повторили пароль. Попробуйте ещё раз.");
}

void registration::setSocket(QTcpSocket *_socket) {
    socket = _socket;
}

