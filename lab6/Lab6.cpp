
#include "pch.h"
#include <iostream>

class matrixd
{
protected:
	int rows;
	int columns;
	double *ma;
public:
	matrixd();
	~matrixd();
	void create();
	void input();
	void print();
	int getrows();
	int getcolumns();
	bool summ(matrixd ma2);
	bool mult(matrixd ma2);
	void transp();
	double getelem(int r, int c)
	{
		return ma[r*columns + c];
	}
};


matrixd::matrixd()
{
}

matrixd::~matrixd()
{
}

void matrixd::create()
{
	int rs;
	int cs;
	std::cout << "Rows = ";
	std::cin >> rs;
	std::cout << "Columns = ";
	std::cin >> cs;
	std::cout << "\n";
	rows = rs;
	columns = cs;
	ma = new double[rows*columns];
}

void matrixd::input()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
		{
			std::cout << "Matr[" << i + 1 << "][" << j + 1 << "] = ";
			std::cin >> ma[i*columns + j];
		}
	std::cout << "\n";
}

void matrixd::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << ma[i*columns + j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "\n";
}

int matrixd::getrows()
{
	return rows;
}

int matrixd::getcolumns()
{
	return columns;
}

bool matrixd::summ(matrixd ma2)
{
	if (rows < ma2.getrows())
		return false;
	if (columns < ma2.getcolumns())
		return false;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			ma[i*columns + j] += ma2.getelem(i, j);
		}

	}
	return true;
}

bool matrixd::mult(matrixd ma2)
{
	if (columns != ma2.getrows())
	{
		std::cout << "ERROR \n" << std::endl;
		return false;
	}

	double *ma3 = new double[rows*ma2.getcolumns()];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			ma3[i*columns + j] = ma[i*columns + j];
		}
	}
	int temp = columns;
	columns = ma2.getcolumns();
	for (int j = 0; j < ma2.getcolumns(); j++)
	{
		for (int i = 0; i < rows; i++)
		{
			double x = 0;
			for (int t = 0; t < temp; t++)
			{
				x += ma3[i*temp + t] * ma2.getelem(t, j);
			}
			ma[i*columns + j] = x;
		}
	}
	delete ma3;
	return true;
}

void matrixd::transp()
{
	double * ma3 = new double[rows*columns];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			ma3[i*columns + j] = ma[i*columns + j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			ma[(i + 1)*columns - j] = ma3[i*columns + j];
		}
	}
	int temp = rows;
	rows = columns;
	columns = temp;
	delete ma3;
}

int main()
{
	matrixd A;
	matrixd B;
	A.create();
	A.input();
	std::cout << "A = \n" << std::endl;
	A.print();
	B.create();
	B.input();
	std::cout << "B = \n" << std::endl;
	B.print();
	A.summ(B);
	std::cout << "A + B = \n" << std::endl;
	A.print();
	A.transp();
	std::cout << "(A + B) TRANSPOSED = \n" << std::endl;
	A.print();
	A.mult(B);
	std::cout << "((A + B) TRANSPOSED) * B = \n" << std::endl;
	A.print();

	system("pause");
	return 0;
}