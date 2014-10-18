#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "Heap.h"

class PriorityQueue : public Heap {
private:
	int m_priority;
public:
	PriorityQueue(): m_priority(0) {}

	void insert(int priority, int data);
	int pullHighestPriority();
	void peak(Node* node);
	void print(Node* node);
};

#endif