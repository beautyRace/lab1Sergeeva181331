#include<iostream>
#include<set>
#include <iterator>
/*
Set � ������������� ���������, ������� �������� ������������� ����� ���������� �������� ���� Key. 
���������� ��������� �������������� ����������� ������� Compare � ������ ���������.
*/
int main()
{
	std::cout << "lab13task5\n" << std::endl;
	std::set<char> mySet; // �������� ������ ���������
	// ��������� �������� � ���������
	//����
	mySet.insert('L');
	mySet.insert('o');
	mySet.insert('v');
	mySet.insert('e');
	//�����
	copy(mySet.begin(), mySet.end(), std::ostream_iterator<char>(std::cout, " "));
	std::cout << std::endl;
	std::cout << "As you see, set autosorts. But you know, what's the word up there..." << std::endl;
	//����������
	mySet.insert('I');
	mySet.insert('U');
	std::cout << "I added 2 elements...\t";
	copy(mySet.begin(), mySet.end(), std::ostream_iterator<char>(std::cout, " "));	
	std::cout << std::endl;
	//��������
	mySet.erase('I');
	mySet.erase('U');
	std::cout << "I erased them...\t";
	copy(mySet.begin(), mySet.end(), std::ostream_iterator<char>(std::cout, " "));
	std::cout << std::endl;
	system("pause");
	return 0;
}