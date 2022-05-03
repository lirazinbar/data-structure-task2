#pragma once

#include "Person.h"

// Selection algorithm using random pivot
const Person& RandSelection(Person[], int n, int k, int& numComp);
// Selection algorithm using random pivot - Different function signature
const Person& select(Person arr[], int left, int right, int k, int& numComp);
// Partition algorithm which using random pivot
int randPartition(Person arr[], int left, int right, int& numComp);
// Partition algorithm
int partition(Person arr[], int left, int right, int& numComp);
// True if the pivot is more left but bigger, or more right but smaller
bool neededToSwap(int pivot, int nonPivot, int pivotKey, int nonPivotKey);
// Swap two persons in array
void swapPerson(Person arr[], int index1, int index2);
// Swap two integers
void swap(int& a, int& b);