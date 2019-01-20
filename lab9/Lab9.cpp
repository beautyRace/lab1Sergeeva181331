#include "pch.h"
#include <iostream> 
#include <fstream> 

class matrixdyn
{
protected:
	double *matr;
	int rows;
	int colums;
	bool boo;
public:
	virtual void create(); //виртуальные функции переопределяются в дочернем классе
	virtual void input();
	void print();
	void transp();
	int getrows() const //гарантирует, что мы не сможем изменить переменную
	{
		return rows;
	}
	int getcolums() const
	{
		return colums;
	}
	double getelem(int r, int c) const
	{
		return matr[r*colums + c]; //matr - одномерный массив, но работаем как с двумерным
	}
	void olelem(int oro, int oco, double oel)
	{
		matr[oro*colums + oco] = oel; //заменяем элемент матрицы
	}
	void odim(int oro, int oco) //выделяем память под массив длинны oro X oco
	{
		rows = oro;
		colums = oco;
		matr = new double[rows*colums];
	}
	friend std::ostream& operator << (std::ostream& os, const matrixdyn& d); //прототип дружественной функции переопределения потокового вывода в консоль
	void del();
	friend matrixdyn operator + (matrixdyn A, matrixdyn B); //прототипы дружественных функций переопределения операторов
	friend matrixdyn operator - (matrixdyn A, matrixdyn B);
	friend matrixdyn operator * (matrixdyn A, matrixdyn B);
};

class vectordyn : public matrixdyn
{
public:
	void virtual input(); //прототипы переопределяемых функций
	void virtual create();

	friend std::ostream& operator << (std::ostream& os, const matrixdyn& d);
	friend vectordyn operator * (vectordyn C, int k);
};

int main()
{
	setlocale(0, ""); //разрешаем вывод кириллицы в консоль
	matrixdyn A, B;
	A.create();
	A.input();
	std::cout << "Матрица A \n";
	A.print();

	B.create();
	B.input();
	std::cout << "Матрица B \n";
	B.print();

	
	std::cout << "Демострируем сложение матриц: \n";
	std::cout << "A + B \n" << A + B << std::endl;
	std::cout << "Демострируем вычитание матриц: \n";
	std::cout << "A - B \n" << A - B << std::endl;
	A.transp(); //транспонируем
	std::cout << "Демострируем умножение матриц: \n";
	std::cout << "A * B \n" << A * B << std::endl;

	A.del();
	B.del();

	vectordyn C, D;
	C.create();
	C.input();
	std::cout << "Вектор C \n";
	C.print();

	D.create();
	D.input();
	std::cout << "Вектор D \n";
	D.print();
	std::cout << "Демострируем умножение вектора на константу: \n";
	std::cout << "C * 7 \n" << C * 7 << std::endl;
	std::cout << "Демострируем сложение векторов: \n";
	std::cout << "C + D \n" << C + D << std::endl;
	D.transp();
	std::cout << "Демострируем умножение векторов: \n";
	std::cout << "C * D \n" << C * D << std::endl;

	C.del();
	D.del();

	getchar();
	return 0;
}

//перегрузка оператора +
matrixdyn operator + (matrixdyn A, matrixdyn B)
{
	matrixdyn res;
	res.odim(A.getrows(), A.getcolums());
	if (A.getrows() != B.getrows() || A.getcolums() != B.getcolums())
	{
		std::cout << "Сложение не выполнено! Возвращено первое слагаемое! \n";
		return A;
	}
	for (int i = 0; i < B.getrows(); i++)
		for (int j = 0; j < A.getcolums(); j++)
			res.olelem(i, j, A.getelem(i, j) + B.getelem(i, j));
	return res;
}

// перегрузка оператора -
matrixdyn operator - (matrixdyn A, matrixdyn B)
{
	matrixdyn res;
	res.odim(A.getrows(), A.getcolums());
	if (A.getrows() != B.getrows() || A.getcolums() != B.getcolums())
	{
		std::cout << "Вычитание не выполнено! Возвращено уменьшаемое! \n";
		return A;
	}
	for (int i = 0; i < B.getrows(); i++)
		for (int j = 0; j < A.getcolums(); j++)
			res.olelem(i, j, A.getelem(i, j) - B.getelem(i, j));
	return res;
}

//перегрузка оператора *
matrixdyn operator * (matrixdyn A, matrixdyn B)
{
	matrixdyn res;
	if (A.getcolums() != B.getrows())
	{
		std::cout << "Умножение не выполнено! Возвращен первый множитель! \n";
		return A;
	}
	res.odim(A.getrows(), B.getcolums());
	int rows = A.getrows();
	int temp = A.getcolums();
	int colums = B.getcolums();
	for (int j = 0; j < colums; j++)
		for (int i = 0; i < rows; i++)
		{
			double x = 0;
			for (int t = 0; t < temp; t++)
				x += A.getelem(i, t)*B.getelem(t, j);
			res.olelem(i, j, x);
		}
	return res;
}

//перегрузка оператора <<
std::ostream & operator << (std::ostream & os, const matrixdyn & d)
{
	for (int i = 0; i < d.getrows(); i++) {
		for (int j = 0; j < d.getcolums(); j++)
			os << d.getelem(i, j) << "\t";
		os << "\n";
	}
	return os;
}

void matrixdyn::create()
{
	std::cout << "Введите количество строк" << std::endl;
	std::cin >> rows;
	std::cout << "Введите количество столбцов" << std::endl;
	std::cin >> colums;
	std::cout << "\n";
	matr = new double[rows*colums];
}

void matrixdyn::input()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < colums; j++)
		{
			std::cout << "Матрица[" << i + 1 << "][" << j + 1 << "] = ";
			std::cin >>

				matr[i*colums + j];
		}
	std::cout << "\n";
	boo = true;
}

void matrixdyn::print()
{
	if (!boo)
	{
		std::cout << "Ошибка! Матрица не проинициализирована!" << "\n" << "\n";
	}
	else
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < colums; j++)

				std::cout << matr[i*colums + j] << "\t";
			std::cout << std::endl;
		}
		std::cout << "\n";
	}
}

void matrixdyn::transp()
{
	double * ma3 = new double[rows*colums];
	std::cout << "Мы транспонируем матрицу..." << std::endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			ma3[i*colums + j] = matr[i*colums + j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			matr[j*rows + i] = ma3[i*colums + j];
		}
	}
	int temp = rows;
	rows = colums;
	colums = temp;
	delete ma3;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
			std::cout << matr[i*colums + j] << "\t";
		std::cout << std::endl;
	}
	std::cout << "\n";
}

void matrixdyn::del()
{
	if (matr != NULL)
	{
		delete[] matr;
		matr = NULL;
	}
	else
		std::cout << "Тут чисто!" << std::endl;
}

void vectordyn::input()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < colums; j++)
		{
			std::cout << "Вектор[" << j + 1 << "] = ";
			std::cin >> matr[i*colums + j];
		}
	std::cout << "\n";
	boo = true;
}

void vectordyn::create()
{
	std::cout << "Количество строк = 1" << std::endl;
	std::cout << "Введите количество столбцов" << std::endl;
	std::cin >> colums;
	rows = 1;
	matr = new double[rows*colums];
}

vectordyn operator * (vectordyn C, int k)
{
	vectordyn result;
	int u = C.getrows();
	int uu = C.getcolums();
	result.odim(u, uu);
	for (int i = 0; i < u; i++)
		for (int j = 0; j < uu; j++)
		{
			double a = C.getelem(i, j);
			result.olelem(i, j, k*a);
		}
	return result;
}