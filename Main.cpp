//user libraries
#include "Heap.h"
//sort declarations
#include "Sorts.h"
#include "Globals.h"

int main(void) {
	//rand seed for quicksort c++11
	std::random_device rd;
	//our heap
	Heap Heapster;
	//our working array
	vector < int > varray;
	//build heap
	varray = { 99, 22, 3, 8, 5, 4, 7, 11, 9, 78, 25, 909, 76, 55, 1, 2 };
	Heapster.heapify(varray);
	
	int iuserInput = 0;
	char cuserInput;
	bool running = true;
	bool showBefore = false;
	bool showAfter = false;
	while (running) {
		varray.clear();
		varray = { 99, 22, 3, 8, 5, 4, 7, 11, 9, 78, 25, 909, 76, 55, 1, 2 };
		cout << "1-Insertion\n2-Selection\n3-Bubble\n4-Shell\n5-Heap\n6-Merge\n7-Quick\n8-Bucket\n9-Quit" << endl;
		cout << "Enter number: ";
		std::cin >> cuserInput;
		cout << cuserInput << " ";
		cout << endl;
		iuserInput = cuserInput - '0';
		switch (iuserInput) {
		case Globals::Sorts::INSERTION_SORT:
			//begin
			cout << "Array before: " << endl;
			print(varray);
			cout << "\nThere were " << insertion(varray) << " nr of swaps before sorting completed. \n" << endl;
			showAfter = true;
			break;
		case Globals::Sorts::BUBBLE_SORT:
			//begin
			cout << "Array before: " << endl;
			print(varray);
			cout << "\nThere were " << bubble(varray) << " nr of swaps before sorting completed. \n" << endl;
			showAfter = true;
			break;
		case Globals::Sorts::BUCKET_SORT:
			//begin
			cout << "Array before: " << endl;
			print(varray);
			cout << "\nThere were " << bucketSort(varray) << " nr of swaps before sorting completed. \n" << endl;
			showAfter = true;
			break;
		case Globals::Sorts::HEAP_SORT:
			//begin
			cout << "Array before: " << endl;
			print(varray);
			cout << "Array After: " << endl;
			Heapster.print(Heapster.getRoot());
			cout << endl;
			break;
		case Globals::Sorts::MERGE_SORT:
			//begin
			cout << "Array before: " << endl;
			print(varray);
			cout << "\nThere were " << merge(varray) << " nr of swaps before sorting completed. \n" << endl;
			showAfter = true;
			break;
		case Globals::Sorts::QUICK_SORT:
			//begin
			cout << "Array before: " << endl;
			print(varray);
			cout << "\nThere were " << quickSort(varray, 0, varray.size() - 1) << " nr of swaps before sorting completed. \n" << endl;
			showAfter = true;
			break;
		case Globals::Sorts::SELECTION_SORT:
			//begin
			cout << "Array before: " << endl;
			print(varray);
			cout << "\nThere were " << selection(varray) << " nr of swaps before sorting completed. \n" << endl;
			showAfter = true;
			break;
		case Globals::Sorts::SHELL_SORT:
			//begin
			cout << "Array before: " << endl;
			print(varray);
			cout << "\nThere were " << shell(varray) << " nr of swaps before sorting completed. \n" << endl;
			showAfter = true;
			break;
		case Globals::QUIT:
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