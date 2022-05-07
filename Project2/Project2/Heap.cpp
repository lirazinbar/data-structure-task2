#include "Heap.h"

void Heap::insert(Person* p, int& NumComp) {
	arr[heapSize] = p;
	heapifyUp(heapSize, NumComp);
	heapSize++;
}

void Heap::heapifyUp(int index, int& NumComp) {
	if (index == 0)  return;

	int parentI = (index - 1) / 2;

	NumComp++;
	if (arr[parentI]->getId() > arr[index]->getId()) {
		swap((arr+parentI), (arr+index));

		heapifyUp(parentI, NumComp);
	}
}

Person* Heap::deleteMin(int& NumComp) {
	Person* min = arr[0];

	arr[0] = arr[heapSize - 1];
	// delete arr[heapSize - 1];
	heapSize--;
	heapifyDown(0, NumComp);
	return min;
}

void Heap::heapifyDown(int index, int& NumComp) {
	int leftI, rightI;

	leftI = (index * 2) + 1;
	rightI = leftI + 1;

	if (leftI >= heapSize) return; // is leave

	if (rightI >= heapSize) {
		NumComp++;
		if (arr[leftI]->getId() < arr[index]->getId()) {
			swap(arr + leftI, arr + index);
		}
	}
	else {
		NumComp++;
		if (arr[leftI]->getId() < arr[rightI]->getId()) {
			NumComp++;
			if (arr[leftI]->getId() < arr[index]->getId()) {
				swap(arr + leftI, arr + index);
				heapifyDown(leftI, NumComp);
			}
		}
		else {
			NumComp++;
			if (arr[rightI]->getId() < arr[leftI]->getId()) {
				NumComp++;
				if (arr[rightI]->getId() < arr[index]->getId()) {
					swap(arr + rightI, arr + index);
					heapifyDown(rightI, NumComp);
				}
			}
		}
	}
}

void Heap::buildHeap(Person** arrToBuild, int& NumComp) {
	int i;

	for (i = 0; i < heapSize; i++) {
		arr[i] = arrToBuild[i];
	}

	for (i = heapSize / 2 - 1; i >= 0; i--) {
		heapifyDown(i, NumComp);
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

Person* Heap::selectHeap(int k, int& NumComp) {
	Person* p = nullptr;
	for (int i = 1; i <= k; i++) {
		p = deleteMin(NumComp);
	}

	return p;
}