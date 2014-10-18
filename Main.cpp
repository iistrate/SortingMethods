//user libraries
#include "Heap.h"
#include "Sorts.h"
#include "Globals.h"
#include "PriorityQueue.h"
#include <string>

int main(void) {
	//rand seed for quicksort c++11
	std::random_device rd;
	//our working array
	vector < int > varray;
	//build heap
	Heap Heapster;
	varray = { 99, 22, 3, 8, 5, 4, 7, 11, 9, 78, 25, 909, 76, 55, 1, 2 };
	Heapster.heapify(varray);
	//priority queue
	PriorityQueue PQ;
//	PQ.heapify(varray);
	
	int iuserInput = 0;
	std::string suserInput;
	bool running = true;
	bool showBefore = false;
	bool showAfter = false;
	while (running) {
		varray.clear();
		varray = { 99, 22, 3, 8, 5, 4, 7, 11, 9, 78, 25, 909, 76, 55, 1, 2 };
		cout << "1-Insertion Sort\n2-Selection Sort\n3-Bubble Sort\n4-Shell Sort\n5-Heap Sort\n6-Merge Sort\n7-Quick Sort\n8-Bucket Sort\n9-Quit\n10-PQInsert\n11-PQPull\n12-PQPeek\n13-PQ_Print" << endl;
		cout << "Enter number: ";
		std::getline(std::cin, suserInput);
		cout << suserInput << " ";
		cout << endl;
		iuserInput = atoi(suserInput.c_str());
		switch (iuserInput) {
		case Globals::Commands::INSERTION_SORT:
			//begin
			cout << "Array before: " << endl;
			print(varray);
			cout << "\nThere were " << insertion(varray) << " nr of swaps before sorting completed. \n" << endl;
			showAfter = true;
			break;
		case Globals::Commands::BUBBLE_SORT:
			//begin
			cout << "Array before: " << endl;
			print(varray);
			cout << "\nThere were " << bubble(varray) << " nr of swaps before sorting completed. \n" << endl;
			showAfter = true;
			break;
		case Globals::Commands::BUCKET_SORT:
			//begin
			cout << "Array before: " << endl;
			print(varray);
			cout << "\nThere were " << bucketSort(varray) << " nr of swaps before sorting completed. \n" << endl;
			showAfter = true;
			break;
		case Globals::Commands::HEAP_SORT:
			//begin
			cout << "Array before: " << endl;
			print(varray);
			cout << "Array After: " << endl;
			Heapster.print(Heapster.getRoot());
			cout << endl;
			break;
		case Globals::Commands::MERGE_SORT:
			//begin
			cout << "Array before: " << endl;
			print(varray);
			cout << "\nThere were " << merge(varray) << " nr of swaps before sorting completed. \n" << endl;
			showAfter = true;
			break;
		case Globals::Commands::QUICK_SORT:
			//begin
			cout << "Array before: " << endl;
			print(varray);
			cout << "\nThere were " << quickSort(varray, 0, varray.size() - 1) << " nr of swaps before sorting completed. \n" << endl;
			showAfter = true;
			break;
		case Globals::Commands::SELECTION_SORT:
			//begin
			cout << "Array before: " << endl;
			print(varray);
			cout << "\nThere were " << selection(varray) << " nr of swaps before sorting completed. \n" << endl;
			showAfter = true;
			break;
		case Globals::Commands::SHELL_SORT:
			//begin
			cout << "Array before: " << endl;
			print(varray);
			cout << "\nThere were " << shell(varray) << " nr of swaps before sorting completed. \n" << endl;
			showAfter = true;
			break;
		case Globals::Commands::PQ_INSERT:
			int data, priority;
			cout << "Please enter value: ";
			getline(std::cin, suserInput);
			data = atoi(suserInput.c_str());
			cout << "Please enter priority: ";
			getline(std::cin, suserInput);
			priority = atoi(suserInput.c_str());
			PQ.insert(priority, data);
			system("cls");
			cout << "Succesfully Inserted value: " << data << " with priority: " << priority << endl;
			break;
		case Globals::Commands::PQ_PULL:
			break;
		case Globals::Commands::PQ_PEEK:
			PQ.peak(PQ.getRoot());
			break;
		case Globals::Commands::PQ_PRINT:
			PQ.print(PQ.getRoot());
			break;
		case Globals::Commands::QUIT:
			running = false;
			break;
		default:
			//reset
			showAfter = false;
			break;
		}
		if (showAfter) {
			//begin
			cout << "Array after: " << endl;
			print(varray);
			cout << endl;
		}
	}
	return 0;
}