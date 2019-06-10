#ifndef SOCKET_H
#define SOCKET_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>

class Socket: public QTcpSocket
{
    Q_OBJECT
public:
    Socket();
    void sendToClient(QTcpSocket* socket, const QString &str);

private:
    QTcpSocket* socket;

public slots:

signals:
    //void setSocket(QTcpSocket * socket);
};

#endif // SOCKET_H
