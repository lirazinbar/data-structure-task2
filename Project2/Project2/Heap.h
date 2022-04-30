#pragma once
#include "Person.h"

class Heap {
	Person** arr;
	int heapSize;

	void heapifyUp(int index);
	void heapifyDown(int index);
	void swap(Person** p1, Person** p2);

public:
	Heap(int n, int _heapSize) : arr(new Person*[n]), heapSize(_heapSize) {}
	void insert(Person* p);
	Person* min() { return arr[0]; }
	Person* deleteMin();
	void buildHeap(Person** arrToBuild);
	void makeEmpty();
	bool isEmpty() { return heapSize == 0; }
};

