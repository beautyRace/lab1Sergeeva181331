#ifndef AUTORIZATION_H
#define AUTORIZATION_H
#include "workerform.h"
#include "adminform.h"

#include <QWidget>

namespace Ui {
class autorization;
}

class autorization : public QWidget
{
    Q_OBJECT

public:
    explicit autorization(QWidget *parent = nullptr);
    ~autorization();

private slots:
    void on_enterButton_clicked();

private:
    Ui::autorization *ui;
    workerform *wf;
    adminForm *af;
};

#endif // AUTORIZATION_H
