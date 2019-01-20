

#include "pch.h"
#include <iostream>

class Matrix
{
private:
	int* a;
	int m = 10;
	int n = 10;
public:
	Matrix();
	bool print();
	void set_matrix(int* new_a, int m1, int n1);
	bool input();
	bool transp();
	bool summMatrix(Matrix b);
	bool multMatrix(Matrix b);
	int get_m() { return m; }
	int get_n() { return n; }
	double getElem(int row, int col)
	{
		if (row<m && col<n && row>-1 && col>-1)
		{
			return a[row*n + col];
		}
		std::cout << "Connot get elenent. Index Error!\n";
		return -1;
	};
	bool setElem(int row, int col, double elem) {
		if (row<m && col<n && row>-1 && col>-1)
		{
			a[row*n + col] = elem;
			return true;
		}
		std::cout << "Connot set elenent. Index Error!\n";
		return false;
	};
	friend Matrix operator+ (const Matrix& a, const Matrix& b);
	friend Matrix operator- (const Matrix& a, const Matrix& b);
	Matrix & operator= (Matrix b) {
		delete[] a;
		a = new int[b.get_m()*b.get_n()];
		for (int i = 0; i < b.get_m(); i++) {
			for (int j = 0; j < b.get_n(); j++) {
				a[i*b.get_n() + j] = b.getElem(i, j);
			}
		}
		m = b.get_m();
		n = b.get_n();
		return *this;
	};
	friend std::ostream &operator << (std::ostream &os, Matrix &b);
};

std::ostream& operator << (std::ostream &os, Matrix &b)
{
	for (int i = 0; i < b.get_m(); i++) {
		for (int j = 0; j < b.get_n(); j++) {
			os << b.getElem(i, j) << "\t";
		};
		os << std::endl;
	};
	return os;
}

Matrix operator+ (Matrix& a, Matrix& b) {
	if ((a.get_m() == b.get_m()) && (a.get_n() == b.get_n())) {
		Matrix C;
		int *new_c = new int[a.get_m()*a.get_n()];
		for (int i = 0; i < a.get_m(); i++) {
			for (int j = 0; j < a.get_n(); j++) {
				new_c[i*a.get_n() + j] = a.getElem(i, j) + b.getElem(i, j);
			};
		};
		C.set_matrix(new_c, a.get_m(), a.get_n());
		delete[] new_c;
		return C;
	}
	else {
		return a;
	}
}

Matrix operator- (Matrix& a, Matrix& b) {
	if ((a.get_m() == b.get_m()) && (a.get_n() == b.get_n())) {
		Matrix C;
		int *new_c = new int[a.get_m()*a.get_n()];
		for (int i = 0; i < a.get_m(); i++) {
			for (int j = 0; j < a.get_n(); j++) {
				new_c[i*a.get_n() + j] = a.getElem(i, j) - b.getElem(i, j);
			};
		};
		C.set_matrix(new_c, a.get_m(), a.get_n());
		delete[] new_c;
		return C;
	}
	else {
		return a;
	}
}

Matrix::Matrix() {
	a = new int[10];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i*n + j] = 0;
		}
	}
}

bool Matrix::transp() {
	int * new_a = new int[m*n];
	if (m < n) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				new_a[i*n + j] = a[i*n + j];
			};
		};
		for (int i = 0; i < m; i++) {
			for (int j = i + 1; j < m; j++) {
				int buf = new_a[j*n + i];
				new_a[j*n + i] = new_a[i*n + j];
				new_a[i*n + j] = buf;
			};
		};
		for (int i = 0; i < m; i++) {
			for (int j = n - m; j < n; j++) {
				new_a[j*m + i] = a[i*n + j];
			}
		};
		int buf = m;
		m = n;
		n = buf;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				a[i*n + j] = new_a[i*n + j];
			};
		};

	}
	else if (n < m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				new_a[i*n + j] = a[i*n + j];
			};
		};
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int buf = new_a[j*n + i];
				new_a[j*n + i] = new_a[i*n + j];
				new_a[i*n + j] = buf;
			};
		};
		for (int i = 0; i < m; i++) {
			for (int j = n - m; j < n; j++) {
				new_a[j*m + i] = a[i*n + j];
			}
		};
		int buf = m;
		m = n;
		n = buf;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				a[i*n + j] = new_a[i*n + j];
			};
		};
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int buf = a[j*n + i];
				a[j*n + i] = a[i*n + j];
				a[i*n + j] = buf;
			};
		};
	}
	delete[] new_a;
	return true;
}

bool Matrix::multMatrix(Matrix b) {
	if (n == b.get_m()) {
		int * new_a = new int[b.get_n()*m];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < b.get_n(); j++) {
				new_a[i*b.get_n() + j] = 0;
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < b.get_n(); j++) {
				for (int k = 0; k < n; k++) {
					new_a[i*b.get_n() + j] += a[i*n + k] * b.getElem(k, j);
				};
			};
		};
		n = b.get_n();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				a[i*n + j] = new_a[i*n + j];
			};
		};
		delete[] new_a;
		return true;
	}
	else {
		return false;
	};
}

bool Matrix::input()
{
	int new_rows;
	std::cin >> new_rows;
	if (new_rows < 1) {
		return false;
	}
	int new_colums;
	std::cin >> new_colums;
	if (new_colums < 1) {
		return false;
	}
	delete[] a;
	a = new int[new_rows*new_colums];
	for (int i = 0; i < new_rows; i++) {
		for (int j = 0; j < new_colums; j++) {
			std::cin >> a[i*new_colums + j];
		}
	}
	m = new_rows;
	n = new_colums;
	return true;
}

bool Matrix::summMatrix(Matrix b) {
	if ((m == b.get_m()) && (n == b.get_n())) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				a[i*n + j] = a[i*n + j] + b.getElem(i, j);
			};
		};
		return true;
	}
	else {
		return false;
	}
}

bool Matrix::print() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << a[i*n + j] << "\t";
		};
		std::cout << std::endl;
	};
	return true;
}

void Matrix::set_matrix(int* new_a, int m1, int n1) {
	delete[] a;
	m = m1;
	n = n1;
	a = new int[m*n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i*n + j] = new_a[i*n + j];
		};
	};
}

class Vector : public Matrix
{
public:
	double scalMultVector(Vector vec2);
	double MultVector(int num);
};

double Vector::MultVector(int num) {
	for (int i = 0; i < this->get_n(); i++) {
		this->setElem(0, i, this->getElem(0, i) * num);
	}
	return 1;
}

double Vector::scalMultVector(Vector vec2) {
	if (this->get_n() != vec2.get_n()) {
		return 0;
	}
	for (int i = 0; i < vec2.get_n(); i++) {
		this->setElem(0, i, this->getElem(0, i) * vec2.getElem(0, i));
	}
	return 1;
}

int main(int argc, const char * argv[]) {
	Matrix A, B, C;
	A.input();
	B.input();
	std::cout << "-------------------" << std::endl;
	std::cout << A;
	std::cout << "-------------------" << std::endl;
	std::cout << B;
	std::cout << "-------------------" << std::endl;
	C = A - B;
	std::cout << C;
	std::cout << "-------------------" << std::endl;
	C = C + A;
	std::cout << C;
	return 0;
}