#include<iostream>
#include<set>
#include <iterator>
/*
Set Ч ассоциативный контейнер, который содержит упор€доченный набор уникальных объектов типа Key. 
—ортировка элементов осуществл€етс€ применением функции Compare к ключам множества.
*/
int main()
{
	std::cout << "lab13task5\n" << std::endl;
	std::set<char> mySet; // объ€вили пустое множество
	// добавл€ем элементы в множество
	//ввод
	mySet.insert('L');
	mySet.insert('o');
	mySet.insert('v');
	mySet.insert('e');
	//вывод
	copy(mySet.begin(), mySet.end(), std::ostream_iterator<char>(std::cout, " "));
	std::cout << std::endl;
	std::cout << "As you see, set autosorts. But you know, what's the word up there..." << std::endl;
	//добавление
	mySet.insert('I');
	mySet.insert('U');
	std::cout << "I added 2 elements...\t";
	copy(mySet.begin(), mySet.end(), std::ostream_iterator<char>(std::cout, " "));	
	std::cout << std::endl;
	//удаление
	mySet.erase('I');
	mySet.erase('U');
	std::cout << "I erased them...\t";
	copy(mySet.begin(), mySet.end(), std::ostream_iterator<char>(std::cout, " "));
	std::cout << std::endl;
	system("pause");
	return 0;
}