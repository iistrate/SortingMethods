#include <iostream>

using std::cout;
using std::endl;

void print(int *array, const int length);
int insertion(int *array, const int length);
int selection(int *array, const int length);

int main() {
	int array[10] = { 99, 22, 3, 8, 5, 4, 7, 11, 9, 78 };

	//begin
	cout << "Array before: " << endl;
	print(array, 10);
	
	cout << "\n" << insertion(array, 10) << " nr of swaps \n" << endl;

	cout << "Array after: " << endl;
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


//21 nr of swaps
int selection(int *array, int length) {
	//holds each element
	int swaps = 0;
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
				swaps++;
			}
			j++;
		}
	}
	return swaps;
}
//nr of swaps
int insertion(int *array, const int length) {
	int swaps = 0;
	int j;
	int temp;

	for (int i = 1; i < length; i++) {
		//start at the 2nd element for comparison reasons
		j = i;
		while (j > 0 && array[j - 1] > array[j]) {
			//if the current element is smaller than the previous swap positions
			temp = array[j - 1];
			array[j - 1] = array[j];
			array[j] = temp;
			swaps++;
			j--;
		}
	}
	return swaps;
}