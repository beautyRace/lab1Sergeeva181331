#ifndef SEVER_H
#define SEVER_H
#include <QWidget>
#include <QTcpSocket>

class QTcpServer;
class QTcpSocket;
class QTextEdit;

class Server: public QWidget{
Q_OBJECT

private:

    QString xo[3][3];

void setArray(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            xo[i][j] = " - ";
        }
    }
}

QTcpServer *_tcpServer;
QTcpSocket *_clientSocket1;
quint16 _nextBlockSize;
QTextEdit *_text;

QMap<qintptr,QTcpSocket *> Clients;
QMap<qintptr, int> Check;

int nk = 0;
int num1;
int num2;
bool flag;
bool flag1;

void sendToClient(QTcpSocket *socket, const QString &str);
void print(qintptr numSoket, QString str, QString winner, QString finish);
//void check(QString symbol);

public:

Server(quint16 port);

public slots:

virtual void slotNewConnection();
void slotReadClient();

};

#endif // SEVER_H
