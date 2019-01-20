#include<iostream>
#include<map>
#include<string>
/*
map � ��������������� ������������� ���������, ������� �������� ���� ����-�������� � ���������������� �������. 
������� ������ ������� �������� ��������� Compare.
��������� map, ����� ����� �� ��������� ����������, ����� ��� vector, list, deque, �� � ��������� ��������. 
� ���� ��������� ����� �������� ����� ��� ��������.
*/
int main() 
{
	std::map <std::string, int> myFirstMap = { { "Mother", 39 },
								 { "Father", 41 },///map ���� ����������������
								 { "Brother", 17 },
								 { "Sister", 22 } };

	///����� ���� ������������������ map �� �����
	std::cout << "Default example of map:" << std::endl;
	for (auto it = myFirstMap.begin(); it != myFirstMap.end(); ++it)
	{
		std::cout << it->first << " : " << it->second << std::endl;
	}
	std::cout << std::endl;
	int a;
	char c;
	int checker = 1;
	std::map <char, int> mySecondMap;
	while (checker == 1)//input
	{
		std::cout << "Name:  ";
		std::cin >> c;
		std::cout << "Value:  ";
		std::cin >> a;
		mySecondMap.insert(std::pair<char, int>(c, a)); //map ���������������� �� ����
		std::cout << std::endl;
		std::cout << "More?(1=yes, 0=no) ";
		std::cin >> checker;
	}
	std::cout << std::endl;
	std::cout <<"Let's look what you've done!"<< std::endl;
	for (auto it = mySecondMap.begin(); it != mySecondMap.end(); ++it)
	{
		std::cout << (*it).first << " : " << (*it).second << std::endl;
	}
	std::cout << std::endl;
	std::cout << "I know You want to add something!"<<std::endl;
	std::cout << "Name:  ";
	std::cin >> c;
	std::cout << "Value:  ";
	std::cin >> a;
	mySecondMap.insert(std::pair<char, int>(c, a));
	std::cout << std::endl;
	std::cout << "Look at this! " << std::endl;
	for (auto it = mySecondMap.begin(); it != mySecondMap.end(); ++it)
	{
		std::cout << (*it).first << " : " << (*it).second << std::endl;
	}
	std::cout << std::endl;
	mySecondMap.erase(a);
	mySecondMap.erase(c);
	std::cout << "It's a trap! I erased this! " << std::endl;
	for (auto it = mySecondMap.begin(); it != mySecondMap.end(); ++it)
	{
		std::cout << (*it).first << " : " << (*it).second << std::endl;
	}
	system("pause");
	return 0;
}
