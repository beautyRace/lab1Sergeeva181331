#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include "registration.h"
#include <QMessageBox>
#include "information.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Socket classSocket;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();
    void sockReady();
    void sockDisc();

    void on_pushButton_2_clicked();

private:
    QTcpSocket* socket;
    QByteArray Block;
    quint16 _nextBlockSize;
    Ui::MainWindow *ui;
    QByteArray Data;
    QString log;
    QString pass;
    Information *inf;
    registration *reg;
    void statusUsername(QString strU);
    void statusPassword(QString strP);

signals:
    void sendSocket(QTcpSocket *);
    void sendSocketAndInf(QTcpSocket*, QString);
};

#endif // MAINWINDOW_H
