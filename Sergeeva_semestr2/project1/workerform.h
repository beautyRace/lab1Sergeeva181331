#ifndef WORKERFORM_H
#define WORKERFORM_H
#include "assets.h"
#include <QStandardItemModel>

#include <QWidget>
#include <QList>

namespace Ui {
class workerform;
}

class workerform : public QWidget
{
    Q_OBJECT

public:
    explicit workerform(QWidget *parent = nullptr);
    ~workerform();

private slots:
    void on_sortName_clicked();
    void on_sortCategory_clicked();
    void on_find_clicked();

private:
    Ui::workerform *ui;
    QList <assets> as;
    QStandardItemModel *model;
    QStringList horizontalHeader;
    QStandardItem *item;
};

#endif // WORKERFORM_H
