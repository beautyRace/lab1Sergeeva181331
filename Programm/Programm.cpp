#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class MassOfSimbols {
private:
	int n; //длинна массива символов
	char *mass; //указатель на массив

public:
	//конструктор без параметров
	MassOfSimbols() {
		n = 0;
		mass = new char[n];
	}
	//коструктор, в котором в массив класса копируется массив из параметра
	MassOfSimbols(char array[], int length) {
		n = length;
		mass = new char[n];
		for (int i = 0; i < n; i++) {
			mass[i] = array[i];
		}
	}
	//конструктор, который копирует содержимое из объекта аналогичного класса
	MassOfSimbols(const MassOfSimbols & m) {
		n = m.n;
		mass = new char[n];
		for (int i = 0; i < n; i++) {
			mass[i] = m.mass[i];
		}
	}
	//конструктор, копирующий содержимое из std::string;
	MassOfSimbols(string s) {
		n = s.length(); //определяем длинну строки
		mass = new char[n];//выделяем память для массива
		for (int i = 0; i < n; i++) {
			mass[i] = s[i];
		}
	}
	//деструктор
	~MassOfSimbols() {
		if (mass) {
			delete[] mass;
		}
	}
	char* getMass() {
		return mass;
	}
	int getN() {
		return n;
	}
	//демонстриует поля класса
	void show() {
		cout << "Count of simbols = " << n << endl;
		for (int i = 0; i < n; i++) {
			cout << mass[i] << endl;
		}
	}
	//сбрасывает длину строки в ноль
	void clear() {
		n = 0;
		delete[] mass;
		mass = new char[n];
	}
	//метод add() добавляет символы в конец массива
	void add(string s) {
		string myString(mass, n); //копируем символьный массив mass в строку myString
		delete[] mass;
		n = n + s.length();
		mass = new char[n];
		for (int i = 0; i < n; i++) {
			if (i < myString.length()) {
				mass[i] = myString[i];
			}
			else
			{
				mass[i] = s[i - myString.length()];
			}
		}
	}
	void add(char array[], int length) {
		string myString(mass, n);
		delete[] mass;
		n = n + length;
		mass = new char[n];
		for (int i = 0; i < n; i++) {
			if (i < myString.length()) {
				mass[i] = myString[i];
			}
			else
			{
				mass[i] = array[i - myString.length()];
			}
		}

	}
	//вставляет на заданную позицию внутри строки указанную в параметрах последовательность символов
	void insert(string s, int pozition) {
		string myString(mass, n);
		myString.insert(pozition - 1, s);
		delete[] mass;
		n = n + s.length();
		mass = new char[n];
		for (int i = 0; i < n; i++) {
			mass[i] = myString[i];
		}
	}
	void insert(char array[], int length, int pozition) {
		string myString(mass, n);
		string s(array, length);
		myString.insert(pozition - 1, s);
		delete[] mass;
		n = n + length;
		mass = new char[n];
		for (int i = 0; i < n; i++) {
			mass[i] = myString[i];
		}
	}
	//удаляет с заданной позиции заданное в параметрах количество символов
	void cut(int pozition, int count) {
		string myString(mass, n);
		delete[] mass;
		myString.erase(pozition - 1, count);
		n = n - count;
		mass = new char[n];
		for (int i = 0; i < n; i++) {
			mass[i] = myString[i];
		}
	}
	//осуществляет поиск последовательности символов (*char) либо строку (std::sting) в строке класса
	void find(string s) {
		string myString(mass, n);
		int p = myString.find(s);
		if (p == -1) {
			cout << "Not found!" << endl;
		}
		else {
			cout << "This string start with simbol number " << p + 1 << endl;
		}
	}
	void find(char array[], int length) {
		string myString(mass, n);
		string s(array, length);
		int p = myString.find(s);
		if (p == -1) {
			cout << "Not found!" << endl;
		}
		else {
			cout << "This string start with simbol number " << p + 1 << endl;
		}
	}
	//для записи в файл
	void save(string fileName) {
		string myString(mass, n);
		ofstream fout(fileName);
		fout << myString << endl;
		fout.close();
	}
	//для чтения из файла
	void load(string fileName) {
		ifstream fin(fileName);
		if (!fin) {
			cout << "File not open!" << endl;
		}
		else {
			string s;
			getline(fin, s);
			n = s.length();
			delete[] mass;
			mass = new char[n];
			for (int i = 0; i < n; i++) {
				mass[i] = s[i];
			}
		}
	}
};

//перегрузка оператора плюс
MassOfSimbols operator + (MassOfSimbols &obj1, MassOfSimbols &obj2) {
	int n = obj1.getN() + obj2.getN();
	char *m = new char[n];
	for (int i = 0; i < n; i++) {
		if (i < obj1.getN()) {
			m[i] = obj1.getMass()[i];
		}
		else
		{
			m[i] = obj2.getMass()[i - obj1.getN()];
		}
	}
	MassOfSimbols obj(m, n);
	return obj;
}

//перегрузка оператора <<
ostream& operator << (ostream &s, MassOfSimbols obj) {
	string str(obj.getMass(), obj.getN());
	s << "Count of simbols = " << obj.getN() << endl << "Array (string): " << str << endl;
	return s;
}

int main() {
	//проверка коструктора, в котором в массив класса копируется массив из параметра
	char array[] = { 'a', 's', 's', 'd' };
	int count = sizeof(array) / sizeof(char);
	MassOfSimbols myObject1(array, count);
	myObject1.show();

	//проверка конструктора копирования
	MassOfSimbols m(myObject1);
	m.show();

	//прверка конструктора, копирующего содержимое из std::string;
	string str = "dkthdnsl222";
	MassOfSimbols myObject2(str);
	myObject2.show();

	//проверка метода clear()
	myObject1.clear();
	myObject1.show();

	//проверка метода add(string s), add(char array[], int length)
	MassOfSimbols myObject3("mybook");
	myObject3.add("ku-ku");
	myObject3.show();
	myObject3.add(array, count);
	myObject3.show();

	//проверка метода insert()
	MassOfSimbols myObject4("my_mother");
	myObject4.insert("dad_and_", 4);
	myObject4.show();
	myObject4.insert(array, count, 2);
	myObject4.show();

	//проверка метода cut()
	MassOfSimbols myObject5("my_mother_and_dad");
	myObject5.cut(4, 11);
	myObject5.show();

	//проверка на защищенность от утечки памяти (в режиме debug)
	MassOfSimbols myObject6 = MassOfSimbols();
	for (int i = 0; i < 10000; i++) {
		myObject6.add("ku-ku-ku-ku");
		myObject6.insert("dad_and_", 4);
		myObject6.clear();
	}

	//проверка перегрузки оператора +
	MassOfSimbols myObject7("name");
	MassOfSimbols myObject8("Kate");
	(myObject7 + myObject8).show();

	//проверка перегрузки оператора <<
	cout << myObject8;

	//проверка метода find()
	MassOfSimbols myObject9("123456789");
	myObject9.find("567");
	myObject9.find("ghgj");
	MassOfSimbols myObject10("123456assd789");
	myObject10.find(array, count);

	//проверка метода save()
	myObject5.save("file1.txt");

	//проверка метода load()
	myObject10.load("file.txt");
	cout << myObject10;

	return 0;
}