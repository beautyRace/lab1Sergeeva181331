#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <openssl/sha.h>
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap myPix("14.bmp"); // изображение
    ui->img1->setPixmap(myPix);
    ui->img2->setText("Здесь будет изображение");
    ui->label->setText("Здесь будет хэш");
    ui->img1->setScaledContents( true );
    ui->img1->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}

QString MainWindow::makeSHA1(const unsigned char text[])
{
    unsigned char hash[20];// стандартная длина хеша (20 байт)
    SHA1(text, sizeof(text) - 1, hash); // вызов функции
    char sha1string[20*2 +1]; // выделяем массив для конечного результата
    for(int i = 0; i < 20; ++i)
    {
        sprintf(&sha1string[i*2], "%02x", (unsigned int)hash[i]); //создаёт отформатированную строку из произвольного списка аргументов
    }
    return sha1string; //возвращаем результат
}

void MainWindow::on_shaButton_clicked(){
    QString str = ui->lineEdit->text(); //получаем строку
    unsigned char *fio = (unsigned char *)strdup(str.toLocal8Bit().constData()); //конвертируем тип
    myHash=makeSHA1(fio);
    ui->label->setText(myHash);
}

//функция для перевода символа в массив битов
char* chartobin ( unsigned char c )
{
    static char bin[CHAR_BIT + 1] = { 0 };
    int i;

    for ( i = CHAR_BIT - 1; i >= 0; i-- )
    {
        bin[i] = (c % 2) + '0';
        c /= 2;
    }

    return bin;
}

void MainWindow::on_imgButton_clicked(){
   int mass[160] = {272741, 103763, 39639, 15534, 332498, 328936, 58976, 141066, 178799, 162507, 308829,
                   164677, 137276, 287266, 144884, 142327, 67850, 223130, 71388, 361143, 281626, 58539,
                   271243, 396579, 280187, 263350, 342758, 297237, 57157, 106551, 146632, 346314, 99520,
                   331915, 4487, 42061, 298704, 48592, 80752, 113484, 45092, 418558, 319694, 160258, 245331,
                   328807, 390667, 151213, 405806, 104311, 115426, 335362, 248009, 313554, 33831, 173191,
                   325926, 397552, 124741, 250218, 5498, 133482, 34863, 289408, 211629, 239270, 295632,
                   332770, 308967, 230838, 354178, 321252, 291850, 195349, 316551, 215772, 44033, 151701,
                   297930, 252060, 273737, 51809, 153361, 206576, 187731, 32393, 290646, 233276, 107139,
                   69522, 60484, 393654, 68837, 13925, 76099, 353654, 73921, 272835, 416920, 388534, 371808,
                   356981, 262769, 221190, 146130, 308750, 301406, 120987, 411780, 235202, 135652, 37399,
                   396853, 120383, 31090, 50047, 359023, 359775, 233149, 301590, 114158, 390634, 82216,
                   258398, 301030, 344546, 147607, 359716, 141433, 382630, 11305, 23640, 150768, 240239,
                   226336, 21035, 418400, 207640, 154200, 29392, 208103, 284698, 343496, 410887, 59025,
                   162693, 330109, 346305, 168897, 314832, 413081, 404199, 103296, 60247, 111591, 229226,
                   93621, 34391, 82844, 179577}; //заданный массив
    ifstream f;
    ofstream f1;
    f.open ("14.bmp",ios::binary);// открываем файл для чтения
    f1.open ("14_n.bmp",ios::binary); //открываем файл для записи модифицированного изображения
    char a ; //вспомогательная переменная
    char mas[421202]; //массив для нового изображения
       for (int i  = 0 ; i < 421202; i++ )
       {
           f.read(&mas[i],1); //записываем байт
       }
    unsigned char *fio = (unsigned char *)strdup(myHash.toLocal8Bit().constData()); //конвертируем тип строки с хэшем
    for (int i=0; i<40; i++){ //цикл для хеш-строки
        char *bitMas = chartobin(fio[i]); //переводит в строку бит
        for (int j=0; j<4; j++){
            int q = (int) mas[mass[i+j]];
                   if (bitMas[j] == '0')
                       if (q %2 != 0)                   //данный цикл заменяет последний бит в байтах под указанными номерами
                           q = q-1;                     // на бит из хэш строки
                   if (bitMas[i] == '1')
                       if (q %2 != 1)
                           q = q+1;
                   mas[mass[i+j]] = (char)q;
        }
    }
    for (int i  = 0 ; i < 421202; i++ )
        {
            f1.write(&mas[i],1); //записываем в файл
        }
    QPixmap myPix("14_n.bmp"); // модифицированное изображение
    ui->img2->setPixmap(myPix);
    ui->img2->setScaledContents( true );
    ui->img2->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}


MainWindow::~MainWindow()
{
    delete ui;
}



/*Secure Hash Algorithm 1 — алгоритм криптографического хеширования. Описан в RFC 3174. Для входного сообщения произвольной длины (максимум
2^64 − 1 {\displaystyle 2^{64}-1} бит, что примерно равно 2 эксабайта)
алгоритм генерирует 160-битное (20 байт) хеш-значение, называемое также дайджестом сообщения,
которое обычно отображается как шестнадцатиричное число, длиной в 40 цифр. Используется во многих криптографических приложениях и протоколах.*/
