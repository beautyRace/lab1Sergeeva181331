#include "pch.h"
#include <iostream>

template <typename TT>
class myList {
public:
	TT element;
	myList* prev;
	myList* next;

	myList();
	myList(TT el);

	myList<TT> next_elem() {
		return next;
	}
};

//double myFunc() {}

int main()
{
	int* arrI, sizeI = 5, sizeCh = 5, sizeD = 5;
	char* arrCh;
	double* arrD;

	arrI = new int[sizeI];
	arrCh = new char[sizeCh];
	arrD = new double[sizeD];

	/*std::cout << "int = " << myFunc(arrI, sizeI);
	std::cout << "char = " << myFunc(arrCh, sizeCh);
	std::cout << "double = " << myFunc(arrD, sizeD);*/
	return 0;
}

template<typename TT>
myList<TT>::myList()
{
	prev = NULL;
	next = NULL;
}

template<typename TT>
myList<TT>::myList(TT el)
{
}
