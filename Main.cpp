//gen libraries
#include <iostream>
#include <vector>
//user libraries
#include "Heap.h"

using std::vector;

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

//sort by merge sort; returns nr of swaps
int merge(int *array, const int length);
void split(vector < int >&);

//our heap
Heap Heapster;

int main(void) {
	//our working array
	const int length = 16;
	int array[length] = { 99, 22, 3, 8, 5, 4, 7, 11, 9, 78, 25, 909, 76, 55, 1, 2};

	//build heap
	Heap Heapster;
	Heapster.heapify(array, length);

	//begin
	cout << "Array before: " << endl;
	print(array, length);
	

	//cout << "\nHeap sort ";
	//Heapster.print(Heapster.getRoot());
	//cout << endl;

	cout << "\nThere were " << merge(array, length) << " nr of swaps before sorting completed. \n" << endl;

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
//00 nr of swaps
int merge(int *array, const int length) {
	int swaps = 0;
	//to vectors
	vector < int > varr;
	for (int i = 0; i < length; i++) {
		varr.push_back(array[i]);
	}
	//while there's ints to break apart do so
	split(varr);
	//back to array
	for (int i = 0; i < length; i++) {
		array[i] = varr[i];
	}
	return swaps;
}
void split(vector < int > &orig) {
	vector < int > left;
	vector < int > right;
	//while our vector is greater than one; otherwise it is considered to be sorted
	if (orig.size() > 1) {
		//get length of original vector
		int length = orig.size();
		//get middle of original vector
		int mid = orig.size() / 2;
		//split vector into left and right 
		left.assign(orig.begin(), orig.end() - mid);
		right.assign(orig.end() - mid, orig.end());
		//keep breaking stuff up while we're being called
		split(left);
		split(right);
		
		int i = 0, j = 0, k = 0;
		while (left.size() != j && right.size() != k) {
			if (left[j] < right[k]) {
				orig[i] = left[j];
				i++;
				j++;
			}
			else {
				orig[i] = right[k];
				i++;
				k++;
			}
		}
		while (left.size() != j)
		{
			orig[i] = left[j];
			i++;
			j++;
		}
		while (right.size() != k)
		{
			orig[i] = right[k];
			i++;
			k++;
		}
	}
}