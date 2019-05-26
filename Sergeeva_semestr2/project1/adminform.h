#ifndef ADMINFORM_H
#define ADMINFORM_H
#include "user.h"
#include "assets.h"

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>

namespace Ui {
class adminForm;
}

class adminForm : public QWidget
{
    Q_OBJECT

public:
    explicit adminForm(QWidget *parent = nullptr);
    ~adminForm();

private slots:
    void on_add_clicked();
    void on_safe_clicked();
    void on_check_clicked();

private:
    Ui::adminForm *ui;
    QList <user> us;
    QStandardItemModel *model;
    QStringList horizontalHeader;
    QStandardItem *item;
    QList <assets> as;
    QStandardItemModel *model2;
    QStringList horizontalHeader2;
};

#endif // ADMINFORM_H
