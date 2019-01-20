
#include "pch.h"
#include <iostream>


// шаблон для своего типа данных (объединяет все типы), чтобы не описывать каждый
template <typename MyType>
MyType myFunc(MyType*arr, int size) {
	MyType res = arr[0];
	for (int iter = 0; iter < size; iter++) {
		if (res < arr[iter])
			res = arr[iter];
	}
	return res;
}// шаблон

int main()
{
	int * arrI, sizeI = 5, sizeCh = 5, sizeD = 5;
	char * arrCh;
	double * arrD;

	arrI = new int[sizeI];
	arrCh = new char[sizeCh];
	arrD = new double[sizeD];

	std::cout << "int=" << myFunc(arrI, arrI);
	std::cout << "char=" << myFunc(arrCh, arrCh);
	std::cout << "double=" << myFunc(arrD, arrD);

	return 0;
}


