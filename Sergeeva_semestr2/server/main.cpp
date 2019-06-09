#include <QApplication>
#include "server.h"
#include "client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //############

    Server server(8080);
    server.show();

    Client client1("localhost", "Player 1", 8080);
    client1.show();

    Client client2("localhost", "Player 2", 8080);
    client2.show();

    //############

    return a.exec();
}
