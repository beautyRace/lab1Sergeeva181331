#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include "socket.h"

namespace Ui {
class registration;
}

class registration : public QDialog
{
    Q_OBJECT

public:
    Socket classSocket;
    explicit registration(QWidget *parent = nullptr);
    ~registration();

private slots:
    void on_registration_2_clicked();

public slots:
    void setSocket(QTcpSocket *_socket);

private:
    QTcpSocket* socket;
    QByteArray Block;
    quint16 _nextBlockSize;
    QByteArray Data;
    Ui::registration *ui;
};

#endif // REGISTRATION_H
