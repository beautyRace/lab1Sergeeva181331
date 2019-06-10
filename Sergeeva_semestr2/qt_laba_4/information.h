#ifndef INFORMATION_H
#define INFORMATION_H

#include <QDialog>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>

namespace Ui {
class Information;
}

class Information : public QDialog
{
    Q_OBJECT

public:
    explicit Information(QWidget *parent = nullptr);
    ~Information();

public slots:
    void setSocketAndInf(QTcpSocket *_socket, QString _str);

private:
    QTcpSocket* socket;
    Ui::Information *ui;
};

#endif // INFORMATION_H
