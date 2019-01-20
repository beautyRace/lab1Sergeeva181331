// LabProbnic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>

class shifr {
public:
	shifr();
	~shifr();

	void input();
	void clear();
	void add();
	void cut();

private:
	char *arr;
	int stroka;
};

int main()
{
	setlocale(LC_ALL, "rus");
	shifr A;
	A.input();
}

shifr::shifr()
{
}

shifr::~shifr()
{
}

void shifr::input()
{
	std::cout << "введите длину строки: \t";
	std::cin >> stroka;
	std::cout << "введите элементы: \n";
	for (int i = 0; i < stroka; i++) {
		std::cin >> arr[i];
	}
}

void shifr::clear()
{
}

void shifr::add()
{
}

void shifr::cut()
{
}
