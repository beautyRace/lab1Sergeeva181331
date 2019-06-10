#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "information.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), _nextBlockSize(0),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    reg = new registration();
    inf = new Information(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(sockReady()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(sockDisc()));
    connect(this, SIGNAL(sendSocket(QTcpSocket*)), reg, SLOT(setSocket(QTcpSocket*)));
    connect(this, SIGNAL(sendSocketAndInf(QTcpSocket*, QString)), inf, SLOT(setSocketAndInf(QTcpSocket*, QString)));

    socket->connectToHost("127.0.0.1", 8080);

    //connect(ui->pushButton_2, SIGNAL(clicked()), reg, SLOT(show()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    log = ui->login->text();
    pass = ui->password->text();

    QString jsonArray;

        jsonArray = "{\"status\":\"username\",\"username\":\""+log+"\"}";
        classSocket.sendToClient(socket, jsonArray);
}

void MainWindow::sockDisc(){
    socket->deleteLater();
}

void MainWindow::sockReady(){
    QDataStream in(socket);

    while(true){
        if (_nextBlockSize == 0){
            if (socket->bytesAvailable() <static_cast<int>(sizeof(quint16))){
                break;
            }

            in >> _nextBlockSize;
        }

        if (socket->bytesAvailable() < _nextBlockSize){
            break;
        }
        QString str;
        in >> str;
        //qDebug() << str;
        QJsonDocument doc;
        doc = QJsonDocument::fromJson(str.toUtf8());
        QString status = doc.object().value("status").toString();
        if (status == "username"){
            QString username = doc.object().value("username").toString();
            statusUsername(username);
        }

        if (status == "password"){
            statusPassword(str);
        }
        if (status == "registration"){
            QString registration = doc.object().value("registration").toString();
            if(registration == "yes"){
                QMessageBox::information(this, "Регистрация", "Регистрация прошла успешно");
                reg->hide();
            }
        }

        _nextBlockSize = 0;
        }
    //}
}

void MainWindow::statusUsername(QString strU){
    if (strU == "yes"){
    QString jsonArray;

    jsonArray = "{\"status\":\"password\",\"password\":\""+pass+"\"}";
    classSocket.sendToClient(socket, jsonArray);
    }
    if (strU == "no") QMessageBox::warning(this, "Авторизация", "Пользователя с таким именем нет в системе.");
}

void MainWindow::statusPassword(QString strP){
    QJsonDocument doc;
    doc = QJsonDocument::fromJson(strP.toUtf8());
    QString password = doc.object().value("passwordst").toString();
    if (password == "yes"){
    QMessageBox::information(this, "Авторизация", "Авторизация прошла успешно.");
    emit sendSocketAndInf(socket, strP);
    this->hide();
    inf->show();
    }
    if (password == "no") QMessageBox::warning(this, "Авторизация", "Неверный пароль.");
}



void MainWindow::on_pushButton_2_clicked()
{
    reg->show();
    emit sendSocket(socket);
}

