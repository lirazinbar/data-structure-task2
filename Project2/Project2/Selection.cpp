#include "Selection.h"
#include <iostream>

const Person& RandSelection(Person arr[], int n, int k, int& numComp) {
	return select(arr, 0, n - 1, k, numComp);
}

const Person& select(Person arr[], int left, int right, int k, int& numComp) {
	int pivot; // Pivot index
	int leftPart; // Size fo the left part including the pivot

	pivot = randPartition(arr, left, right, numComp);
	leftPart = pivot - left + 1;
	if (k == leftPart)
		return arr[pivot];
	else if (k < leftPart)
		return select(arr, left, pivot - 1, k, numComp);
	else
		return select(arr, pivot + 1, right, k - leftPart, numComp);
}

int randPartition(Person arr[], int left, int right, int& numComp) {
	int randPivot;

	if (left == right)
		return left;
	// A number between left and right, including
	randPivot = rand() % (right - left) + left;
	// Swap the random pivot to be the first in the array, in order to use the regular partition
	swapPerson(arr, randPivot, left);
	return partition(arr, left, right, numComp);
}

int partition(Person arr[], int left, int right, int& numComp) {
	int pivot = left;
	int nonPivot = right;

	while (pivot != nonPivot) {
		numComp++;
		if (neededToSwap(pivot, nonPivot, arr[pivot].getId(), arr[nonPivot].getId())) {
			// Swap the persons in the array
			swapPerson(arr, pivot, nonPivot);
			// Swap the pivots indexes
			swap(pivot, nonPivot);
		}
		if (nonPivot < pivot) {
			nonPivot++;
		}
		else {
			nonPivot--;
		}
	}
	return pivot;
}

bool neededToSwap(int pivot, int nonPivot, int pivotKey, int nonPivotKey) {
	// True if the pivot is more left but bigger, or more right but smaller
	return (pivot < nonPivot&& pivotKey > nonPivotKey) ||
		(pivot > nonPivot && pivotKey < nonPivotKey);
}

void swapPerson(Person arr[], int index1, int index2) {
	Person tmp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = tmp;
}

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}