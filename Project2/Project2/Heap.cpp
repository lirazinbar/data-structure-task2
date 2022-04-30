#include "Heap.h"

void Heap::insert(Person* p) {
	arr[heapSize] = p;
	heapifyUp(heapSize);
	heapSize++;
}

void Heap::heapifyUp(int index) {
	if (index == 0)  return;

	int parentI = (index - 1) / 2;

	if (arr[parentI]->getId() > arr[index]->getId()) {
		swap((arr+parentI), (arr+index));

		heapifyUp(parentI);
	}
}

Person* Heap::deleteMin() {
	Person* min = arr[0];

	arr[0] = arr[heapSize - 1];
	// delete arr[heapSize - 1];
	heapSize--;
	heapifyDown(0);
	return min;
}

void Heap::heapifyDown(int index) {
	int leftI, rightI;

	leftI = (index * 2) + 1;
	rightI = leftI + 1;

	if (leftI >= heapSize) return; // is leave

	if (rightI >= heapSize) {
		if (arr[leftI] < arr[index]) {
			swap(arr + leftI, arr + index);
		}
	}
	else {
		if (arr[leftI] < arr[rightI] && arr[leftI] < arr[index]) {
			swap(arr + leftI, arr + index);
			heapifyDown(leftI);
		}
		else if (arr[rightI] < arr[leftI] && arr[rightI] < arr[index]) {
			swap(arr + rightI, arr + rightI);
			heapifyDown(rightI);
		}
	}
}

void Heap::buildHeap(Person** arrToBuild) {
	int i;

	for (i = heapSize - 1; i >= heapSize / 2; i--) {
		arr[i] = arrToBuild[i];
	}

	for (i = heapSize / 2 - 1; i >= 0; i--) {
		heapifyDown(i);
	}
}

void Heap::makeEmpty() {
	delete arr;
	heapSize = 0;
}

void Heap::swap(Person** p1, Person** p2) {
	Person* temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}