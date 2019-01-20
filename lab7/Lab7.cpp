
#include "pch.h"
#include <iostream>

class matritsa {
public:
	bool check;
	matritsa();
	~matritsa();
	virtual void input();

	void keep(); //хранение размера матрицы A
	void setkeep();

	bool print();

	bool summ(matritsa matr2);
	bool mult(matritsa matr2);
	bool transpon();

	void deletee();

protected:
	double *arr;
	int stroka, stolbets;
	int p_stolbets, p_stroka;
	double *p_arr;
};

class vector : public matritsa { //наследованный класс вектор
public:
	vector();
	~vector();

	bool sk_mult(vector vec);
	bool num_mult();
	void input();

private:
	//int stroka, stolbets;
	//double *arr;
};

matritsa::matritsa()
{
}

matritsa::~matritsa()
{
}

void matritsa::input()
{
	std::cout << "введите кол-во строк: \t";
	std::cin >> stroka;
	std::cout << "введите кол-во столбцов: \t";
	std::cin >> stolbets;
	arr = new double[stroka*stolbets];
	std::cout << "введите матрицу: " << std::endl;
	for (int i = 0; i < stroka; i++) {
		for (int j = 0; j < stolbets; j++) {
			std::cin >> arr[i * stolbets + j];
		}
	}
}

void matritsa::keep()
{
	p_stroka = stroka;
	p_stolbets = stolbets;
	p_arr = new double[stroka*stolbets];
	for (int i = 0; i < stroka; i++) {
		for (int j = 0; j < stolbets; j++) {
			p_arr[i * stolbets + j] = arr[i * stolbets + j];
		}
	}
}

void matritsa::setkeep()
{
	stroka = p_stroka;
	stolbets = p_stolbets;
	for (int i = 0; i < stroka; i++) {
		for (int j = 0; j < stolbets; j++) {
			arr[i * stolbets + j] = p_arr[i * stolbets + j];
		}
	}
}


bool matritsa::print()
{
	if (!check) {
		std::cout << "ОШИБКА!\n";
		return false;
	}
	for (int i = 0; i < stroka; i++) {
		for (int j = 0; j < stolbets; j++) {
			std::cout << arr[i * stolbets + j] << "; ";
		}
		std::cout << std::endl;
	}
	getchar();
}

bool matritsa::summ(matritsa matr2)
{
	std::cout << "\nA + B = \n";
	if (stroka < 1 || stolbets < 1) {
		return check = false;
	}
	if (stroka != matr2.stroka || stolbets != matr2.stolbets) {
		return check = false;
	}

	for (int i = 0; i < stroka; i++) {
		for (int j = 0; j < stolbets; j++) {
			arr[i * stolbets + j] += matr2.arr[i * stolbets + j];
		}
	}
	return check = true;
}

bool matritsa::mult(matritsa matr2)
{
	double *arr1 = new double[stroka*matr2.stolbets];
	std::cout << "\nA * B = \n";
	if (stroka < 1 || stolbets < 1 || matr2.stolbets < 1) {
		return check = false;
	}
	if (stolbets != matr2.stroka) {
		return check = false;
	}
	double b = 0;
	for (int i = 0; i < stroka; i++) {
		for (int j = 0; j < matr2.stolbets; j++) {

			for (int x = 0; x < stolbets; x++) {
				b += arr[i * stolbets + x] * matr2.arr[x * matr2.stolbets + j];
			}
			arr1[i * matr2.stolbets + j] = b;
			b = 0;
		}
	}
	delete[] arr;
	arr = new double[stroka*matr2.stolbets];
	for (int i = 0; i < stroka; i++) {
		for (int j = 0; j < matr2.stolbets; j++) {
			arr[i * matr2.stolbets + j] = arr1[i * matr2.stolbets + j];
		}
	}
	stolbets = matr2.stolbets;
	return check = true;
	delete[] arr1;
}


bool matritsa::transpon()
{
	std::cout << "\nтранспонированная матрица A: \n";
	double *arr1 = new double[stroka*stolbets];
	for (int i = 0; i < stroka; i++)
	{
		for (int j = 0; j < stolbets; j++)
		{
			arr1[i*stolbets + j] = arr[i*stolbets + j];
		}
	}

	for (int i = 0; i < stroka; i++)
	{
		for (int j = 0; j < stolbets; j++)
		{
			arr[j*stroka + i] = arr1[i*stolbets + j];
		}
	}
	int temp = stroka;
	stroka = stolbets;
	stolbets = temp;
	delete[] arr1;
	return check = true;
}

void matritsa::deletee()
{
	delete[] arr;
}


vector::vector()
{
}

vector::~vector()
{
}

bool vector::sk_mult(vector vec)
{
	double c = 0;
	if (stolbets != vec.stolbets) {
		std::cout << "ОШИБКА!\n";
		return false;
	}

	for (int i = 0; i < stolbets; i++) {
		c += arr[i] * vec.arr[i];
	}
	std::cout << "\nполученное число в результате A * B: " << c << std::endl;
	return true;
}

bool vector::num_mult()
{
	int c;
	std::cout << "Введите число: ";
	std::cin >> c;
	for (int i = 0; i < stolbets; i++) {
		arr[i] *= c;
	}
	std::cout << "A * " << c << ": ";
	for (int i = 0; i < stolbets; i++) {
		std::cout << arr[i] << "; ";
	}
	return true;
}

void vector::input()
{
	arr = new double[stolbets];
	stroka = 1;
	std::cout << "введите размер вектора: \t";
	std::cin >> stolbets;
	std::cout << "введите вектор: " << std::endl;
	for (int i = 0; i < stolbets; i++) {
		std::cin >> arr[i];

	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	matritsa matrA, matrB;
	std::cout << "матрица A: " << std::endl;
	matrA.input(); //ввод матрицы A
	matrA.keep(); //сохранение размера матрицы A
	std::cout << "\nматрица B: " << std::endl;
	matrB.input(); //ввод матрицы B
	matrA.summ(matrB); //сумма
	matrA.print();
	//matrA.setkeep();
	//matrA.mult(matrB); //умножение 
	//matrA.print();
	//matrA.setkeep();
	//matrA.transpon(); //транспонирование
	//matrA.print();
	//matrA.deletee();
	//matrB.deletee();

	vector vecA, vecB;
	std::cout << "вектор A: " << std::endl;
	vecA.input();
	std::cout << "вектор B: " << std::endl;
	vecB.input();
	vecA.summ(vecB);
	vecA.print();
	vecA.sk_mult(vecB);
	vecA.num_mult();
	vecA.deletee();
	vecB.deletee();

	getchar();
	return 0;
}



