#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include <QMessageBox>

using namespace std;

class Person {
    string email;
    string password;
    string role;

public:
    Person (string e, string p, string r){
        this->email=e;
        this->password=p;
        this->role=r;
    }

    string getEmail(){
        return email;
    }

    string getPassword(){
        return password;
    }

    string getRole(){
        return role;
    }
};


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QLabel *labelEmail;
    QLabel *labelPassword;
    QPushButton *button;
    QLineEdit *lineEmail;
    QLineEdit *linePassword;
    QVBoxLayout *layout;

public slots:
    string getEmail(){
        return lineEmail->text().toStdString();
    }
    string getPassword(){
        return linePassword->text().toStdString();
    }
    void enter(){
        string email = getEmail();
        string password = getPassword();
        int flag = 0;
        Person *p[]= {new Person("kiril","password", "admin"), new Person("ivanove","12345","user"),
                     new Person("igor","5678i","user"), new Person("sofia","nyasha","admin")};
        for (int i=0; i<4; i++){
            if (email==p[i]->getEmail() && password == p[i]->getPassword()){
                if (p[i]->getRole()=="admin"){
                    flag=1;
                }else{
                    flag = 2;
                }
            }
        }
        if (flag==1){
            QMessageBox::about(this, "Ура!", "Вы вошли как администратор!");
        }else{
            if (flag == 2){
                QMessageBox::about(this, "Ура!", "Вы вошли как пользователь!");
            }else{
                QMessageBox::about(this, "Ошибка", "Неверный логин или пароль");
            }
        }
    }
};

#endif // WIDGET_H


