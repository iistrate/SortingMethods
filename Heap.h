/*
 / Heap
*/

#ifndef HEAP_H
#define HEAP_H

//gen libraries
#include <iostream>
#include <vector>

//namespaces
using std::cout;
using std::endl;
using std::vector;

class Heap {
protected:
	class Node {
	private:
		Node* m_Right;
		Node* m_Left;
		int m_data;
		int m_value;
	public:
		//empty node
		Node(void) : m_data(0), m_Right(0), m_Left(0), m_value(0) {}
		//node with data
		Node(int i) : m_data(i), m_Right(0), m_Left(0), m_value(0) {}
		//node with data and priority
		Node(int i, int ii) : m_data(i), m_Right(0), m_Left(0), m_value(ii) {}

		void setRight(Node* node) {
			m_Right = node;
		}
		void setLeft(Node* node) {
			m_Left = node;
		}
		void setData(int i) {
			m_data = i;
		}
		void setValue(int i) {
			m_value = i;
		}
		Node* getRight(void) {
			return m_Right;
		}
		Node* getLeft(void) {
			return m_Left;
		}
		int getData(void) {
			return m_data;
		}
		int getValue() {
			return m_value;
		}
	};

	Node* m_Root;
	int m_count;
public:
	//empty
	Heap(void): m_Root(0) {}
	Heap(int i): m_Root(new Node(i)), m_count(1) {}

	//Heap.cpp
	void heapify(vector < int > varray);
	void insertPriorityNode(int data, int priority);
	void insertNode(int data);
	void insertNode(int data, Node* NewNode);
	void print(Node* node);

	/* Inline
	*/
	Node* getRoot(void) {
		return m_Root;
	}
	void setRoot(Node* Root) {
		m_Root = Root;
	}
	//get count
	int getCount(void) {
		return m_count;
	}
};

#endif // end Heap.h