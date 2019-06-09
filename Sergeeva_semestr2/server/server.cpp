#include "server.h"

#include <QTcpServer>
#include <QTcpSocket>

#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>

#include <QDataStream>
#include <QTime>
#include <QDebug>

#include <QTableWidget>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

Server::Server(quint16 port): _nextBlockSize(0){
    _tcpServer = new QTcpServer(this);

    if (!_tcpServer->listen(QHostAddress::Any, port)){
        _tcpServer->close();
        return;
    }

    connect(_tcpServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));

    _text = new QTextEdit();
    _text->setReadOnly(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(new QLabel("<H1>Server</H1>"));
    layout->addWidget(_text);
    setLayout(layout);
    setWindowTitle("Server");
    setArray();
}

void Server::slotNewConnection(){

    _clientSocket1 = _tcpServer->nextPendingConnection();
    qintptr number = _clientSocket1->socketDescriptor();
    Clients[number]=_clientSocket1;

    connect(Clients[number], SIGNAL(disconnected()), Clients[number], SLOT(deleteLater()));
    connect(Clients[number], SIGNAL(readyRead()), this, SLOT(slotReadClient()));

    sendToClient(Clients[number], "Как играть:\r\nЧтобы сделать ход, введите координату по горизонтали, а затем, через пробел, по вертикали.\r\nЧтобы начать игра, просто сделайте ход.");
}

void Server::slotReadClient(){

    qintptr key = 0;

    flag = true;
    flag1 = true;
    bool correct = true;

    QString winner = "";
    QString messForCurrentClient = "";
    QString finish = "";

    QString symbol;
    nk++;
    int a = 0;

    foreach(qintptr i, Clients.keys()){
        a++;
        QDataStream in(Clients[i]);
        //in.setVersion(QDataStream::Qt_5_10);

        while(true){

            if (_nextBlockSize == 0){
                if (Clients[i]->bytesAvailable() <static_cast<int>(sizeof(quint16))){
                    break;
                }

                in >> _nextBlockSize;
            }

            if (Clients[i]->bytesAvailable() < _nextBlockSize){
                break;
            }

                if(nk == 1) foreach(qintptr k, Clients.keys()){
                    Check[i] = nk;
                    if(k != i) Check[k] = 2;
                }


            if(nk % 2 == 1){
                symbol = " x ";
            }
            else symbol = " o ";

            QTime time;
            QString str;
            in >> time >> str;
            correct = false;
            for(int j = 1; j < 4; j++){
                for(int m = 1; m < 4; m++){
                    if(str == QString::number(j) + ' ' + QString::number(m)) correct = true;
                }
            }
            if(correct == false){
                nk = nk - 1;
                break;
            }

            string textInput = str.toUtf8().constData();

            istringstream text(textInput);
            string n;
            string a, b;
            int k = 0;
            while(getline(text, n, ' ')){
                if(k == 0) a = n;
                if(k == 1) b = n;
                k++;
            }

            key = i;
            QString _a = QString::fromLocal8Bit(a.c_str());
            QString _b = QString::fromLocal8Bit(b.c_str());

            int num1 = stoi(a)-1;
            int num2 = stoi(b)-1;
            if((Check[i] % 2) != (nk % 2)){

                messForCurrentClient ="\r\nВы уже сделали свой ход!";
                nk = nk - 1;
                break;
            }
            if(xo[num1][num2] == " - ") xo[num1][num2] = symbol;
            else {
                messForCurrentClient = messForCurrentClient + "\r\nЭто поле уже заполнено. Попробуйте сделать другой ход.";
                nk = nk - 1;
            }

            _text -> clear();
            QString message = "Game is started!";
            _text->append(message);

            for(int i = 0; i < 3; i++){
                QString message = xo[i][0] + xo[i][1] + xo[i][2];
                _text->append(message);
            }

            if(xo[num1][num2 % 3] == symbol && xo[num1][(num2 + 1) % 3] == symbol && xo[num1][(num2 + 2) % 3] == symbol){
                flag = false;
            }

            else if(xo[num1 % 3][num2] == symbol && xo[(num1 + 1) % 3][num2] == symbol && xo[(num1 + 2) % 3][num2] == symbol){
                flag = false;
            }

            else if(xo[0][0] == symbol && xo[1][1] == symbol && xo[2][2] == symbol){
                flag = false;
            }
            else if(xo[0][2] == symbol && xo[1][1] == symbol && xo[2][0] == symbol){
                flag = false;
            }

            else if(xo[0][0] != " - " && xo[0][1] != " - " && xo[0][2] != " - " && xo[1][0] != " - " && xo[1][1] != " - "
                    && xo[1][2] != " - " && xo[2][0] != " - " && xo[2][1] != " - " && xo[2][2] != " - "){
                flag1 = false;
            }

            if(flag == false){
                QString message = "\r\nGame is finished!";
                _text->append(message);
                winner = "\r\n\r\nВы выиграли!";
            }

        } if(correct == true){
            if(a == 2 && (flag == false || flag1 == false)) finish = "\r\n\r\nИгра окончена! Чтобы начать новую игру, введите координаты.";
        if(a == 2) print(key, messForCurrentClient, winner, finish);
        }

        if(a == 2 && (flag == false || flag1 == false)){
            nk = 0;
            setArray();
        }
        _nextBlockSize = 0;
    }
}


void Server::sendToClient(QTcpSocket* socket, const QString &str){
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    //out.setVersion(QDataStream::Qt_5_10);

    out << quint16(0) << QTime::currentTime() << str;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - static_cast<int>(sizeof(quint16)));

    socket->write(arrBlock);
}

void Server::print(qintptr numSoket, QString str, QString winner, QString finish){
    QString loss = "";
    foreach(qintptr j, Clients.keys()){
        if(winner == "\r\n\r\nВы выиграли!") loss = "\r\n\r\nК сожалению, вы проиграли.";
        if(numSoket == j) sendToClient(Clients[j], "Игра началась!\r\n" + (xo[0][0] + xo[0][1] + xo[0][2] + "\r\n" + xo[1][0] + xo[1][1] + xo[1][2] + "\r\n" + xo[2][0] + xo[2][1] + xo[2][2]) + str + winner + finish);
        if(numSoket != j) sendToClient(Clients[j], "Игра началась!\r\n" + (xo[0][0] + xo[0][1] + xo[0][2] + "\r\n" + xo[1][0] + xo[1][1] + xo[1][2] + "\r\n" + xo[2][0] + xo[2][1] + xo[2][2]) + loss + finish);
    }
}

