#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QFrame>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_shaButton_clicked(); //вызывается по нажатию кноки для получения хэш-строки
    void on_imgButton_clicked(); // вызывается по нажатию кнопки для внедрения кода в изображение

private:
    Ui::MainWindow *ui;
    QString myHash; //сюда записывается строка хэш для хранения
    QString makeSHA1(const unsigned char text[]); // функция для получения хэша
    char* chartobin ( unsigned char c );
};

#endif // MAINWINDOW_H

