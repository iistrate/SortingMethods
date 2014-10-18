#include "PriorityQueue.h"

void PriorityQueue::insert(int priority, int data) {
	Heap::insertPriorityNode(priority, data);
}
void PriorityQueue::peak(Node* node) {
	int value = 0;
	if (node) {
		//go left
		value = node->getLeft()->getValue();
	}
	else {
		cout << "Highest priority number is: " << value << endl;
	}
}
void PriorityQueue::print(Node* node) {
	if (node) {
		//go left
		print(node->getLeft());
		std::cout << node->getValue() << " ";
		//go right
		print(node->getRight());
	}
}