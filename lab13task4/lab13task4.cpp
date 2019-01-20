#include <iostream>
#include <list>
/*
Список представляет собой контейнер, который поддерживает быструю вставку и удаление элементов из любой позиции в контейнере. 
Быстрый произвольный доступ не поддерживается. Он реализован в виде двусвязного списка.
*/
int main() 
{
	std::cout << "lab13task4\n" << std::endl;
	std::cout << "Input List\n" << std::endl;
	std::list <int> mylist;
	int checker = 1;
	int a;
	while (checker == 1)//input
	{
		std::cin >> a;
		mylist.push_back(a);
		std::cout<<std::endl;
		std::cout << "More?(1=yes, 0=no) ";
		std::cin >> checker;
	}
	std::cout << "This is the list:\t" << std::endl;
	std::list <int> ::iterator it;
	for (it = mylist.begin(); it != mylist.end(); it++)//output 
	{
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
	mylist.pop_back();
	std::cout << "Deleted last element:\t" << std::endl;
	for (it = mylist.begin(); it != mylist.end(); it++)//output 
	{
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
	mylist.pop_front();
	std::cout << "Deleted first element:\t" << std::endl;
	for (it = mylist.begin(); it != mylist.end(); it++)//output 
	{
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
	mylist.sort();//ascending
	std::cout << "Ascending sort:\t" << std::endl;
	for (it = mylist.begin(); it != mylist.end(); it++)//output 
	{
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
	mylist.sort(std::greater<int>());//descending
	std::cout << "Descending sort:\t" << std::endl;
	for (it = mylist.begin(); it != mylist.end(); it++)//output 
	{
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}