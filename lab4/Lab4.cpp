

#include "pch.h"
#include <iostream>

// 5. ПЕРЕДАЧА В ФУКНЦИЮ МАССИВОВ
// fnc1(double a[размер_массива]);

//// ПЕРЕДАЧА МАССИВОВ В ФУНКЦИЮ
//void fnc4_1(int matr[3][3]);
//void fnc4_2(int matr[][3]);
//void fnc4_3(int(&matr)[3][3]);
//void fnc4_4(int ** matr);
////Само тело функции везде одинаковое void fnc4_3(int(&matr)[3][3])
{
matr[1][1] = 10; // какие-то действия с массивом и его элементами
return;
}

void typedata(int numb) {
	std::cout << "Size of char : " << sizeof(char) << "     " << (pow(2, sizeof(char) * 8.0) - 1) << std::endl;
	std::cout << "Size of int : " << sizeof(int) << "     " << (pow(2, sizeof(int) * 8.0 - 1) - 1) << std::endl;
	std::cout << "Size of short int : " << sizeof(short int) << "     " << (pow(2, sizeof(short int) * 8.0 - 1) - 1) << std::endl;
	std::cout << "Size of long int : " << sizeof(long int) << "     " << (pow(2, sizeof(unsigned long int) * 8.0) - 1) << std::endl;
	std::cout << "Size of float : " << sizeof(float) << "     " << (pow(2, sizeof(float) * 8.0 - 1) - 1) << std::endl;
	std::cout << "Size of double : " << sizeof(double) << "     " << (pow(2, sizeof(double) * 8.0 - 1) - 1) << std::endl;
	std::cout << "Size of bool : " << sizeof(bool) << "     " << (pow(2, sizeof(bool) * 8.0) - 1) << std::endl;
}
void sheiker(int numb) {
	int masraz = 10;
	int mass[10] = { 12,-12,-15,9,4,3,7,1,9,10 };
	int low, high;
	int cachee;
	low = 0;
	high = masraz - 1;
	while (low < high)
	{
		for (int i = 0; i > masraz; i++) {
			if (mass[i] > mass[i + 1]) {
				cachee = mass[i];
				mass[i] = mass[i + 1];
				mass[i + 1] = cachee;
			}
			high = high + 1;
		}
		for (int j = 0; j < masraz; j++) {
			if (mass[j] < mass[j - 1]) {
				cachee = mass[j];
				mass[j] = mass[j - 1];
				mass[j - 1] = cachee;
			}
			low = low - 1;
		}

	}
	for (int i = 0; i < masraz; i++) {
		std::cout << mass[i] << " " << std::endl;
	}
}
void puz(int numb) {
	int a = 5;
	int b[] = { 5,-12,-15,9,4 };
	std::cout << "enter the numders" << std::endl;
	int cache;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a - i - 1; j++) {
			if (b[j] > b[j + 1]) {
				cache = b[j];
				b[j] = b[j + 1];
				b[j + 1] = cache;
			}
		}
	}
	for (int i = 0; i < a; i++) {
		std::cout << b[i] << " " << std::endl;
	}

}
void Shif(int numb) {

	int k = 22;
	int n = 33;
	int s;
	char str[200] = { "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ" };
	std::cout << "Строка до шифрования " << std::endl;
	std::cout << str << std::endl;
	for (int i = 0; i < strlen(str); i++) {

		str[i] = (str[i] + k) % (n + __toascii('А'));
	}
	std::cout << "Строки после шифровния " << std::endl;
	std::cout << str;
	for (int i = 0; i < strlen(str); i++) {

		str[i] = (str[i] - k - (n + __toascii('А'))) % (n + __toascii('А'));
	}
	std::cout << '\n' << "Расшифрованная строка: " << '\n' << std::endl;
	std::cout << str << std::endl;

	//
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int h;
	std::cin >> h;
	typedata(h);
	sheiker(h);
	puz(h);
	Shif(h);


}