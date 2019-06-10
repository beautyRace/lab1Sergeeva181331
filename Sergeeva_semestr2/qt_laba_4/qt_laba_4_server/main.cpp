#include <QCoreApplication>
#include "server.h"
#include <QDebug>
#include "database.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server server;
    server.startServer();

    return a.exec();
}
