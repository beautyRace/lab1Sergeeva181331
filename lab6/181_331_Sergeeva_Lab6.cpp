// pch.cpp: исходный файл, соответствующий предкомпилированному заголовку; нужен для компиляции

#include "pch.h"
#include <iostream>
#include "181_331_Sergeeva_Lab6.h"

class Mat {
public:
	Mat(); 
	~Mat();
	void setMat(int p_stroka, int p_stolbets, int p_arr[10][10]);
	void input();
	int getStroka();
		int getStolbets();
		void print();
		void sMat(Mat arr); // Сложение
		void pMat(Mat arr); // Умножение 
		void tMat(); // Транспонирование

private:
	int arr[10][10];
	int stroka=10, stolbets=10;


};
int main()
{
	Mat arrA, arrB;
	arrA.input();
	arrB.input();
	arrA.sMat(arrB);
	arrA.print();
	arrA.pMat(arrB);
	arrA.print();
	arrA.tMat();
	arrA.print();

	getchar();
	return 0;
}



// В целом этот файл можно пропустить, но не удаляйте его, если вы используете предкомпилированные заголовки.

Mat::Mat()
{
}

Mat::~Mat()
{
}

void Mat::input()
{
	for (int i = 0, i < stroka, i++); {
		for (int j = 0, j < stolbets, j++); {
			std::cin >> arr[i][j];
		}
	}
}

int Mat::getStroka()
{
	for (int i = 0, i < stroka, i++); {
		for (int j = 0, j < stolbets, j++); {
			std::cout << arr[i][j] << ";";
		}
	}
	std::cout << std::endl;
}
    getchar(); 
	return 0;
}

int Mat::getStolbets()
{
	return 0;
}

void Mat::print()
{
}

void Mat::sMat(Mat arr2)
{
	for (c = 0; c < 10; c++)
		for (d = 0; d < 10; d++)
			arr[c][d] = arr[c][d] + arr2[c][d];
}

void Mat::pMat(Mat arr2)
{
	array[10][10] product;

	for (int row = 0; row < 10; row++) {
		for (int col = 0; col < 10; col++) {
			for (int inner = 0; inner < 10; inner++) {
				product[row][col] += aMatrix[row][inner] * bMatrix[inner][col];
			}
		}
	}

	arr = product;
}

void Mat::tMat()
{
	array[10][10] transMatrix;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			transMatrix[j][i] = matrix[i][j];
		}
	}

	arr = transMatrix;
}








/* НАССЛЕДОВАНИЕ КЛАССОВ - 
   взаимствование свойств и методов родительского класса дочерним. 
 1. СИНТАКСИС КЛАССОВ:
 class имя_нового_класса : [тип наследования] имя_родительского_класса_1
                           [тип наследования] имя_родительского_класса_2
    где "тип наследования" - тоже public, protected и private
	но не обязательно указывать.
	2. Метод, переопределенный в дочернем классе, полностью заменит унаследованный родительский метод. 
 Чтобы при запуске нового дочернего метода также выполнять и родительский необходимо указать это явно
    в родитедьском классе - void reload(){};
    в дочернем классе - void reload()::reload(), ..., (еще методы - другие), ... {}; 
 3. если объявить метод со словом vertual, в данном клвссе можно не 
    приводить реализацию метода и определить его (привести реализацию)
    только в дочерних классах.
 4. ЗАДАНИЕ:
    Определить от класса матрицы дочерний класс вектора 
	и дописать ему векторные операции (скалярное и векторное умножение).
	
 4* ПРИВЕДЕНИЕ ТИПОВ
 При попытке сложить/поделить/умножить числа двух разных типов  (например doubl и int)
 оба операнда автоматически преобразуются к наиболее сложному/длинному типу. 
 Пример:
 doubl + int оба числа к doubl
 char + int оба к int
 беззнаковые к знаковым
 int + "123"   
 */

class Vec: public Mat{
public:
	void calcScalarMultiplication(Mat arr);
	void calcVectorMultiplication(Mat arr);

	private
		vector[10];
}

Vec::calcScalarMultiplication(Vec vector2) {
	double s = 0;

	for (int i = 0; i < 10; i++) s += vector[i] * vector2[i];
}

Vec::calcVectorMultiplication(Vec vector2) {
	double c[10];
	
	for(i=0; i < 10; i++) c[i]=vector[(i+1)%3]* vector2[(i+2)%3] -vector[(i+2)%3]* vector2[(i+1)%3];
}