#ifndef DATABASE_H
#define DATABASE_H
#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QString>
#include <QJsonDocument>

using namespace std;

class DataBase
{
private:
    QSqlDatabase db;
    QString str;
    QByteArray blockDb;
    QJsonDocument doc;

public:
    void handleErrors(void);
    int do_crypt(unsigned char *plaintext, int plaintext_len, unsigned char *ciphertext, int do_encrypt);
    DataBase();
    void newTableAuthorization();
    QString newDataAuthorithation(const QString& _str);
    QString checkDataAuthorithation(QString namelem, QString elem);
};

#endif // DATABASE_H
