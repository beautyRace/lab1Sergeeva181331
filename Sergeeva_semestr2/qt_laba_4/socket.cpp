#include "socket.h"
#include <QDataStream>

Socket::Socket(){

}

void Socket::sendToClient(QTcpSocket* socket, const QString &str){
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);

    out << quint16(0) << str;
    out.device()->seek(0); //переход в начало
    out << quint16(arrBlock.size() - static_cast<int>(sizeof(quint16))); //вычесляем размер записанной строки и пишем на место пустых битов

    socket->write(arrBlock);
    socket->waitForBytesWritten(500);
}
