#include <iostream>

using std::cout;
using std::endl;

void print(int *array, int length);
void insertion(int *array, int length);

int main() {
	int array[10] = { 99, 22, 3, 8, 5, 4, 7, 11, 9, 78 };

	print(array, 10);
	insertion(array, 10);
	print(array, 10);

	system("pause");

	return 0;
}

void print(int *array, int length) {
	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void insertion(int *array, int length) {
	int cursor;
	int j;
	//insertion
	for (int i = 0; i < length; i++) {
		j = i;
		while (j > 0 && array[j - 1] > array[j]) {
			cursor = array[j - 1];
			array[j - 1] = array[j];
			array[j] = cursor;
			j = j - 1;
		}
	}
}