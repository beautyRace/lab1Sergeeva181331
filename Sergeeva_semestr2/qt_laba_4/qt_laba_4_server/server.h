#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include "database.h"
#include <QJsonDocument>
#include <QJsonObject>


class Server: public QTcpServer
{
    Q_OBJECT
private:
    QTcpServer* server;
    QTcpSocket* socket;
    quint16 _nextBlockSize;
    DataBase db;
    QJsonDocument doc;

public slots:
    void startServer();
    void incomingConnection(qintptr socketDescriptor);
    void sockRedy();
    void sockDisc();

public:

    void sendToClient(QTcpSocket* socket, const QString &str);
    //QMap<qintptr, QTcpSocket *> Clients;
    Server();
    ~Server();
};

#endif // SERVER_H
