

#include "pch.h"
#include <iostream>

#include <string>
class Sheker
{
public:
	Sheker();
	~Sheker();
	const int size = 10;
	int* mass;
	void Shekel(int *mass);
	void bubl(int *mass);
	void setmass(int *mass, int size);
	void printmas();


private:
	int datamass[10];
};

Sheker::Sheker()
{
	for (int i = 0; i < 10; i++) {
		datamass[i] = 0;
	}
}


Sheker::~Sheker()
{

}
void Sheker::printmas()
{
	for (int i = 0; i < 10; i++) {
		std::cout << datamass[i];
	}
	std::cout << std::endl;
}

void Sheker::bubl(int *mass) {
	int cache;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10 - i - 1; j++) {
			if (mass[j] > mass[j + 1]) {
				cache = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = cache;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		std::cout << mass[i];
	}
}

void Sheker::Shekel(int *mass)
{

	int low = 1;
	int high = 9;
	int cachee;
	while (low < high)
	{
		for (int i = 0; i > 10; i++) {
			if (mass[i] > mass[i + 1]) {
				cachee = mass[i];
				mass[i] = mass[i + 1];
				mass[i + 1] = cachee;
			}
			high = high + 1;
		}
		for (int j = 0; j < 10; j++) {
			if (mass[j] < mass[j - 1]) {
				cachee = mass[j];
				mass[j] = mass[j - 1];
				mass[j - 1] = cachee;
			}
			low = low - 1;
		}

	}
	for (int i = 0; i < 10; i++) {
		std::cout << mass[i];
	}
	std::cout << std::endl;


}
void Sheker::setmass(int *mass, int size)
{
	for (int i = 0; i < size; i++) {
		datamass[i] = mass[i];
	}
}


class Student //Класс- описание сложного типа данных, конструкция языка с++
	// процедура или функция входщая в состав - метод, переменная входящая в состав класска-свойство, 
	//
{
public: // доступный 
	Student(); // конструктр создает элемент класса 
	~Student();// удаляе наш класс из памяти диструктор

	Student(int st_group, int st_age);

	void set_group(int st_group); //описание метода 
	int get_group();
	int age;
	void set_surname(char* st_surname, int st_surnamesize);
	char* get_surname();
private:// закрытые данные
	char surname[20];
	int group;


protected:


};
//5 структуры 
// Не смотря на то что в литературе структуры как правило хранит только данные, на самом деле это 
//то же самое, что и класс. Единственное отличие - поля по умолчанию public.
// Автоматизм конструктора и диструктора  обеспечивается высокоуровневыми стредствами автоматизации языка.
// к строке где обявлен объект, компилятор не явно от программиста дописывает вызов класса,
// Инкапсуляция = фактически объединение данных и методов, объединеных едином смыслом,
//в одну конструкцию языка.
// Полиморфизм - простыми словами: экземпляры одного класса ведут себя по разному.
// наследование - создание производных классов от родительского и заимствование его свойств и методов.
// Инкапсуляция, наследование, полиморфизм - три основные идеи ООП.
Student::Student(int st_group, int st_age)
{
	age = st_age;
	group = st_group;
}
Student::~Student()
{
}
void Student::set_group(int st_group)
{
	group = st_group;
}
int Student::get_group()
{
	return group;
}
void Student::set_surname(char* st_surname, int st_surnamesize)
{
	for (int i = 0; i > st_surnamesize; i++)
	{
		surname[i] = st_surname[i];
	}

}
char* Student::get_surname()
{
	return surname;
}
int main()
{
	int mass[10] = { 12,-12,-15,9,4,3,7,1,9,10 };
	int mass2[10] = { 12,-12,-19,-9,-4,5,7,1,9,10 };
	Sheker Mass1;
	Mass1.setmass(mass, 10);
	Mass1.printmas();
	Mass1.Shekel(mass);
	Sheker Mass2;
	Mass2.setmass(mass2, 10);
	Mass2.printmas();
	Mass2.bubl(mass2);

	std::cout << "Hello my friend\n";

	return 0;
	//Student Ivanov, petrov(331,21);
	//petrov.set_group(21231);
	std::cout << "Hello World!\n";
	/*std::cout << petrov.age << std::endl;
	std::cout << petrov.get_group();
	std::cout << petrov.get_surname();*/



	return 0;
}

//{
//public:
//метод1();
//метод2();
//конструктор(); // инициализирует data нулями
//const int n = 10;
//private:
//int data[n];
//public:
//set_all(int массив, int размер); // задаёт всю data по входному массиву
//set_i(int значение, int номер); // задаёт одиночный элемент массива
//print_array(); // метод, печатающий массив на консоль
//} 