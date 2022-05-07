#pragma once
#include "Person.h"

class Heap {
	Person** arr;
	int heapSize;

	void heapifyUp(int index, int& NumComp);
	void heapifyDown(int index, int& NumComp);
	void swap(Person** p1, Person** p2);

public:
	Heap(int n) : arr(new Person*[n]), heapSize(n) {}
	void insert(Person* p, int& NumComp);
	Person* min() { return arr[0]; }
	Person* deleteMin(int& NumComp);
	void buildHeap(Person** arrToBuild, int& NumComp);
	void makeEmpty();
	bool isEmpty() { return heapSize == 0; }
	Person* selectHeap(int k, int& NumComp);
};

