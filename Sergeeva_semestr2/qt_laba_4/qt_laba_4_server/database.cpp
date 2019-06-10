#include "database.h"
#include "server.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/conf.h>
#include <openssl/applink.c>

DataBase::DataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\Users\\Asus\\Desktop\\NECHTO\\qt_laba_4_server\\food.db3");
    if (!db.open()){
        qDebug() << "Cannot open database: " << db.lastError().text();
    }
} //id AUTO_INCREMENT

void DataBase::handleErrors(void){
    ERR_print_errors_fp(stderr);
    abort();
}

int DataBase::do_crypt(unsigned char *plaintext, int plaintext_len, unsigned char *ciphertext, int do_encrypt)
{
    EVP_CIPHER_CTX *ctx;

    int len;
    int ciphertext_len;

    if(!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();

    unsigned char *key = (unsigned char *)"0123456789abcdeF0123456789abcdeF";
    unsigned char *iv = (unsigned char *)"1234567887654321";

    if(1 != EVP_CipherInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv, do_encrypt))
        handleErrors();

    if(1 != EVP_CipherUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();
    ciphertext_len = len;

    if(1 != EVP_CipherFinal_ex(ctx, ciphertext + len, &len))
        handleErrors();
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return ciphertext_len;
}

void DataBase::newTableAuthorization(){
    QSqlQuery query;
    str = "CREATE TABLE authorization (id INTEGER PRIMARY KEY AUTOINCREMENT, username VARCHAR(255), password VARCHAR(255), login VARCHAR(255));";
    if (!query.exec(str)) {
     qDebug() << "Unable to create a table";
     }
}

QString DataBase::newDataAuthorithation(const QString& _str){
    QString returnElem = "{\"status\":\"registration\",\"registration\":\"yes\"}";
    QSqlQuery query;
    doc = QJsonDocument::fromJson(_str.toUtf8());

    QString username = doc.object().value("username").toString();
    QString password = doc.object().value("password").toString();
    //string _password = doc.object().value("password").toString().toUtf8().constData();
    QString login = doc.object().value("login").toString();


//    unsigned char* password = (unsigned char*)_password.c_str();
//    printf("%s\n", password);
//    unsigned char _cipherpassword[128];

//    do_crypt(password, strlen((char *)password), _cipherpassword, 1);
//    printf("%s\n", _cipherpassword);

//    QString cipherpassword = QString::fromUtf8(string(reinterpret_cast< char const* >(_cipherpassword)).c_str());

    QString strF =
            "INSERT INTO authorization (username, password, login) "
            "VALUES('%1', '%2', '%3');";
    str = strF.arg(username)
            .arg(password)
            .arg(login);
    if (!query.exec(str)) {
        qDebug() << "Unable to make insert operation";
        returnElem = "{\"status\":\"registration\",\"registration\":\"no\"}";
    }
    return returnElem;
}

QString DataBase::checkDataAuthorithation(QString nameElem, QString elem){
    QSqlQuery query;
    str = "SELECT * FROM authorization;";
    query.exec(str);
    QSqlRecord rec = query.record();
    QString id;
    QString username;
    //string _cipherpassword;
    QString password;
    QString login;
    QString returnElem;
    if (nameElem == "username") returnElem = "{\"status\":\"username\",\"username\":\"no\"}";
    if (nameElem == "password") returnElem = "{\"status\":\"password\",\"passwordst\":\"no\"}";
    QJsonDocument json;
    QJsonArray recordsArray;
    while (query.next()) {
        id = query.value(rec.indexOf("id")).toString();
        username = query.value(rec.indexOf("username")).toString();
        password = query.value(rec.indexOf("password")).toString();
        //_cipherpassword = query.value(rec.indexOf("password")).toString().toUtf8().constData();
        login = query.value(rec.indexOf("login")).toString();

//        qDebug() << QString::fromUtf8(_cipherpassword.c_str());

//        unsigned char* cipherpassword = (unsigned char*)_cipherpassword.c_str();
//        printf("%s\n", cipherpassword);
//        unsigned char _decryptedpassword[128];

//        int decryptedpassword_len = do_crypt(cipherpassword, strlen((char *)cipherpassword), _decryptedpassword, 0);
//        _decryptedpassword[decryptedpassword_len] = '\0';

//        printf("%s\n", _decryptedpassword);
//        qDebug() << "DECRIPTPASS " << _decryptedpassword;

//        QString decryptedpassword = QString::fromUtf8(string(reinterpret_cast< char const* >(_decryptedpassword)).c_str());

//        qDebug() << "DECRIPTPASS " << decryptedpassword;
        if (nameElem == "username"){
            if (elem == username) returnElem = "{\"status\":\"username\",\"username\":\"yes\"}";
        }
        if (nameElem == "password"){
            //qDebug() << password << " " << elem;
            if (elem == password){
                returnElem = "{\"status\":\"password\",\"passwordst\":\"yes\",\"id\":\"" + id + "\",\"username\":\"" + username + "\",\"password\":\"" + password + "\",\"login\":\"" + login + "\"}";
                }
                //json.setArray(recordsArray);
            }
    }
    return returnElem;
}
