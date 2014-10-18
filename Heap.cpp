#include "Heap.h"


void Heap::insertPriorityNode(int priority, int data) {
	//if empty assign to node
	if (m_count == 0) {
		m_Root = new Node(priority);
		m_Root->setValue(data);
		m_count++;
	}
	//if more than one node
	else {
		insertNode(priority, m_Root);
	}
}

void Heap::insertNode(int data) {
	//if empty assign to node
	if (m_count == 0) {
		m_Root = new Node(data);
		m_count++;
	}
	//if more than one node
	else {
		insertNode(data, m_Root);
	}
}

void Heap::insertNode(int data, Node* NewNode) {
	if (data < NewNode->getData()) {
		if (NewNode->getLeft() != 0) {
			//if left not empty keep looking
			insertNode(data, NewNode->getLeft());
		}
		//create left node
		else {
			Node* left = new Node(data);
			NewNode->setLeft(left);
		}
	}
	else {
		if (NewNode->getRight() != 0) {
			//if right not empty keep looking
			insertNode(data, NewNode->getRight());
		}
		//create left node
		else {
			Node* right = new Node(data);
			NewNode->setRight(right);
		}
	}
}

void Heap::heapify(vector < int > varray) {
	for (int i = 0; i < varray.size(); i++) {
		insertNode(varray[i]);
	}
}
void Heap::print(Node* node) {
	if (node) {
		//go left
		print(node->getLeft());
		std::cout << node->getData() << " ";
		//go right
		print(node->getRight());
	}
}
