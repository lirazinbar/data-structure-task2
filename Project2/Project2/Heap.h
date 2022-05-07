#pragma once
#include "Person.h"

class Heap {
	Person** arr;
	int heapSize;

	void heapifyUp(int index, int& NumComp);
	void heapifyDown(int index, int& NumComp);
	void swap(Person** p1, Person** p2);

public:
	// Ctor
	Heap(int n) : arr(new Person*[n]), heapSize(n) {}
	// Insert the person to the heap
	void insert(Person* p, int& NumComp);
	// Returns the minimum number in the heap
	Person* min() { return arr[0]; }
	// Deletes the minimum number in the heap
	Person* deleteMin(int& NumComp);
	// Builds heap from a given arr of persons and counts the amount of comparisons
	void buildHeap(Person* arrToBuild, int& NumComp);
	// Empties the heap
	void makeEmpty();
	// Return true if the heap is empty
	bool isEmpty() { return heapSize == 0; }
	// Returns the k'th person in the heap
	Person* selectHeap(int k, int& NumComp);
};

