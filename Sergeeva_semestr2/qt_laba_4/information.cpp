#include "information.h"
#include "ui_information.h"

Information::Information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Information)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
}

Information::~Information()
{
    delete ui;
}

void Information::setSocketAndInf(QTcpSocket *_socket, QString _str){
    socket = _socket;
    QJsonDocument doc;
    doc = QJsonDocument::fromJson(_str.toUtf8());
    QString id = doc.object().value("id").toString();
    QString username = doc.object().value("username").toString();
    QString pass = doc.object().value("password").toString();
    QString log = doc.object().value("login").toString();
    ui->id->setText(id);
    ui->username->setText(username);
    ui->pass->setText(pass);
    if (log == "admin") ui->log->setText("администратор");
    if (log == "user") ui->log->setText("пользователь");
}
