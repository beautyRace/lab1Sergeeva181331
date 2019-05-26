#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H
#include "user.h"
#include "assets.h"
#include <QList>

class myFunctions
{
    public:
        static QList<user> getUser();
        static QList<assets> getAssets();
        static void setUser(QList<user> u);
};

#endif // MYFUNCTIONS_H
