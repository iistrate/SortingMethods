//gen libraries
#include <iostream>
//user libraries
#include "Heap.h"

//prints array
void print(int *array, const int length);

//sort by insertion sort; returns nr of swaps
int insertion(int *array, const int length);
//sort by selection sort; returns nr of swaps
int selection(int *array, const int length);
//sort by bubble sort; returns nr of swaps
int bubble(int *array, const int length);
//sort by shell sort; returns nr of swaps
int shell(int *array, const int length);

//our heap
Heap Heapster;

int main(void) {
	//our working array
	const int length = 15;
	int array[length] = { 99, 22, 3, 8, 5, 4, 7, 11, 9, 78, 25, 909, 76, 55, 1 };

	//build heap
	Heap Heapster;
	Heapster.heapify(array, length);

	//begin
	cout << "Array before: " << endl;
	print(array, length);
	

	cout << "\nHeap sort ";
	Heapster.print(Heapster.getRoot());
	cout << endl;

	cout << "\nThere were " << shell(array, length) << " nr of swaps before sorting completed. \n" << endl;

	cout << "Array after: " << endl;
	print(array, length);

	system("pause");

	return 0;
}

//print content of array
void print(int *array, int length) {
	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

//44 nr of swaps
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
//44 nr of swaps
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
//44 nr of swaps
int bubble(int *array, const int length) {
	int swaps = 0;
	int temp;
	bool swapped = true;
	//while we swapped
	while (swapped) {
		swapped = false;
		for (int i = 0; i < length; i++) {
			//make sure we don't exceed array length
			if (i + 1 < length) {
				//if larger then swap
				if (array[i] > array[i + 1]) {
					temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;
					swaps++;
					swapped = true;
				}
			}
		}
	}
	return swaps;
}
//18 nr of swaps
int shell(int *array, const int length) {
	int swaps = 0;
	int temp;
	//initially divide our length by 2; then each iteration half the gap
	for (int gap = length / 2; gap != 0; gap /= 2) {
		//right side of array ++ < length
		for (int i = gap; i < length; i++) {
			//left side of array ++ < beginning of right side
			for (int j = i - gap; j >= 0 && j < i && array[j] > array[j+gap]; j -= gap) {
				temp = array[j];
				array[j] = array[j+gap];
				array[j+gap] = temp;
				swaps++;
			}
		}
	}
	return swaps;
}
