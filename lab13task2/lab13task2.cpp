#include <iostream>
#include <string> 
#include <queue>

int main()
{
	std::cout << "lab13task2\n" << std::endl;
	setlocale(LC_ALL, "rus");
	int checker = 1;
	int classnumber;
	std::string surname;
	std::queue <std::string> class9;
	std::queue <std::string> class10;
	std::queue <std::string> class11;
	std::cout << "Введите данные об учениках" << std::endl;
	while (checker==1)
	{
		std::cout << "Класс - ";
		std::cin >> classnumber;
		std::cout << "Фамилия - ";
		std::cin >> surname;
		if (classnumber == 9)
			class9.push(surname);
		if (classnumber == 10)
			class10.push(surname);
		if (classnumber == 11)
			class11.push(surname);
		std::cout << std::endl;
		std::cout << "More?(1=yes, 0=no) ";
		std::cin >> checker;
	}
	std::cout << "9 класс" << std::endl;
	while (class9.empty()==false)
	{
		std::cout << class9.front()<<std::endl;
		class9.pop();
	}
	std::cout << "10 класс" << std::endl;
	while (class10.empty()==false)
	{
		std::cout << class10.front() << std::endl;
		class10.pop();
	}
	std::cout << "11 класс" << std::endl;
	while (class11.empty()==false)
	{
		std::cout << class11.front() << std::endl;
		class11.pop();
	}
	system("pause");
	return 0;
}