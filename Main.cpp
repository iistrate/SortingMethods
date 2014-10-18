//gen libraries
#include <iostream>
#include <vector>
#include <random>

//user libraries
#include "Heap.h"

using std::vector;

//prints array
void print(vector < int >);

//sort by insertion sort; returns nr of swaps
int insertion(vector < int >&);

//sort by selection sort; returns nr of swaps
int selection(vector < int >&);

//sort by bubble sort; returns nr of swaps
int bubble(vector < int >&);

//sort by shell sort; returns nr of swaps
int shell(vector < int >&);

//sort by merge sort; returns nr of swaps
int merge(vector < int >&);
void split(vector < int >&);

//sort by quicksort
int quickSort(vector < int >&, int, int);

//sort by bucketsort
int bucketSort(vector < int >&);
int getHighest(vector < int >);

//our heap
Heap Heapster;

int main(void) {
	//rand seed for quicksort c++11
	std::random_device rd;

	//our working array
	vector < int > varray = { 99, 22, 3, 8, 5, 4, 7, 11, 9, 78, 25, 909, 76, 55, 1, 2};

	//build heap
	Heap Heapster;
	Heapster.heapify(varray);

	//begin
	cout << "Array before: " << endl;
	print(varray);
	

	//cout << "\nHeap sort ";
	//Heapster.print(Heapster.getRoot());
	//cout << endl;

	cout << "\nThere were " <<  bucketSort(varray) << " nr of swaps before sorting completed. \n" << endl;
	cout << "Array after: " << endl;
	print(varray);

	system("pause");

	return 0;
}

//print content of array
void print(vector < int > varray) {
	for (int i = 0; i < varray.size(); i++) {
		cout << varray[i] << " ";
	}
	cout << endl;
}

int selection(vector < int >& varray) {
	//holds each element
	int swaps = 0;
	int temp;
	int j;
	for (int i = 0; i < varray.size(); i++) {
		//look at the next spot in the array
		j = i + 1;
		//while we're not done comparing temp to every single item in the list starting from the +1 item
		while (j < varray.size()) {
			//compare elements 
			if (varray[j] < varray[i]) {
				temp = varray[i];
				varray[i] = varray[j];
				varray[j] = temp;
				swaps++;
			}
			j++;
		}
	}
	return swaps;
}
int insertion(vector < int >& varray) {
	int swaps = 0;
	int j;
	int temp;

	for (int i = 1; i < varray.size(); i++) {
		//start at the 2nd element for comparison reasons
		j = i;
		while (j > 0 && varray[j - 1] > varray[j]) {
			//if the current element is smaller than the previous swap positions
			temp = varray[j - 1];
			varray[j - 1] = varray[j];
			varray[j] = temp;
			swaps++;
			j--;
		}
	}
	return swaps;
}
int bubble(vector < int >& varray) {
	int swaps = 0;
	int temp;
	bool swapped = true;
	//while we swapped
	while (swapped) {
		swapped = false;
		for (int i = 0; i < varray.size(); i++) {
			//make sure we don't exceed array length
			if (i + 1 < varray.size()) {
				//if larger then swap
				if (varray[i] > varray[i + 1]) {
					temp = varray[i];
					varray[i] = varray[i + 1];
					varray[i + 1] = temp;
					swaps++;
					swapped = true;
				}
			}
		}
	}
	return swaps;
}
//18 nr of swaps
int shell(vector < int >& varray) {
	int swaps = 0;
	int temp;
	//initially divide our length by 2; then each iteration half the gap
	for (int gap = varray.size() / 2; gap != 0; gap /= 2) {
		//right side of array ++ < length
		for (int i = gap; i < varray.size(); i++) {
			//left side of array ++ < beginning of right side
			for (int j = i - gap; j >= 0 && j < i && varray[j] > varray[j+gap]; j -= gap) {
				temp = varray[j];
				varray[j] = varray[j+gap];
				varray[j+gap] = temp;
				swaps++;
			}
		}
	}
	return swaps;
}
int merge(vector < int >& varray) {
	int swaps = 0;
	//while there's ints to break apart do so
	split(varray);
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
int quickSort(vector < int >& varray, int left, int right) {
	//random seed
	std::default_random_engine generator;
	//keep tabs on nr of swaps
	int static swaps = 0;
	//temp values & sorted index
	int temp = 0, sortedIndex = left;
	//left always is 0ish, right tends to go to 0 because of partioning, 
	//when that happens we know we're done partitioning and so we know everything is sorted
	if (right > left) {
		//get random pivot in range [left, right] c++11
		std::uniform_int_distribution<int> distribution(left, right);
		int randInt = distribution(generator);
//test
//		cout << left << " " << right << endl;
//		cout << "pivot index: " << randInt << endl;
//end test
		//make the random number the pivot; and add it to the end of the array
		//avoiding O(n^2)
		temp = varray[right];
		varray[right] = varray[randInt];
		varray[randInt] = temp;

		//loop through array
		for (int i = left; i < right; i++) {
			//if nr less than pivot add to the end of sorted sub array
			if (varray[i] < varray[right]) {
				//swap with sorted index
				temp = varray[sortedIndex];
				varray[sortedIndex] = varray[i];
				varray[i] = temp;
				sortedIndex++;
				swaps++;
			}
			//if no number is less than pivot; pivot is the smallest so add to end of sorted subarray
			if (varray[right] < varray[i] && i + 1 == right) {
				//swap pivot with end of sorted sub array
				temp = varray[sortedIndex];
				varray[sortedIndex] = varray[right];
				varray[right] = temp;
				swaps++;
				//at this point everything smaller than the pivot is on the left side of the array
				//everything bigger on the right side
			}
//test
//			print(varray);
//end test
		}
		//break into left of pivot array
		quickSort(varray, left, sortedIndex - 1);
		//break into right of pivot array
		quickSort(varray, sortedIndex + 1, right);
	}
	return swaps;
}
int bucketSort(vector < int >& varray) {
	static int swaps = 0;
	static int highestValue = 0;
	///our bucket vector, and bucket range
	static int lowRange = 0;
	static int highRange = 10;
	vector < int > bucket;
	static vector < int > sorted;

	//before we do anything get highest range
	if (swaps == 0) {
		highestValue = getHighest(varray);
	}

	vector < int >::const_iterator it;
	it = varray.begin();
	//clear previous bucket
	bucket.clear();
	//break into buckets
//	cout << lowRange << " " << highestValue << " " << highRange << endl;
	while (it != varray.end()) {
		//if in bucket range
		if (*it > lowRange && *it < highRange) {
			bucket.push_back(*it);
//			cout << *it << " ";
		}
		it++;
	}
	//sort values in bucket using any sort
	swaps += shell(bucket);
	//add the bucket back to the vector
	for (int i = 0; i < bucket.size(); i++) {
		sorted.push_back(bucket[i]);
	}
	//while highRange is < HighestValue
	if (highestValue > highRange) {
		//increase range
		lowRange += 10;
		highRange += 10;
		bucketSort(varray);
	}
	//aaaand we're done :)
	else {
		varray = sorted;
	}
	return swaps;
}
int getHighest(vector < int > varray) {
	vector < int > ::const_iterator it;
	it = varray.begin();
	int largest = varray.front();
	while (it != varray.end()) {
		if (largest < *it) {
			largest = *it;
		}
		it++;
	}
	return largest;
}