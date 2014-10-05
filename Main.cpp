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
	//holds each element
	int temp;
	int j;
	for (int i = 0; i < length; i++) {
		//look at the next spot in the array
		j = i + 1;
		//while we're not done comparing temp to every single item in the list starting from the +1 item
		while (j < length) {
			//compare elements 
			if (array[j] < array[i]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
	}
}