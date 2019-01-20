

#include "pch.h"
#include <iostream>

class SummMatr
{

public:
	SummMatr();
	~SummMatr();
	int getElement(int siz, int hig); // возват эементов масива 
	bool setElement(int siz, int hig, double el)
	{
		if (siz<size && hig<high &&  siz>-1 && hig>-1)
		{
			Mass[siz*high + hig] = el;
			return true;
		}
		std::cout << "Connot set elenent. Index Error!\n";
		return false;
	}

	void set_SummMatr(int* p_Mass, int p_size, int p_high); // Ввод масив
	void input();
	int get_size();
	int get_high();// Вывод масива
	void print();
	friend std::ostream & operator<< (std::ostream &os, SummMatr &rhs);
	//friend std::istream & operator >> (std::istream &os,  SummMatr &rhs);
	friend SummMatr operator+ (SummMatr& A, SummMatr& B);
	friend SummMatr operator- (SummMatr& A, SummMatr& B);
	SummMatr & operator = (SummMatr B);
	void Transp();
private:
	int size;
	int high;
	int* Mass;



};
SummMatr operator + (SummMatr& A, SummMatr& B)
{
	std::cout << "Оператор + \n";
	/*std::cout << "Оператор + \n";*/
	if ((A.get_size() == B.get_size()) && (A.get_high() == B.get_high())) {
		SummMatr res;
		int* newC = new int[A.get_size()*B.get_high()];
		for (int i = 0; i < A.get_size(); i++) {
			for (int j = 0; j < A.get_high(); j++) {
				newC[i*A.get_high() + j] = A.getElement(i, j) + B.getElement(i, j);
			}
		}
		res.set_SummMatr(newC, A.get_size(), B.get_high());
		return res;
	}

}
SummMatr operator -(SummMatr& A, SummMatr& B)
{
	std::cout << "Оператор + \n";
	/*std::cout << "Оператор + \n";*/
	if ((A.get_size() == B.get_size()) && (A.get_high() == B.get_high())) {
		SummMatr res;
		int* newC = new int[A.get_size()*B.get_high()];
		for (int i = 0; i < A.get_size(); i++) {
			for (int j = 0; j < A.get_high(); j++) {
				newC[i*A.get_high() + j] = A.getElement(i, j) - B.getElement(i, j);
			}
		}
		res.set_SummMatr(newC, A.get_size(), B.get_high());
		return res;
	}

}

std::ostream & operator<< (std::ostream &os, SummMatr &rhs)
{

	for (int i = 0; i < rhs.get_size(); i++)
	{
		for (int j = 0; j < rhs.get_high(); j++)
		{
			/*os << "SummMatr" << std::endl;*/
			os << rhs.getElement(i, j) << "\t";
		}
		os << std::endl;
	}
	return os;
}

SummMatr::SummMatr()
{
	delete[] Mass;
	int numder = 255;
	Mass = new int[numder];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < high; j++) {
			Mass[i*high + j] = 0;
		};
	};
}
SummMatr::~SummMatr()
{
}
void SummMatr::set_SummMatr(int* p_Mass, int p_size, int p_high)
{

	size = p_size;
	high = p_high;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < high; j++) {
			Mass[i*high + j] = p_Mass[i*high + j];
		};
	};

}
void SummMatr::input()
{
	int new_size;
	std::cin >> new_size;
	int new_high;
	std::cin >> new_high;
	if (new_high > 1 && new_high < 10 && new_size > 1 && new_size < 10)
	{
		for (int i = 0; i < new_size; i++) {
			for (int j = 0; j < new_high; j++) {
				std::cin >> Mass[i*new_high + j];
			}
		}
	}
	size = new_size;
	high = new_high;

}
int SummMatr::get_size() {
	return size;
}
int SummMatr::get_high()
{
	return high;
}
int SummMatr::getElement(int siz, int hig)
{
	if (siz<size && hig<high && siz>-1 && siz>-1)
	{
		return Mass[siz*high + hig];
	}
	std::cout << "Connot get elenent. Index Error!\n";
	return	-1;
}
void SummMatr::print()
{
	std::cout << "Оператор Вывод \n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < high; j++) {
			std::cout << Mass[i*high + j] << "\t";

		}
		std::cout << std::endl;
	}

}



SummMatr & SummMatr::operator=(SummMatr B)
{
	delete[] Mass;
	Mass = new int[B.get_size()*B.get_high()];
	for (int i = 0; i < B.get_size(); i++) {
		for (int j = 0; j < B.get_high(); j++) {
			Mass[i*B.get_high() + j] = B.getElement(i, j);
		}
	}
	size = B.get_size();
	high = B.get_high();
	return *this;
}

void SummMatr::Transp() {
	/*int t;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < high; j++) {
			t = Mass[i][j];
			Mass[i][j] = Mass[j][i];
			Mass[j][i] = t;

		}
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < high; ++j)
			{
				std::cout << Mass[i][j];
				std::cout << '\n';
			}
		}
	}*/
}

int main()
{
	setlocale(LC_ALL, "Rus");

	SummMatr matrA, matrB, matrC;
	matrA.input();
	matrA.print();
	matrB.input();
	matrB.print();
	matrC = matrA + matrB;
	matrC.print();

	return 0;

	system("pause");
	std::cout << "Hello World!\n";
}
















//
//double fnc1(double p1, char p2)  
//{
//std::cout << "fnc1(int double, char)" << std::endl;
//return p1 + p2;
//}
////  перегрузка 
//int fnc1(int p1, char p2)
//{
//	std::cout << "fnc1(int double, char)" << std::endl;
//	return p1 + p2; 
//}


//Компилятор ищет точные совпадение типов аргументов, если он не нашел, точные совпадения, то он пытается  использовать приведение типов (char->int)
//и снова ищет совпадения. Если не нашел, использует стандартные преобразование типов (все указатели void, float-> double,double->int, и т.д.)
//при перегрузки может возникнуть ситуация, что компилятор не будет знать какую функцию выбрать. 




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
// перегрузкой называется объявление несколько функций методов классов и операторов, которые тоже являються функциями с одинаковым именами, но разными набором аргументов.
// если функция различаються только по выходному порамитру, то это перегрузкой не явлется.