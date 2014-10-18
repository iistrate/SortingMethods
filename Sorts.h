#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <random>
//gen libraries
#include <iostream>

//namespaces
using std::vector;
using std::cout;
using std::endl;

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

#endif //end Sorts.H