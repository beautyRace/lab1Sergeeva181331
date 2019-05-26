#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    layout = new QVBoxLayout;
    button = new QPushButton("Войти");
    lineEmail = new QLineEdit();
    linePassword = new QLineEdit();
    labelEmail = new QLabel("Логин");
    labelPassword = new QLabel("Пароль");


    /* добавляем виджеты в лаяут */
     layout->addWidget(labelEmail);
     layout->addWidget(lineEmail);
     layout->addWidget(labelPassword);
     layout->addWidget(linePassword);
     layout->addWidget(button);
     setLayout(layout);


     connect(button, SIGNAL(clicked(bool)), this, SLOT(enter()));

}

Widget::~Widget()
{
    delete ui;
}
