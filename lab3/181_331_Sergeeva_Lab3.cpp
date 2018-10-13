#include "pch.h"
#include <iostream>

int main()
{
	int a; // начало задания 1 
	double dbl;
	int *ptr_int = &a;
	double * ptr_dbl = &dbl;

	std::cout << "int pointer size = " << sizeof(ptr_int) << std::endl;
	std::cout << "double pointer size = " << sizeof(ptr_dbl) << std::endl;
	std::cout << "char pointer size = " << sizeof(char*) << std::endl;
	std::cout << "long long pointer size = " << sizeof(long long *) << std::endl;
	std::cout << "bool pointer size = " << sizeof(bool *) << std::endl; // конец задания 1 


	char arr[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', // начало задания 2 
	'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	char arr1[6] = { 'v', 'i', 'k', 't', 'o', 'r' };
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 26; j++) {
			if (arr1[i] == arr[j]) {
				arr1[i] = arr[(j + 3) % 26];
				break;
			}
		}
	}
	std::cout << "viktor = " << arr1[0] << arr1[1] << arr1[2] << arr1[3] << arr1[4] << arr1[5] << std::endl; // конец задания 2 


	int arr2[5] = { 6, 3, 5, 2, 4 }; // начало задания 3 
	std::cout << arr2[0] << arr2[1] << arr2[2] << arr2[3] << arr2[4] << std::endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr2[j] > arr2[j + 1]) {
				int t = arr2[j];
				arr2[j] = arr2[j + 1];
				arr2[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		std::cout << arr2[i];
	}
	std::cout << ' ' << std::endl; // конец задания 3 


	int arr3[10] = { 5, 10, 3, 6, 7, 1, 4, 2, 9, 8 }; // начало задания 4
	std::cout << arr3[0] << arr3[1] << arr3[2] << arr3[3] << arr3[4] << arr3[5] << arr3[6] << arr3[7] << arr3[8] << arr3[9] << std::endl;
	for (int i = 0; i < 5; i++) {
		int n = 0;
		int kn = 9;
		for (int j = n; j < kn; j++) {
			if (arr3[n] > arr3[n + 1]) {
				int t = arr3[n];
				arr3[n] = arr3[n + 1];
				arr3[n + 1] = t;
			}
			n = n + 1;
			if (arr3[kn - 1] > arr3[kn]) {
				int t = arr3[kn - 1];
				arr3[kn - 1] = arr3[kn];
				arr3[kn] = t;
			}
			kn = kn - 1;
		}
	}
	for (int i = 0; i < 10; i++) {
		std::cout << arr3[i];
	} // конец задания 4

	return 0;
}
