#include "server.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QDataStream>
Server::Server(): _nextBlockSize(0){}

Server::~Server(){}

void Server::startServer(){

    if(this->listen(QHostAddress::Any, 8080)) qDebug() << "Listen";
    else qDebug() << "Not listen";
}

void Server::incomingConnection(qintptr socketDescriptor){
    socket = new QTcpSocket(this);
    //socket = server->nextPendingConnection();

    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, SIGNAL(readyRead()), this, SLOT(sockRedy()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(sockDisc()));

    qDebug() << socketDescriptor << " connected";

    sendToClient(socket, "Connect");
}

void Server::sockDisc(){
    qDebug() << "Disconnect";
    socket->deleteLater();
}

void Server::sockRedy(){
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
        qDebug() << "TAKE " << str;

        doc = QJsonDocument::fromJson(str.toUtf8());

        QString status = doc.object().value("status").toString();

        if (status == "registration"){
            db.newTableAuthorization();
            QString message = db.newDataAuthorithation(str);
            sendToClient(socket, message);
        }

        if (status == "username" || status == "password"){
            QString message = db.checkDataAuthorithation(status, doc.object().value(status).toString());
            sendToClient(socket, message);
        }

        _nextBlockSize = 0;
    }
}

void Server::sendToClient(QTcpSocket* socket, const QString &str){
    qDebug() << "SEND " << str;
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);

    out << quint16(0) << str;
    out.device()->seek(0); //переход в начало
    out << quint16(arrBlock.size() - static_cast<int>(sizeof(quint16))); //вычесляем размер записанной строки и пишем на место пустых битов

    socket->write(arrBlock);
}
