#include "client.h"

#include <QTcpSocket>

#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QTime>

using namespace std;

Client::Client(const QString &strHost, QString name, quint16 port): _nextBlockSize(0){
    _tcpSocket = new QTcpSocket(this);
    _tcpSocket->connectToHost(strHost, port);

    connect(_tcpSocket, SIGNAL(connected()), this, SLOT(slotConnected()));
    connect(_tcpSocket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));

    _textInfo = new QTextEdit();
    _textInput = new QLineEdit();
    _textInput->setMaxLength(3);

    _textInfo->setReadOnly(true);
    QPushButton *button = new QPushButton("Send");

    connect(button, SIGNAL(clicked()), SLOT(slotSendToServer()));
    connect(_textInput, SIGNAL(returnPressed()), this, SLOT(slotSendToServer()));

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(new QLabel("<H1>"+ name +"</H1>"));
    layout->addWidget(_textInfo);
    layout->addWidget(_textInput);
    layout->addWidget(button);
    setLayout(layout);
    setWindowTitle("Client");
}

void Client::slotReadyRead(){
    QDataStream in(_tcpSocket);
    //in.setVersion(QDataStream::Qt_5_10);

    while(true){
        if (_nextBlockSize == 0){
            if (_tcpSocket->bytesAvailable() <static_cast<int>(sizeof(quint16))){
                break;
            }

            in >> _nextBlockSize;
        }

        if (_tcpSocket->bytesAvailable() < _nextBlockSize){
            break;
        }

        QTime time;
        QString str;
        in >> time >> str;
        //_textInfo->append(time.toString() + " " + str);
        _textInfo->clear();
        _textInfo->append(str);

        _nextBlockSize = 0;
    }
}

void Client::slotSendToServer(){
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    //out.setVersion(QDataStream::Qt_5_10);

    out << quint16(0) << QTime::currentTime() << _textInput->text();
    out.device()->seek(0);
    out<< quint16(arrBlock.size() - static_cast<int>(sizeof(quint16)));

    _tcpSocket->write(arrBlock);
    _textInput->setText("");
}

void Client::slotConnected(){
    _textInfo->append("Received the \"connected\" signal.");
}

/*void Client::slotError(QAbstractSocket::SocketError err)

}*/
