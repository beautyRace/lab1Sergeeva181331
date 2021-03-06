
#include "pch.h"
#include <iostream>

class matrix
{
protected:
	double mx[10][10];
	int rows;
	int	columns;
public:
	matrix();
	~matrix();
	bool plus (matrix mx2);
	bool transp();
	bool mult(matrix mx2);
	virtual bool input();
	void print();
	
	int getrows()
	{
		return rows;
	}

	int getcolumns()
	{
		return columns;
	}

	double getelem(int r, int c)
	{
		if (r < rows && c<columns && c>-1)
			return mx[r][c];
		std::cout << "CANNOT GET ELEMENT. ERROR\n";
		return -1;
	}
};

matrix::matrix()
{

}
matrix::~matrix()
{

}
bool matrix::plus(matrix mx2)
{
	if (rows != mx2.getrows())
		return false;
	if (columns != mx2.getcolumns())
		return false;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			mx[i][j] += mx2.getelem(i,j);
	}
	return true;
}
bool matrix::input()
{
	int rs;
	int cs;
	std::cout << "Rows = "; 
	std::cin >> rs;
	if (rs < 0)
	{
		std::cout << "ERROR ROWS  \n" << std::endl;
		return false;
	}
	if (rs > 10)
	{
		std::cout << "ERROR ROWS  \n" << std::endl;
		return false;
	}
	std::cout << "Columns = "; 
	std::cin >> cs;
	std::cout << "\n";
	if (cs < 0)
	{
		std::cout << "ERROR COLUMNS  \n" << std::endl;
		return false;
	}
	if (cs > 10)
	{
		std::cout << "ERROR COLUMNS  \n" << std::endl;
		return false; 
	}
		
	for (int i = 0; i < rs; i++)
		for (int j = 0; j < cs; j++)
			std::cin >> mx[i][j];
	columns = cs;
	rows = rs;
	std::cout << "\n";
	return true;
}

void matrix::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			std::cout << mx[i][j] << "\t";
		std::cout << std::endl; 
	}
	std::cout << "\n";
}

bool matrix::transp()
{
	double mx3[10][10];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			mx3[i][j] = mx[i][j];
		}
	}

for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			mx[j][i] = mx3[i][j];
		}
	}
	int temp = rows;
	rows = columns;
	columns = temp;

	return true;
}

bool matrix::mult(matrix mx2)
{
	
	if (columns != mx2.getrows())
	{
		std::cout << "ERROR \n" << std::endl;
		return false;
	}

	double mx3[10][10];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			mx3[i][j] = mx[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < mx2.getcolumns(); j++)
		{
			double x = 0.0;
			for (int t = 0; t < columns; t++)
			{
				x += mx3[i][t] * mx2.getelem(t, j);
			}
			mx[i][j] = x;

		}
	}
	columns = mx2.getcolumns();
	return true;
}


class vector : public matrix
{
public:
	
	vector();
	double scalmultvector(vector vec2);
	void xmult(double k);
	virtual bool input();
	double summvector(vector vec2);
};

bool vector::input()
{
	int rs = 1;
	int cs;
	std::cout << "Rows = 1"<<std::endl; 
	if (rs < 0)
		return false;
	if (rs > 10)
		return false;
	std::cout << "Columns = ";
	std::cin >> cs;
	for (int i = 0; i < rs; i++)
		for (int j = 0; j < cs; j++)
			std::cin >> mx[i][j];
	columns = cs;
	rows = rs;
	std::cout << "\n";
	return true;
}

double vector::summvector(vector vec2)
{
	vector tmp = *this;
	if (tmp.plus(vec2))
	{
		return tmp.getelem(0, 0);
	}
	tmp = *this;
	tmp.transp();
	if (tmp.plus(vec2))
	{
		return tmp.getelem(0, 0);
	}
	return -1;
}

vector::vector()
{
}

double vector::scalmultvector(vector vec2)
{
	vector tmp = *this;
	if (tmp.mult(vec2))
	{
		return tmp.getelem(0, 0);
	}
	tmp = *this;
	tmp.transp();
	if (tmp.mult(vec2))
	{
		return tmp.getelem(0, 0);
	}
	return -1;
}

void vector::xmult(double k)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			mx[i][j] *= k;
		}
	}
}

int main()
{
	std::cout << "lab6\n" << std::endl;
	std::cout << "DO NOT USE NUMBERS MORE THAN 10 FOR ROWS AND COLUMNS\n" << std::endl;
	matrix mxA;
	std::cout << "INPUT A\n" << std::endl;
	mxA.input();
	std::cout << "A = \n";
	mxA.print();
	matrix mxB;
	std::cout << "INPUT B\n" << std::endl;
	mxB.input();
	std::cout << "B = \n";
	mxB.print();
	mxA.plus(mxB);
	std::cout << "A + B = \n";
	mxA.print();
	mxA.transp();
	std::cout << "A transposed = \n";
	mxA.print();
	std::cout << "A * B = \n";
	mxA.mult(mxB);
	mxA.print();
	vector mxA1;
	vector mxB1;
	std::cout << "INPUT VECTOR A\n" << std::endl;
	mxA1.input();
	std::cout << "VECTOR A = \n";
	mxA1.print();
	std::cout << "INPUT VECTOR B\n" << std::endl;
	mxB1.input();
	std::cout << "VECTOR B = \n";
	mxB1.print();
	mxA1.transp();
	std::cout << "VECTOR A TRANSPOSED = \n";
	mxA1.print();
	mxA1.xmult(5);
	std::cout << "VECTOR A * 5 = \n";
	mxA1.print();
	double f = mxA1.scalmultvector(mxB1);
	std::cout << "ScalMult =\t" << f << std::endl;
	mxA1.plus(mxB1);
	mxA1.print();
	getchar();
	return 0;
}
