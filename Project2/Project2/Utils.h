#pragma once
#include "Person.h"
#include "Heap.h"

// Print the result from one of the selection function to the screen
void printResult(const Person& kPerson, int numComp, const char* algorithm);
const Person& selectHeap(Person* persons, int n, int k, int& NumComp);
const Person& BST(Person* persons, int n, int k, int& NumComp);
