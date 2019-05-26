#include "widget.h"
#include "autorization.h"
#include "user.h"
#include <QApplication>
#include <string>

using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    autorization w;
    w.show();

    return a.exec();
}
