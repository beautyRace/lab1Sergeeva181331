class lab5 {
public:
	void do1 {
		int arr2[5] = { 6, 3, 5, 2, 4 };
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
		std::cout << ' ' << std::endl;
	}

	void do2 {
		int arr3[10] = { 5, 10, 3, 6, 7, 1, 4, 2, 9, 8 };
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
		}
	}

	lab5 {
		for (int i = 0; i < n; i++) {
			data[i] = 0;
		}
	}
	const int n = 10;
private:
	int data[n];
public:
	set_all(int[] sourceArr, int sourceArrLength) {
		for (int count = 0; count < data.length; count++) {
			data[count] = sourceArr[count];
		}
	}

	set_i(int value, int index) {
		if (data.length > index - 1) {
			data[index] = value;
		}
	}

	print_array() {
		for (int i = 0; i < data.length; i++) {
			std::cout << data[i];
		}
	}
}
